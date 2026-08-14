//8. Contador de números positivos e negativos

#include <stdio.h>

int main() {
    int numero;
    int positivos = 0;
    int negativos = 0;
    int zeros = 0;
    int i;

    for (i = 1; i <= 10; i++) {
        printf("Digite o %d numero: ", i);
        scanf("%d", &numero);

        if (numero > 0) {
            positivos++;
        } else if (numero < 0) {
            negativos++;
        } else {
            zeros++;
        }
    }

    printf("\nPositivos: %d\n", positivos);
    printf("Negativos: %d\n", negativos);
    printf("Zeros: %d\n", zeros);

    return 0;
}