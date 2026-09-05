//Encontrar o maior elemento do vetor

#include <stdio.h>

int main() {

    int numeros[10];
    int maior;

    // Preenchendo o vetor
    for (int i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Considera o primeiro numero como o maior inicialmente
    maior = numeros[0];

    // Procurando o maior numero
    for (int i = 1; i < 10; i++) {

        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }

    // Mostrando o vetor
    printf("\nNumeros digitados:\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n\nMaior numero: %d\n", maior);

    return 0;
}