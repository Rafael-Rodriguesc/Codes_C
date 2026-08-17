//Celsius para Fahrenheit

#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("Temperatura em Fahrenheit: %.2f\n", fahrenheit);

    return 0;
}