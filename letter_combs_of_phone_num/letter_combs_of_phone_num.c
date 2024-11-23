#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

//creates all possible combinations of letters based on the number of digits in input and mappings they correspond to
char* createCombination(int digits, int mappingIndex, char* combination, char** mappings, char*** arr) { 
    char **result = *arr;  
    //digits starts at number of digits in input
    //mappingIndex starts at 0  
    if(digits > 0) {
        //fill the combination string with all possible orderings of letters by recursion
        for(int i = 0; i < strlen(mappings[mappingIndex]); i++){
            combination[strlen(combination)] = mappings[mappingIndex][i];
            createCombination(digits - 1, mappingIndex + 1, combination, mappings, &result);
            combination[strlen(combination) - 1] = '\0';
        }
    } else {
        //add final form of current combination string to result array
        strcpy(*(result + count), combination);
        count++;
        return combination;
    }
    return "";
}

char** letterCombinations(char* digits, int* returnSize) {
    //all mappings of digits to letters
    char *base_mappings[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    //array of strings for storing mappings from digits sent as input, i.e. mappings which will be used to generate combinations of letters
    char **mappings = (char**) malloc (sizeof(char*));
    //comb_factor is a number of possible combinations that will be in the output, it equals the product of numbers of letters in each mapping from selected mappings (based on input digits)
    int comb_factor = 1;
    //filling the mappings array with particular mappings from base_mappings
    for(int i = 0; i < (*returnSize); i++) {
        *(mappings + i) = malloc (sizeof(base_mappings[(*(digits + i) - '2')]));
        strcpy(*(mappings + i), base_mappings[(*(digits + i) - '2')]);
        comb_factor = comb_factor * strlen(*(mappings + i));
        mappings = (char**) realloc (mappings, (i + 2) * sizeof(char*));
    }
    //result is the returned array of combination strings
    char **result = (char**) malloc (comb_factor * sizeof(char*));
    //allocating comb_factor number of character spaces for each returned combination string
    for(int i = 0; i < comb_factor; i++) {
        *(result + i) = (char*) malloc (*returnSize * sizeof(char));
    }
    char *combination = (char*) malloc (*returnSize * sizeof(char));
    //call to recursive createCombination, which generates all possible combinations for input digits
    createCombination(*returnSize, 0, combination, mappings, &result);
    //printing the output
    for(int i = 0; i < comb_factor; i++) {
        printf("%s\n", *(result + i));
    }
    //freeing the memory allocated to combination string
    free(combination);
    combination = NULL;
    //freeing the space allocated to mappings array
    for(int i = 0; i < (*returnSize); i++) {
        free(*(mappings + i));
        *(mappings + i) = NULL;
    }
    //freeing the space allocated for mappings array
    free(mappings);
    mappings = NULL;
    //freeing the memory allocated for the output array
    for(int i = 0; i < comb_factor; i++) {
        free(*(result + i));
        *(result + i) = NULL;
    }
    free(result);
    result = NULL;
    return NULL;
}

int main() {
    char *digits = "23";
    int digits_size = strlen(digits);
    letterCombinations(digits, &digits_size);
    return 0;
 }