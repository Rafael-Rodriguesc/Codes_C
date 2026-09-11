// Sistema de telemetria e despacho de frota (Logística)

#include <stdio.h>

#define LIMITE 20
#define VEICULOS_INICIAIS 4

void calcular_autonomia(float combustivel[], float eficiencia[],
                        float autonomia[], int n) {
    for (int i = 0; i < n; i++) {
        autonomia[i] = combustivel[i] * eficiencia[i];
    }
}

void relatorio_frota(int ids[], float combustivel[], float eficiencia[],
                     float autonomia[], int n, float distancia_alvo) {

    // Calcula a autonomia de todos os veículos
    calcular_autonomia(combustivel, eficiencia, autonomia, n);

    // Exibe o relatório
    for (int i = 0; i < n; i++) {
        if (autonomia[i] >= distancia_alvo) {
            printf("Veiculo %d - Autonomia: %.2f km - STATUS: AUTORIZADO\n",
                   ids[i], autonomia[i]);
        } else {
            printf("Veiculo %d - Autonomia: %.2f km - STATUS: REJEITADO\n",
                   ids[i], autonomia[i]);
        }
    }
}

int main() {

    // Vetores estáticos paralelos
    int ids[LIMITE] = {101, 102, 103, 104};

    float combustivel[LIMITE] = {
        300.0, 250.0, 400.0, 350.0
    };

    float eficiencia[LIMITE] = {
        2.5, 3.0, 2.0, 2.8
    };

    float autonomia[LIMITE];

    int n_novos;
    int total;
    float distancia_alvo;

    // Entrada da quantidade de novos veículos
    printf("Digite a quantidade de novos caminhoes: ");
    scanf("%d", &n_novos);

    // Verificação do limite do vetor
    if (n_novos < 0 || VEICULOS_INICIAIS + n_novos > LIMITE) {
        printf("Quantidade invalida. O limite da frota e de %d veiculos.\n",
               LIMITE);
        return 1;
    }

    // Cadastro dos novos veículos
    for (int i = VEICULOS_INICIAIS; i < VEICULOS_INICIAIS + n_novos; i++) {

        printf("\nCadastro do veiculo %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &ids[i]);

        printf("Nivel de combustivel (litros): ");
        scanf("%f", &combustivel[i]);

        printf("Eficiencia (km/l): ");
        scanf("%f", &eficiencia[i]);
    }

    // Total de veículos válidos
    total = VEICULOS_INICIAIS + n_novos;

    // Distância do trajeto
    printf("\nDigite a distancia do trajeto alvo (km): ");
    scanf("%f", &distancia_alvo);

    // Relatório final
    printf("\n===== RELATORIO DA FROTA =====\n");

    relatorio_frota(
        ids,
        combustivel,
        eficiencia,
        autonomia,
        total,
        distancia_alvo
    );

    return 0;
}