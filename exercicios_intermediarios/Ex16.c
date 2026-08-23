//Média das notas dos alunos

#include <stdio.h>

int main() {
    float nota1, nota2, media;
    int aprovados = 0;
    int reprovados = 0;
    float maiorMedia = 0;

    for (int i = 1; i <= 5; i++) {

        printf("\nAluno %d\n", i);

        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);

        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);

        media = (nota1 + nota2) / 2;

        printf("Media: %.2f\n", media);

        if (media >= 6) {
            printf("Aprovado!\n");
            aprovados++;
        } else {
            printf("Reprovado!\n");
            reprovados++;
        }

        if (media > maiorMedia) {
            maiorMedia = media;
        }
    }

    printf("\n===== RESULTADO DA TURMA =====\n");
    printf("Alunos aprovados: %d\n", aprovados);
    printf("Alunos reprovados: %d\n", reprovados);
    printf("Maior media: %.2f\n", maiorMedia);

    return 0;
}