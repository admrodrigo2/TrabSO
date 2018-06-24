#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "banqueiro.h"
#include "processos.h"


int requisicao_recursos(int i, int *necessita){

    int j;

    for (j = 0; j < n_recursos; ++j) {
        if(necessita[j] >= disponivel[j]) {
            return -1;
        }
    }

    for (j = 0; j < n_recursos; ++j) {
        alocado[j] += necessita[j];
        disponivel[j]--;
    }

    return 0;
}

int libera_recursos(int i, int *recursos){

    int j;

    for (j = 0; j < n_recursos; ++j) {
        alocado[j] = alocado[j] - recursos[j];
        disponivel[j]++;
    }

    return 0;
}
