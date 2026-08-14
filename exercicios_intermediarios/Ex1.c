//9. Menu de operações

#include <stdio.h>

int main() {
    float num1, num2, resultado;
    int opcao;

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    printf("\n===== MENU =====\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            resultado = num1 + num2;
            printf("Resultado: %.2f\n", resultado);
            break;

        case 2:
            resultado = num1 - num2;
            printf("Resultado: %.2f\n", resultado);
            break;

        case 3:
            resultado = num1 * num2;
            printf("Resultado: %.2f\n", resultado);
            break;

        case 4:
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("Resultado: %.2f\n", resultado);
            } else {
                printf("Nao e possivel dividir por zero.\n");
            }
            break;

        default:
            printf("Opcao invalida.\n");
    }

    return 0;
}