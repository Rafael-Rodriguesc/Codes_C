//Controle de temperaturas

#include <stdio.h>

int main() {

    float temperaturas[7];
    float soma = 0;
    float media;
    float maior, menor;
    int diaMaior = 0;
    int diaMenor = 0;
    int acimaMedia = 0;

    // Entrada das temperaturas
    for (int i = 0; i < 7; i++) {
        printf("Digite a temperatura do dia %d: ", i + 1);
        scanf("%f", &temperaturas[i]);

        soma += temperaturas[i];
    }

    // Calculando a media
    media = soma / 7;

    // Inicializando maior e menor
    maior = temperaturas[0];
    menor = temperaturas[0];

    // Encontrando maior e menor temperatura
    for (int i = 1; i < 7; i++) {

        if (temperaturas[i] > maior) {
            maior = temperaturas[i];
            diaMaior = i;
        }

        if (temperaturas[i] < menor) {
            menor = temperaturas[i];
            diaMenor = i;
        }
    }

    // Contando temperaturas acima da media
    for (int i = 0; i < 7; i++) {

        if (temperaturas[i] > media) {
            acimaMedia++;
        }
    }

    // Exibindo resultados
    printf("\nRESULTADO\n");

    printf("Temperatura media: %.2f graus\n", media);
    printf("Maior temperatura: %.2f graus - Dia %d\n", maior, diaMaior + 1);
    printf("Menor temperatura: %.2f graus - Dia %d\n", menor, diaMenor + 1);
    printf("Dias acima da media: %d\n", acimaMedia);

    return 0;
}