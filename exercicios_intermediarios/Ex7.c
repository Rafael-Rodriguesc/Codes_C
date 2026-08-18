//Calculadora com funções

#include <stdio.h>

float somar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    return a / b;
}

int main() {
    float num1, num2;
    int opcao;

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    printf("\n===== CALCULADORA =====\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Resultado: %.2f\n", somar(num1, num2));
            break;

        case 2:
            printf("Resultado: %.2f\n", subtrair(num1, num2));
            break;

        case 3:
            printf("Resultado: %.2f\n", multiplicar(num1, num2));
            break;

        case 4:
            if (num2 != 0) {
                printf("Resultado: %.2f\n", dividir(num1, num2));
            } else {
                printf("Nao e possivel dividir por zero.\n");
            }
            break;

        default:
            printf("Opcao invalida.\n");
    }

    return 0;
}