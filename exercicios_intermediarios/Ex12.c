//Maior e menor valor de um vetor

#include <stdio.h>

int main() {
    int numeros[10];
    int maior, menor;
    int posMaior, posMenor;

    for (int i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    maior = numeros[0];
    menor = numeros[0];

    posMaior = 0;
    posMenor = 0;

    for (int i = 1; i < 10; i++) {

        if (numeros[i] > maior) {
            maior = numeros[i];
            posMaior = i;
        }

        if (numeros[i] < menor) {
            menor = numeros[i];
            posMenor = i;
        }
    }

    printf("\nMaior valor: %d", maior);
    printf("\nPosicao do maior: %d", posMaior);

    printf("\n\nMenor valor: %d", menor);
    printf("\nPosicao do menor: %d\n", posMenor);

    return 0;
}