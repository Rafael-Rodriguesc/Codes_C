//Jogo de adivinhação

#include <stdio.h>

int main() {
    int numeroSecreto = 73;
    int tentativa;
    int tentativas = 0;

    printf("JOGO DE ADIVINHACAO\n");
    printf("Tente descobrir o numero entre 1 e 100!\n");

    do {
        printf("\nDigite sua tentativa: ");
        scanf("%d", &tentativa);

        tentativas++;

        if (tentativa > numeroSecreto) {
            printf("Muito alto!");
        } else if (tentativa < numeroSecreto) {
            printf("Muito baixo!");
        } else {
            printf("Acertou!");
        }

    } while (tentativa != numeroSecreto);

    printf("\nVoce precisou de %d tentativa(s).\n", tentativas);

    return 0;
}