#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "banqueiro.h"

int *vet_alocacao;
int *disponivel;
int **necessita;
int **max;
int **alocado;

int main(int argc, char *argv[]) {

	if (argc <= 2) {
        printf("Falta argumentos!");
        return -1;
    }

	int n_recursos = argc - 4;
	int num_processos = atoi(argv[2]) ;
	int i,j,sucesso;

	necessita = alocarMatriz(num_processos,n_recursos);
	max = alocarMatriz(num_processos,n_recursos);
	alocado = alocarMatriz(num_processos,n_recursos);

	disponivel = (int*) malloc (sizeof(int) * (n_recursos));
	if(disponivel == NULL) {
		printf("Erro na alocacao");
		return NULL;
	}

	vet_alocacao = (int*) malloc (sizeof(int) * (n_recursos));
		if(vet_alocacao == NULL) {
		printf("Erro na alocacao");
		return NULL;
	}

    for (i = 0; i <= n_recursos; i++) {
		vet_alocacao[i] = atoi(argv[i+4]);
		disponivel[i] = vet_alocacao[i];
	}

	for (i = 0; i < num_processos; ++i)	{
		for (j = 0; j < n_recursos; ++j)
		{
			max[i][j] = rand() % (disponivel[j] + 1);
			alocado[i][j] = 0;
			necessita[i][j] = max[i][j] - alocado[i][j];
		}
	}
/*
	while(true) {

		sucesso = requisicao_recursos(int pid, int recursos[]);

		if(sucesso == 0){

			sleep(rand() % 100);

			libera_recursos(int pid, int recursos[])
		}

	}
*/

	return 0;
}
