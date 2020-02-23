#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

char *concatena(char *s1, char *s2){
    return strcat(s1, s2);
}

int main(int argc, char const *argv[]){
    char* string1 = (char*) malloc(MAX_SIZE*sizeof(char));
    char* string2 = (char*) malloc(MAX_SIZE*sizeof(char));;

    gets(string1);
    gets(string2);
    char* frase = concatena(string1, string2);

    printf("%s", frase);
    return 0;
}