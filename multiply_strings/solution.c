#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

// this solution doesn't work for very large integers, because there is a limit to how large a number can be
// stored in long long or uintmax_t types
// char *multiply(char *num1, char *num2) {
//     if(num1 == NULL || num2 == NULL) {
//         return NULL;
//     }
//     if(strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
//         // char *zero = (char *)malloc(sizeof(char));
//         // *zero = '0';
//         // return zero;
//         return "0";
//     }
//     long long power = 0;
//     long long len1 = strlen(num1);
//     long long len2 = strlen(num2);
//     uintmax_t n1, n2, product;
//     n1 = n2 = product = 0;

//     long long i = len1 - 1;
//     while(i >= 0) {
//         // putchar(num1[i--]);
//         n1 = n1 + ((num1[i--] - 48) * pow(10, (power++)));
//     }
//     // printf("%u\n", n1);
//     // fprintf(stdout, "%u\n", n1);
//     i = len2 - 1;
//     power = 0;
//     while(i >= 0) {
//         // putchar(num2[i--]);
//         n2 = n2 + ((num2[i--] - 48) * pow(10, (power++)));
//     }
//     // printf("%u\n", n2);

//     product = n1 * n2;
//     // printf("%u\n", product);

//     // unsigned int ch = num1[0];
//     // printf("%d\n", ch);
//     // printf("%d\n", ch-48);
//     // putc('\n', stdout);

//     long long lenProduct = 0;
//     uintmax_t temp = product;
//     while(temp > 0) {
//         temp = temp / 10;
//         lenProduct++;
//     }
//     printf("%lld\n", lenProduct); 
//     // char productStr[lenProduct] = {};
//     char *productStr = (char *)malloc((lenProduct + 1) * sizeof(char));
//     productStr[lenProduct] = '\0';
//     for(i = lenProduct - 1; i >= 0; i--) {
//         productStr[i] = (product % 10) + 48;
//         product = product / 10;
//     }
//     // printf("%d\n", product % 10);
//     // putc((product % 10) + 48, stdout);
//     // putc('\n', stdout);
//     return productStr;
// }

//second solution, uses manual multiplication as would be performed by hand
char *multiply(char *num1, char *num2) {
    if(num1 == NULL || num2 == NULL) {
        return NULL;
    }
    if(strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        return "0";
    }
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char *res1 = (char *)malloc(2);
    res1[1] = '\0';
    res1[0] = ((num1[0] - '0') * (num2[0] - '0')) + '0';
    if((len1 == 1) && (len2 == 1) && (res1[0] < (10 + '0'))) {
        return res1;
    }
    int *result = (int *)malloc((len1 + len2) * sizeof(int));
    int i, j, temp, sum;
    i = j = temp = sum = 0;
    for(i = len2 - 1; i >= 0; i--) {
        for(j = len1 - 1; j >= 0; j--) {
            temp = (num2[i] - '0') * (num1[j] - '0');
            sum = temp + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    i = 0;
    while(result[i] == 0) {
        result++;
        i++;
    }
    for(j = 0; j < (len1 + len2 - i); j++) {
        printf("%d ", result[j]);
    }
    printf("\n");
    char *res = (char *)malloc(len1 + len2 - i + 1);
    // char res[len1 + len2 - i + 1] = {};
    for(j = 0; j < (len1 + len2 - i); j++) {
        res[j] = result[j] + '0';
    }
    res[j] = '\0';
    return res;
}

int main(void) {
    char num1[] = "111";
    char num2[] = "111";
    // multiply(num1, num2);
    char *res = multiply(num1, num2);
    printf("%s\n", res);
    free(res);
    res = NULL;
    return 0;
}