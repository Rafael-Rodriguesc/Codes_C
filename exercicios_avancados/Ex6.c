//16. Jogo da Velha

#include <stdio.h>

void mostrarTabuleiro(char tabuleiro[3][3]) {
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", 
               tabuleiro[i][0], 
               tabuleiro[i][1], 
               tabuleiro[i][2]);

        if (i < 2) {
            printf("\n---+---+---\n");
        }
    }

    printf("\n");
}

int verificarVitoria(char tabuleiro[3][3], char jogador) {

    for (int i = 0; i < 3; i++) {

        if (tabuleiro[i][0] == jogador &&
            tabuleiro[i][1] == jogador &&
            tabuleiro[i][2] == jogador) {
            return 1;
        }

        if (tabuleiro[0][i] == jogador &&
            tabuleiro[1][i] == jogador &&
            tabuleiro[2][i] == jogador) {
            return 1;
        }
    }

    if (tabuleiro[0][0] == jogador &&
        tabuleiro[1][1] == jogador &&
        tabuleiro[2][2] == jogador) {
        return 1;
    }

    if (tabuleiro[0][2] == jogador &&
        tabuleiro[1][1] == jogador &&
        tabuleiro[2][0] == jogador) {
        return 1;
    }

    return 0;
}

int main() {

    char tabuleiro[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char jogador = 'X';
    int jogadas = 0;
    int posicao;
    int linha, coluna;

    while (jogadas < 9) {

        mostrarTabuleiro(tabuleiro);

        printf("\nJogador %c, escolha uma posicao: ", jogador);
        scanf("%d", &posicao);

        if (posicao < 1 || posicao > 9) {
            printf("Posicao invalida!\n");
            continue;
        }

        linha = (posicao - 1) / 3;
        coluna = (posicao - 1) % 3;

        if (tabuleiro[linha][coluna] == 'X' ||
            tabuleiro[linha][coluna] == 'O') {

            printf("Essa posicao ja esta ocupada!\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogador;
        jogadas++;

        if (verificarVitoria(tabuleiro, jogador)) {

            mostrarTabuleiro(tabuleiro);

            printf("\nJogador %c venceu!\n", jogador);

            return 0;
        }

        if (jogador == 'X') {
            jogador = 'O';
        } else {
            jogador = 'X';
        }
    }

    mostrarTabuleiro(tabuleiro);

    printf("\nEmpate!\n");

    return 0;
}