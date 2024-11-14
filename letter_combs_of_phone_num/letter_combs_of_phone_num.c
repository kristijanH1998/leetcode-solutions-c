#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* createCombination(int digits, int mappingIndex, char* combination, char** mappings) {
    
//digits starts at number of digits in input
//mappingIndex starts at 0  

    if(digits > 0) {
        if(digits == (sizeof(mappings) / sizeof(char*))) {
            char *combination = (char*) malloc (digits * sizeof(char));
        }

        for(int i = 0; i < strlen(mappings[mappingIndex]); i++){
            // printf("%c", mappings[mappingIndex][i]);
            combination[strlen(combination)] = mappings[mappingIndex][i];

            // char *combination_new = (char*) malloc (1 * sizeof(char));
            createCombination(digits - 1, mappingIndex + 1, combination, mappings);
            printf("\n");
        }
        
    } else {
        printf("%s\n", combination);
        return combination;
    }
    

    return "";
}

char** letterCombinations(char* digits, int* returnSize) {
    char *mappings[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // printf("%c\n", mapping[0][2]);

    for(int i = 0; i < (*returnSize); i++) {
        printf("%c\n", mappings[(*(digits + i) - '2')][0]);
    }
    printf("%d\n", strlen(mappings[0]));

    return NULL;
}

int main() {
    char *digits = "2342";
    int digits_size = strlen(digits);
    // letterCombinations(digits, &digits_size);


    char *mappings[] = {"abc", "def"};
    
    createCombination(2, 0, NULL, mappings);
    // printf("%d\n", sizeof(mappings) / sizeof(char*));
    return 0;
 }