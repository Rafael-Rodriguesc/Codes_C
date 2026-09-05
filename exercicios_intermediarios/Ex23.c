//Inverter um vetor

#include <stdio.h>

int main() {

    int numeros[8];
    int temp;

    // Preenchendo o vetor
    for (int i = 0; i < 8; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Mostrando o vetor original
    printf("\nVetor original:\n");

    for (int i = 0; i < 8; i++) {
        printf("%d ", numeros[i]);
    }

    // Invertendo o vetor
    for (int i = 0; i < 4; i++) {

        temp = numeros[i];

        numeros[i] = numeros[7 - i];

        numeros[7 - i] = temp;
    }

    // Mostrando o vetor invertido
    printf("\n\nVetor invertido:\n");

    for (int i = 0; i < 8; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n");

    return 0;
}