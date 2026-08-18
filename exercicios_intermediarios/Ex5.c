//Contar números pares em um vetor

#include <stdio.h>

int main() {
    int numeros[10];
    int quantidadePares = 0;
    int somaPares = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\nNumeros pares: ");

    for (int i = 0; i < 10; i++) {
        if (numeros[i] % 2 == 0) {
            printf("%d ", numeros[i]);

            quantidadePares++;
            somaPares += numeros[i];
        }
    }

    printf("\nQuantidade de pares: %d\n", quantidadePares);
    printf("Soma dos pares: %d\n", somaPares);

    return 0;
}