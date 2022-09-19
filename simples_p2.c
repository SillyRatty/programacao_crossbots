#include <stdio.h>

int num_perfeito(int num){
  int max = num/2, sum = 0;

  for(int i = 1; i <= max; i++) if (num%i == 0) sum += i;

  return sum == num; //Retorna 1 se sum==num ou 0 se sum!=num
}

int main(void) {
  int num = 0;

  printf("\nDigite o número que deseja verificar: ");
  scanf("%d", &num);

  if (num_perfeito(num)) printf("\nO número é perfeito!\n");
  else printf("\nO número não é perfeito.\n");
  return 0;
}