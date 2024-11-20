#include <stdio.h>
#include <stdlib.h>

//Code below doesn't work:
// int** func(int** arr) {
//     for(int i = 1; i <= 5; i++) {
//         *arr = (int*) realloc (*arr, (i + 1) * sizeof(int));
//         *(*(arr + (i - 1))) = i;
//     }
//     return arr;
// }

// int main() {
//     int *arr = (int*) malloc (1 * sizeof(int));
//     int **res = func(&arr);
//     for(int i = 0; i < 5; i++) {
//         printf("%d ", *(*(res + i)));
//     }
//     return 0;
// }

//This works:
int* func(int** arr) {
    int *result = *arr;

    for(int i = 1; i <= 5; i++) {
        result = (int*) realloc (result, (i + 1) * sizeof(int));
        *(result + (i - 1)) = i;
    }
   
    return result;
}


int main() {
    int *arr = (int*) malloc (1 * sizeof(int));
    int *res = func(&arr);
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(res + i));
    }

    return 0;
}