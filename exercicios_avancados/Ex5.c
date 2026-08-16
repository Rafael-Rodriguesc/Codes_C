//14. Gerenciador de tarefas com ponteiros

#include <stdio.h>

struct Tarefa {
    char descricao[100];
    int prioridade;
    int concluida;
};

void concluirTarefa(struct Tarefa *tarefa) {
    tarefa->concluida = 1;
}

void listarTarefas(struct Tarefa tarefas[], int quantidade) {
    int i;

    printf("\n===== TAREFAS =====\n");

    for (i = 0; i < quantidade; i++) {
        printf("\n%d - %s\n", i + 1, tarefas[i].descricao);
        printf("Prioridade: %d\n", tarefas[i].prioridade);

        if (tarefas[i].concluida) {
            printf("Status: Concluida\n");
        } else {
            printf("Status: Pendente\n");
        }
    }
}

int main() {
    struct Tarefa tarefas[10];

    int quantidade = 0;
    int opcao;
    int numero;

    do {
        printf("\n===== GERENCIADOR =====\n");
        printf("1 - Adicionar tarefa\n");
        printf("2 - Listar tarefas\n");
        printf("3 - Concluir tarefa\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                if (quantidade >= 10) {
                    printf("Limite de tarefas atingido.\n");
                    break;
                }

                printf("Descricao: ");
                scanf(" %[^\n]", tarefas[quantidade].descricao);

                printf("Prioridade (1-5): ");
                scanf("%d", &tarefas[quantidade].prioridade);

                tarefas[quantidade].concluida = 0;

                quantidade++;

                printf("Tarefa adicionada!\n");

                break;

            case 2:

                listarTarefas(tarefas, quantidade);

                break;

            case 3:

                if (quantidade == 0) {
                    printf("Nenhuma tarefa cadastrada.\n");
                    break;
                }

                listarTarefas(tarefas, quantidade);

                printf("\nQual tarefa deseja concluir? ");
                scanf("%d", &numero);

                if (numero >= 1 && numero <= quantidade) {
                    concluirTarefa(&tarefas[numero - 1]);
                    printf("Tarefa concluida!\n");
                } else {
                    printf("Tarefa invalida.\n");
                }

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