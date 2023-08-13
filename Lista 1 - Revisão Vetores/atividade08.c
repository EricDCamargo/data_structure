#include <stdio.h>

/*
(LIS - Longest Increasing Subsequence) en 
(MSC - Maior Subsequ�ncia Crescente) pt-br
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
    	// Inicializa��o dos arrays lis[] e prevIndex[]
        lis[i] = 1;          // Inicializa a maior subsequ�ncia no m�nimo com 1 (cada elemento � uma subsequ�ncia por si s�).
        prevIndex[i] = -1;   // Inicializa o �ndice anterior como -1 (ainda n�o temos �ndice anterior).
    }
    
    int maxLength = 1;      // Inicializa o tamanho m�ximo de subsequ�ncia como 1 (pelo menos um elemento).
    int endIndex = 0;       // �ndice final da maior subsequ�ncia.
    
    // Loop externo para percorrer o array de elementos.
    for (i = 1; i < length; i++) {
        // Loop interno para comparar com os elementos anteriores.
        for (j = 0; j < i; j++) {
            // Verifica se o elemento atual (array[i]) � maior do que o elemento anterior (array[j]).
            // E tamb�m se a subsequ�ncia terminando no �ndice i (lis[i]) � menor do que a subsequ�ncia terminando no �ndice j + 1 (lis[j] + 1).
            if (array[i] > array[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;   // Atualiza o tamanho da maior subsequ�ncia terminando no �ndice i.
                prevIndex[i] = j;      // Armazena o �ndice anterior para reconstruir a subsequ�ncia.
                
                // Atualiza o tamanho m�ximo da subsequ�ncia se a subsequ�ncia terminando no �ndice i for maior.
                if (lis[i] > maxLength) {
                    maxLength = lis[i];
                    endIndex = i;         // Atualiza o �ndice final da maior subsequ�ncia
                }
            }
        }
    }
    
    // Imprime a maior subsequ�ncia crescente
    printf("Maior Subsequ�ncia Crescente: ");
    printLIS(array, prevIndex, endIndex);
    printf("\n");
}


int main() {
	//mais uma vez array inicializado com 100 pois � uma quantidade sufciente para teste, fiz o mesmo no exercicio 07 dessa lista.
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

