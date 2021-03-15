#include "gul-e-din.h"

int **criaMatriz(int v)
{
    int **mat = (int**) malloc(v * sizeof(int*));
    for(int i = 0; i < v; i++) {
        mat[i] = (int*) malloc(v * sizeof(int));
    }
    return mat;
}

void preencheVetor(int *vt, int v) 
{
    int i = 0;
    while(i < v) {
        printf("DIGITE OS VALORES PARA O INDICE %d DO VETOR: ", i);
        scanf("%d", &vt[i]);
        i++;
    }
}

int *auxVetor(int v)
{
    int *vet;
    vet = (int*) malloc(v * sizeof(int));
    return vet;
}

int *realocarAux(int *fim, int tam)
{
    int *vet;
    vet = (int*) realloc(fim, tam * sizeof(int));
    return vet;
}

void seqCresc(int *vt, int **mat, int v)
{
    int i = 0, j, ctrl, aux = 0, max = 1, maior1, maior2, temp = 0, a, b, soma;
    int *adjc = auxVetor(v);
    int *seq = auxVetor(v);
    int *aux2 = auxVetor(v);
    int *final;
    for(i = 0; i < v; i++) {
        adjc[i] = 0;
        seq[i] = 0;
    }
    i = 0;
    while(i < v) {
        j = 0;
        while(j < v) {
            mat[i][j] = 0;    
            j++;
        }
        i++;
    }
    i = 0;
    while(i < v) {
        j = i;
        while(j < v) {
            if(vt[i] < vt[j]) {
                mat[i][j] = 1;
                adjc[i]++;
            }    
            j++;
        }
        i++;
    }
    i = 0;
    while(i < v) {
        soma = 0;
        j = 0;
        while(j < v) {
            if(mat[i][j] == 1) {
                soma++;
            }    
            j++;
        }
        aux2[i] = soma;
        i++;
    }
    do {
        ctrl = 0;
        for(i = 0; i < v; i++) {
            if(adjc[i] > temp) {
                temp = adjc[i]; 
                aux = i;   
                ctrl = 1;
            }
        }
    }while(ctrl == 1);
    seq[0] = vt[aux];
    do {
        maior1 = aux;
        maior2 = -1;  
        i = aux + 1;
        while(i < v) {
            if((mat[maior1][i] == 1) && (adjc[i] > maior2)) {
                maior2 = adjc[i];
                aux = i;
            }
            i++;
        } 
        seq[max] = vt[aux];
        max++; 
    }while(adjc[aux] != 0);
    final = auxVetor(max);
    i = 0;
    printf("\nALGORITMO GULOSO"); 
    printf("\nMATRIZ\n");
    printf("   "); 
    for(a = 0; a < v; a++) {
        printf("%d ", vt[a]);
    }
    printf("| G\n");
    for(a = 0; a < v; a++) {
        printf("%d |", vt[a]);
        for(b = 0; b < v; b++) {
            printf("%d ", mat[a][b]);
            if((b + 1) == v) {
                printf("| %d", aux2[a]);
            }
        }
        printf("\n");
    } 
    printf("\nTAMANHO DA SUBSEQUENCIA CRESCENTE: %d\n", max);
    printf("SUBSEQUENCIA CRESCENTE - {");
    while(i < max) {
        final[i] = seq[i];
        if((i + 1) == max) { 
            printf("%d", final[i]);
        }else {
            printf("%d, ", final[i]);
        }
        i++;
    }
    printf("}\n");
}   

void seqCresc2(int *vt, int v)
{
    int *ant = auxVetor(v);
    int *seq = auxVetor(v);
    int *ind = auxVetor(v);
    int *fim;
    int max = 0, indice, k, x, j, i, p, w, tam = 1;
    for(i = 0; i < v; i++) {
		x = vt[i];
		j = 0;
		for(k = 0; k < max; k++) {
		   if(seq[k] < x) {
		      j++;
            }
        }		
		seq[j] = x;
		ind[j] = i;
		if(j == max) {
			max++;
			indice = i;
		}
		if(j) {
		   ant[i] = ind[j - 1];
        }else {
		   ant[i] = -1;
        }
	}  
    p = max - 1;
    fim = auxVetor(max);
    w = vt[indice];
    while(p >= 0) {
        fim[p--] = w;
        indice = ant[indice];
        w = vt[indice];
    } 
    printf("\nALGORITMO PROGRAMACAO DINAMICA\n"); 
    printf("TAMANHO DA SUBSEQUENCIA CRESCENTE: %d\n", max);
    printf("SUBSEQUENCIA CRESCENTE - {");
    i = 0;
    while(i < max) {
        if((i + 1) == max) { 
            printf("%d", fim[i]);
        }else {
            printf("%d, ", fim[i]);
        }
        i++;
    }
    printf("}\n");
}
