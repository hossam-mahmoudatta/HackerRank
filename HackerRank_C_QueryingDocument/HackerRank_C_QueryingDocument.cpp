// Problem Link
// https://www.hackerrank.com/challenges/querying-the-document/problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

// This problem gonna be hard

// Creating a function to split a string
char** split_string(char* text, char delim) {
    // The idea here is to use strtok, and to use strtok, we need a delimiter
    // Dynamically allocating memory space for string
    char** resultString = (char**)malloc(1 * sizeof(char*));
    int size = 1;

    char* temp = strtok(text, &delim);
    *resultString = temp;

    while (temp != NULL) {
        size++;
        // I'm changing the size of the string as i go
        resultString = (char**)realloc(resultString, size * sizeof(char*));
        temp = strtok(NULL, &delim);
        //Now I'm storing the word inside the result
        resultString[size - 1] = temp;
    }
    return resultString;
}

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n - 1][m - 1][k - 1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[m - 1][k - 1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k - 1];
}

char**** get_document(char* text) {
    // All the logic of the problem is in this function
    char**** documentHM = NULL;
    // To identify a paragraph, I have to detect the newline after a sentence end
    char** paragraphHM = split_string(text, '\n');
    
    // Here I will be counting the amount of paragraphs I have
    int paraNumber = 0;
    while (paragraphHM[paraNumber] != NULL) {
        paraNumber++;
    }

    // Here I allocated space for the document
    documentHM = (char****)malloc((paraNumber + 1) * sizeof(char***));
    documentHM[paraNumber] = NULL;

    // Document [Paragraphs][Sentences][Words]
    // Remember this is my array

    int i = 0;
    while (paragraphHM[i] != NULL) {
        char** sentenceHM = split_string(paragraphHM[i], '.');
        int sentenceNumber = 0;
        while (sentenceHM[sentenceNumber] != NULL) {
            sentenceNumber++;
        }

        documentHM[i] = (char***)malloc((sentenceNumber + 1) * sizeof(char**));
        documentHM[i][sentenceNumber] = NULL;
        // As u saw from the previous block of code, its all about
        // allocating memory correctly for our arrays

        int j = 0;
        while (sentenceHM[j] != NULL) {
            documentHM[i][j] = split_string(sentenceHM[j], ' ');
            j++;
        }

        i++;
    }
    // What should be my next step,
    // I allocated my memory, now i need to store the input in variables
    // If we think about it, a char makes a word,
    // a word makes a sentence, a sentence makes a paragraph
    // a paragraph makes a document
    // So if i created a multi-dimensional array
    // Document [Paragraphs][Sentences][Words][Letters]
    // So I need to allocate space for a multidimensional array
    return documentHM;

}


char* get_input_text() {
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));

    // Input Character
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

// Prints the word
void print_word(char* word) {
    printf("%s", word);
}

// Prints a list of words, a sentence
void print_sentence(char** sentence) {
    int word_count;
    // Gets the number of words to print
    scanf("%d", &word_count);
    for (int i = 0; i < word_count; i++) {
        printf("%s", sentence[i]);
        if (i != word_count - 1)
            printf(" ");
    }
}

// Prints sentences from a paragraph
void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main()
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3) {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else {
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }
}