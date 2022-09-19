#include <stdio.h>
#include <stdlib.h>

double* filtra_diferentes(double *lista, int tam){ //Recebe uma lista de inteiros e seu tamanho e retorna a lista sem valores repetidos
  int flag = 0, tam_aux = 0;
  double *aux = NULL, *ans = NULL;

  aux = (double*) malloc(tam*sizeof(double)); //Aloca o valor maximo da lista auxiliar, que e igual ao tamanho da lista recebida
  
  aux[0] = lista[0]; //O primeiro valor sempre fara parte da lista auxiliar
  tam_aux = 1;

  for(int i = 1; i < tam; i++){ //Percorre a lista recebida a partir do segundo valor
    flag = 0;
    for(int j = 0; j < tam_aux; j++){ //Percorre a lista auxiliar
      if(aux[j] == lista[i]){ //Levanta o flag se encontrar algum valor que esta na lista auxiliar
        flag = 1;
        break;
      }
    }
    if(!flag) aux[tam_aux++] = lista[i]; //Se o flag estiver abaixado, o valor ainda nao havia aparecido e eh adicionado na lista auxiliar
  }

  aux = realloc(aux, tam_aux*sizeof(double)); //Reduz o tamanho da lista auxiliar para o tamanho necessario
  
  return aux; //Retorna a lista auxiliar
}

int main(void) {
  double *lista = NULL, *lista_filtrada = NULL;
  int tam = 0;

  printf("Digite o tamanho da lista: ");
  scanf("%d", &tam);
  
  lista = malloc(tam*sizeof(double));
  printf("Digite os valores da lista:\n");
  for(int i = 0; i < tam; i++) scanf("%lf", &lista[i]);
  
  lista_filtrada = filtra_diferentes(lista, tam);

  for(int i = 0; i < tam; i++)
    printf("%lf\n", lista_filtrada[i]);

  free(lista);
  free(lista_filtrada);
  
  return 0;
}