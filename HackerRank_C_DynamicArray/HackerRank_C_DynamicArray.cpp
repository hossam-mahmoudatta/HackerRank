// Problem Link
// https://www.hackerrank.com/challenges/dynamic-array-in-c/problem?isFullScreen=false
// I dont understand the final lines of code solutions..
#include <stdio.h>
#include <stdlib.h>

// This stores the total number of books in each shelf.
int* total_number_of_books;
// So that I can read what the value the address is holding?

// This stores the total number of pages in each book of each shelf.
//The rows represent the shelves and the columns represent the books.
int** total_number_of_pages;
// Why is this a pointer to a pointer to an integer?

int main()
{
    // Here i will be inputting the number of shelves
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    // Here i will be inputting the number of queries
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    // I will create dynamic arrays of the books and pages by allocating memory for them.
    total_number_of_books = (int*)malloc(sizeof(int) * total_number_of_shelves);
    total_number_of_pages = (int**)malloc(sizeof(int *) * total_number_of_shelves);

    // Now i will initialize the values of the allocated memory by zero.
    for (int i = 0; i < total_number_of_shelves; i++) {
        // initialize books by zero
        total_number_of_books[i] = 0;

        // But why did i allocate here again for the pages?
        total_number_of_pages[i] = (int*)malloc(sizeof(int)); // ?
    }

    while (total_number_of_queries--) {
        int type_of_query;
        // The type of query either its 1, 2, or 3
        scanf("%d", &type_of_query);

        if (type_of_query == 1) {
            
            // Process the query of first type here.
            int x, y;
            scanf("%d %d", &x, &y);
            
            // int x is the number of the shelve, so if i wanted this query
            // then that means i need to increment the count of books 
            // by one each time i do this query.
            total_number_of_books[x] += 1;
            
            // Why did i reallocate here for the pages again?
            // these two commands i really dont understand them..
            total_number_of_pages[x] = realloc(total_number_of_pages[x], 
                total_number_of_books[x] * sizeof(int));
            total_number_of_pages[x][total_number_of_books[x] - 1] = y;

        }

        else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);

            // Query2 function is to print the number of pages in the Yth book on the Xth Shelve
            // 
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        }
        else {
            int x;
            scanf("%d", &x);

            // Query3 function is to print the number of books on the Xth Shelve
            // 
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }

    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }

    if (total_number_of_pages) {
        free(total_number_of_pages);
    }

    return 0;
}