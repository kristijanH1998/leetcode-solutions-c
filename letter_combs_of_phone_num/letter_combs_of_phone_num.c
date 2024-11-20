#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

char* createCombination(int digits, int mappingIndex, char* combination, char** mappings, char*** arr) { 
    char **result = *arr;  
    //digits starts at number of digits in input
    //mappingIndex starts at 0  
    if(digits > 0) {
        for(int i = 0; i < strlen(mappings[mappingIndex]); i++){
            combination[strlen(combination)] = mappings[mappingIndex][i];
            createCombination(digits - 1, mappingIndex + 1, combination, mappings, &result);
            combination[strlen(combination) - 1] = '\0';
        }
    } else {
        strcpy(*(result + count), combination);
        count++;
        return combination;
    }
    return "";
}

char** letterCombinations(char* digits, int* returnSize) {
    char *base_mappings[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **mappings = (char**) malloc (sizeof(char*));
    int comb_factor = 1;
    for(int i = 0; i < (*returnSize); i++) {
        *(mappings + i) = base_mappings[(*(digits + i) - '2')];
        comb_factor = comb_factor * strlen(*(mappings + i));
        mappings = (char**) realloc (mappings, (i + 2) * sizeof(char*));
    }
    char **result = (char**) malloc (comb_factor * sizeof(char*));
    for(int i = 0; i < comb_factor; i++) {
        *(result + i) = (char*) malloc (*returnSize * sizeof(char));
    }
    char *combination = (char*) malloc (*returnSize * sizeof(char));
    createCombination(*returnSize, 0, combination, mappings, &result);
    for(int i = 0; i < comb_factor; i++) {
        printf("%s\n", *(result + i));
    }
    return NULL;
}

int main() {
    char *digits = "253";
    int digits_size = strlen(digits);
    letterCombinations(digits, &digits_size);
    return 0;
 }