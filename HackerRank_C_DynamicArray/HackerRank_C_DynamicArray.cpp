#include <stdio.h>
#include <stdlib.h>

// This stores the total number of books in each shelf.
int* total_number_of_books;

// This stores the total number of pages in each book of each shelf.
//The rows represent the shelves and the columns represent the books.
int** total_number_of_pages;

int main()
{
    // Here i will be inputting the number of shelves
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    // Here i will be inputting the number of queries
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);


    while (total_number_of_queries--) {
        int type_of_query;

        // The type of query either its 1, 2, or 3
        scanf("%d", &type_of_query);

        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);

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