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
    //Otherwise, start breaking num down digit by digit, filling the result with Roman letters accordingly
    while((pow_of_ten > 0) && (num > 0)) {
        int current_digit = num / (int) pow(10, pow_of_ten - 1);
        if(!((current_digit == 4) || (current_digit == 9))) {
            {
                int i = ((pow_of_ten == 4) ? 0 : ((pow_of_ten == 3) ? 1 : ((pow_of_ten == 2) ? 3 : 5)));
                while(!((num - roman_num_values[i]) >= 0)) {
                    i++;
                }
                for(; (num - roman_num_values[i]) >= 0; i++) {
                    while((num - roman_num_values[i]) >= 0) {
                        res = strcat(res, roman_num_letters[i]);
                        num = num - roman_num_values[i];
                    }
                    if(((pow_of_ten - 2) >= 0) && (((num / (int) pow(10, pow_of_ten - 2)) == 4) || 
                        ((num / (int) pow(10, pow_of_ten - 2)) == 9))) {
                        break;
                    }
                }
            }
        } else {  //If next digit is 4 or 9, process it using subtractive form (one symbol subtracted from the following symbol, as in 4 being 1(I) less than the following 5 (V), so 4 is IV)
            switch(pow_of_ten) {
                case 3:
                    if(num >= 900) {
                        res = strcat(res, "CM");
                        num = num - 900;
                    } else {
                        res = strcat(res, "CD");
                        num = num - 400;
                    }
                    break;
                case 2:
                    if(num >= 90) {
                        res = strcat(res, "XC");
                        num = num - 90;
                    } else {
                        res = strcat(res, "XL");
                        num = num - 40;
                    }
                    break;
                case 1:
                    if(num == 9) {
                        res = strcat(res, "IX");
                        num = num - 9;
                    } else {
                        res = strcat(res, "IV");
                        num = num - 4;
                    }
                    break;
            }
        }
        pow_of_ten--;
    }
    return res;
}

int main() {
    char *result = intToRoman(3444);
    printf("%s\n", result);
    return 0;
}