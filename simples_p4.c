#include <stdio.h>

int encontra_letra(char letra, char *frase){
  int ans = 0;
  for (int i = 0; frase[i] != '\0' && frase[i] != EOF; i++)
    if (letra == frase[i]) ans+=1;

  return ans;
}

int main(void) {
  char letra, frase[100], buf;
  scanf("%c", &letra);
  while (getchar() != '\n' && getchar() != EOF); //Libera o buffer de entrada
  fgets(frase, 100, stdin);

  printf("%d\n", encontra_letra(letra,frase));
  return 0;
}