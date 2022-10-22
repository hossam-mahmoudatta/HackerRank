// Problem Link
// https://www.hackerrank.com/challenges/for-loop-in-c/problem?isFullScreen=false
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main()
{
    int a, b;
    const char* numbers[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    scanf("%d\n%d", &a, &b);
    // Complete the code.
    
    for (int i = a ; i <= b ; i++) {
        if (i >= 1 && i <= 9) {
            printf("%s\n", numbers[i]);
            // to print the number words between the constraints
        }
        else if (i % 2 == 0) {
            printf("even\n");
            // to print the number larger than 9
        }
        else {
            printf("odd\n");
            // to print the number larger than 9
        }
    }

    return 0;
}

