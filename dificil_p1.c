#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int counter = 0, flag = 0, N = 0, *results = NULL;
  char string[1000 + 1]; //1000 caracteres de <,> e . mais 1 para guardar o NULL do fgets
  
  printf("Digite o numero de casos:\n");
  scanf("%d", &N);
  while(getchar() != '\n' && getchar() != EOF); //Limpa o buffer

  results = malloc(N*sizeof(int)); //Aloca a quantidade necessária para a lista de resultados

  for(int i = 0; i < N; i++){
    counter = 0;
    flag = 0;
  
    printf("\nDigite o caso de teste %d:\n", i+1);
    fgets(string, sizeof(string), stdin); //Recebe as strings de diamantes
  
    for(int pos = 0; string[pos] != '\0' && string[pos] != EOF; pos++){
      if(string[pos] == '<'){ //Se encontrar um "inicio de diamante"
        flag++; //Aumenta 1 na flag para contar quantos diamantes podem ser formados
      }
      else if(string[pos] == '>' && flag != 0){ //Se um diamante pode ser formado
        counter++; //Conta um diamante formado
        flag--; //Tira um da quantidade de diamantes que podem ser formados
      }
    }
  
    results[i] = counter; //Guarda um resultado na lista
  }

  for (int i = 0; i < N; i++) printf("%d\n", results[i]);

  free(results);
  
  return 0;
}