/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Parameters to process_transaction function.  */

struct thread_params {
 int from;
 int to;
 float dollars;
};

/* An array of balances in accounts, indexed by account number.  */

float* account_balances;

/* Transfer DOLLARS from account FROM_ACCT to account TO_ACCT.  Return
   0 if the transaction succeeded, or 1 if the balance FROM_ACCT is
   too small.  */

void* process_transaction (void *args)
{
  struct thread_params *p= (struct thread_params *)args; 
  int from_acct = p->from;
  int to_acct = p->to;
  float dollars = p->dollars;

  int old_cancel_state;

  /* Check the balance in FROM_ACCT.  */
  if (account_balances[from_acct] < dollars)
    return (void *)1;

  /* Begin critical section.  */
  pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state);
  /* Move the money.  */
  account_balances[to_acct] += dollars;
  account_balances[from_acct] -= dollars;
  /* End critical section.  */
  pthread_setcancelstate (old_cancel_state, NULL);

  return NULL;
}

int main() {
  pthread_t thread_id;
  int thread_return_value;

  struct thread_params p;
  p.from = 0;
  p.to = 5;
  p.dollars = 9;
 
  account_balances = (float *)malloc(10*sizeof(float));
  account_balances[0] = 100;
  account_balances[1] = 67;
  account_balances[2] = 78;
  account_balances[3] = 10;
  account_balances[4] = 93;
  account_balances[5] = 1;
  account_balances[6] = 46;
  account_balances[7] = 90;
  account_balances[8] = 34;
  account_balances[9] = 13;

  for(int i=0; i< 10; i++)
    printf("[%d] %1.f$\n", i, account_balances[i]);

  pthread_create (&thread_id, NULL, &process_transaction, &p);
  pthread_join (thread_id, (void *) &thread_return_value);

  printf("\n");
  for(int i=0; i< 10; i++)
    printf("[%d] %1.f$\n", i, account_balances[i]);

  return 0;
}
