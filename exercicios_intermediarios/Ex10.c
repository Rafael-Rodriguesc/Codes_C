//Fatorial de um número

#include <stdio.h>

int main() {
    int numero;
    int fatorial = 1;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Nao existe fatorial de numero negativo.\n");
    } else {
        for (int i = 1; i <= numero; i++) {
            fatorial = fatorial * i;
        }

        printf("O fatorial de %d e: %d\n", numero, fatorial);
    }

    return 0;
}