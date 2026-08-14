//10. Ordenação de vetor

#include <stdio.h>

int main() {
    int numeros[10];
    int i, j, temp;

    // Entrada dos números
    for (i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Ordenação - Bubble Sort
    for (i = 0; i < 10 - 1; i++) {
        for (j = 0; j < 10 - i - 1; j++) {

            if (numeros[j] > numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    // Exibição
    printf("\nNumeros em ordem crescente:\n");

    for (i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n");

    return 0;
}