#include <execinfo.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

void child_process(char **arguments,int case_t)
{//from professor's slides
  
    
    int status=EXIT_SUCCESS;
    pid_t pid;
    pid = fork();
    if (pid < 0)
        perror("fork failed!");
    else if (pid==0){
            if(case_t){
            //printing out the arguments 
                for (int i = 0; arguments[i]; i++)
                        fprintf(stderr, "%s ", arguments[i]);
                fprintf(stderr,"\n");       
            }
                
                
        execvp(arguments[0], arguments);//actual execution happens here
        fprintf(stderr,"execvp failed; invalid command?\n");
        exit(EXIT_FAILURE);
    }
    else
        if(waitpid(pid,&status,0)==-1){
            fprintf(stderr,"waitpid failed");
            exit(EXIT_FAILURE);
    }

}


int main(int argc, char *argv[])
{
    int max_n = 128,r,i,opt,case_t=0;
    size_t len = 0;
    
    //option parsing
    while ((opt = getopt(argc, argv, "n:t")) != -1)
    {
        
        switch (opt)
        {
        case 'n':
            if(atoi(optarg)>=1)
                max_n = atoi(optarg);
                //max_n gets changed to option n's argument
            break;
        case 't':
            case_t=1;
            break;
        default:
            fprintf(stderr,
                    "Usage: -n to specify max number of arguments per line, -t to show "
                    "argument list before"
                    "command is executed\n");
            exit(EXIT_FAILURE);
        }
    }
    //creating an array with the command and its arguments
    //the first position will be the command itself
    //and the last position should be null
   
   
   char *arguments[max_n+2];

    if (optind == argc) //if there are no commands mentioned, default is /bin/echo
       arguments[0]="/bin/echo";
    else
        arguments[0]=argv[optind];

    for (;;)
    {
        
        for (i = 1; i <= max_n; i++)
        {
            arguments[i]=NULL;
            //inititalising everything with NULL
            if((r=getline(&arguments[i],&len,stdin))==-1)//reading with getline
                break;//break if there is nothing more to read
            arguments[i][strlen(arguments[i]) - 1] = '\0';//replacing the last \n with null
            
        }
        for (int k = i; k <= max_n + 1;k++)
            arguments[k] = NULL; //rest of the arguments get NULL
        child_process(arguments, case_t);//calling the function where a child is created
        //and the child takes the command
    if(r<=0) //checking one more time if there is anything left to read
        break;
    }

    return 0;
}