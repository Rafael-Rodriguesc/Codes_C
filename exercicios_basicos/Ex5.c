//5. Calcular o dobro de um número

#include <stdio.h>

int main() {
    int numero, dobro;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    dobro = numero * 2;

    printf("O dobro do numero e: %d\n", dobro);

    return 0;
}