// Problem Link
// https://www.hackerrank.com/challenges/printing-pattern-2/problem?isFullScreen=false

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf_s("%d", &n);
    printf("\n");
    // So how to think about it?
    // There is a pattern, that the 1st row is 
    // print n = [(n * 2) - 1] times
    // Its a nested for loop, and both loops should run for [(n * 2) - 1] times
    // Nested for loop with the same conditions because it prints a square
    // 
    // Second row is 
    // Complete the code to print the pattern.
    // 
    int sizeLimit = (n * 2) - 1;
    int start = 0;
    int end = sizeLimit - 1;
    //int numberArray[sizeLimit][sizeLimit];

   /*    */

    // Allocate memory for the array of pointers to rows
    int** numberArray = (int**)malloc(sizeLimit * sizeof(int*));

    // Allocate memory for each row
    for (int i = 0 ; i < sizeLimit ; i++) {
        numberArray[i] = (int*)malloc(sizeLimit * sizeof(int));
    }


    while (n != 0) {
        for (int i = start ; i <= end; i++) {
            for (int j = start ; j <= end ; j++) {
                if ((i == start) || (j == start) || (i == end) || (j == end)) {
                    // This condition detects if its the 1st row so that I could print "n"
                    numberArray[i][j] = n;
                    //printf("%d ", numberArray[i][j]);
                }
            }
        }
        ++start;
        --end;
        --n;
    }
    for (int i = 0; i < sizeLimit; i++) {
        for (int j = 0 ; j < sizeLimit; j++) {
            printf("%d ", numberArray[i][j]);
        }
        printf("\n");
    }

    for (int i = 0 ; i < sizeLimit ; i++) {
        free(numberArray[i]);
    }
    free(numberArray);
    /*
    */
    return 0;
}


// = ($B$1 - ($B$1 * (IF((YEAR(NOW()) - $B$3) = 0, 0, (IF((YEAR(NOW()) - $B$3) >= 1, 0.1 + ((YEAR(NOW()) - $B$3) - 1) * 0.05, 0)))))) * (IF($B$2 = 1, 0.66, (IF($B$2 = 2, 2.23, 2.78))))