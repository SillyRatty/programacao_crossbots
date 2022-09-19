#include <stdio.h>
#define VECTOR_MAX 10

int main(void) {
  int vec[VECTOR_MAX], X = 0, Y = 0;

  printf("\nDigite os valores do vetor: \n");
  for(int i = 0; i < VECTOR_MAX; i++) scanf("%d", &vec[i]);

  printf("\nDigite as posições do vetor que devem ser somadas (considerando que o primeiro valor do vetor tem posição 0):\n");
  scanf("%d %d", &X, &Y);

  if (X < 0 || X > VECTOR_MAX-1 || Y < 0 || Y > VECTOR_MAX-1) printf("\nPosições inválidas\n");

  else printf("\nA soma dos valores encontrados no vetor é: %d\n", vec[X] + vec[Y]);
  
  return 0;
}