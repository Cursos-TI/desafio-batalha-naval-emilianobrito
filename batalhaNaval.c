#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível novato
 
int main() {

  char linha[10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  int tabuleiro [10][10];
  int barco1[3] = {1, 1, 1};
  int barco2[3] = {2, 2, 2};

  //Inicializando a matriz tabuleiro com valores iguais a zero para todas posições
  for (int i=0; i<10;i++){
    for (int j=0; j<10; j++){
        tabuleiro[i][j]=0;
    }
  }
 
  //Posicionando o barco1 na horizontal
  tabuleiro [2][6] = barco1[0];
  tabuleiro [2][7] = barco1[1]; 
  tabuleiro [2][8] = barco1[2];
  //Posicionando o barco2 na vertical 
  tabuleiro [6][2] = barco2[0];
  tabuleiro [7][2] = barco2[1];
  tabuleiro [8][2] = barco2[2];

  //Impressao dos indices da coordenada x - representados por letras
  printf ("   ");
  for (int j =0; j<10; j++){
    printf (" %c", linha[j]);
  }
  printf ("\n");  

  //Impressao do tabuleiro
  for (int i=0; i<10;i++){
    //Impressao dos indices da coordenada y - representados por numeros
    if (i <9){
      printf (" %d  ", i + 1);
    }
    else {
      printf ("%d  ", i + 1);
    }
    for (int j=0; j<10;j++){
      printf ("%d ", tabuleiro [i][j]);
    }     
    printf ("\n");  
  } 
}