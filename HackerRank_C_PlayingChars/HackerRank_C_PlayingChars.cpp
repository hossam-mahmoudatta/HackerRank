#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main()
{
    char ch;
    char s[MAX_LENGTH];
    char sen[MAX_LENGTH];

    scanf("%c", &ch);
    getchar(); // to eat the newline command

    fgets(s, MAX_LENGTH, stdin);
    
    fgets(sen, MAX_LENGTH, stdin);
    
    printf("%c\n", ch);
    fputs(s, stdout); //fputs not the normal puts so that it wont create a newline
    fputs(sen, stdout);
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}