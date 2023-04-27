#include <stdio.h>

void int_to_string(int num, char str[]) {
  int i = 0;
  int is_negative = 0;

  // Trata o caso especial de zero
  if (num == 0) {
    str[i++] = '0';
    str[i] = '\0';
    return;
  }

  // Trata números negativos
  if (num < 0) {
    is_negative = 1;
    num = -num;
  }

  // Cria a string reversa dos dígitos
  while (num > 0) {
    str[i++] = (num % 10) + '0';
    num /= 10;
  }

  // Adiciona o sinal de negativo, se necessário
  if (is_negative) {
    str[i++] = '-';
  }

  // Inverte a string
  int j;
  for (j = 0; j < i / 2; j++) {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }

  // Adiciona o caractere nulo para terminar a string
  str[i] = '\0';
}

int main() {
  char number_str[20];
  int number = 5;
  int_to_string(number, number_str);
  printf("%s", number_str);
  return 0;
}
