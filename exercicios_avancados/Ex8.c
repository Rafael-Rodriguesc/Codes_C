//1. Ordenação e busca em vetor

#include <stdio.h>

void mostrar(int vetor[], int tamanho) {

    printf("\nVetor: ");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}

void ordenar(int vetor[], int tamanho) {

    int temp;

    for (int i = 0; i < tamanho - 1; i++) {

        for (int j = 0; j < tamanho - i - 1; j++) {

            if (vetor[j] > vetor[j + 1]) {

                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    printf("Vetor ordenado!\n");
}

int buscaBinaria(int vetor[], int tamanho, int valor) {

    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {

        int meio = (inicio + fim) / 2;

        if (vetor[meio] == valor) {
            return meio;
        }

        if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {

    int vetor[10];
    int opcao;
    int valor;
    int resultado;

    printf("Digite 10 numeros:\n");

    for (int i = 0; i < 10; i++) {
        printf("%d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    do {

        printf("\n===== MENU =====\n");
        printf("1 - Mostrar vetor\n");
        printf("2 - Ordenar vetor\n");
        printf("3 - Buscar numero\n");
        printf("4 - Mostrar maior e menor\n");
        printf("5 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                mostrar(vetor, 10);
                break;

            case 2:
                ordenar(vetor, 10);
                break;

            case 3:

                printf("Digite o numero que deseja buscar: ");
                scanf("%d", &valor);

                resultado = buscaBinaria(vetor, 10, valor);

                if (resultado != -1) {
                    printf("Numero encontrado na posicao %d.\n", resultado);
                } else {
                    printf("Numero nao encontrado.\n");
                }

                break;

            case 4:

                ordenar(vetor, 10);

                printf("Menor numero: %d\n", vetor[0]);
                printf("Maior numero: %d\n", vetor[9]);

                break;

            case 5:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}