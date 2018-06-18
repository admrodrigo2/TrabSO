#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <windows.h>
#include "banqueiro.h"
#include "processos.h"

int main(int argc, char *argv[]) {

	if (argc <= 2) {
        printf("Falta argumentos!");
        return -1;
    }

	n_recursos = argc - 4;
	num_processos = atoi(argv[2]) ;
	int i,j;

	necessita = alocarMatriz(num_processos,n_recursos);
	maximo = alocarMatriz(num_processos,n_recursos);
	alocado = alocaVetor(n_recursos);
	disponivel = alocaVetor(n_recursos);
	vet_alocacao = alocaVetor(n_recursos);

    for (i = 0; i < n_recursos; i++) {
		vet_alocacao[i] = atoi(argv[i+4]);
		disponivel[i] = vet_alocacao[i];
	}

	for (i = 0; i < num_processos; ++i)	{
        alocado[i] = 0;
		for (j = 0; j < n_recursos; ++j)
		{
			maximo[i][j] = rand() % (disponivel[j] + 1);

			necessita[i][j] = maximo[i][j];
		}
	}

	printf("Quanto cada processo necessita\n");
	for (i = 0; i < num_processos; ++i)	{
		for (j = 0; j < n_recursos; ++j)
		{
            printf("%d ",necessita[i][j]);
		}
		printf("\n");
	}

	int pid = 0;
	int res;

    while(pid <= num_processos-1){

        if(requisicao_recursos(pid,necessita) == 0){

            for(i=0;i<n_recursos;i++){
                alocado[i] = alocado[i] + necessita[pid][i];
            }
            Sleep(2);
            res = libera_recursos(pid, necessita);
        }


        pid++;
    }

    printf("\nDepois de finalizado\n");
	for (i = 0; i < num_processos; ++i)	{
		for (j = 0; j < n_recursos; ++j)
		{
            printf("%d ",necessita[i][j]);
		}
        printf("\n");
	}

	desalocaMatriz(necessita);
	desalocaMatriz(maximo);
	desalocarVetor(alocado);
	desalocarVetor(disponivel);
	desalocarVetor(vet_alocacao);

	return 0;
}
