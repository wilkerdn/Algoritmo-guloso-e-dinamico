#include "gul-e-din.h"

int main () 
{
    int v;
    int **mat;
    int * vt;
    printf("INFORME O TAMANHO DO VETOR: ");
    scanf("%d", &v);   
    mat = criaMatriz(v);
    vt = auxVetor(v);
    preencheVetor(vt, v);     
    seqCresc(vt, mat, v); 
    seqCresc2(vt, v);
    for(int i = 0; i < v; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}
