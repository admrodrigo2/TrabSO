int n_recursos;
int num_processos;
//int pid = 0;

void * minha_thread ( void *);

int **necessita;
int **maximo;
int *alocado;
int *disponivel;
int *vet_alocacao;


int * random();
int * alocaVetor(int n_recursos);
int ** alocarMatriz(int num_processos, int n_recursos);
void desalocaMatriz(int **matriz);
void desalocarVetor(int *vetor);
