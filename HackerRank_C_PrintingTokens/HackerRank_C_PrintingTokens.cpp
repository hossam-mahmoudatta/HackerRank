// Problem Link
// https://www.hackerrank.com/challenges/printing-tokens-/problem?isFullScreen=false

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    // Allocating the size for the sentence as the max of 1000 chars
    char *sentence = (char *)malloc(1024 * sizeof(char));
    // Getting user input untill newline char
    scanf("%[^\n]", sentence);
    // Reallocating memory to the exact length of the sentence
    sentence = (char*)realloc(sentence, strlen(sentence) + 1);

    //Write your logic to print the tokens of the sentence here.
    for (int i = 0 ; i < strlen(sentence) ; i++) {
        if (sentence[i] == ' ') {
            printf("\n");
        }
        else {
            printf("%c", sentence[i]);
        }
    }
    printf("\n");
    
    free(sentence);
    return 0;
}