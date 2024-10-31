#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* intToRoman(int num) {
    //Check that num is within constraints (1 <= num <= 3999)
    if((num < 1) || (num > 3999)) {
        return "The number must be between 1 and 3999";
    }
    int temp = num;
    int pow_of_ten = 1;
    while(temp / 10 > 0) {
        pow_of_ten++;
        temp = temp / 10;
    }
    // printf("%d\n", pow_of_ten);
    char *res = (char*) malloc ((pow_of_ten + 1) * sizeof(char));
    temp = num;
    int roman_num_values[7] = {1000, 500, 100, 50, 10, 5, 1};
    char* roman_num_letters[7] = {"M", "D", "C", "L", "X", "V", "I"};
    //If num is one of the values that are represented in Roman with a single letter, return that as res
    for(int i = 0; i < (sizeof(roman_num_values) / sizeof(int)); i++) {
        if(num == roman_num_values[i]) {
            res = strcat(res, roman_num_letters[i]);
            return res;
        }
    }
    //Otherwise, start breaking num down digit by digit
    while(pow_of_ten > 0 && (num > 0)) {
        int current_digit = num / (int) pow(10, pow_of_ten - 1);
        if(!((current_digit == 4) || (current_digit == 9))) {
            // for(int i = ((pow_of_ten == 4) ? 0 : ((pow_of_ten == 3) ? 1 : 3));
            //     i < (sizeof(roman_num_values) / sizeof(int)); i++) {
            //         while((num - roman_num_values[i]) > 0) {
            //             res = strcat(res, roman_num_letters[i]);
            //             num = num - roman_num_values[i];
            //         }
                    
            // }
            {
                int i = ((pow_of_ten == 4) ? 0 : ((pow_of_ten == 3) ? 1 : ((pow_of_ten == 2) ? 3 : 5)));
                while(!((num - roman_num_values[i]) >= 0)) {
                    i++;
                }
                for(; (num - roman_num_values[i]) >= 0; i++) {
                    // printf("i skipped; i is %d\n", i);
                    while((num - roman_num_values[i]) >= 0) {
                        res = strcat(res, roman_num_letters[i]);
                        num = num - roman_num_values[i];
                    }
                }
            }
            



            pow_of_ten--;
        }
        // num = num % (int) pow(10, pow_of_ten);
        
    }

    // char *str = strcat(res, "abcdefghijkl");
    // printf("%s\n", str);

    return res;
}

int main() {
    // int pow_of_ten = 2;
    // int i = ((pow_of_ten == 4) ? 0 : ((pow_of_ten == 3) ? 1 : ((pow_of_ten == 2) ? 3 : 5)));
    // printf("%d\n", i);


    char *result = intToRoman(115);
    printf("%s\n", result);
    return 0;
}