#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "banqueiro.h"
#include "processos.h"



int * random(){

	int j;
	int * req = alocaVetor(n_recursos);

	for (j = 0; j < n_recursos; ++j) {
        req[j] = rand() % (disponivel[j] + 1);
    }

	return req;
}


int** alocarMatriz(int Linhas,int Colunas){ //Recebe a quantidade de Linhas e Colunas como Parâmetro

    int i; //Variáveis Auxiliares

    int **m = (int**)calloc(Linhas, sizeof(int*)); //Aloca um Vetor de Ponteiros

    for (i = 0; i < Linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
        m[i] = (int*) calloc(Colunas, sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
    }

    return m; //Retorna o Ponteiro para a Matriz Alocada
}

int * alocaVetor(int n_recursos){

  int *v = (int*) calloc (n_recursos, sizeof(int));

  if(v == NULL){
        return NULL;
  }

  return v;
}

void desalocaMatriz(int **matriz){

    int i;

    for(i = 0;i < num_processos;i++){
        free(matriz[i]);
        matriz[i] = NULL;
    }

    free(matriz);
    matriz = NULL;

}
void desalocarVetor(int *vetor){

    if(vetor == NULL){
        return;
    }

    free(vetor);
    vetor = NULL;
}
