#include <stdio.h>
#include <limits.h>
/*2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
  What is the sum of the digits of the number 2^1000? */
/*
   0  1  2  3  4  5  6  7  8  9  10
   1
   2
   4
   8
   6  1
   2  3
   4  6
   8  2  1 
   6  5  2
   double, then add carry
   */

int main() {
    unsigned char two[2000];
    unsigned int place;
    unsigned int carryCurrent = 0;
    unsigned int carryNext = 0;
    //set up two[]
    //two[] will contain all digits for this number. 
    two[0] = 1;
    for (int i = 1; i < 2000; i++)
        two[i] = 0;

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 100; j++) {
            two[j] = two[j] + two[j];
            if (two[j] >= 10){
                carryNext = two[j] / 10; //in c division truncates to 0
                two[j] = two[j] % 10; //bring number down to single digit
                two[j] = two[j] + carryCurrent;
                //if we were doing powers of 3 then we would need to worry aobut two[j] + carryCurrent being a 2 digit number, but with powers of 2 this should never happen. 
                if (two[j] >= 10) {
                    printf("Error, two[%d] in illegal state with value: %c\n", j, two[j]);
                }
            }
            else if (two[j] == 0) {
                two[j] = carryCurrent;
                carryNext = 0;
            }
            else {
                two[j] = two[j] + carryCurrent;
                carryNext = 0;
                if (two[j] >= 10) {
                    printf("Error, two[%d] in illegal state with value: %c\n", j, two[j]);
                }
            }
            carryCurrent = carryNext;
            carryNext = 0;
        }
    }

    for (int i = 0; i <= 1001; i++) {
        char toPrint = two[i];
        printf("%d ", toPrint);
    }
}
