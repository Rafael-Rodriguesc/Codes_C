//Média e maior número

#include <stdio.h>

int main() {
    int numero;
    int maior;
    int soma = 0;
    float media;

    for (int i = 1; i <= 5; i++) {
        printf("Digite o %d numero: ", i);
        scanf("%d", &numero);

        soma += numero;

        if (i == 1 || numero > maior) {
            maior = numero;
        }
    }

    media = soma / 5.0;

    printf("\nMedia: %.2f\n", media);
    printf("Maior numero: %d\n", maior);

    return 0;
}