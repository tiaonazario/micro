char volatile *iostatus = (char *)0x0;
char volatile *iodata = (char *)0xC;

void int_to_string(unsigned short num, char str[]) {
  unsigned short i = 0;
  unsigned short is_negative = 0;

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
  unsigned short j;
  for (j = 0; j < i / 2; j++) {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }

  // Adiciona o caractere nulo para terminar a string
  str[i] = '\0';
}

void uart_send_string(char *str)
{
  for (unsigned short i = 0; str[i] != '\0'; i++)
  {
    while ((*iostatus & 0x20) != 0x20)
      ;
    *iodata = str[i];
  }
}

void uart_send_integer(unsigned short num)
{
  char str[20];
  int_to_string(num, str);
  uart_send_string(str);
}

int main()
{

	unsigned short arr[] = {1, 2, 3, 4, 5, 6, 7};
  unsigned short n = sizeof(arr) / sizeof(arr[0]);

  uart_send_string("\nClassificador de pares e impares\n");
  for (unsigned short i = 0; i < n; i++)
  {
    if (arr[i] % 2 == 0)
    {
      uart_send_integer(arr[i]);
			uart_send_string(" é par");
			uart_send_string("\n");
    }
		
		else {
      uart_send_integer(arr[i]);
			uart_send_string(" é impar");
			uart_send_string("\n");
		}
  }

  return 0;
}
