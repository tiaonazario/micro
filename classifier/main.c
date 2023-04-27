char volatile *iostatus = (char *)0x0;
char volatile *iodata = (char *)0xC;

void int2string(int num, char *str)
{
  int i = 0;
  int isNegative = 0;
  char tempStr[20]; // Tamanho maximo da string

  // Verifica se o numero e negativo
  if (num < 0)
  {
    isNegative = 1;
    num = -num;
  }

  // Lida com o caso especial de 0
  if (num == 0)
  {
    str[i++] = '0';
    str[i] = '\0';
    return;
  }

  // Converte cada digito em um caractere
  while (num != 0)
  {
    int digit = num % 10;
    tempStr[i++] = digit + '0';
    num = num / 10;
  }

  // Adiciona o sinal de negativo, se necessario
  if (isNegative)
  {
    tempStr[i++] = '-';
  }

  // Inverte a string
  int j;
  for (j = 0; j < i; j++)
  {
    str[j] = tempStr[i - 1 - j];
  }
  str[i] = '\0'; // Adiciona o caractere nulo para terminar a string
}

void uart_send_string(char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    while ((*iostatus & 0x20) != 0x20)
      ;
    *iodata = str[i];
  }
}

void uart_send_integer(int num)
{
  char str[20];
  int2string(num, str);
  uart_send_string(str);
}

int main()
{

  uart_send_string(" ========= CLASSIFICADOR DE NUMEROS PARES E IMPARES ========= \n");

  int arr[] = {112, 98, 12, 80};
  int n = sizeof(arr) / sizeof(arr[0]);

  uart_send_string("\n Numeros pares: ");
  for (int i = 0; i < n; i++)
  {
    if (arr[i] % 2 == 0)
    {
      uart_send_integer(arr[i]);
    }
  }

  uart_send_string("\n Numeros impares: ");
  for (int i = 0; i < n; i++)
  {
    if (arr[i] % 2 != 0)
    {
      uart_send_integer(arr[i]);
    }
  }

  return 0;
}