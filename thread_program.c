#include <stdio.h>  // For printf()
#include <stdlib.h> // For exit()
#include <pthread.h>

/* Global variable: accessible to all threads */
int thread_count = 0;

int main(int argc, char *argv[])
{
  long thread; /* Use long in case of a 64-bit system */
  pthread_t *thread_handles;
  long val;
  char *argument_pointer;

  if (argc - 1 < 1)
  {
    fprintf(stderr, "main: no argument specified\n");
    exit(1);
  }

  argument_pointer = argv[1];

  /* Get number of threads from command line */
  val = strtol(argument_pointer, &argument_pointer, 10);
  if (*argument_pointer != 0)
  {
    fprintf(stderr, "main: argument is not an integer\n");
    exit(1);
  }
  thread_count = (int)val;

}
