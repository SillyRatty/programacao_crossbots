#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Retorna um vetor preenchido com os primos presentes na lista. Caso nao haja nenhum primo na lista, retorna NULL
int* filtra_primos(int *lista, int tam){ //Recebe uma lista e seu tamanho
  int *primos = NULL, ctd = 0, flag = 0, max_div = 0;

  primos = malloc(tam*sizeof(int)); //Aloca o maior tamanho possivel para a lista final, que e o mesmo da lista de entrada

  for(int i = 0; i < tam; i++){ //Percorre a lista
    flag = 0;
    if(lista[i] == 1) flag = 1; //Caso especial do numero 1
    max_div = (int) (sqrt(lista[i])); //O maior divisor primo de um numero será sua raiz quadrada, logo nao e necessario verificar numeros apos ela
    for(int j = 2; j <= max_div; j++) //Percorre todos os numeros entre 2 e a raiz quadrada do numero analisado
      if(lista[i] % j == 0){ //Se encontrar um divisor, levanta o flag e quebra o laço
        flag = 1;
        break;
      }
    if(!flag) primos[ctd++] = lista[i]; //Se o flag nao estiver erquido, o numero e primo
  }

  if(ctd == 0){
    free(primos);
    return NULL; //Caso nao tenha nenhum primo, retorna NULL
  }

  primos = realloc(primos, ctd*sizeof(int)); //Reduz o tamnho alocado para a quantidade de primos encontrada

  return primos; //Retorna a lista de primos
}

int main(void) {
  int *lista = NULL, *primos = NULL, tam = 0;

  printf("Digite o tamanho da lista: ");
  scanf("%d", &tam);

  lista = malloc(tam*sizeof(int));
  
  printf("Digite os valores da lista:\n");

  for(int i = 0; i < tam; i++) scanf("%d", &lista[i]);

  primos = filtra_primos(lista, tam);

  if(primos == NULL) printf("Nenhum primo encontrado\n");

  else{
    printf("Primos encontrados:\n");
    for(int i = 0; i < tam; i++){
      if(primos[i] == 0) break; //Sera zero se nao tiver mais primos na lista
      printf("%d ", primos[i]);
    }
    printf("\n");
  }

  free(lista);
  free(primos);
  
  return 0;
}