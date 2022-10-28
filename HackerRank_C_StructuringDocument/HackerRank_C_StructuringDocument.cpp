// Problem Link
// https://www.hackerrank.com/challenges/structuring-the-document/problem?isFullScreen=false

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count; //denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data;
    int sentence_count; //denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count; //denotes number of paragraphs in a document
};

// COMPLETE THESE FUNCTIONS
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

struct document get_document(char* text) {
    // All the logic of the problem is in this function
    struct document documentHM;
    struct paragraph paragraphHM = split_string(text, '\n');
    documentHM.data = (struct)malloc((paraNumber + 1) * sizeof(char***));

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

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc[n - 1][m - 1][k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {

}

struct paragraph kth_paragraph(struct document Doc, int k) {

}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for (int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for (int i = 0; i < para.sentence_count; i++) {
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for (int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
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

int main()
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3) {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen = kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else {
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }
}