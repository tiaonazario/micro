#define ARR_LEN 7
char volatile *iostatus = (char *)0x0;
char volatile *iodata = (char *)0xC;

void int2string(int num, char *str)
{
  int i = 0;
  unsigned short int isNegative = 0; // casc
  char tempStr[20];                  // Tamanho máximo da string

  // Verifica se o número é negativo
  if (num < 0)
  {
    isNegative = 1;
    num = -num;
  }
  else if (num == 0)
  { // Lida com o caso especial de 0
    str[i++] = '0';
    str[i] = '\0';
    return;
  }

  // Converte cada dígito em um caractere
  while (num != 0)
  {
    int digit = num % 10;
    tempStr[i++] = digit + '0';
    num = num / 10;
  }

  // Adiciona o sinal de negativo, se necessário
  if (isNegative)
  {
    tempStr[i++] = '-';
  }

  // Inverte a string
  unsigned short int j = 0;
  for (j = 0; j < i; j++)
  {
    str[j] = tempStr[i - 1 - j];
  }
  str[i] = '\0'; // Adiciona o caractere nulo para terminar a string
}

void uart_send_string(char *str)
{
  for (unsigned short int i = 0; str[i] != '\0'; i++)
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

void mostrarVetor(int *unsorted_array, unsigned short int arr_len)
{
  uart_send_string("O vetor atual é\n");
  for (unsigned short int i = 0; i < arr_len; i++)
  {
    uart_send_integer(unsorted_array[i]);
    uart_send_string("\n");
  }
}

int main(void)
{

  unsigned int arr[] = {3, 8, 5, 7, 1, 6};
  unsigned int len = sizeof(arr) / sizeof(arr[0]);

  mostrarVetor(arr, len);

  // Bubble Sort
  for (unsigned short int i = 0; i < len - 1; i++)
  {
    for (unsigned short int j = 0; j < len - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        unsigned int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  mostrarVetor(arr, len);

  /*
    uart_send_string("Os elementos do array organizados é: ");
    for (unsigned short int i=0; i<len; i++) {
  uart_send_integer(arr[i]);
  uart_send_string(" ");
    }*/

  return 0;
}