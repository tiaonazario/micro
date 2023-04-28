#include <stdio.h>

void reverse(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void float_to_string(float num, char *str, int precision) {
    // converte a parte inteira para string
    int integer_part = (int)num;
    int i = 0;
    do {
        str[i++] = integer_part % 10 + '0';
        integer_part /= 10;
    } while (integer_part > 0);

    // reverte a string
    reverse(str);

    // adiciona o ponto decimal
    str[i++] = '.';

    // converte a parte decimal para string
    float decimal_part = num - (int)num;
    for (int j = 0; j < precision; j++) {
        decimal_part *= 10;
        int digit = (int)decimal_part;
        str[i++] = digit + '0';
        decimal_part -= digit;
    }

    // adiciona o caractere nulo para terminar a string
    str[i] = '\0';
}

int main() {
    float num = 3.14159;
    char str[32];
    int precision = 2;

    float_to_string(num, str, precision);

    printf("O numero %.2f em formato de string e: %s\n", num, str);

    return 0;
}
