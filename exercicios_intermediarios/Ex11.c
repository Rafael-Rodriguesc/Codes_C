//Verificador de palíndromo

#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    int inicio, fim;
    int palindromo = 1;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    inicio = 0;
    fim = strlen(palavra) - 1;

    while (inicio < fim) {

        if (palavra[inicio] != palavra[fim]) {
            palindromo = 0;
            break;
        }

        inicio++;
        fim--;
    }

    if (palindromo) {
        printf("A palavra e um palindromo.\n");
    } else {
        printf("A palavra nao e um palindromo.\n");
    }

    return 0;
}