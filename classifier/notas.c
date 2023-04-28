char volatile *iostatus = (char *)0x0;
char volatile *iodata = (char *)0xC;

void reverse(char *str)
{
  int length = 0;
  while (str[length] != '\0')
  {
    length++;
  }

  for (int i = 0; i < length / 2; i++)
  {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
}

void float_to_string(float num, char *str, int precision)
{
  // converte a parte inteira para string
  int integer_part = (int)num;
  int i = 0;
  do
  {
    str[i++] = integer_part % 10 + '0';
    integer_part /= 10;
  } while (integer_part > 0);

  // reverte a string
  reverse(str);

  // adiciona o ponto decimal
  str[i++] = '.';

  // converte a parte decimal para string
  float decimal_part = num - (int)num;
  for (int j = 0; j < precision; j++)
  {
    decimal_part *= 10;
    int digit = (int)decimal_part;
    str[i++] = digit + '0';
    decimal_part -= digit;
  }

  // adiciona o caractere nulo para terminar a string
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

void uart_send_float(float num)
{
  char str[20];
  int precision = 2;
  float_to_string(num, str, precision);
  uart_send_string(str);
}

int main()
{

  float notas[3] = {5, 6, 4};
  float media;

  media = ((notas[0] * 2 + notas[1] * 3 + notas[2] * 4) / 9);

  uart_send_string("\nCalculador de média\n");
  uart_send_string("Média = ");
  uart_send_float(media);

  uart_send_string("\nFim...");

  return 0;
}
