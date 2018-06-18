#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "banqueiro.h"
#include "processos.h"



int** alocarMatriz(int Linhas,int Colunas){ //Recebe a quantidade de Linhas e Colunas como Parâmetro

  int i,j; //Variáveis Auxiliares

  int **m = (int**)malloc(Linhas * sizeof(int*)); //Aloca um Vetor de Ponteiros

  for (i = 0; i < Linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
       m[i] = (int*) malloc(Colunas * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (j = 0; j < Colunas; j++){ //Percorre o Vetor de Inteiros atual.
            m[i][j] = 0; //Inicializa com 0.
       }
  }
return m; //Retorna o Ponteiro para a Matriz Alocada
}

int * alocaVetor(int n_recursos){

	int *v = (int*) malloc (sizeof(int) * (n_recursos));

	return v;
}

void ** desalocaMatriz(int **matriz){

    int i;

    for(i=0;i<n_recursos;i++){
        free(matriz[i]);
    }
    free(matriz);

}
void * desalocarVetor(int *vetor){

    free(vetor);
}
