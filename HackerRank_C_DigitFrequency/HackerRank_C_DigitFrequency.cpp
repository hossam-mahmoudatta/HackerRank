// Problem Link
// https://www.hackerrank.com/challenges/frequency-of-digits-1/problem?isFullScreen=true

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    // Allocating the size for the sentence as the max of 1000 chars
    char* sentence = (char*)malloc(1024 * sizeof(char));
    int frequency[10] = { 0 };
    // Getting user input untill newline char
    scanf("%s", sentence);
    // Reallocating memory to the exact length of the sentence
    sentence = (char*)realloc(sentence, strlen(sentence) + 1);

    //Write your logic to print the tokens of the sentence here.
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == '0') {
            frequency[0] += 1;
        }
        else if (sentence[i] == '1') {
            frequency[1] += 1;
        }
        else if (sentence[i] == '2') {
            frequency[2] += 1;
        }
        else if (sentence[i] == '3') {
            frequency[3] += 1;
        }
        else if (sentence[i] == '4') {
            frequency[4] += 1;
        }
        else if (sentence[i] == '5') {
            frequency[5] += 1;
        }
        else if (sentence[i] == '6') {
            frequency[6] += 1;
        }
        else if (sentence[i] == '7') {
            frequency[7] += 1;
        }
        else if (sentence[i] == '8') {
            frequency[8] += 1;
        }
        else if (sentence[i] == '9') {
            frequency[9] += 1;
        }
    }
    //printf("\nFrequency is: \n");
    for (int i = 0; i < (sizeof(frequency) / sizeof(int)) ; i++) {
        printf("%d ", frequency[i]);
    }
    free(sentence);
    return 0;
}