#include <stdio.h>
#include <stdlib.h>

#define RIGHT "R"
#define DOWN "D"

void generate_paths(int m, int n, int *count) {
    if(m == 0 && n == 0) {
        (*count)++;
        // printf("\n");
        return;
    }  
    if(m > 0) {
        // printf("D ");
        generate_paths(m - 1, n, count);
    }
    if(n > 0) {
        // printf("R ");
        generate_paths(m, n - 1, count);
    }
    return;
} 

// m - 1 downs and n - 1 rights
int unique_paths(int m, int n) {
    // printf("%d %d\n", m, n);
    if(m == 1 || n == 1) {
        return 1;
    }
    int count = 0;
    // generate_paths(m - 2, n - 1, DOWN, &count);
    // generate_paths(m - 1, n - 2, RIGHT, &count);
    generate_paths(m - 1, n - 1, &count);
    // printf("%d\n", count);
    return count;
}

int main(void) {
    // printf("%s\n", RIGHT);
    // int (*fptr)(int, int);
    // fptr = &uniquePaths;
    // (*fptr)(3, 4);
    printf("%d\n", unique_paths(3, 7));
    return 0;
}