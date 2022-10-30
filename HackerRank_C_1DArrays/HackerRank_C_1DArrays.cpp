// Problem Link
// https://www.hackerrank.com/challenges/1d-arrays-in-c/problem?isFullScreen=false

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    //printf("Enter the size of the array: ");
    scanf("%d", &n);
    int sum = 0;
    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }
    printf("%d", sum);
    
    free(array);
    return 0;
}