//Sistema de Estoque

#include <stdio.h>
#include <string.h>

struct Produto {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
};

void cadastrar(struct Produto produtos[], int *total) {

    if (*total >= 20) {
        printf("Estoque cheio!\n");
        return;
    }

    printf("\nCodigo: ");
    scanf("%d", &produtos[*total].codigo);

    printf("Nome: ");
    scanf(" %[^\n]", produtos[*total].nome);

    printf("Quantidade: ");
    scanf("%d", &produtos[*total].quantidade);

    printf("Preco: ");
    scanf("%f", &produtos[*total].preco);

    (*total)++;

    printf("Produto cadastrado!\n");
}

void listar(struct Produto produtos[], int total) {

    if (total == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\n===== ESTOQUE =====\n");

    for (int i = 0; i < total; i++) {

        printf("\nCodigo: %d\n", produtos[i].codigo);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
    }
}

void buscar(struct Produto produtos[], int total) {

    int codigo;
    int encontrado = 0;

    printf("\nDigite o codigo: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++) {

        if (produtos[i].codigo == codigo) {

            printf("\nProduto encontrado!\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            printf("Preco: R$ %.2f\n", produtos[i].preco);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }
}

void alterarQuantidade(struct Produto produtos[], int total) {

    int codigo;
    int novaQuantidade;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total; i++) {

        if (produtos[i].codigo == codigo) {

            printf("Nova quantidade: ");
            scanf("%d", &novaQuantidade);

            produtos[i].quantidade = novaQuantidade;

            printf("Quantidade atualizada!\n");

            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

int main() {

    struct Produto produtos[20];

    int total = 0;
    int opcao;

    do {

        printf("\n===== SISTEMA DE ESTOQUE =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto\n");
        printf("4 - Alterar quantidade\n");
        printf("5 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                cadastrar(produtos, &total);
                break;

            case 2:
                listar(produtos, total);
                break;

            case 3:
                buscar(produtos, total);
                break;

            case 4:
                alterarQuantidade(produtos, total);
                break;

            case 5:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}