#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <windows.h>
#include <semaphore.h>
#include "banqueiro.h"
#include "processos.h"


sem_t mutex;

void * minha_thread (void * apelido){

    while(1){

        sem_wait(&mutex);
        if(requisicao_recursos(apelido,necessita[(int)apelido]) == 0){
            Sleep(2);
            libera_recursos(1, *necessita);
            sem_post(&mutex);
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
	int i,j;
	pthread_t *pth;


	necessita = alocarMatriz(num_processos,n_recursos);
	//maximo = alocarMatriz(num_processos,n_recursos);
	alocado = alocaVetor(n_recursos);
	disponivel = alocaVetor(n_recursos);
	vet_alocacao = alocaVetor(n_recursos);

    for (i = 0; i < n_recursos; i++) {
		vet_alocacao[i] = atoi(argv[i+4]);
		disponivel[i] = vet_alocacao[i];
	}

	printf("Quantidade que cada processo necessita\n");
    for (i = 0; i < num_processos; ++i)	{
        alocado[i] = 0;
        printf("%d - ",i);
		for (j = 0; j < n_recursos; ++j){
            necessita[i][j] = rand() % (disponivel[j] + 1);
            printf("%d ", necessita[i][j]);
		}
		printf("\n");
    }

    sem_init(&mutex, 0, 1);

    pth = (pthread_t *) malloc(sizeof(pthread_t) * num_processos);

    for(i = 0; i < num_processos; i ++){
		pthread_create(&(pth[i]), NULL, minha_thread, (void *)i);
	}

	for(i = 0; i < num_processos; i ++){
		pthread_join(pth[i], NULL);
	}

    printf("terminou o programa!");
	desalocaMatriz(necessita);
	//desalocaMatriz(maximo);
	desalocarVetor(alocado);
	desalocarVetor(disponivel);
	desalocarVetor(vet_alocacao);
}
