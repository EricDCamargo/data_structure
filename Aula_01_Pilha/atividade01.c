#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->top++;
        stack->items[stack->top] = value;
    } else {
        printf("Stack pilha\n");
    }
}

char pop(Stack *stack) {
    if (stack->top >= 0) {
        char value = stack->items[stack->top];
        stack->top--;
        return value;
    } else {
        printf("Stack pilha\n");
        return '\0';
    }
}

int is_balanced(char expression[]) {
    Stack stack;
    stack.top = -1; // Inicializa a pilha vazia

    int length = strlen(expression);

    for (int i = 0; i < length; i++) {
        char current = expression[i];

        // Se encontrar um caractere de abertura, empilha na pilha
        if (current == '(' || current == '[' || current == '{') {
            push(&stack, current);
        } else if (current == ')' || current == ']' || current == '}') {
            // Se encontrar um caractere de fechamento
            if (stack.top == -1) {
                return 0; // Se a pilha estiver vazia, expressão não está balanceada
            }

            char top_element = pop(&stack); // Desempilha o caractere de abertura correspondente

            // Verifica se os caracteres correspondentes estão balanceados
            if ((current == ')' && top_element != '(') ||
                (current == ']' && top_element != '[') ||
                (current == '}' && top_element != '{')) {
                return 0; // Expressão não está balanceada
            }
        }
    }

    return stack.top == -1; // Se a pilha estiver vazia, a expressão está balanceada
}

int main() {
   char expression[MAX_SIZE];

    printf("Digite uma expressao: ");
    scanf("%s", expression);

    if (is_balanced(expression)) {
        printf("Expressao balanceada\n");
    } else {
        printf("Expressao não balanceada\n");
    }

    return 0;
}
