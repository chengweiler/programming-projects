#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 0
#define FALSE 1

void readfile(char operation[3], char path1[101], char path2[101]);

int main() {
    // parameters
    char operation[3];
    char path1[101];
    char path2[101];
    
    // scanning parameters
    scanf("%s", operation);
    scanf("%s", path1);
    scanf("%s", path2);
    
    // passing parameters
    readfile(operation, path1, path2);
    return 0;
}

void readfile(char operation[3], char path1[101], char path2[101]) {
    // opening files
    FILE *pFile1 = fopen(path1, "r");
    FILE *pFile2 = fopen(path2, "r");
    
    // char containing numbers
    char number1Char;
    char number2Char;
    
    // int arrays containing numbers
    int number1[20];
    int number2[20];
    int result[20];
    
    // read files
    int i;
    int x;
    for (i = 0; i < 20; i++) {
        // read single character
        fscanf(pFile1, "%c", &number1Char);
        fscanf(pFile2, "%c", &number2Char);
        
        // convert to integer
        number1[i] = (int) number1Char;
        number2[i] = (int) number2Char;
    }
    
    if (strcmp(operation, "add") == TRUE) {
        for (x = 19; x >= 0; x--) {
            result[x] = number1[x] + number2[x];
            if (result[x] >= 10) {
                result[x - 1]++;
            }
        }
    } else if (strcmp(operation, "sub") == TRUE) {
        for (x = 19; x >= 0; x--) {
            result[x] = number1[x] - number2[x];
            if (number1[x] < number2[x]) {
                number1[x - 1] -= number2[x] - number1[x];
            }
        }
    } else if (strcmp(operation, "mul") == TRUE) {
        for (x = 19; x >= 0; x--) {
            result[x] = number1[x] * number2[x];
            if (result[x] >= 10) {
                result[x - 1] += result[x] / 10;
            }
        }
    } else {
        exit(0);
    }
    int j;
    for (j = 0; j < 20; j++) {
        printf("%d", result[j]);
    }
}
