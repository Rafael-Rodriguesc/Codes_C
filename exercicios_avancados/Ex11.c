//Sistema de gerenciamento de funcionários

#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    int id;
    char nome[50];
    int idade;
    float salario;
} Funcionario;

int buscarFuncionario(Funcionario funcionarios[], int quantidade, int id) {

    for (int i = 0; i < quantidade; i++) {

        if (funcionarios[i].id == id) {
            return i;
        }
    }

    return -1;
}

int cadastrarFuncionario(Funcionario funcionarios[], int quantidade) {

    if (quantidade >= MAX) {
        printf("\nLimite de funcionarios atingido!\n");
        return quantidade;
    }

    int id;

    printf("\nCADASTRO\n");

    printf("Digite o ID: ");
    scanf("%d", &id);

    if (buscarFuncionario(funcionarios, quantidade, id) != -1) {
        printf("Esse ID ja esta cadastrado!\n");
        return quantidade;
    }

    funcionarios[quantidade].id = id;

    printf("Digite o nome: ");
    scanf(" %[^\n]", funcionarios[quantidade].nome);

    printf("Digite a idade: ");
    scanf("%d", &funcionarios[quantidade].idade);

    printf("Digite o salario: ");
    scanf("%f", &funcionarios[quantidade].salario);

    printf("\nFuncionario cadastrado com sucesso!\n");

    return quantidade + 1;
}

void listarFuncionarios(Funcionario funcionarios[], int quantidade) {

    if (quantidade == 0) {
        printf("\nNenhum funcionario cadastrado.\n");
        return;
    }

    printf("\nFUNCIONARIOS\n");

    for (int i = 0; i < quantidade; i++) {

        printf("\nFuncionario %d\n", i + 1);
        printf("ID: %d\n", funcionarios[i].id);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Idade: %d\n", funcionarios[i].idade);
        printf("Salario: R$ %.2f\n", funcionarios[i].salario);
    }
}

void consultarFuncionario(Funcionario funcionarios[], int quantidade) {

    int id;

    printf("\nDigite o ID que deseja buscar: ");
    scanf("%d", &id);

    int posicao = buscarFuncionario(funcionarios, quantidade, id);

    if (posicao == -1) {
        printf("\nFuncionario nao encontrado.\n");
        return;
    }

    printf("\nFUNCIONARIO ENCONTRADO\n");
    printf("ID: %d\n", funcionarios[posicao].id);
    printf("Nome: %s\n", funcionarios[posicao].nome);
    printf("Idade: %d\n", funcionarios[posicao].idade);
    printf("Salario: R$ %.2f\n", funcionarios[posicao].salario);
}

// Altera o salario
void alterarSalario(Funcionario funcionarios[], int quantidade) {

    int id;
    float novoSalario;

    printf("\nDigite o ID do funcionario: ");
    scanf("%d", &id);

    int posicao = buscarFuncionario(funcionarios, quantidade, id);

    if (posicao == -1) {
        printf("Funcionario nao encontrado.\n");
        return;
    }

    printf("Funcionario: %s\n", funcionarios[posicao].nome);
    printf("Salario atual: R$ %.2f\n", funcionarios[posicao].salario);

    printf("Digite o novo salario: ");
    scanf("%f", &novoSalario);

    funcionarios[posicao].salario = novoSalario;

    printf("\nSalario alterado com sucesso!\n");
}

int excluirFuncionario(Funcionario funcionarios[], int quantidade) {

    int id;

    printf("\nDigite o ID do funcionario que deseja excluir: ");
    scanf("%d", &id);

    int posicao = buscarFuncionario(funcionarios, quantidade, id);

    if (posicao == -1) {
        printf("Funcionario nao encontrado.\n");
        return quantidade;
    }

    for (int i = posicao; i < quantidade - 1; i++) {
        funcionarios[i] = funcionarios[i + 1];
    }

    printf("\nFuncionario excluido com sucesso!\n");

    return quantidade - 1;
}

void maiorSalario(Funcionario funcionarios[], int quantidade) {

    if (quantidade == 0) {
        printf("\nNenhum funcionario cadastrado.\n");
        return;
    }

    int posicaoMaior = 0;

    for (int i = 1; i < quantidade; i++) {

        if (funcionarios[i].salario > funcionarios[posicaoMaior].salario) {
            posicaoMaior = i;
        }
    }

    printf("\nMAIOR SALARIO\n");
    printf("ID: %d\n", funcionarios[posicaoMaior].id);
    printf("Nome: %s\n", funcionarios[posicaoMaior].nome);
    printf("Idade: %d\n", funcionarios[posicaoMaior].idade);
    printf("Salario: R$ %.2f\n", funcionarios[posicaoMaior].salario);
}

int main() {

    Funcionario funcionarios[MAX];

    int quantidade = 0;
    int opcao;

    do {
        printf(" SISTEMA DE FUNCIONARIOS\n");

        printf("1 - Cadastrar funcionario\n");
        printf("2 - Listar funcionarios\n");
        printf("3 - Buscar funcionario\n");
        printf("4 - Alterar salario\n");
        printf("5 - Excluir funcionario\n");
        printf("6 - Maior salario\n");
        printf("7 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                quantidade = cadastrarFuncionario(funcionarios, quantidade);
                break;

            case 2:
                listarFuncionarios(funcionarios, quantidade);
                break;

            case 3:
                consultarFuncionario(funcionarios, quantidade);
                break;

            case 4:
                alterarSalario(funcionarios, quantidade);
                break;

            case 5:
                quantidade = excluirFuncionario(funcionarios, quantidade);
                break;

            case 6:
                maiorSalario(funcionarios, quantidade);
                break;

            case 7:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 7);

    return 0;
}