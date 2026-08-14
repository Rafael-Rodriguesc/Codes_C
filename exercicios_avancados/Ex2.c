//11. Cadastro de alunos usando struct

#include <stdio.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    struct Aluno alunos[5];

    int i;
    int maiorNota = 0;

    // Cadastro
    for (i = 0; i < 5; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("Idade: ");
        scanf("%d", &alunos[i].idade);

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }

    // Encontrar maior nota
    for (i = 1; i < 5; i++) {
        if (alunos[i].nota > alunos[maiorNota].nota) {
            maiorNota = i;
        }
    }

    // Exibir alunos
    printf("\n===== ALUNOS =====\n");

    for (i = 0; i < 5; i++) {
        printf("\nNome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n", alunos[i].nota);
    }

    printf("\n===== MAIOR NOTA =====\n");
    printf("Aluno: %s\n", alunos[maiorNota].nome);
    printf("Nota: %.2f\n", alunos[maiorNota].nota);

    return 0;
}