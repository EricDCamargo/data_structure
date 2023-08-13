#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  

int searchNumberPosition(int providedNumber, int array[], int sizeOfArry, int currentIndex) {
    if (currentIndex >= sizeOfArry) {
        return -1; //  número não encontrado
    }

    if (array[currentIndex] == providedNumber) {
        return currentIndex; // número encontrado
    }

    return searchNumberPosition(providedNumber, array, sizeOfArry, currentIndex + 1); // Recursão
}

int main() {
    int sizeOfArry, v1[] = {15, 8, 42, 19, 30};
    char choice;
	sizeOfArry = sizeof(v1) / sizeof(int);

    do {
        int currentSearch, position;

        printf("Digite um numero para pesquisar no array: ");
        scanf("%d", &currentSearch);

        position = searchNumberPosition(currentSearch, v1, sizeOfArry, 0);

        if (position != -1) {
            printf("O numero %d foi encontrado na posicao %d do array.\n", currentSearch, position + 1);
        } else {
            printf("O numero %d nao foi encontrado no array.\n", currentSearch);
        }

        sleep(1.5);

        printf("Deseja fazer outra pesquisa?\n\n"
               "S para sim\n"
               "Qualquer outra tecla para sair\n"
        );

        scanf(" %c", &choice);
        choice = toupper(choice); // Converte o caracter para maiúsculo
    } while (choice == 'S');
    
    printf("Saindo do programa...\n");
    return 0;
}

