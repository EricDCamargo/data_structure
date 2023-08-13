#include <stdio.h>


int main() {
    int i, size = chooseSize();

	/*
	Inicializei com 100 pois achei uma quantidade razoável de espaço na memória, embora o tamanho real possa ser menor ou maior.
	Neste cenario para exemplos de teste tá ok mas imagino que em maiores proporções possa causar problemas como,
	como estouro de memória ou de acesso a áreas inválidas da memória.
	*/
    int matrix[100][100];
    int array[100 * 100]; 
    
    fillMatrix(matrix, size);
    turnMatrixInSpiralArray(matrix, size, array);

    printf("Array com os elementos em espiral: ");
    for ( i = 0; i < size * size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}


//Só escolhe o tamnho da matrix, mas deixei travado em size x sixe então a escolha representará uma matrix com as mesmas dimesoes x - y sempre.

int chooseSize() {
    int size;
    printf("Digite o tamanho da matriz (impar): ");
    scanf("%d", &size);

    if (size % 2 == 0) {
        printf("O tamanho da matriz deve ser impar. Tente novamente.\n");
        return chooseSize();
    }

    return size;
}


/*
Preenche a matrix de tamanho x tamanho com valores sequenciais começando de 1 e seguindo um padrão em espiral. O processo é dividido em quatro etapas:

Preenche a linha superior da matriz (da esquerda para a direita) com os valores sequenciais.
Preenche a coluna direita da matriz (de cima para baixo) com os valores sequenciais.
Preenche a linha inferior da matriz (da direita para a esquerda) com os valores sequenciais.
Preenche a coluna esquerda da matriz (de baixo para cima) com os valores sequenciais. 

*/ 



void fillMatrix(int matrix[][100], int size) {
    int value = 1;
    int start = 0;
    int end = size - 1;
    int i;

    while (start <= end) {
        for ( i = start; i <= end; i++) {
            matrix[start][i] = value++;
        }

        for ( i = start + 1; i <= end; i++) {
            matrix[i][end] = value++;
        }

        for ( i = end - 1; i >= start; i--) {
            matrix[end][i] = value++;
        }

        for ( i = end - 1; i > start; i--) {
            matrix[i][start] = value++;
        }
        start++;
        end--;
    }
}

//Simplesmente percorre a Matris e asiciona os elementos ao array.
void turnMatrixInSpiralArray(int matrix[][100], int size, int array[]) {
    int i, j, index = 0;
    for ( i = 0; i < size; i++) {
        for ( j = 0; j < size; j++) {
            array[index++] = matrix[i][j];
        }
    }
}
