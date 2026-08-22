// Contador de vogais

#include <stdio.h>
#include <ctype.h>

int main() {
    char texto[100];
    int vogais = 0;

    printf("Digite uma palavra ou frase: ");
    fgets(texto, 100, stdin);

    for (int i = 0; texto[i] != '\0'; i++) {

        char caractere = tolower(texto[i]);

        if (caractere == 'a' ||
            caractere == 'e' ||
            caractere == 'i' ||
            caractere == 'o' ||
            caractere == 'u') {

            vogais++;
        }
    }

    printf("Quantidade de vogais: %d\n", vogais);

    return 0;
}