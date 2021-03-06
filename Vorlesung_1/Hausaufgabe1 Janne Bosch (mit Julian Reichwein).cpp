/*
Homework 1
C-PROGRAMMING Semester 2
Names: Janne Bosch, Julian Reichwein
Tutor:  Jannik Wiessler
Date: 09.05.2020

This is a program that applies the Newton-Raphson method to a function "fncn"
that is hardcoded in. Also the derivation of the function "derv" has to be
hardcoded in.
*/




#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fncn(float x)
{
    float res;
    res = (x-3)*(x-3);
    return res;
}

float derv(float x)
{
    float res;
    res = 2*(x-3);
    return res;
}

int main()
{
    float xn=1;
    float xnplus=2;
    
    do
    {
        xnplus = xn-fncn(xn) / derv(xn);
        xn = xnplus;
        printf("%f \n", xnplus);
    }
    while(fncn(xn)>0.0000000000001);

    return 0;
}

/*
JW-2020-05-12:
--------------
> nice implementation! (8/10) 
> missing extra lib (*.c + *.h) incl. includegard includeguards: -1 P
> missing abort criteria of max iterations: -1P
> please insert *.c files instead of .cpp next time :-) thanks !
*/
