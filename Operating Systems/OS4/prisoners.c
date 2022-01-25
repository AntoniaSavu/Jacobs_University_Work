#include <getopt.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int drawers[100], wins = 0;
static bool status = true;
/* start with the status (wether every prisoner has found their number)
as true, and when even one prisoner has ended their search without
their number, this will get changed to false (and reset back to true after
joining the threads)
*/
pthread_mutex_t big_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t drawers_mutex[101] = PTHREAD_MUTEX_INITIALIZER;
static void *
random_global(void *number) { // selecting random drawers using only one lock
  if (pthread_mutex_lock(&big_mutex) != 0) {
    perror("mutex lock failed");
    exit(EXIT_FAILURE);
  }
  // lock before  going through the drawers
  int n = *(int *)number;
  bool temp_status = false;
  // the prisoner starts by not finding their number
  for (int i = 0; i < 50; i++) { // selecting a random drawer
    int temp = drawers[rand() % (100) + 1];
    if (temp == n) {
      temp_status = true;
      // when they do, there is no need to search anymore
      break;
    }
  }
  if (temp_status == false)
    status = false;
  // if the prisoner didn't find the key, the game can't be
  // won anymore
  pthread_mutex_unlock(&big_mutex);
  // unlock so that other threads can go in

  return NULL;
}
static void *random_drawer(void *number) {
  int n = *(int *)number;
  bool temp_status = false;

  for (int i = 0; i < 50; i++) {
    int index = rand() % 100 + 1;
    // locking just this particular drawer
    pthread_mutex_lock(&drawers_mutex[index]);
    if (drawers[index] == n)
      temp_status = true;
    pthread_mutex_unlock(&drawers_mutex[index]);
    // unlocking after the prisoner is done searching through it
    if (temp_status == true)
      break;
  }
  if (temp_status == false)
    status = false;
  // analogous random_global function
  return NULL;
}
static void *strategy_global(void *number) {

  pthread_mutex_lock(&big_mutex);
  // having just a lock at the beginning
  int n = *(int *)number;
  int aux = n;
  bool temp_status = false;
  for (int i = 0; i < 50; i++) {
    // start by looking into the locker
    // with the prisoners number
    if (drawers[aux - 1] == n) {
      temp_status = true;
      break;
    } else
      aux = drawers[aux - 1];
    // and if it is not found, look in the
    // drawer with the number found
  }
  if (temp_status == false)
    status = false; // analogous
  pthread_mutex_unlock(&big_mutex);
  // unlock for the next prisoner
  return NULL;
}
static void *strategy_drawer(void *number) {

  int n = *(int *)number;
  bool temp_status = false;
  int aux = n;
  for (int i = 0; i < 50; i++) {
    // locking just this specific drawer
    pthread_mutex_lock(&drawers_mutex[aux - 1]);
    if (drawers[aux - 1] == n)
      temp_status = true;
    pthread_mutex_unlock(&drawers_mutex[aux - 1]);
    if (temp_status == true)
      break;
    aux = drawers[aux - 1];
  }
  if (temp_status == false)
    status = false;
  return NULL;
}
void shuffle(int a[]) {
  // function to shuffle an array
  // will use it for the drawers array
  for (int i = 0; i < 100; i++)
    a[i] = i + 1;
  for (int i = 0; i < 100; i++) {
    int aux = a[i];
    int random = rand() % 100 + 1;
    a[i] = a[random];
    a[random] = aux;
  }
}
void run_threads(int n, void *(*proc)(void *)) {
  pthread_t prisoners[101];
  int prisoners_id[101];
  int rc;
  shuffle(drawers);
  for (int i = 1; i <= 100; i++) {
    // create the threads
    // and use an additional array to be able to pass it as a parameter.
    // for all the methods to solve the riddle
    prisoners_id[i] = i;
    rc = pthread_create(&prisoners[i], NULL, proc, (void *)(prisoners_id + i));
    if (rc) {
      fprintf(stderr, "pthread_create() failed: %s\n", strerror(rc));
      exit(EXIT_FAILURE);
    }
  }
  for (int i = 0; i < 100; i++) {
    if (prisoners[i])
      rc = pthread_join(prisoners[i], NULL); // joining all the threads
    if (rc) {
      fprintf(stderr, "pthread_join() failed: %s\n", strerror(rc));
      exit(EXIT_FAILURE);
    }
  }
  // after all the threads have joined, time to look if they won
  if (status == true)
    wins++;
  status = true; // resetting the status before every game
}

static double
timeit(int n, void *(*proc)(void *)) { // exactly the same as in the HW Sheet
  clock_t t1, t2;
  t1 = clock();
  run_threads(n, proc);
  t2 = clock();
  return ((double)t2 - (double)t1) / CLOCKS_PER_SEC * 1000;
}

int main(int argc, char *argv[]) {

  int opt, option_s = 0;
  int number_games = 100;
  // option parsing
  while ((opt = getopt(argc, argv, "sn:")) != -1) {
    switch (opt) {
    case 'n':
      if (atoi(optarg) >= 1)
        number_games = atoi(optarg);
      break;
    case 's':
      option_s = 1;
      srand(time(NULL));
      break;
    default:
      fprintf(stderr, "Usage: -n to specify the number of games (requires "
                      "argument), -s to seed the random number generator \n");
      exit(EXIT_FAILURE);
    }
  }
  if (!option_s)
    srand(0);
  /*just printing in the same format as the professor's example*/
  double time = timeit(number_games, random_global);
  printf("method random_global\t%d/%d wins=%0.2lf%%\t%0.3lf ms\n", wins,
         number_games, ((double)wins / number_games) * 100, time);
  wins = 0; // resetting the wins everytime
  time = timeit(number_games, random_drawer);
  printf("method random_drawer\t%d/%d wins=%0.2lf%%\t%0.3lf ms\n", wins,
         number_games, ((double)wins / number_games) * 100, time);
  wins = 0;
  time = timeit(number_games, strategy_global);
  printf("method strategy_global\t%d/%d wins=%0.2lf%%\t%0.3lf ms\n", wins,
         number_games, ((double)wins / number_games) * 100, time);
  wins = 0;
  time = timeit(number_games, strategy_drawer);
  printf("method strategy_drawer\t%d/%d wins=%0.2lf%%\t%0.3lf ms\n", wins,
         number_games, ((double)wins / number_games) * 100, time);
  wins = 0;

  return 0;
}