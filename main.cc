/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Bookstore Management System          */
/*  Author:   Christine Laurendeau                 */
/*                                                 */
/*     Modified by Ryan Lacroix for Assignment 3   */
/*                                                 */
/*  Date:     12-FEB-2016                          */
/*                                                 */
/*  (c) 2015 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>

using namespace std;

#include "BMScontrol.h"


int main()
{
  BMScontrol* control;
  control = new BMScontrol();

  control->launch();
  
  delete control;

}

