//Sistema de vendas

#include <stdio.h>

#define PRODUTOS 5
#define DIAS 7

void cadastrarVendas(int vendas[PRODUTOS][DIAS]) {

    printf(" CADASTRO DE VENDAS \n");

    for (int i = 0; i < PRODUTOS; i++) {

        printf("\nProduto %d\n", i + 1);

        for (int j = 0; j < DIAS; j++) {

            printf("Quantidade vendida no dia %d: ", j + 1);
            scanf("%d", &vendas[i][j]);
        }
    }
}

void mostrarVendas(int vendas[PRODUTOS][DIAS]) {

    printf("\n TABELA DE VENDAS \n");

    printf("          ");

    for (int j = 0; j < DIAS; j++) {
        printf("Dia%d   ", j + 1);
    }

    printf("\n");

    for (int i = 0; i < PRODUTOS; i++) {

        printf("Produto %d ", i + 1);

        for (int j = 0; j < DIAS; j++) {
            printf("%6d ", vendas[i][j]);
        }

        printf("\n");
    }
}

void totalPorProduto(int vendas[PRODUTOS][DIAS]) {

    printf("\n TOTAL POR PRODUTO \n");

    for (int i = 0; i < PRODUTOS; i++) {

        int total = 0;

        for (int j = 0; j < DIAS; j++) {
            total += vendas[i][j];
        }

        printf("Produto %d: %d vendas\n", i + 1, total);
    }
}

void totalPorDia(int vendas[PRODUTOS][DIAS]) {

    printf("\nTOTAL POR DIA\n");

    for (int j = 0; j < DIAS; j++) {

        int total = 0;

        for (int i = 0; i < PRODUTOS; i++) {
            total += vendas[i][j];
        }

        printf("Dia %d: %d vendas\n", j + 1, total);
    }
}

void produtoMaisVendido(int vendas[PRODUTOS][DIAS]) {

    int maiorProduto = 0;
    int maiorTotal = 0;

    for (int i = 0; i < PRODUTOS; i++) {

        int total = 0;

        for (int j = 0; j < DIAS; j++) {
            total += vendas[i][j];
        }

        if (i == 0 || total > maiorTotal) {
            maiorTotal = total;
            maiorProduto = i;
        }
    }

    printf("\nPRODUTO MAIS VENDIDO\n");

    printf("Produto: %d\n", maiorProduto + 1);
    printf("Total vendido: %d unidades\n", maiorTotal);
}

void diaMaiorVenda(int vendas[PRODUTOS][DIAS]) {

    int maiorDia = 0;
    int maiorTotal = 0;

    for (int j = 0; j < DIAS; j++) {

        int total = 0;

        for (int i = 0; i < PRODUTOS; i++) {
            total += vendas[i][j];
        }

        if (j == 0 || total > maiorTotal) {
            maiorTotal = total;
            maiorDia = j;
        }
    }

    printf("\nDIA COM MAIS VENDAS \n");

    printf("Dia: %d\n", maiorDia + 1);
    printf("Total vendido: %d unidades\n", maiorTotal);
}

void totalGeral(int vendas[PRODUTOS][DIAS]) {

    int total = 0;

    for (int i = 0; i < PRODUTOS; i++) {

        for (int j = 0; j < DIAS; j++) {
            total += vendas[i][j];
        }
    }

    printf("\n TOTAL GERAL \n");
    printf("Total de unidades vendidas: %d\n", total);
}

int main() {

    int vendas[PRODUTOS][DIAS];
    int opcao;

    do {

        printf("\n==============================\n");
        printf("       SISTEMA DE VENDAS\n");
        printf("==============================\n");

        printf("1 - Cadastrar vendas\n");
        printf("2 - Mostrar vendas\n");
        printf("3 - Total por produto\n");
        printf("4 - Total por dia\n");
        printf("5 - Produto mais vendido\n");
        printf("6 - Dia com mais vendas\n");
        printf("7 - Total geral\n");
        printf("8 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                cadastrarVendas(vendas);
                break;

            case 2:
                mostrarVendas(vendas);
                break;

            case 3:
                totalPorProduto(vendas);
                break;

            case 4:
                totalPorDia(vendas);
                break;

            case 5:
                produtoMaisVendido(vendas);
                break;

            case 6:
                diaMaiorVenda(vendas);
                break;

            case 7:
                totalGeral(vendas);
                break;

            case 8:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 8);

    return 0;
}