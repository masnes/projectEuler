/*
 * =====================================================================================
 *
 *       Filename:  triangle.c
 *
 *    Description:  Solution to project Euler problem 12 - factors of triangles *
 *        Version:  1.0
 *        Created:  10/23/2013 04:41:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Asnes
 *   Organization:  
 *
 *
 * =====================================================================================
 */


/* A program designed to solve the problem present in the instructions.txt file. This problem created by project euler */

// Michael Asnes

#include <stdio.h>
#include <math.h>

int factors(int x) {
    // count factors of x here
    int counter = 1;
    int stopper = sqrt(x); 
    int factors = 0;
    do {
        if (x%counter == 0) {
            factors++;
        }
        counter++;
    } while (counter <= stopper);
    // since stopper == sqrt(x), the number of factors will be twice what it appears to be
    return (2*factors);

}
/* count up the triangle numbers. factor each one. Stop when the number of factors = numfact. print the triangle number which contains these factors */
int main() {
   int numfact;
   int intcounter = 0;
   int triangle = 0;
   // count up the triangle
   do {
       intcounter ++;
       triangle += intcounter;
       numfact = factors(triangle);
       if (numfact >= 500 ) 
       {
           printf("%d\n", triangle);
           printf("%d\n", numfact);
           break;
       }
   } while ((numfact < 500) && (intcounter < 1000000));
   if (numfact < 500) 
   {
       printf("Program terminated before finding a sufficiently large triangle number");
       printf("%d\n", triangle);
       printf("%d\n", numfact);
   }

}
