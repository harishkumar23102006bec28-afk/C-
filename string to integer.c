#include <stdio.h>
#include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    long result = 0;
    int sign = 1;

    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || s[i] == '\f' || s[i] == '\r') {
        i++;
    }

    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return (int)(sign * result);
}

int main() {
    char testInput[] = "   -042words"; 
    int output = myAtoi(testInput);
    printf("Input: \"%s\"\n", testInput);
    printf("Output: %d\n", output);
    return 0;
}
