#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrix_mult(int **a, int **b, int **c, int nl_a, int nc_a, int nc_b) {
    
    int soma = 0;

    for(int i = 0; i < nl_a; i++) {
        
        for(int j = 0; j < nc_b; j++) {
            
            for(int k = 0; k < nc_a; k++) {
                soma += a[i][k] * b[k][j];
            }
            
            c[i][j] = soma;
        }
    }


}

void printar(int **matrix, int nl, int nc) {
   
   printf("\n");
    for(int i=0; i < nl; i++) {
        printf("  [");
        for(int j=0; j < nc; j++) {
            printf(" %4d ", matrix[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

int** allocMatrix(int nl, int nc) {
    
    int **matrix = (int **)malloc(nl * sizeof(int *));

    for(int i=0; i < nl; i++) {
       matrix[i] = (int *)malloc(nc * sizeof(int));
    }

    return matrix;
}

void preencher_matrix(int **matrix, int nl, int nc) {

    for(int i = 0; i < nl; i++) {
        for(int j = 0; j < nc; j++){
            matrix[i][j] = rand() % 100;
        }
    }
}

int main() {

    int nl_a, nc_a, nl_b, nc_b;

    printf("insira o numero de linhas da matriz 1: ");
    scanf("%d", &nl_a);

    printf("insira o numero de colunas da matriz 1: ");
    scanf("%d", &nc_a);

    printf("insira o numero de linhas da matriz 2: ");
    scanf("%d", &nl_b);

    printf("insira o numero de colunas da matriz 2: ");
    scanf("%d", &nc_b);


    int **a = allocMatrix(nl_a, nc_a);
    int **b = allocMatrix(nl_b, nc_b);
    int **c = allocMatrix(nl_a, nc_b);
    

    srand(time(0));
    preencher_matrix(a, nl_a, nc_a);
    preencher_matrix(b, nl_b, nc_b);

    matrix_mult(a, b, c, nl_a, nc_a, nc_b);   

    printf("\nMatriz A: ");
    printar(a, nl_a, nc_a);

    printf("Matriz B: ");
    printar(b, nl_b, nc_b);

    printf("Matriz C: ");
    printar(c, nl_a, nc_b);

    free(a);
    free(b);
    free(c);

    return 0;
}