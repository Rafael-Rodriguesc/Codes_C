//Soma e média dos números positivos

#include <stdio.h>

int main() {
    int numero;
    int positivos = 0;
    int negativos = 0;
    int somaPositivos = 0;
    float media;

    for (int i = 1; i <= 10; i++) {
        printf("Digite o %d numero: ", i);
        scanf("%d", &numero);

        if (numero > 0) {
            positivos++;
            somaPositivos += numero;
        } else if (numero < 0) {
            negativos++;
        }
    }

    printf("\nRESULTADO\n");
    printf("Quantidade de positivos: %d\n", positivos);
    printf("Soma dos positivos: %d\n", somaPositivos);
    printf("Quantidade de negativos: %d\n", negativos);

    if (positivos > 0) {
        media = (float)somaPositivos / positivos;
        printf("Media dos positivos: %.2f\n", media);
    } else {
        printf("Nao existem numeros positivos para calcular a media.\n");
    }

    return 0;
}