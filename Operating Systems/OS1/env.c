
#include <ctype.h>
#include <execinfo.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void trace_stack() {
  // using the functions backtrace
  // and backtrace_symbols in order to
  // implement the -v option
  int temp;
  void *buffer[BUFFER_SIZE];
  char **s;
  temp = backtrace(buffer, BUFFER_SIZE);
  printf("backtrace() returned %d addresses\n", temp);
  s = backtrace_symbols(buffer, temp);
  if (s == NULL) {
    perror("backtrace_symbols() failed!");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < temp; i++)
    printf("%s\n", s[i]);
  free(s);
}
void simple_print() {
  // prints the environment
  // when env is called with
  // no arguments or just env vars
  extern char **environ;
  for (int i = 0; environ[i]; i++)
    printf("%s\n", environ[i]);
}

int valid_input(char s[]) {
  // verifying if the pairs have the correct syntax
  char special_characters[] = " ?* ()!`~\n\t$%#^&+[]{};':><@";
  // easily modifiable based on what the correct syntax is considered
  for (int i = 0; special_characters[i]; i++)
    if (strchr(s, special_characters[i]) != NULL)
      return 0;

  if (!(isalpha(s[0]) &&
        (isdigit(s[strlen(s) - 1]) || isalpha(s[strlen(s) - 1])) &&
        strchr(s, '=') != NULL))
    return 0;
  return 1;
}

int main(int argc, char *argv[]) {
  int opt;
  int j = 0;
  int temp = 1;
  while ((opt = getopt(argc, argv, "vu:")) != -1) {
    switch (opt) {

    case 'u':
      unsetenv(optarg);
      // unsetting env variable
      j += 2;
      temp = 0;
      break;
    case 'v':
      // trace to stack
      trace_stack();
      j++;
      temp = 0;
      // unsure if when the option v
      // is called if the environment should still be printed
      // if that is the case, just delete line 71
      break;
    default:
      fprintf(stderr,
              "Usage: %s -v to print a tarce , -u to remove an environment "
              "variable (expects argument) \n",
              argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  if (argc > 1) {
    for (int i = 1 + j; argv[i]; i++) {
      if (valid_input(argv[i]))
        putenv(argv[i]);
      else {
        // if the input is not considered a pair,
        // it assumes the commands start and tries to look for one
        temp = 0;
        if (fork() == 0) {
          // only commands with no arguments work
          int status_code = execvp(argv[i], &argv[i]);
          if (status_code == -1) {
            // if no unix commands are found, it means that either a pair that
            // tried to be added
            // has the wrong syntax, or the command attempted does not exist
            perror("Something went wrong with execvp:\n-perhaps entered an "
                   "argument after the pairs that is not a command?\n"
                   "-or pair syntax is  incorrect\n");
            exit(EXIT_FAILURE);
          }
        }
      }
    }
  }
  if (temp)
    // checking if there are only pairs or no arguments after the call
    // in order to print the environment only in those situations
    simple_print();
  return 0;
}