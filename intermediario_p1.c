#include <stdio.h>
#include <math.h>

typedef struct Coord_t{ //Estrutura que guarda as coordenadas (x,y) de um ponto
  double x,y;
} coord;

double prod_int(coord V1, coord V2){ //Retorna o produto interno de dois vetores
  return (V1.x*V2.x) + (V1.y*V2.y);
}

double mod(coord V){ //Retorna o modulo de um vetor
  return sqrt(pow(V.x,2) + pow(V.y,2));
}

double angulo_entre_ABC_rad(coord A, coord B, coord C){ //Retorna o angulo entre tres pontos (x,y) no plano cartesiano em radianos
  coord BA, BC;

  BA.x = A.x - B.x; //Faz se os vetores com centro em B
  BA.y = A.y - B.y;

  BC.x = C.x - B.x;
  BC.y = C.y - B.y;
  
  return acos(prod_int(BA,BC) / (mod(BA) * mod(BC))); //Retorna o valor do angulo em radianos usando a formula do produto interno
}

double rad2deg(double rad){ //Converte ângulos em radianos para graus
  return rad*180/M_PI;
}

double deg2rad(double deg){ //Converte ângulos em graus para radianos
  return deg*M_PI/180;
}

int main(void) {
  coord A, B, C;
  double angle = 0;

  printf("\nDigite as coordenadas (x,y) do ponto A:\n");
  scanf("%lf %lf", &A.x, &A.y);
  
  printf("\nDigite as coordenadas (x,y) do ponto B:\n");
  scanf("%lf %lf", &B.x, &B.y);
  
  printf("\nDigite as coordenadas (x,y) do ponto C:\n");
  scanf("%lf %lf", &C.x, &C.y);

  angle = angulo_entre_ABC_rad(A, B, C);

  printf("\nO ângulo <ABC é: %lf rad = %lf°\n", angle, rad2deg(angle));
  
  return 0;
}