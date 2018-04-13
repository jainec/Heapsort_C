#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg{
    int numPacote, verifica;
    char *sequencia;
}pacote;

void initialize(pacote E[], int n){
    int i;
    for(i = 0; i < n; i++){
        E[i].numPacote = -1;
        E[i].verifica = -1;
        E[i].sequencia = NULL;
    }
}

int pai(int i){
    return (i-1)/2;
}

int esquerda(int i){
    return 2*i + 1;
}

int direita(int i){
    return 2*i + 2;
}

void trocar(pacote V[], int a, int b){
    int aux = V[a].numPacote;
    V[a].numPacote = V[b].numPacote;
    V[b].numPacote = aux;

    char aux2[ (strlen(V[a].sequencia) + strlen(V[b].sequencia)) ];
    char aux3[ (strlen(V[a].sequencia) + strlen(V[b].sequencia)) ];
    strcpy(aux2, V[a].sequencia);
    strcpy(aux3, V[b].sequencia);
    free(V[a].sequencia);
    free(V[b].sequencia);
    V[a].sequencia = (char *) malloc(sizeof(aux3));
    strcpy(V[a].sequencia, aux3);
    V[b].sequencia = (char *) malloc(sizeof(aux2));
    strcpy(V[b].sequencia, aux2);
}

void heapify(pacote V[], int i, int n) {
    unsigned int P = i;
    unsigned int E = esquerda(i);
    unsigned int D = direita(i);
    if(E < n && V[E].numPacote > V[P].numPacote) P = E;
    if(D < n && V[D].numPacote > V[P].numPacote) P = D;
    if(P != i) {
        trocar(V, P, i);
        heapify(V, P, n);
    }
}

void heapsort(pacote V[], int n){
    int i;
    for (i = n / 2 - 1; i >= 0; i--){   //build heap (rearrange array)
        heapify(V, i, n);
    }

    for(i = n - 1; i > 0 ; i--) {
        trocar(V, 0, i);
        heapify(V, 0, i);
    }
}

void carregaArquivo(int totalPacotes, pacote pacotes[], FILE* input){
    int i;
    for(i = 0; i < totalPacotes; i++){
        int tam;
        fscanf(input, "%d %d ", &pacotes[i].numPacote, &tam);
        pacotes[i].sequencia = (char *) malloc(tam*4);
        fscanf(input, "%[^\n]s", pacotes[i].sequencia);
    }
}

void gravaArquivo(int totalPacotes, int qntVerificar, pacote pacotes[], FILE* output){
    int count = -1, i;
    for(i = 1; i <= totalPacotes; i++){
        if( (i % qntVerificar) == 0 || i == totalPacotes){
            int j, aux  = 0;
            heapsort(pacotes, i);

            for(j = 0; j < i; j++){
                if(pacotes[j].numPacote == j && pacotes[j].verifica != 1) aux++;
            }

            if(aux != 0){
                count++;
                fprintf(output, "%d: ", count);
                for(j = 0; j < i; j++){
                    if(pacotes[j].numPacote == j && pacotes[j].verifica != 1){
                        pacotes[j].verifica = 1;
                        fprintf(output, "%s ", pacotes[j].sequencia);
                    }
                }
                fprintf(output, "\n");
            }
        }
    }
}

void libera(pacote E[], int n){
    int i;
    for(i = 0; i < n; i++)
        free(E[i].sequencia);
}

int main(int argc, char* argv[]){
    printf("#ARGS = %i\n", argc);
    printf("PROGRAMA = %s\n", argv[0]);
    printf("ARG1 = %s, ARG2 = %s\n", argv[1], argv[2]);

    int totalPacotes, qntVerificar;
    FILE* input = fopen(argv[1], "r");
    fscanf(input, "%d %d\n", &totalPacotes, &qntVerificar);
    pacote pacotes[totalPacotes];
    initialize(pacotes, totalPacotes);
    carregaArquivo(totalPacotes, pacotes, input);
    fclose(input);

    FILE* output = fopen(argv[2], "w");
    gravaArquivo(totalPacotes, qntVerificar, pacotes, output);
    fclose(output);
    libera(pacotes, totalPacotes);

    return 0;
}
