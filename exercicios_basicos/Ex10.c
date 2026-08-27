//Converter metros para centímetros

#include <stdio.h>

int main() {
    float metros, centimetros;

    printf("Digite a medida em metros: ");
    scanf("%f", &metros);

    centimetros = metros * 100;

    printf("A medida em centimetros e: %.2f\n", centimetros);

    return 0;
}