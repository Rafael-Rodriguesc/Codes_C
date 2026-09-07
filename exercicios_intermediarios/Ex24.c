//Separar números pares e ímpares

#include <stdio.h>

int main() {

    int numeros[10];
    int pares[10];
    int impares[10];

    int qtdPares = 0;
    int qtdImpares = 0;

    // Preenchendo o vetor principal
    for (int i = 0; i < 10; i++) {

        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);

        if (numeros[i] % 2 == 0) {
            pares[qtdPares] = numeros[i];
            qtdPares++;
        } else {
            impares[qtdImpares] = numeros[i];
            qtdImpares++;
        }
    }

    // Mostrando o vetor original
    printf("\n===== VETOR ORIGINAL =====\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }

    // Mostrando os pares
    printf("\n\n===== NUMEROS PARES =====\n");

    for (int i = 0; i < qtdPares; i++) {
        printf("%d ", pares[i]);
    }

    // Mostrando os impares
    printf("\n\n===== NUMEROS IMPARES =====\n");

    for (int i = 0; i < qtdImpares; i++) {
        printf("%d ", impares[i]);
    }

    printf("\n\nQuantidade de pares: %d\n", qtdPares);
    printf("Quantidade de impares: %d\n", qtdImpares);

    return 0;
}