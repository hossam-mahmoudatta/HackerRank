// Problem Link
// https://www.hackerrank.com/challenges/printing-pattern-2/problem?isFullScreen=false

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    // Complete the code to print the pattern.
    for (int i = n ; i > 0 ; i--) {
        printf("%d ", i);
    }




    return 0;
}


// = ($B$1 - ($B$1 * (IF((YEAR(NOW()) - $B$3) = 0, 0, (IF((YEAR(NOW()) - $B$3) >= 1, 0.1 + ((YEAR(NOW()) - $B$3) - 1) * 0.05, 0)))))) * (IF($B$2 = 1, 0.66, (IF($B$2 = 2, 2.23, 2.78))))