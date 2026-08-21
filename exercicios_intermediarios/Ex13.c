//Sequência de Fibonacci

#include <stdio.h>

int main() {
    int n;
    int primeiro = 0;
    int segundo = 1;
    int proximo;

    printf("Digite a quantidade de termos: ");
    scanf("%d", &n);

    printf("Fibonacci: ");

    for (int i = 1; i <= n; i++) {
        printf("%d ", primeiro);

        proximo = primeiro + segundo;
        primeiro = segundo;
        segundo = proximo;
    }

    printf("\n");

    return 0;
}