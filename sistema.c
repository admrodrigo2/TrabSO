#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <windows.h>
#include "banqueiro.h"
#include "processos.h"

void * minha_thread (void * apelido){

    while(1){

        necessita = random();

        if(requisicao_recursos(1,necessita) == 0){

            Sleep(2);

            libera_recursos(1, necessita);
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {

	if (argc <= 4) {
        printf("Falta argumentos!");
        return -1;
    }

	n_recursos = argc - 4;
	num_processos = atoi(argv[2]) ;
	int i, *necessita;
	pthread_t *pth;


	//necessita = alocarMatriz(num_processos,n_recursos);
	//maximo = alocarMatriz(num_processos,n_recursos);
	alocado = alocaVetor(n_recursos);
	disponivel = alocaVetor(n_recursos);
	vet_alocacao = alocaVetor(n_recursos);

    for (i = 0; i < n_recursos; i++) {
		vet_alocacao[i] = atoi(argv[i+4]);
		disponivel[i] = vet_alocacao[i];
	}

    pth = (pthread_t *) malloc(sizeof(pthread_t) * num_processos);

    for(i = 0; i < num_processos; i ++){
		pthread_create(&(pth[i]), NULL, minha_thread, &i);
	}

	for(i = 0; i < num_processos; i ++){
		pthread_join(pth[i], NULL);
	}

	//desalocaMatriz(necessita);
	//desalocaMatriz(maximo);
	//desalocarVetor(alocado);
	//desalocarVetor(disponivel);
	//desalocarVetor(vet_alocacao);
}
