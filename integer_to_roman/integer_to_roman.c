#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* intToRoman(int num) {
    //Check that num is within constraints (1 <= num <= 3999)
    if((num < 1) || (num > 3999)) {
        return "The number must be between 1 and 3999";
    }
    char *res = (char*) malloc (1 * sizeof(char));
    int divisor = 1000;
    char* roman_tens[5] = {"M\0", "C\0", "X\0", "I\0", 0};
    char* roman_fives[4] = {"D\0", "L\0", "V\0", 0};
    int tens_index = 0;
    int fives_index = 0;
    int letters;
    while(num > 0) {
        letters = 0;
        while(num >= divisor) {
            // if((num / divisor) > 0) {
                
            // }
            letters++;
            num -= divisor;
        }
        while(letters > 0) {
            if(letters == 9) {
                res = strcat(res, roman_tens[tens_index]);
                res = strcat(res, roman_tens[tens_index - 1]);
                break;
            }
            if(letters == 4) {
                res = strcat(res, roman_tens[tens_index]);
                res = strcat(res, roman_fives[fives_index]);
                break;
            }
            if(letters >= 5) {
                res = strcat(res, roman_fives[fives_index]);
                letters -= 5;
            } else {
                letters--;
                res = strcat(res, roman_tens[tens_index]);
            }
        }
        tens_index++;
        fives_index = tens_index - 1;
        divisor /= 10;
    }
    res = strcat(res, "\0");
    return res;

    // First attempt: contained bugs that made me decide to consider a bit different approach, which resulted in the algorithm above
    // int temp = num;
    // int pow_of_ten = 1;
    // while(temp / 10 > 0) {
    //     pow_of_ten++;
    //     temp = temp / 10;
    // }
    // char *res = (char*) malloc ((pow_of_ten + 1) * sizeof(char));
    // temp = num;
    // int roman_num_values[7] = {1000, 500, 100, 50, 10, 5, 1};
    // char* roman_num_letters[7] = {"M", "D", "C", "L", "X", "V", "I"};
    // //If num is one of the values that are represented in Roman with a single letter, return that as res
    // for(int i = 0; i < (sizeof(roman_num_values) / sizeof(int)); i++) {
    //     if(num == roman_num_values[i]) {
    //         res = strcat(res, roman_num_letters[i]);
    //         return res;
    //     }
    // }
    // //Otherwise, start breaking num down digit by digit, filling the result with Roman letters accordingly
    // while((pow_of_ten > 0) && (num > 0)) {
    //     int current_digit = num / (int) pow(10, pow_of_ten - 1);
    //     if(!((current_digit == 4) || (current_digit == 9))) {
    //         {
    //             int i = ((pow_of_ten == 4) ? 0 : ((pow_of_ten == 3) ? 1 : ((pow_of_ten == 2) ? 3 : 5)));
    //             while(!((num - roman_num_values[i]) >= 0)) {
    //                 i++;
    //             }
    //             for(; (num - roman_num_values[i]) >= 0; i++) {
    //                 while((num - roman_num_values[i]) >= 0) {
    //                     res = strcat(res, roman_num_letters[i]);
    //                     num = num - roman_num_values[i];
    //                 }
    //                 if((num / (int)(pow(10, pow_of_ten))) == 0) {
    //                     pow_of_ten--;
    //                 }
    //                 if((pow_of_ten > 0) && (((num / (int) pow(10, pow_of_ten - 1)) == 4) || 
    //                     ((num / (int) pow(10, pow_of_ten - 1)) == 9))) {
    //                     break;
    //                 }   
    //             }
    //         }
    //     } else {  //If next digit is 4 or 9, process it using subtractive form (one symbol subtracted from the following symbol, as in 4 being 1(I) less than the following 5 (V), so 4 is IV)
    //         switch(pow_of_ten) {
    //             case 3:
    //                 if(num >= 900) {
    //                     res = strcat(res, "CM");
    //                     num = num - 900;
    //                 } else {
    //                     res = strcat(res, "CD");
    //                     num = num - 400;
    //                 }
    //                 break;
    //             case 2:
    //                 if(num >= 90) {
    //                     res = strcat(res, "XC");
    //                     num = num - 90;
    //                 } else {
    //                     res = strcat(res, "XL");
    //                     num = num - 40;
    //                 }
    //                 break;
    //             case 1:
    //                 if(num == 9) {
    //                     res = strcat(res, "IX");
    //                     num = num - 9;
    //                 } else {
    //                     res = strcat(res, "IV");
    //                     num = num - 4;
    //                 }
    //                 break;
    //         }
    //         pow_of_ten--;
    //     }
        
    // }
}

int main() {
    char *result = intToRoman(99);
    printf("%s\n", result);
    return 0;
}