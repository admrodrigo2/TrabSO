int n_recursos;
int num_processos;

int **necessita;
int **maximo;
int *alocado;
int *disponivel;
int *vet_alocacao;


int * alocaVetor(int n_recursos);
int ** alocarMatriz(int num_processos, int n_recursos);
void desalocaMatriz(int **matriz);
void desalocarVetor(int *vetor);