//Safedrive - Processamento de telemetria ADAS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_AMOSTRAS 100
#define AMOSTRAS_INICIAIS 50

// Carrega 50 amostras aleatorias
void inicializarDados(
    double velocidades[][2],
    double sensores_frontais[][3],
    double sensores_laterais[][2],
    double processamento[][2],
    int status[][3]
) {
    int i;

    for (i = 0; i < AMOSTRAS_INICIAIS; i++) {
        velocidades[i][0] = 40 + rand() % 81;
        velocidades[i][1] = 40 + rand() % 81;

        sensores_frontais[i][0] = 10 + rand() % 91;
        sensores_frontais[i][1] = 10 + rand() % 91;
        sensores_frontais[i][2] = 10 + rand() % 91;

        sensores_laterais[i][0] =
            (10 + rand() % 141) / 100.0;

        sensores_laterais[i][1] =
            (10 + rand() % 141) / 100.0;

        processamento[i][0] = 0;
        processamento[i][1] = 0;

        status[i][0] = 0;
        status[i][1] = 0;
        status[i][2] = 0;
    }
}

// Calcula a mediana dos sensores
double calcularMediana(double a, double b, double c) {
    if ((a >= b && a <= c) || (a >= c && a <= b))
        return a;

    if ((b >= a && b <= c) || (b >= c && b <= a))
        return b;

    return c;
}

// Faz a fusao dos sensores
void fusaoSensores(
    double sensores_frontais[][3],
    double processamento[][2],
    int quantidade
) {
    int i;

    for (i = 0; i < quantidade; i++) {
        processamento[i][0] = calcularMediana(
            sensores_frontais[i][0],
            sensores_frontais[i][1],
            sensores_frontais[i][2]
        );
    }
}

// Calcula a distancia segura
void calcularDistanciaSegura(
    double velocidades[][2],
    double processamento[][2],
    double atrito,
    int sensibilidade,
    int quantidade
) {
    int i;
    double tempoReacao;
    double velocidade;

    if (sensibilidade == 1)
        tempoReacao = 1.0;
    else if (sensibilidade == 2)
        tempoReacao = 1.5;
    else
        tempoReacao = 2.0;

    for (i = 0; i < quantidade; i++) {
        velocidade = velocidades[i][0] / 3.6;

        processamento[i][1] =
            (velocidade * tempoReacao) +
            ((velocidade * velocidade) /
            (2.0 * atrito * 9.81));
    }
}

// Analisa o risco frontal
void analisarRiscoFrontal(
    double velocidades[][2],
    double processamento[][2],
    int status[][3],
    int quantidade
) {
    int i;
    double velocidadeRelativa;

    for (i = 0; i < quantidade; i++) {
        velocidadeRelativa =
            velocidades[i][0] - velocidades[i][1];

        if (velocidadeRelativa <= 0) {
            status[i][0] = 0;
        }
        else if (processamento[i][0] >= processamento[i][1]) {
            status[i][0] = 0;
        }
        else if (processamento[i][0] >=
                 processamento[i][1] * 0.50) {
            status[i][0] = 1;
        }
        else {
            status[i][0] = 2;
        }
    }
}

// Analisa as faixas
void analisarFaixas(
    double velocidades[][2],
    double sensores_laterais[][2],
    int status[][3],
    int quantidade
) {
    int i;
    double margem;

    for (i = 0; i < quantidade; i++) {
        margem = 0.50;

        if (velocidades[i][0] > 80)
            margem += (velocidades[i][0] - 80) * 0.01;

        if (sensores_laterais[i][0] < margem)
            status[i][1] = 2;
        else if (sensores_laterais[i][0] < margem + 0.20)
            status[i][1] = 1;
        else
            status[i][1] = 0;

        if (sensores_laterais[i][1] < margem)
            status[i][2] = 2;
        else if (sensores_laterais[i][1] < margem + 0.20)
            status[i][2] = 1;
        else
            status[i][2] = 0;
    }
}

// Exibe o relatorio
void exibirRelatorio(
    double velocidades[][2],
    double sensores_frontais[][3],
    double sensores_laterais[][2],
    double processamento[][2],
    int status[][3],
    int quantidade
) {
    int i;
    int maiorRisco;

    printf("\n========== SAFEDRIVE - RELATORIO ==========\n");

    for (i = 0; i < quantidade; i++) {

        printf("\n----------- AMOSTRA %d -----------\n", i + 1);

        printf("\n[DADOS DE ENTRADA]\n");
        printf("Velocidade atual: %.2f km/h\n",
               velocidades[i][0]);
        printf("Velocidade a frente: %.2f km/h\n",
               velocidades[i][1]);

        printf("\nSensores frontais:\n");
        printf("Radar: %.2f m\n",
               sensores_frontais[i][0]);
        printf("Lidar: %.2f m\n",
               sensores_frontais[i][1]);
        printf("Camera: %.2f m\n",
               sensores_frontais[i][2]);

        printf("\nSensores laterais:\n");
        printf("Faixa esquerda: %.2f m\n",
               sensores_laterais[i][0]);
        printf("Faixa direita: %.2f m\n",
               sensores_laterais[i][1]);

        printf("\n[DADOS PROCESSADOS]\n");
        printf("Distancia validada: %.2f m\n",
               processamento[i][0]);
        printf("Distancia segura: %.2f m\n",
               processamento[i][1]);

        printf("\n[STATUS FRONTAL]\n");

        if (status[i][0] == 0)
            printf("SEGURO\n");
        else if (status[i][0] == 1)
            printf("ATENCAO\n");
        else
            printf("RISCO DE COLISAO (AEB ACIONADO)\n");

        printf("\n[FAIXAS]\n");

        printf("Esquerda: ");
        if (status[i][1] == 0)
            printf("NORMAL\n");
        else if (status[i][1] == 1)
            printf("ATENCAO\n");
        else
            printf("PERIGO DE INVASAO\n");

        printf("Direita: ");
        if (status[i][2] == 0)
            printf("NORMAL\n");
        else if (status[i][2] == 1)
            printf("ATENCAO\n");
        else
            printf("PERIGO DE INVASAO\n");

        maiorRisco = status[i][0];

        if (status[i][1] > maiorRisco)
            maiorRisco = status[i][1];

        if (status[i][2] > maiorRisco)
            maiorRisco = status[i][2];

        printf("\n[STATUS GERAL]\n");

        if (maiorRisco == 2)
            printf("STATUS GERAL: INTERVENCAO CRITICA EXIGIDA\n");
        else if (maiorRisco == 1)
            printf("STATUS GERAL: ATENCAO\n");
        else
            printf("STATUS GERAL: NORMAL\n");
    }

    printf("\n============================================\n");
}


// Funcao principal
int main() {
    double velocidades[MAX_AMOSTRAS][2];
    double sensores_frontais[MAX_AMOSTRAS][3];
    double sensores_laterais[MAX_AMOSTRAS][2];
    double processamento[MAX_AMOSTRAS][2];
    int status[MAX_AMOSTRAS][3];

    double atrito;
    int sensibilidade;
    int opcao;
    int quantidade = 0;

    srand(time(NULL));

    // Configuracoes iniciais
    printf("Informe o atrito da via: ");
    scanf("%lf", &atrito);

    while (atrito <= 0) {
        printf("Atrito invalido. Informe novamente: ");
        scanf("%lf", &atrito);
    }

    printf("\n1 - Esportivo\n");
    printf("2 - Normal\n");
    printf("3 - Seguro\n");
    printf("Sensibilidade: ");
    scanf("%d", &sensibilidade);

    while (sensibilidade < 1 || sensibilidade > 3) {
        printf("Opcao invalida. Informe 1, 2 ou 3: ");
        scanf("%d", &sensibilidade);
    }

    // Menu principal
    do {
        printf("\n========== SAFEDRIVE ==========\n");
        printf("1 - Carregar dados iniciais\n");
        printf("2 - Inserir nova amostra\n");
        printf("3 - Processar e exibir relatorio\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {

            inicializarDados(
                velocidades,
                sensores_frontais,
                sensores_laterais,
                processamento,
                status
            );

            quantidade = AMOSTRAS_INICIAIS;

            printf("50 amostras carregadas.\n");
        }

        else if (opcao == 2) {

            if (quantidade >= MAX_AMOSTRAS) {
                printf("Limite de 100 amostras atingido.\n");
            }
            else {
                printf("\n--- Nova amostra ---\n");

                printf("Velocidade atual: ");
                scanf("%lf", &velocidades[quantidade][0]);

                printf("Velocidade a frente: ");
                scanf("%lf", &velocidades[quantidade][1]);

                printf("Radar: ");
                scanf("%lf", &sensores_frontais[quantidade][0]);

                printf("Lidar: ");
                scanf("%lf", &sensores_frontais[quantidade][1]);

                printf("Camera: ");
                scanf("%lf", &sensores_frontais[quantidade][2]);

                printf("Faixa esquerda: ");
                scanf("%lf", &sensores_laterais[quantidade][0]);

                printf("Faixa direita: ");
                scanf("%lf", &sensores_laterais[quantidade][1]);

                quantidade++;

                printf("Amostra inserida.\n");
            }
        }

        else if (opcao == 3) {

            if (quantidade == 0) {
                printf("Nenhuma amostra cadastrada.\n");
            }
            else {
                fusaoSensores(
                    sensores_frontais,
                    processamento,
                    quantidade
                );

                calcularDistanciaSegura(
                    velocidades,
                    processamento,
                    atrito,
                    sensibilidade,
                    quantidade
                );

                analisarRiscoFrontal(
                    velocidades,
                    processamento,
                    status,
                    quantidade
                );

                analisarFaixas(
                    velocidades,
                    sensores_laterais,
                    status,
                    quantidade
                );

                exibirRelatorio(
                    velocidades,
                    sensores_frontais,
                    sensores_laterais,
                    processamento,
                    status,
                    quantidade
                );
            }
        }

        else if (opcao == 4) {
            printf("Encerrando o SafeDrive...\n");
        }

        else {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 4);

    return 0;
}