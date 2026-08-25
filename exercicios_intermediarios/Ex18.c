//Contagem de números repetidos

#include <stdio.h>

int main() {
    int numeros[10];
    int procurado;
    int quantidade = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("Digite um numero para procurar: ");
    scanf("%d", &procurado);

    for (int i = 0; i < 10; i++) {
        if (numeros[i] == procurado) {
            quantidade++;
        }
    }

    printf("O numero %d apareceu %d vez(es).\n", procurado, quantidade);

    return 0;
}