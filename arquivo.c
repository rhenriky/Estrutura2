#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 300
#define MAX_LINES 30000

int main() {
    FILE *fptr;
    char myString[MAX_LINE_LENGTH];
    char *palavras[MAX_LINES]; 
    int i = 0;

   
    fptr = fopen("ListaDePalavrasPT.txt", "r");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    
    while (fgets(myString, sizeof(myString), fptr) && i < MAX_LINES) {
        
        //printf("%s", myString);
        //printf("\n%d",strlen(myString));
        
        palavras[i] = malloc(strlen(myString) + 1);
        
        //printf ("%s", palavras[i]);
        
        if (palavras[i] == NULL) {
            printf("Falha na alocação de memória");
            fclose(fptr);
            return 1;
        }
        strcpy(palavras[i], myString);
        i++;
    }

    fclose(fptr);
    
    for (int j = 0; j < i; j++) {
        printf("%s", palavras[j]);
    }
    
    return 0;
}

