// Problem Link
// https://www.hackerrank.com/challenges/sorting-array-of-strings/problem?isFullScreen=false

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    // a and b are strings
    int aLength = strlen(a);
    int bLength = strlen(b);
    int order = 0;

    if (a[0] < b[0]) {
        order = 1;
        return order;
    }
    else if (a[0] > b[0]) {
        order = 2;
        return order;
    }

    if (aLength < bLength) {
        for (int i = 0; i < aLength; i++) {
            if (a[i] < b[i]) {
                order = 1;
                return order;
            }
            else if (a[i] > b[i]) {
                order = 2;
                return order;
            }
        }
    }
    else {
        for (int i = 0; i < bLength; i++) {
            if (a[i] < b[i]) {
                order = 1;
                return order;
            }
            else if (a[i] > b[i]) {
                order = 2;
                return order;
            }
        }
    }
    return order;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    // a and b are strings
    int aLength = strlen(a);
    int bLength = strlen(b);
    int order = 0;

    if (a[0] < b[0]) {
        order = 2;
        return order;
    }
    else if (a[0] > b[0]) {
        order = 1;
        return order;
    }

    if (aLength < bLength) {
        for (int i = 0; i < aLength; i++) {
            if (a[i] < b[i]) {
                order = 2;
                return order;
            }
            else if (a[i] > b[i]) {
                order = 1;
                return order;
            }
        }
    }
    else {
        for (int i = 0; i < bLength; i++) {
            if (a[i] < b[i]) {
                order = 2;
                return order;
            }
            else if (a[i] > b[i]) {
                order = 1;
                return order;
            }
        }
    }
    return order;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    // a and b are strings
    int aLength = strlen(a);
    int bLength = strlen(b);
    int order = 0;
    
    char tempA = a[0];
    char tempB = b[0];
    for (int i = 0; i < aLength; i++) {

    }
    if (aLength < bLength) {
        order = 1;
        return order;
    }
    else if (aLength == bLength) {
        order = lexicographic_sort(a, b);
        return order;
    }
    else if (aLength > bLength) {
        order = 2;
        return order;
    }
    return order;

}

int sort_by_length(const char* a, const char* b) {
    // a and b are strings
    int aLength = strlen(a);
    int bLength = strlen(b);
    int order = 0;

    if (aLength < bLength) {
        order = 1;
        return order;
    }
    else if (aLength == bLength) {
        order = lexicographic_sort(a, b);
        return order;
    }
    else if (aLength > bLength) {
        order = 2;
        return order;
    }
    return order;
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    // Why is the Array of strings length is declared in const?
    // 
    // Declaring a temp variable to store the 1st word from the main array
    char* temp;
    temp = (char*)malloc(1 * sizeof(char*));

    for (int i = 1; i < len; i++) {
        temp = arr[i - 1];
        printf("\n%d: %s\n", (i + 1), *(arr + i)); // reading whats inside the address place
        printf("Printing now characters of the word: \n");

        for (int j = 0; j < strlen(*(arr + i)); i++) {
            // *(&arr[j] + i) actually prints garbage in the place of the characters
            // Turns out that *((*(arr + i)) + j) is what will print the chars inside the string
            // And turns out that arr[i][j] works too!
            // To explain, *(arr + i) means arr[i]
            // And *((*(arr + i)) + j) means arr[i][j]
            printf("%d.%d: %c\n", (i + 1), (j + 1), *((*(arr + i)) + j));
        }
    }


}


int main()
{
    int n;
    scanf("%d", &n);

    char** arr;
    arr = (char**)malloc(n * sizeof(char*));
    arr = NULL;

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
    free(arr);
}