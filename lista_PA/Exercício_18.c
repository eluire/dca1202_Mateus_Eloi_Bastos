#include <stdio.h>
#include <stdlib.h>

int * soma_array(int *arr1, int *arr2, int *arr3, int n){

	for(int i=0;i<n;i++){
			
		arr3[i]=arr1[i]+arr2[i];
	}

	return arr3;
}

void printar(int *arr,int n){

	for(int i=0; i<n; i++){
		 printf("%d\n",arr[i] );
	}

}
int * set_array(int *arr,int n){

	int aux;
	int i,n1,n2;

	printf("\n Digite os elementos do array\n");

	for(i=0;i<n;i++){

		scanf("%d",&aux);
		arr[i] = aux;

	}
	
	return arr;
}

int main()
{

	int * arr1,* arr2,* arr3;

	int n;

	h:
	
	printf("\nDigite o tamanho do vetor:\n");
	
	scanf("%d",&n);
	
	arr1 = (int *)malloc(n*sizeof(int));
	
	arr2 = (int *)malloc(n*sizeof(int));
	
	arr3 = (int *)malloc(n*sizeof(int)); 
	printf("\npreencha o vetor 1:\n");
	
	set_array(arr1,n);
	
	printf("\npreencha o vetor 2:\n");
	
	set_array(arr2,n);	
	
	printf("\nExecução da soma...\n");

 	arr3 = soma_array(arr1,arr2,arr3,n);
	
	printf("\nO vetor soma é = \n");

	printar(arr3,n);

	return 0;
}
