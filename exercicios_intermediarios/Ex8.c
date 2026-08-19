//Verificador de número primo

#include <stdio.h>

int main() {
    int numero;
    int divisores = 0;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            divisores++;
        }
    }

    if (divisores == 2) {
        printf("%d e um numero primo.\n", numero);
    } else {
        printf("%d nao e um numero primo.\n", numero);
    }

    return 0;
}