/*===========================================================================*/
/*                                                                           */
/* This file is part of the SYMPHONY Branch, Cut, and Price Library.         */
/*                                                                           */
/* SYMPHONY was jointly developed by Ted Ralphs (tkralphs@lehigh.edu) and    */
/* Laci Ladanyi (ladanyi@us.ibm.com).                                        */
/*                                                                           */
/* (c) Copyright 2000, 2001, 2002 Ted Ralphs. All Rights Reserved.           */
/*                                                                           */
/* This software is licensed under the Common Public License. Please see     */
/* accompanying file for terms.                                              */
/*                                                                           */
/*===========================================================================*/

#include <stdio.h>

#include "BB_constants.h"
#include "cp_u.h"

/*===========================================================================*/

/*===========================================================================*\
 * This file contains the user-written functions of the cut pool process.
\*===========================================================================*/

/*===========================================================================*\
 * Here is where the user must receive all of the data sent from
 * user_send_cp_data() and set up data structures. Note that this function is
 * only called if one of COMPILE_IN_CP, COMPILE_IN_LP, or COMPILE_IN_TM is
 * FALSE.
\*===========================================================================*/

int user_receive_cp_data(void **user)
{
   *user = NULL;
   
   return(USER_NO_PP);
}

/*===========================================================================*/

/*===========================================================================*\
 * Here, we free up the data structures
\*===========================================================================*/

int user_free_cp(void **user)
{
   return(USER_NO_PP);
}

/*===========================================================================*/

int user_receive_lp_solution_cp(void *user)
{
   return(USER_NO_PP);
}

/*===========================================================================*/

/*===========================================================================*\
 * When a new solution arrives to the cut pool, this function is invoked
 * so that the user can prepare for checking many cuts (probably set up
 * some data structures that make ckecking more efficient). 
\*===========================================================================*/

int user_prepare_to_check_cuts(void *user, int varnum, int *indices,
			       double *values)
{
   return(USER_NO_PP);
}


/*===========================================================================*/

/*===========================================================================*\
 * Check to see whether a particular cut is violated by the current LP sol.
\*===========================================================================*/
      
int user_check_cut(void *user, double etol, int number, int *indices,
		   double *values, cut_data *cut, int *is_violated,
		   double *quality)
{
   /*------------------------------------------------------------------------*\
    * Here the cut is "unpacked" and checked for violation. Each cut is
    * stored as compactly as possible. The subtour elimination constraints
    * are stored as a vector of bits indicating which side of the cut each
    * node is on. If the cut is violated, it is sent back to the lp.
    * Otherwise, "touches" is incremented. "Touches" is a measure of the
    * effectiveness of a cut and indicates how long it has been since a
    * cut was useful
   \*------------------------------------------------------------------------*/

  switch (cut->type){
      
    default:
       printf("Cut type not recognized! \n\n");
       *is_violated = FALSE; 
       return(USER_NO_PP);
  }

  return(USER_NO_PP);
}

/*===========================================================================*/

/*===========================================================================*\
 * This function is invoked when all cuts that needed to be checked for
 * the current solution have been checked already. (Disassemble the
 * data structures built up in 'user_prepare_to_check_cuts'.
\*===========================================================================*/

int user_finished_checking_cuts(void *user)
{
   return(USER_NO_PP);
}

/*===========================================================================*/

