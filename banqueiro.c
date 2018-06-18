#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "banqueiro.h"
#include "processos.h"


int requisicao_recursos(int pid, int **necessita){

    int j;

    for (j = 0; j < n_recursos; ++j) {
        if(necessita[pid][j] <= (disponivel[j] - alocado[j])) {
            continue;
        }
        else{
            return -1;
        }
    }

    return 0;
}

int libera_recursos(int pid, int **recursos){

    int j;

    for (j = 0; j < n_recursos; ++j) {
        alocado[j] = alocado[j] - recursos[pid][j];
        recursos[pid][j] = -1;
    }

    return 0;
}
