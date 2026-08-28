//Caixa eletrônico

#include <stdio.h>

int main() {
    int valor;
    int notas100, notas50, notas20, notas10;

    printf("Digite o valor do saque: ");
    scanf("%d", &valor);

    if (valor <= 0 || valor % 10 != 0) {
        printf("Valor invalido! Digite um valor multiplo de 10.\n");
        return 0;
    }

    notas100 = valor / 100;
    valor = valor % 100;

    notas50 = valor / 50;
    valor = valor % 50;

    notas20 = valor / 20;
    valor = valor % 20;

    notas10 = valor / 10;

    printf("\nNOTAS\n");
    printf("Notas de R$100: %d\n", notas100);
    printf("Notas de R$50: %d\n", notas50);
    printf("Notas de R$20: %d\n", notas20);
    printf("Notas de R$10: %d\n", notas10);

    return 0;
}