#include <stdio.h>

int main()
{
  int tamanho, i;

  printf("Tamanho do vetor: ");
  scanf("%d", &tamanho);

  int vetor[tamanho];

  for (i = 0; i < tamanho; i++)
  {
    printf("Digite o elemeto %d do vetor: ", i+1);
    scanf("%d", &vetor[i]);
  }

  printf("\nVetor desordenado: ");
  for (i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }

  int atual, numero, anterior;
  for (atual = 1; atual < tamanho; atual++)
  {
    numero = vetor[atual];
    anterior = atual - 1;

    while (anterior >= 0 && vetor[anterior] > numero)
    {
      vetor[anterior + 1] = vetor[anterior];
      anterior = anterior - 1;
    }
    vetor[anterior + 1] = numero;
  }

  printf("\nVetor ordenado: ");
  for (i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }

  printf("\n");

  return 0;
}
