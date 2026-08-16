//13. Sistema de cadastro com arquivos

#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

void cadastrar() {
    struct Pessoa pessoa;
    FILE *arquivo;

    arquivo = fopen("pessoas.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\nNome: ");
    scanf(" %[^\n]", pessoa.nome);

    printf("Idade: ");
    scanf("%d", &pessoa.idade);

    fprintf(arquivo, "%s;%d\n", pessoa.nome, pessoa.idade);

    fclose(arquivo);

    printf("Pessoa cadastrada com sucesso!\n");
}

void listar() {
    FILE *arquivo;
    char nome[50];
    int idade;

    arquivo = fopen("pessoas.txt", "r");

    if (arquivo == NULL) {
        printf("Nenhuma pessoa cadastrada.\n");
        return;
    }

    printf("\n===== PESSOAS CADASTRADAS =====\n");

    while (fscanf(arquivo, " %49[^;];%d", nome, &idade) == 2) {
        printf("Nome: %s | Idade: %d\n", nome, idade);
    }

    fclose(arquivo);
}

void buscar() {
    FILE *arquivo;
    char nome[50];
    char busca[50];
    int idade;
    int encontrado = 0;

    arquivo = fopen("pessoas.txt", "r");

    if (arquivo == NULL) {
        printf("Nenhuma pessoa cadastrada.\n");
        return;
    }

    printf("\nDigite o nome para buscar: ");
    scanf(" %[^\n]", busca);

    while (fscanf(arquivo, " %49[^;];%d", nome, &idade) == 2) {

        if (strcmp(nome, busca) == 0) {
            printf("\nPessoa encontrada!\n");
            printf("Nome: %s\n", nome);
            printf("Idade: %d\n", idade);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Pessoa nao encontrada.\n");
    }

    fclose(arquivo);
}

int main() {
    int opcao;

    do {
        printf("\n===== SISTEMA =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar();
                break;

            case 2:
                listar();
                break;

            case 3:
                buscar();
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 4);

    return 0;
}