#include <stdio.h>
#include <stdlib.h>

//Define-se um numero maximo de jogos em 1000
#define MAX_GAMES 1000

typedef struct Coord_t{ //Usou-se a estrutura de coordenadas para facilitar o manejo das variaveis dentro da matriz
  int x,y;
} coord;

enum{ //Usou-se a enumeracao para deixar o codigo mais didatico e legivel
  NO_KINGS = -1,
  NO_CHECKS,
  WHITE_CHECK,
  BLACK_CHECK
};

void inicializa_tabuleiro(char tab[8][8]){ //Reseta o tabuleiro
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
      tab[i][j] = '.';
}

void printa_tabuleiro(char tab[8][8]){ //Printa as linhas do tabuleiro, usada para depuracao do codigo
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++)
      printf("%c",tab[i][j]);
    printf("\n");
  }
}

void preenche_tabuleiro(char tab[8][8]){//Preenche o tabuleiro de acordo com as entradas do usuario
  for(int i = 0; i < 8; i++){
    scanf("%s", tab[i]); //Le cada linha
    while(getchar() != '\n' && getchar() != EOF); //Limpa o buffer
  }
}

void get_kings(char tab[8][8], coord *K, coord *k){ //Guarda as coordenadas dos reis nas variaveis K e k
  int ctd = 0;
  K->x = -1; //Inicializa as coordenadas dos reis em (-1,-1)
  K->y = -1;
  k->x = -1;
  k->y = -1;
  
  for(int i = 0; i < 8; i++) //Percorre a matriz ate encontrar os dois reis
    for(int j = 0; j < 8; j++){
      if(tab[i][j] == 'K'){
        K->x = j;
        K->y = i;
        ctd++;
      }
      else if(tab[i][j] == 'k'){
        k->x = j;
        k->y = i;
        ctd++;
      }
      if(ctd >= 2) break;
    }
}

//Funcoes que verificam quais pecas para denunciar um cheque
int check_black_rook_queen(char p){
  if(p == 'r' || p == 'q')
    return WHITE_CHECK;
  else
    return NO_CHECKS;
}

int check_black_bishop_queen(char p){
  if(p == 'b' || p == 'q')
    return WHITE_CHECK;
  else
    return NO_CHECKS;
}

int check_black_knight(char p){
  if(p == 'n')
    return WHITE_CHECK;
  else
    return NO_CHECKS;
}

int check_black_pawn(char p){
  if(p == 'p')
    return WHITE_CHECK;
  else
    return NO_CHECKS;
}

int check_white_rook_queen(char p){
  if(p == 'R' || p == 'Q')
    return BLACK_CHECK;
  else
    return NO_CHECKS;
}

int check_white_bishop_queen(char p){
  if(p == 'B' || p == 'Q')
    return BLACK_CHECK;
  else
    return NO_CHECKS;
}

int check_white_knight(char p){
  if(p == 'N')
    return BLACK_CHECK;
  else
    return NO_CHECKS;
}

int check_white_pawn(char p){
  if(p == 'P')
    return BLACK_CHECK;
  else
    return NO_CHECKS;
}

//Função que verifica se ha cheques em certo tabuleiro a partir das coordenadas dos reis
int check_checks(char tab[8][8], coord K, coord k){
  int i = 0, j = 0;

  //Se as coordenadas estiverem na situacao de inicializacao, nao haviam reis no tabuleiro
  if(K.x == -1 || K.y == -1 || k.x == -1 || k.y == -1) return NO_KINGS;
  
  //Rei Branco (K)

  //Peões
  if(K.y > 0){ //Verifica-se os peoes primeiro pois assim a checagem das diagonais fica mais simples
    if(K.x < 7)
      if(check_black_pawn(tab[K.y-1][K.x+1])) return WHITE_CHECK;

    if(K.x > 0)
      if(check_black_pawn(tab[K.y-1][K.x-1])) return WHITE_CHECK;
  }

  //Torres e Rainhas
  //Sao verificadas as posicoes acima, abaixo, na esquerda e na direita das coordenadas do rei recebido
  
  //Para Cima
  for(i = K.y-1; i >= 0; i--){
    if(tab[i][K.x] != '.'){
      if(check_black_rook_queen(tab[i][K.x])) return WHITE_CHECK;
      break;
    }
  }

  //Para Baixo
  for(i = K.y+1; i < 8; i++){
    if(tab[i][K.x] != '.'){
      if(check_black_rook_queen(tab[i][K.x])) return WHITE_CHECK;
      break;
    }
  }

  //Para a Esquerda
  for(i = K.x-1; i >= 0; i--){
    if(tab[K.y][i] != '.'){
      if(check_black_rook_queen(tab[K.y][i])) return WHITE_CHECK;
      break;
    }
  }

  //Para a Direita
  for(i = K.x+1; i < 8; i++){
    if(tab[K.y][i] != '.'){
      if(check_black_rook_queen(tab[K.y][i])) return WHITE_CHECK;
      break;
    }
  }

  //Bispos e Rainhas

  //Sao verificadas as diagonais das coordenadas do rei recebido
  
  //Superior Esquerda
  i = K.y-1;
  j = K.x-1;
  while(i >= 0 && j >= 0){
    if(tab[i][j] != '.'){
      if(check_black_bishop_queen(tab[i][j])) return WHITE_CHECK;
      break;
    }
    i--;
    j--;
  }

  //Superior Direita
  i = K.y-1;
  j = K.x+1;
  while(i >= 0 && j < 8){
    if(tab[i][j] != '.'){
      if(check_black_bishop_queen(tab[i][j])) return WHITE_CHECK;
      break;
    }
    i--;
    j++;
  }

  //Inferior Esquerda
  i = K.y+1;
  j = K.x-1;
  while(i < 8 && j >= 0){
    if(tab[i][j] != '.'){
      if(check_black_bishop_queen(tab[i][j])) return WHITE_CHECK;
      break;
    }
    i++;
    j--;
  }

  //Inferior Direita
  i = K.y+1;
  j = K.x+1;
  while(i < 8 && j < 8){
    if(tab[i][j] != '.'){
      if(check_black_bishop_queen(tab[i][j])) return WHITE_CHECK;
      break;
    }
    i++;
    j++;
  }
  
  //Cavalos
  //Verifica-se cada caso do cavalo separadamente, pois nao ha logica melhor para verificar os movimentos possiveis sem correr o risco de acessar posicoes invalidas na matriz
  //Dois para baixo e um para a direita
  if(K.x < 7 && K.y < 6)
    if(check_black_knight(tab[K.y+2][K.x+1])) return WHITE_CHECK;

  //Um para baixo e dois para a direita
  if(K.x < 6 && K.y < 7)
    if(check_black_knight(tab[K.y+1][K.x+2])) return WHITE_CHECK;

  //Um para cima e dois para a direita
  if(K.x < 6 && K.y > 0)
    if(check_black_knight(tab[K.y-1][K.x+2])) return WHITE_CHECK;

  //Dois para cima e um para a direita
  if(K.x < 7 && K.y > 1)
    if(check_black_knight(tab[K.y-2][K.x+1])) return WHITE_CHECK;

  //Dois para cima e um para a esquerda
  if(K.x > 0 && K.y > 1)
    if(check_black_knight(tab[K.y-2][K.x-1])) return WHITE_CHECK;

  //Um para cima e dois para a esquerda
  if(K.x > 1 && K.y > 0)
    if(check_black_knight(tab[K.y-1][K.x-2])) return WHITE_CHECK;

  //Um para baixo e dois para a esquerda
  if(K.x > 1 && K.y < 7)
    if(check_black_knight(tab[K.y+1][K.x-2])) return WHITE_CHECK;

  //Dois para baixo e um para a esquerda
  if(K.x > 0 && K.y < 6)
    if(check_black_knight(tab[K.y+2][K.x-1])) return WHITE_CHECK;




  //A logica para a verificacao das pecas que ameacam o rei preto eh analoga a logica usada para o rei branco


  
  //Rei Preto (k)

  //Peões
  if(k.y < 7){
    if(k.x < 7)
      if(check_white_pawn(tab[k.y+1][k.x+1])) return BLACK_CHECK;

    if(k.x > 0)
      if(check_white_pawn(tab[k.y+1][k.x-1])) return BLACK_CHECK;
  }

  //Torres e Rainhas
  
  //Para Cima
  for(i = k.y-1; i >= 0; i--){
    if(tab[i][k.x] != '.'){
      if(check_white_rook_queen(tab[i][k.x])) return BLACK_CHECK;
      break;
    }
  }

  //Para Baixo
  for(i = k.y+1; i < 8; i++){
    if(tab[i][k.x] != '.'){
      if(check_white_rook_queen(tab[i][k.x])) return BLACK_CHECK;
      break;
    }
  }

  //Para a Esquerda
  for(i = k.x-1; i >= 0; i--){
    if(tab[k.y][i] != '.'){
      if(check_white_rook_queen(tab[k.y][i])) return BLACK_CHECK;
      break;
    }
  }

  //Para a Direita
  for(i = k.x+1; i < 8; i++){
    if(tab[k.y][i] != '.'){
      if(check_white_rook_queen(tab[k.y][i])) return BLACK_CHECK;
      break;
    }
  }

  //Bispos e Rainhas
  
  //Superior Esquerda
  i = k.y-1;
  j = k.x-1;
  while(i >= 0 && j >= 0){
    if(tab[i][j] != '.'){
      if(check_white_bishop_queen(tab[i][j])) return BLACK_CHECK;
      break;
    }
    i--;
    j--;
  }

  //Superior Direita
  i = k.y-1;
  j = k.x+1;
  while(i >= 0 && j < 8){
    if(tab[i][j] != '.'){
      if(check_white_bishop_queen(tab[i][j])) return BLACK_CHECK;
      break;
    }
    i--;
    j++;
  }

  //Inferior Esquerda
  i = k.y+1;
  j = k.x-1;
  while(i < 8 && j >= 0){
    if(tab[i][j] != '.'){
      if(check_white_bishop_queen(tab[i][j])) return BLACK_CHECK;
      break;
    }
    i++;
    j--;
  }

  //Inferior Direita
  i = k.y+1;
  j = k.x+1;
  while(i < 8 && j < 8){
    if(tab[i][j] != '.'){
      if(check_white_bishop_queen(tab[i][j])) return BLACK_CHECK;
      break;
    }
    i++;
    j++;
  }
  
  //Cavalos
  //Dois para baixo e um para a direita
  if(k.x < 7 && k.y < 6)
    if(check_white_knight(tab[k.y+2][k.x+1])) return BLACK_CHECK;

  //Um para baixo e dois para a direita
  if(k.x < 6 && k.y < 7)
    if(check_white_knight(tab[k.y+1][k.x+2])) return BLACK_CHECK;

  //Um para cima e dois para a direita
  if(k.x < 6 && k.y > 0)
    if(check_white_knight(tab[k.y-1][k.x+2])) return BLACK_CHECK;

  //Dois para cima e um para a direita
  if(k.x < 7 && k.y > 1)
    if(check_white_knight(tab[k.y-2][k.x+1])) return BLACK_CHECK;

  //Dois para cima e um para a esquerda
  if(k.x > 0 && k.y > 1)
    if(check_white_knight(tab[k.y-2][k.x-1])) return BLACK_CHECK;

  //Um para cima e dois para a esquerda
  if(k.x > 1 && k.y > 0)
    if(check_white_knight(tab[k.y-1][k.x-2])) return BLACK_CHECK;

  //Um para baixo e dois para a esquerda
  if(k.x > 1 && k.y < 7)
    if(check_white_knight(tab[k.y+1][k.x-2])) return BLACK_CHECK;

  //Dois para baixo e um para a esquerda
  if(k.x > 0 && k.y < 6)
    if(check_white_knight(tab[k.y+2][k.x-1])) return BLACK_CHECK;

  return NO_CHECKS;
}

int main(void) {
  char tab[8][8], buff;
  int *results = NULL, number_of_games = 0;
  coord K, k;

  results = (int*) malloc(MAX_GAMES*sizeof(int)); //Usou-se um numero maximo de 1000 casos para fazer a alocacao de espaco

  while(1){ //sempre entra-se no laco, pois nao ha maneira de verificar a condicao de parada antes de receber os tabuleiros
    inicializa_tabuleiro(tab);
  
    preenche_tabuleiro(tab); //Recebe o tabuleiro do usuario
  
    get_kings(tab, &K, &k); //Guarda as posicoes dos reis
  
    results[number_of_games] = check_checks(tab, K, k); //Guarda o resultado de cada analise de jogo

    if(results[number_of_games++] == NO_KINGS) break; //A condicao de parada do laco ocorre quando eh recebido um tabuleiro vazio, ou seja, sem reis
    
    fgets(&buff, 1, stdin); //Elimina-se a linha vazia entre cada entrada do usuário a armazenado numa variável
  }

  for(int i = 0; i < number_of_games; i++){ //Faz se o print final dependendo do resultado de cada jogo
    if(results[i] == NO_CHECKS) printf("Jogo #%d: nenhum rei esta em cheque.\n", i+1);
    else if(results[i] == WHITE_CHECK) printf("Jogo #%d: rei branco esta em cheque.\n", i+1);
    else if(results[i] == BLACK_CHECK) printf("Jogo #%d: rei preto esta em cheque.\n", i+1);
  }

  free(results); //Libera o espaco alocado

  return 0;
}