#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRAS 1000
#define MAX_TAM 100
#define MAX_STOP 1000

char dicionario[MAX_PALAVRAS][MAX_TAM];
int freq[MAX_PALAVRAS];
int total = 0;

char stopWords[MAX_STOP][MAX_TAM];
int totalStop = 0;

// Busca binaria recursiva.
int buscaBinaria(const char *palavra, int ini, int fim) {
    if (ini > fim)
        return -ini - 1;

    int meio = (ini + fim) / 2;
    int cmp = strcmp(palavra, dicionario[meio]);

    if (cmp == 0)
        return meio;
    if (cmp < 0)
        return buscaBinaria(palavra, ini, meio - 1);
    return buscaBinaria(palavra, meio + 1, fim);
}

// Insercao ordenada
void inserirOrdenado(const char *palavra, int pos) {
    for (int i = total; i > pos; i--) {
        strcpy(dicionario[i], dicionario[i - 1]);
        freq[i] = freq[i - 1];
    }
    strcpy(dicionario[pos], palavra);
    freq[pos] = 1;
    total++;
}

int ehStopWord(const char *palavra) {
    for (int i = 0; i < totalStop; i++)
        if (strcmp(palavra, stopWords[i]) == 0)
            return 1;
    return 0;
}

void processarPalavra(const char *palavra) {
    if (palavra[0] == '\0' || ehStopWord(palavra))
        return;

    int r = buscaBinaria(palavra, 0, total - 1);
    if (r >= 0) {
        freq[r]++;
    } else if (total < MAX_PALAVRAS) {
        inserirOrdenado(palavra, -(r + 1));
    }
}

int main(void) {
    char linha[MAX_TAM * 2];

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        int j = 0;
        char palavra[MAX_TAM];
        for (int i = 0; linha[i] != '\0' && j < MAX_TAM - 1; i++)
            if (isalpha((unsigned char)linha[i]))
                palavra[j++] = (char)tolower((unsigned char)linha[i]);
        palavra[j] = '\0';

        if (j == 0)          // linha em branco: fim das stop words
            break;
        if (totalStop < MAX_STOP)
            strcpy(stopWords[totalStop++], palavra);
    }

    //Le o texto caractere a caractere, formando as palavras
    char palavra[MAX_TAM];
    int tam = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (isalpha((unsigned char)c)) {
            if (tam < MAX_TAM - 1)
                palavra[tam++] = (char)tolower((unsigned char)c);
        } else {
            palavra[tam] = '\0';
            processarPalavra(palavra);
            tam = 0;
        }
    }
    palavra[tam] = '\0';
    processarPalavra(palavra);   // ultima palavra, se o texto nao termina em separador


    for (int i = 0; i < total; i++)
        printf("%s, %d\n", dicionario[i], freq[i]);

    printf("\ntotal de palavras diferentes no dicionario = %d\n", total);
    
    return 0;
}