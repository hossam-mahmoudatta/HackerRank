// HackerRank_PS(Intermediate)_Bitwise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    
    printf("Hello World!\n\n");
    // BITWISE AND Problem
    // So whats the algorithm?
    /*
    I will AND the index with its next one
    Nested for loop so that i can take each index with the next one
    After ANDing, I will save the result, and then check if its a power of two if  i squared
    if then, increment a counter

    */
    int arr[3] = { 0, 2, 4 };
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    int value = 0;
    int counter = 0;
    int power = 0;
    for (int i = 0; i < arrLength; i++) {
        for (int j =i + 1; j < arrLength; j++) {
            value = arr[i] & arr[j];
            //value = sqrt(value);
            if (value == 0) {
                continue;
             }
            while (value % 2 == 0) {
                value /= 2;
            }
            if (value == 1) {
                counter++;
            }

            /*
            while (pow(2, power) != value) {
                power++;
                if (power > 12) {
                    continue;
                }
            }
            counter++;
            */
            value = 0;
        }
    }
    printf("How many pairs? %d", counter);
    printf("\n");

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
