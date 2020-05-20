/*
Homework 2
C-PROGRAMMING Semester 2
Names: Janne Bosch, Julian Reichwein
Tutor:  Jannik Wiessler
Date: 16.05.2020

* DESCRIPTION: complex calculator applied in as datastructur
* INFO: For DHBW use only.

time: 11:00 - 13:30
      20:30 - 22:00
      -> total 4h

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
  char input1[100];
  char input2[100];
  double resultReal;
  double resultImag;
  char desiredaction;

  printf("Enter first complex number in format a+bi: ");
  scanf("%s", input1);

  printf("\nEnter second complex number in format a+bi: ");
  scanf("%s", input2);

  printf("\nfirst number: %s", input1);
  printf("\nsecond number: %s", input2);

  typedef struct
  {
    double realteil;
    double imagteil;
  }complexnumber;
  complexnumber num1, num2;

  char delimiter[] = "+i";
  char *ptr;

  // ************* First Number ********
  ptr = strtok(input1, delimiter);
    num1.realteil = atof(ptr);
    ptr = strtok(NULL, delimiter);

    num1.imagteil = atof(ptr);
    ptr = strtok(NULL, delimiter);
  //************************************


  // ************* Second Number *******
  ptr = strtok(input2, delimiter);
    num2.realteil = atof(ptr);
    ptr = strtok(NULL, delimiter);

    num2.imagteil = atof(ptr);
    ptr = strtok(NULL, delimiter);
  //************************************

/*
  printf("\n\nContent of num1.realteil: %f", num1.realteil);
  printf("\n\nContent of num1.imagteil: %f", num1.imagteil);
  printf("\n\nContent of num2.realteil: %f", num2.realteil);
  printf("\n\nContent of num2.imagteil: %f", num2.imagteil);
*/

  printf("\n\nDo you want to (Enter first letter):\n");
  printf("(A)dd, (S)ubtract, (M)ultiply, or (D)ivide?\n");

  printf("Your choice: ");
  do { // JW 2020-05-20 this captures default case in switch statement, well done !
    desiredaction = getchar();
  } while(desiredaction!='A' && desiredaction!='S' && desiredaction!='M' && desiredaction!='D');
  
  printf("\n");
  
  switch(desiredaction) { 

    case 'A':
      resultReal = num1.realteil + num2.realteil;
      resultImag = num1.imagteil + num2.imagteil;
      printf("%.3lf+%.3lfi + %.3lf+%.3lfi = ", num1.realteil, num1.imagteil, num2.realteil, num2.imagteil);
      printf("%.3lf+%.3lfi", resultReal, resultImag);
      break;

    case 'S':
      resultReal = num1.realteil - num2.realteil;
      resultImag = num1.imagteil - num2.imagteil;
      printf("%.3lf+%.3lfi - %.3lf+%.3lfi = ", num1.realteil, num1.imagteil, num2.realteil, num2.imagteil);
      printf("%.3lf+%.3lfi", resultReal, resultImag);
      break;

    case 'M': 
      resultReal = num1.realteil * num2.realteil - num1.imagteil * num2.imagteil;
      resultImag = num1.realteil * num2.imagteil + num2.realteil* num1.imagteil;
      printf("%.3lf+%.3lfi * %.3lf+%.3lfi = ", num1.realteil, num1.imagteil, num2.realteil, num2.imagteil);
      printf("%.3lf+%.3lfi", resultReal, resultImag);
      break;

    case 'D':
      resultReal = (num1.realteil* num2.realteil +  num1.imagteil * num2.imagteil) / (num2.realteil*num2.realteil + num2.imagteil * num2.imagteil);
      resultImag = (num1.imagteil * num2.realteil - num1.realteil * num2.imagteil) / (num2.realteil*num2.realteil + num2.imagteil * num2.imagteil);
      printf("%.3lf+%.3lfi / %.3lf+%.3lfi = ", num1.realteil, num1.imagteil, num2.realteil, num2.imagteil);
      printf("%.3lf+%.3lfi", resultReal, resultImag);
      break;
  }

 return 0;
}
/*
JW-2020-06-20:
--------------
> well done! (8/10) 
> no header and c-lib for functions and struct definition: -2 Pkt
*/
