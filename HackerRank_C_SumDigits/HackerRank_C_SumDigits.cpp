
// Problem Link
// https://www.hackerrank.com/challenges/sum-of-digits-of-a-five-digit-number/problem?isFullScreen=true
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int i = 0;
    int dividend = 10000;
    int sum = 0;
    while (i < 5) {
        n = n / dividend;
        dividend /= 10;

        sum += n;
        
        i++;
    }
    printf("The sum of the digits is: %d", sum);
    return 0;
}