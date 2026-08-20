// Inverter um número

#include <stdio.h>

int main() {
    int numero;
    int invertido = 0;
    int resto;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    while (numero != 0) {
        resto = numero % 10;
        invertido = invertido * 10 + resto;
        numero = numero / 10;
    }

    printf("Numero invertido: %d\n", invertido);

    return 0;
}