#include <stdio.h>

void insertion_sort(int array[], int size)
{
  int current, number, prev;
  for (current = 1; current < size; current++)
  {
    number = array[current];
    prev = current - 1;

    while (prev >= 0 && array[prev] > number)
    {
      array[prev + 1] = array[prev];
      prev = prev - 1;
    }
    array[prev + 1] = number;
  }
}

void print_array(int array[], int size)
{
  int element;
  for (element = 0; element < size; element++)
  {
    printf("%d ", array[element]);
  }
}

int main()
{
  int size, i;

  printf("========= ORDENADOR DE VETOR (ARRAY) =========\n");

  printf("Digite o tamanho do array: ");
  scanf("%d", &size);

  int array[size];

  for (i = 0; i < size; i++)
  {
    printf("Digite o elemeto %d do array: ", i+1);
    scanf("%d", &array[i]);
  }

  printf("\nArray Original: ");
  print_array(array, size);

  insertion_sort(array, size);

  printf("\nVetor ordenado: ");
  print_array(array, size);

  return 0;
}
