//Soma dos elementos de uma matriz

#include <stdio.h>

int main() {
    int matriz[3][3];
    int soma = 0;

    printf("Digite os valores da matriz 3x3:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            soma += matriz[i][j];
        }
    }

    printf("\nMatriz:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }

    printf("\nSoma dos elementos: %d\n", soma);

    return 0;
}