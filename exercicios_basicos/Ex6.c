//6. Verificar se o aluno foi aprovado

#include <stdio.h>

int main() {
    float media;

    printf("Digite a media do aluno: ");
    scanf("%f", &media);

    if (media >= 6) {
        printf("Aluno aprovado!\n");
    } else {
        printf("Aluno reprovado!\n");
    }

    return 0;
}