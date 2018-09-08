#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// implementação da função de ordenação bubble sort
int * BubbleSort(int *arr, int n){
    int aux, i, j;
    for(j=n-1; j>=1; j--){
        for(i=0; i<j; i++){
            if(arr[i]>arr[i+1]){
                aux=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=aux;
            }
        }
    }

    return arr;
}
// Função de comparação do qsort
int compare(const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main() {
    int *arr1,*arr2,*arr3;
    clock_t cmc_t, fim_t;
    int n = 100000; // foi utilizado um n grande para podermos ter um tempo maior...
    
    // Aloca 3 arrays com n elementos
    arr1 = (int *)malloc(n * sizeof(int)),
    arr2 = (int *)malloc(n * sizeof(int)),
    arr3 = (int *)malloc(n * sizeof(int));

    // Preenche um array com numeros aleatórios
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        *(arr1 + i) = rand() % 100;        
    }

    // Copia o array random para os outros arrays
    memcpy(arr2, arr1, n * sizeof(int));
    memcpy(arr3, arr1, n * sizeof(int));

    cmc_t = clock();
    BubbleSort(arr1, n-1);
    fim_t = clock();
    printf("bubble_sort levou: %fseg\n", (double)(fim_t - cmc_t / CLOCKS_PER_SEC));
    free(arr2);
    // Libera o array 1
    free(arr1);
    //repete o procedimento para os outros arrays 
    cmc_t = clock();
    qsort(arr2, n, sizeof(int), compare);
    fim_t = clock();
    printf("Qsort levou: %fseg\n", (double)(fim_t - cmc_t) / CLOCKS_PER_SEC);
    free(arr2);

    void (*ponteiro_qsort)(void *arr, size_t n, size_t size, int(*compar)(const void *, const void *));
    ponteiro_qsort = qsort;

    cmc_t = clock();
    ponteiro_qsort(arr3, n, sizeof(int), compare);
    fim_t = clock();
    printf("Qsort pelo ponteiro levou: %fseg\n", (double)(fim_t - cmc_t) / CLOCKS_PER_SEC);
    free(arr3);

    return 0;
}