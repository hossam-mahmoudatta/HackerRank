#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void calculate_the_maximum(int n, int k) {
    //Write your code here.
    int* arr;
    int a, b;
    int maxAnd = 0, maxOr = 0, maxXor = 0; // Initializing values
    int andOP, orOP, xorOP; // This for comparing the andOperation with its Maximum value

    arr = (int*)malloc(n * sizeof(int)); // Creating a dynamic array with the size of 'n'
    for (int i = 0 ; i < n ; i++) {
        arr[i] = i + 1; // Fillin ght earray starting from 1
    }

    for (int i = 0; i < n; i++) {
        // Here the implementation is a nested for loop
        a = arr[i];
        for (int j = i + 1 ; j < n ; j++) {
            b = arr[j];

            andOP = a & b;
            orOP = a | b;
            xorOP = a ^ b;

            if (andOP < k) {
                if (andOP > maxAnd) {
                    maxAnd = andOP;
                }
            }
            if (orOP < k) {
                if (orOP > maxOr) {
                    maxOr = orOP;
                }
            }
            if (xorOP < k) {
                if (xorOP > maxXor) {
                    maxXor = xorOP;
                }
            }
        }
    }
    printf("%d\n%d\n%d", maxAnd, maxOr, maxXor);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
