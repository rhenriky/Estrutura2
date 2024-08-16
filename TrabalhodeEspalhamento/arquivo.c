#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

#define MAX_WORDS 1000
#define WORD_LENGTH 100
#define MATRIX_SIZE 32  // Ajuste conforme necessário para ter uma matriz quadrada

void loadWords(const char* filename, char words[MAX_WORDS][WORD_LENGTH], int *wordCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    int i = 0;
    while (fgets(words[i], WORD_LENGTH, file) && i < MAX_WORDS) {
        words[i][strcspn(words[i], "\n")] = '\0'; // Remove newline character
        i++;
    }
    *wordCount = i;
    fclose(file);
}

void printWord(void *data) {
    printf("%s ", (char*)data);
}

void generatePPM(int hashTable[MAX], const char* filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not create file %s\n", filename);
        exit(1);
    }

    // Define the size of the image
    int width = MATRIX_SIZE;
    int height = MATRIX_SIZE;

    // Write the PPM header
    fprintf(file, "P3\n%d %d\n255\n", width, height);

    // Normalize the collision counts to the range 0-255
    int maxCollision = 0;
    for (int i = 0; i < MAX; i++) {
        if (hashTable[i] > maxCollision) {
            maxCollision = hashTable[i];
        }
    }

    // Create a 2D array to represent the matrix
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {0};
    for (int i = 0; i < MAX; i++) {
        int row = i / MATRIX_SIZE;
        int col = i % MATRIX_SIZE;
        matrix[row][col] = (hashTable[i] * 255) / maxCollision;
    }

    // Write the pixel data
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int colorValue = matrix[row][col];
            fprintf(file, "0 %d 0 ", colorValue);  // Use green channel for visualization
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    HashStruct hashStruct;
    char words[MAX_WORDS][WORD_LENGTH];
    int wordCount;
    int hashTable[MAX] = {0};  // Array to store collision counts
    
    loadWords("ListaDePalavrasPT.txt", words, &wordCount);
    initHash(&hashStruct);

    for (int i = 0; i < wordCount; i++) {
        put(&hashStruct, words[i], words[i], (compare)strcmp);
    }

    for (int i = 0; i < MAX; i++) {
        hashTable[i] = hashStruct.hashes[i].size;
    }

    showHashStruct(&hashStruct, printWord);
    generatePPM(hashTable, "hash_collisions.ppm");

    return 0;
}
