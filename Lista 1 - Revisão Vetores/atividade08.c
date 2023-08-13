#include <stdio.h>

/*
(LIS - Longest Increasing Subsequence) en 
(MSC - Maior Subsequência Crescente) pt-br
*/

void printLIS(int array[], int lis[], int endIndex) {
    if (endIndex == -1) {
        return;
    }
    
    printLIS(array, lis, lis[endIndex]);
    printf("%d ", array[endIndex]);
}

void findLIS(int array[], int length) {
    int lis[length];
    int prevIndex[length];
    int i, j;
    
   
    for (i = 0; i < length; i++) {
    	// Inicialização dos arrays lis[] e prevIndex[]
        lis[i] = 1;          // Inicializa a maior subsequência no mínimo com 1 (cada elemento é uma subsequência por si só).
        prevIndex[i] = -1;   // Inicializa o índice anterior como -1 (ainda não temos índice anterior).
    }
    
    int maxLength = 1;      // Inicializa o tamanho máximo de subsequência como 1 (pelo menos um elemento).
    int endIndex = 0;       // Índice final da maior subsequência.
    
    // Loop externo para percorrer o array de elementos.
    for (i = 1; i < length; i++) {
        // Loop interno para comparar com os elementos anteriores.
        for (j = 0; j < i; j++) {
            // Verifica se o elemento atual (array[i]) é maior do que o elemento anterior (array[j]).
            // E também se a subsequência terminando no índice i (lis[i]) é menor do que a subsequência terminando no índice j + 1 (lis[j] + 1).
            if (array[i] > array[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;   // Atualiza o tamanho da maior subsequência terminando no índice i.
                prevIndex[i] = j;      // Armazena o índice anterior para reconstruir a subsequência.
                
                // Atualiza o tamanho máximo da subsequência se a subsequência terminando no índice i for maior.
                if (lis[i] > maxLength) {
                    maxLength = lis[i];
                    endIndex = i;         // Atualiza o índice final da maior subsequência
                }
            }
        }
    }
    
    // Imprime a maior subsequência crescente
    printf("Maior Subsequência Crescente: ");
    printLIS(array, prevIndex, endIndex);
    printf("\n");
}


int main() {
	//mais uma vez array inicializado com 100 pois é uma quantidade sufciente para teste, fiz o mesmo no exercicio 07 dessa lista.
    int i, size, array[100];

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    printf("Digite os elementos do vetor: ");
    for ( i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    findLIS(array, size);

    return 0;
}

