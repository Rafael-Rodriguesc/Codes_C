//Sistema de gerenciamento de alunos

#include <stdio.h>

struct Aluno {
    char nome[50];
    int matricula;
    float notas[3];
    float media;
};

void calcularMedia(struct Aluno *aluno) {
    aluno->media = (aluno->notas[0] +
                    aluno->notas[1] +
                    aluno->notas[2]) / 3;
}

void cadastrarAluno(struct Aluno alunos[], int *total) {

    if (*total >= 10) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    printf("\nNome: ");
    scanf(" %[^\n]", alunos[*total].nome);

    printf("Matricula: ");
    scanf("%d", &alunos[*total].matricula);

    for (int i = 0; i < 3; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &alunos[*total].notas[i]);
    }

    calcularMedia(&alunos[*total]);

    (*total)++;

    printf("Aluno cadastrado com sucesso!\n");
}

void listarAlunos(struct Aluno alunos[], int total) {

    if (total == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n===== ALUNOS =====\n");

    for (int i = 0; i < total; i++) {

        printf("\nNome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Media: %.2f\n", alunos[i].media);

        if (alunos[i].media >= 7) {
            printf("Situacao: Aprovado\n");
        } else if (alunos[i].media >= 5) {
            printf("Situacao: Recuperacao\n");
        } else {
            printf("Situacao: Reprovado\n");
        }
    }
}

void buscarAluno(struct Aluno alunos[], int total) {

    int matricula;

    printf("Digite a matricula: ");
    scanf("%d", &matricula);

    for (int i = 0; i < total; i++) {

        if (alunos[i].matricula == matricula) {

            printf("\nAluno encontrado!\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Media: %.2f\n", alunos[i].media);

            return;
        }
    }

    printf("Aluno nao encontrado.\n");
}

void maiorMedia(struct Aluno alunos[], int total) {

    if (total == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int posicao = 0;

    for (int i = 1; i < total; i++) {

        if (alunos[i].media > alunos[posicao].media) {
            posicao = i;
        }
    }

    printf("\n===== MAIOR MEDIA =====\n");
    printf("Aluno: %s\n", alunos[posicao].nome);
    printf("Matricula: %d\n", alunos[posicao].matricula);
    printf("Media: %.2f\n", alunos[posicao].media);
}

void mediaTurma(struct Aluno alunos[], int total) {

    if (total == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    float soma = 0;

    for (int i = 0; i < total; i++) {
        soma += alunos[i].media;
    }

    printf("Media da turma: %.2f\n", soma / total);
}

int main() {

    struct Aluno alunos[10];

    int total = 0;
    int opcao;

    do {

        printf("===== SISTEMA DE ALUNOS =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno\n");
        printf("4 - Mostrar maior media\n");
        printf("5 - Media da turma\n");
        printf("6 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                cadastrarAluno(alunos, &total);
                break;

            case 2:
                listarAlunos(alunos, total);
                break;

            case 3:
                buscarAluno(alunos, total);
                break;

            case 4:
                maiorMedia(alunos, total);
                break;

            case 5:
                mediaTurma(alunos, total);
                break;

            case 6:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 6);

    return 0;
}