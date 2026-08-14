//12. Sistema bancário simples

#include <stdio.h>

void mostrarMenu() {
    printf("\n===== BANCO =====\n");
    printf("1 - Consultar saldo\n");
    printf("2 - Depositar\n");
    printf("3 - Sacar\n");
    printf("4 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int opcao;
    float saldo = 0;
    float valor;

    do {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("\nSaldo atual: R$ %.2f\n", saldo);
                break;

            case 2:
                printf("\nDigite o valor do deposito: R$ ");
                scanf("%f", &valor);

                if (valor > 0) {
                    saldo += valor;
                    printf("Deposito realizado!\n");
                    printf("Novo saldo: R$ %.2f\n", saldo);
                } else {
                    printf("Valor invalido.\n");
                }

                break;

            case 3:
                printf("\nDigite o valor do saque: R$ ");
                scanf("%f", &valor);

                if (valor <= 0) {
                    printf("Valor invalido.\n");
                } else if (valor > saldo) {
                    printf("Saldo insuficiente.\n");
                } else {
                    saldo -= valor;
                    printf("Saque realizado!\n");
                    printf("Novo saldo: R$ %.2f\n", saldo);
                }

                break;

            case 4:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}