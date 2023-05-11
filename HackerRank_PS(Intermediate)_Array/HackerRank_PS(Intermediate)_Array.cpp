// HackerRank_PS(Intermediate)_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    printf("Hello World!\n\n");
    // Equalizing Array Elements
    // So whats the algorithm?
    /*
    Have an array, I have a threshold of how many equal elements
    and I need to count the number of operations to do this
    Algorithm: 


    */
    int arr[4] = { 64, 30, 25, 33 };
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    int value = 0;
    int divisionParameter = 2;
    int threshold = 3;
    int counter = 0;

    for (int i = 0; i < arrLength; i++) {
        for (int j = i + 1; j < arrLength; j++) {
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
