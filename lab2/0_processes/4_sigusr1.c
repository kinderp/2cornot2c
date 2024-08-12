/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define SOME_MINUTES 5 
#define SECONDS_PER_MINUTE 60

sig_atomic_t sigusr1_count = 0;

void handler (int signal_number)
{
  ++sigusr1_count;
}

int main ()
{
  struct sigaction sa;
  memset (&sa, 0, sizeof (sa));
  sa.sa_handler = &handler;
  sigaction (SIGUSR1, &sa, NULL);

  time_t start = time(NULL); 
  while (time(NULL) - start < (time_t) (SOME_MINUTES * SECONDS_PER_MINUTE)) { 
    printf("*");
  } 
  printf ("SIGUSR1 was raised %d times\n", sigusr1_count);
  return 0;
}
