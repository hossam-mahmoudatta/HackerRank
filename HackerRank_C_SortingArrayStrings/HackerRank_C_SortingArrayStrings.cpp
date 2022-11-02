// Problem Link
// https://www.hackerrank.com/challenges/sorting-array-of-strings/problem?isFullScreen=false

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    // a and b are strings
    int aLength = strlen(a);
    int bLength = strlen(b);

    if (aLength < bLength) {
        for (int i = 0; i < aLength; i++) {
            if (a[i] < b[i])
        }
    }
    else {
        for (int i = 0; i < bLength; i++) {

        }
    }

}

int lexicographic_sort_reverse(const char* a, const char* b) {

}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {

}

int sort_by_length(const char* a, const char* b) {

}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    // Why is the Array of strings lengthis declared in const?
    // Here I will take a string, or array of Strings
    // Now I have inputted the string of arrays
    // i guess i can access the chars by using nested for loop

    // Declaring a temp variable to store the 1st word from the main array
    char** temp;
    temp = (char**)malloc(1 * sizeof(char*));
    temp = arr;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < strlen(*(arr + i)); i++) {
            printf("%d: %s\n", (j + 1), **(arr + i));
        }
    }


}


int main()
{
    int n;
    scanf("%d", &n);

    char** arr;
    arr = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        *(arr + i) = (char*)malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = (char*)realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
    printf("\n");
}