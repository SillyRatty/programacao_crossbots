#include <stdio.h>
#include <math.h>

/*
  Para facilitar o uso das variáveis,
  foi usado um struct para guardar ambas
  as coordenadas de cada ponto.
*/
typedef struct Coordenadas_t{
  double x, y;
} coordenadas;

//A distância entre os pontos A e B é o módulo do vetor AB:
double distancia_entre_pontos(coordenadas p1, coordenadas p2){
  return sqrt(pow((p2.y - p1.y), 2) + pow((p2.x - p1.x), 2));
}


int main(void) {
  coordenadas a, b;
  
  printf("\nDigite as coordenadas (x,y) do ponto 1: ");
  scanf("%lf %lf", &a.x, &a.y);
  printf("\nDigite as coordenadas (x,y) do ponto 2: ");
  scanf("%lf %lf", &b.x, &b.y);

  printf("\nA distancia entre eles é: %lf\n", distancia_entre_pontos(a, b));
  
  return 0;
}