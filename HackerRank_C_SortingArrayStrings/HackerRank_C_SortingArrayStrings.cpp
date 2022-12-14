// Problem Link
// https://www.hackerrank.com/challenges/sorting-array-of-strings/problem?isFullScreen=false

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    // a and b are strings
    // Here the while loop will loop untill the null character inside the character
    while (*a != '\0' || *b != '\0') {
        if (*a < *b) {
            return -1;
        }
        else if (*a > *b) {
            return 1;
        }
        else if (*a == '\0') {
            return -1;
        }
        else if (*b == '\0') {
            return 1;
        }
        a++, b++;
    }
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    // a and b are strings
    return -1 * lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    // a and b are strings
    int aLength = strlen(a);
    int bLength = strlen(b);

    if (aLength < bLength) {
        return -1;
    }
    else if (aLength > bLength) {
        return 1;
    }
    return lexicographic_sort(a, b);
}

int distinct_identifer(const char* a) {
    const char* temp;
    int sum = 0;
    int is_distinct;

    while (*a != '\0') {
        // Since a is not null, then its a unique char
        is_distinct = 1;
        // set the temp char to the next char in the string
        temp = a + 1;
        while (*temp != '\0') {
            if (*temp == *a) {
                // if this condition is true, then the letters are same, so no distinctions
                is_distinct = 0;
                // Break will go outside the while loop of the temp
                break;
            }
            temp++;
        }
        sum += is_distinct;
        a++;
    }
    return sum;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    // a and b are strings
    int a_distinct = distinct_identifer(a);
    int b_distinct = distinct_identifer(b);

    if (a_distinct < b_distinct)
        return -1;
    if (a_distinct > b_distinct)
        return 1;

    // else
    return lexicographic_sort(a, b);
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    // Why is the Array of strings length is declared in const?
    // 
    // Declaring a temp variable to store the 1st word from the main array
    char* temp;
    int k = 1;

    for (int i = 0 ; i < len ; i++) {
        //printf("\n%d: %s\n", (i + 1), *(arr + i)); // reading whats inside the address place
        //printf("Printing now characters of the word: \n");

        for (int j = i + 1; j < len ; j++) {
            // *(&arr[j] + i) actually prints garbage in the place of the characters
            // Turns out that *((*(arr + i)) + j) is what will print the chars inside the string
            // And turns out that arr[i][j] works too!
            // To explain, *(arr + i) means arr[i]
            // And *((*(arr + i)) + j) means arr[i][j]
            //printf("%d.%d: %c\n", (i + 1), (k), *((*(arr + i)) + k - 1));
            if (cmp_func(arr[i], arr[j]) > 0) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            k++;
        }
    }
}


int main()
{
    printf("Size of the array of strings: \n");
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
    free(arr);
}