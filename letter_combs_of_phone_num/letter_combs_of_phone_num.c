#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* createCombination(int digits, int mappingIndex, char* combination, char** mappings) {
    
    //digits starts at number of digits in input
    //mappingIndex starts at 0  
    // char *current_combination = (char*) malloc (((sizeof(combination) / sizeof(char)) + 1) * sizeof(char));
    // current_combination[]
    
    if(digits > 0) {
        // if(digits == (sizeof(mappings) / sizeof(char*))) {
        //     char *combination = (char*) malloc (digits * sizeof(char));
        // }

        for(int i = 0; i < strlen(mappings[mappingIndex]); i++){
            // printf("%c", mappings[mappingIndex][i]);
            combination[strlen(combination)] = mappings[mappingIndex][i];

            // combination = (char*) realloc(combination, (i + 2) * sizeof(char));

            // char *combination_new = (char*) malloc ((strlen(combination) / sizeof(char)) * sizeof(char));
            // strcpy(combination_new, combination);

            createCombination(digits - 1, mappingIndex + 1, combination, mappings);
            combination[strlen(combination) - 1] = '\0';
        }
        
    } else {
        printf("%s\n", combination);
        // combination[strlen(combination) - 1] = '\0';

        // if(digits ==)

        // memset(combination, 0, (strlen(combination) / sizeof(char)));
        // strcpy(combination, "");
        // combination = (char*) realloc(combination, sizeof(char));
        // *combination = '\0';
        // free(combination);
        // char *combination = (char*) malloc (sizeof(char));
        return combination;
    }
    return "";
}

char** letterCombinations(char* digits, int* returnSize) {
    char *base_mappings[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **mappings = (char**) malloc (sizeof(char*));

    for(int i = 0; i < (*returnSize); i++) {
        *(mappings + i) = base_mappings[(*(digits + i) - '2')];
        mappings = (char**) realloc (mappings, (i + 2) * sizeof(char*));
    }


    char *combination = (char*) malloc (*returnSize * sizeof(char));
    createCombination(*returnSize, 0, combination, mappings);

    return NULL;
}

int main() {
    char *digits = "232";
    int digits_size = strlen(digits);
    letterCombinations(digits, &digits_size);
    // char *mappings[] = {"abc", "def"};
    // createCombination(2, 0, NULL, mappings);
    // printf("%d\n", sizeof(mappings) / sizeof(char*));
    return 0;
 }