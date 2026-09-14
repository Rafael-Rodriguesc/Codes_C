/* submódulo de segurança de um Rover de exploração autônoma. O
veículo escaneia o terreno à sua frente e gera uma grade topográfica de elevações.
Neste desafio, o seu objetivo é implementar um algoritmo de "Área de influência de risco"
utilizando matrizes na linguagem C */

#include <stdio.h>

void gerar_mapa_risco(int mapa[][5], int cratera, int pico)
{
    int risco[5][5];
    int linha, coluna;
    int i, j;
    int seguro;
    int zonasSeguras = 0;

    // identifica os riscos 2
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {

            if (mapa[linha][coluna] < cratera ||
                mapa[linha][coluna] > pico) {
                risco[linha][coluna] = 2;
            }
            else {
                risco[linha][coluna] = 0;
            }
        }
    }

    // identifica os riscos 1
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {

            if (risco[linha][coluna] == 0) {
                seguro = 1;

                for (i = linha - 1; i <= linha + 1; i++) {
                    for (j = coluna - 1; j <= coluna + 1; j++) {

                        if (i >= 0 && i < 5 &&
                            j >= 0 && j < 5) {

                            if (risco[i][j] == 2) {
                                seguro = 0;
                            }
                        }
                    }
                }

                if (seguro == 0) {
                    risco[linha][coluna] = 1;
                }
            }
        }
    }

    // imprime o mapa e conta os riscos 0
    printf("\nMapa de Risco Gerado:\n");

    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {

            printf("%d ", risco[linha][coluna]);

            if (risco[linha][coluna] == 0) {
                zonasSeguras++;
            }
        }

        printf("\n");
    }

    printf("Zonas Totalmente Seguras: %d\n", zonasSeguras);
}

int main()
{
    int mapa[5][5];
    int cratera, pico;
    int linha, coluna;

    // lê os limites
    printf("Digite o limite de cratera: ");
    scanf("%d", &cratera);

    printf("Digite o limite de pico: ");
    scanf("%d", &pico);

    // lê o mapa
    printf("Digite as altitudes do terreno:\n");

    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            scanf("%d", &mapa[linha][coluna]);
        }
    }

    gerar_mapa_risco(mapa, cratera, pico);

    return 0;
}
```
