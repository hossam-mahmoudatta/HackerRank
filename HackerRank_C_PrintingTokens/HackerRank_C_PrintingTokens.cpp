// Problem Link
// https://www.hackerrank.com/challenges/printing-tokens-/problem?isFullScreen=false

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char *s = (char *)malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = (char*)realloc(s, strlen(s) + 1);

    //Write your logic to print the tokens of the sentence here.
    for (int i = 0; i < strlen(s); i++) {
        printf("%s", s[i]);
    }
    
    free(s);
    return 0;
}