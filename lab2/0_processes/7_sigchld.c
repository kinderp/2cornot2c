/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <signal.h>	// sigaction
#include <string.h>	// memset()
#include <stdio.h>   	// fprintf()
#include <stdlib.h> 	// abort()
#include <sys/types.h>	// pid_t
#include <sys/wait.h>	// wait()
#include <unistd.h>	// fork() exec()
#include <time.h>	// time()

#define N_CHILDS 10

#define SOME_MINUTES 2
#define SECONDS_PER_MINUTE 60

sig_atomic_t child_exit_status;

void clean_up_child_process (int signal_number)
{
  /* Clean up the child process.  */
  int status;
  wait (&status);
  /* Store its exit status in a global variable.  */
  child_exit_status = status;
  fprintf (stdout, "Child exit with %d status\n", status);
}


int spawn (char* program, char** arg_list)
{
  pid_t child_pid;

  /* Duplicate this process.  */
  child_pid = fork ();
  if (child_pid != 0){
    /* This is the parent process.  */
    fprintf (stdout, "Child %d created\n", child_pid);
  } else {
    /* Now execute PROGRAM, searching for it in the path.  */
    execvp (program, arg_list);
    /* The execvp function returns only if an error occurs.  */
    fprintf (stderr, "an error occurred in execvp\n");
    abort ();
  }
}

int main ()
{
  /* Handle SIGCHLD by calling clean_up_child_process.  */
  struct sigaction sigchld_action;
  memset (&sigchld_action, 0, sizeof (sigchld_action));
  sigchld_action.sa_handler = &clean_up_child_process;
  sigaction (SIGCHLD, &sigchld_action, NULL);

  /* Now do things, including forking a child process.  */
  /* The argument list to pass to the "ls" command.  */
  char* arg_list[] = {
    "sleep",     /* argv[0], the name of the program.  */
    "60", 
    NULL      /* The argument list must end with a NULL.  */
  };

  for(int i=0; i<N_CHILDS; i++)
     spawn ("sleep", arg_list);
  
  time_t start = time(NULL);
  while (time(NULL) - start < (time_t) (SOME_MINUTES * SECONDS_PER_MINUTE));
  fprintf (stdout, "Father's quitting\n");

  return 0;
}
