#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* convert(char* s, int numRows) {
    if(numRows == 1) {
        return s;
    }
    int len = strlen(s); 
    int *rows = (int *) malloc (len * sizeof(int));
    int counter = 1;
    bool increment = true;
    for(int i = 0; i < len; i++) {        
        if(increment) {
            rows[i] = counter++;
        } else {
            rows[i] = counter--;
        }
        if(counter == numRows || counter == 1){
            increment = !increment;
        }    
    }   
    int currentRow = 1;
    char *resString = (char *) malloc ((len + 1) * sizeof(char));
    int j = 0;
    while(currentRow <= numRows) {
        for(int i = 0; i < len; i++) {
            if(rows[i] == currentRow) {
                resString[j] = s[i];
                j++;
            }
        }
        currentRow++;
    }
    resString[len] = '\0';
    free(rows);
    return resString;
}

int main() {
    char *result = convert("PAYPALISHIRING", 3);
    printf("%s\n", result);
    free(result);
    return 0;
}