// Problem Link
// https://www.hackerrank.com/challenges/sum-numbers-c/problem?isFullScreen=false

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float FLVar1, FLVar2;
    int Var1, Var2;
    scanf("%d %d", &Var1, &Var2);
    scanf("%f %f", &FLVar1, &FLVar2);

    printf("%d %d\n", (Var1 + Var2), (Var1 - Var2));
    printf("%f %f\n", (FLVar1 + FLVar2), (FLVar1 - FLVar2));


    return 0;
}