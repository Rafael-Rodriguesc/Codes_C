//Conversor de minutos

#include <stdio.h>

int main() {

    int minutos;
    int horas;
    int minutosRestantes;

    printf("Digite a quantidade de minutos: ");
    scanf("%d", &minutos);

    horas = minutos / 60;
    minutosRestantes = minutos % 60;

    printf("%d horas e %d minutos\n", horas, minutosRestantes);

    return 0;
}