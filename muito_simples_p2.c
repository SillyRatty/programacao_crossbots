#include <stdio.h>

double fahrenheit_to_celsius(double F){
  return (F-32)*5/9;
}

int main(void) {
  double F;
  
  printf("\nDigite a temperatura em Fahrenheit: ");
  scanf("%lf", &F);

  printf("\nA temperatura convertida para Celsius é: %.2lf\n", fahrenheit_to_celsius(F));
  
  return 0;
}