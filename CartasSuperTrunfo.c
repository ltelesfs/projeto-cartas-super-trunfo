#include <stdio.h>
#include <stdlib.h>

#define TAM_NOVATO 5
#define TAM_AVENTUREIRO 10
#define TAM_MESTRE 5

// Função do Nível Novato
void nivelNovato() {
    int tabuleiro[TAM_NOVATO][TAM_NOVATO] = {0};

    printf("\n🏅 Nível Novato - Coordenadas dos navios:\n");

    // Navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][0] = 3;
        printf("Navio 1 - Parte %d: (%d, %d)\n", i + 1, i, 0);
    }

    // Navio horizontal
    for (int j = 1; j <= 3; j++) {
        tabuleiro[4][j] = 3;
        printf("Navio 2 - Parte %d: (%d, %d)\n", j, 4, j);
    }
}

// Função do Nível Aventureiro
void nivelAventureiro() {
    int tabuleiro[TAM_AVENTUREIRO][TAM_AVENTUREIRO] = {0};

    printf("\n🏅 Nível Aventureiro - Tabuleiro com 4 navios:\n");

    // Navio horizontal
    for (int j = 0; j < 4; j++)
        tabuleiro[0][j] = 3;

    // Navio vertical
    for (int i = 2; i <= 5; i++)
        tabuleiro[i][5] = 3;

    // Diagonal principal
    for (int i = 6; i < 10; i++)
        tabuleiro[i][i] = 3;

    // Diagonal secundária
    for (int i = 0; i < 4; i++)
        tabuleiro[3 + i][6 - i] = 3;

    // Exibe o tabuleiro
    for (int i = 0; i < TAM_AVENTUREIRO; i++) {
        for (int j = 0; j < TAM_AVENTUREIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Utilitários para exibir matrizes
void exibirMatriz(int matriz[TAM_MESTRE][TAM_MESTRE]) {
    for (int i = 0; i < TAM_MESTRE; i++) {
        for (int j = 0; j < TAM_MESTRE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Habilidade Cone
void habilidadeCone() {
    int cone[TAM_MESTRE][TAM_MESTRE] = {0};
    cone[0][2] = 1;
    cone[1][1] = cone[1][2] = cone[1][3] = 1;
    for (int j = 0; j < TAM_MESTRE; j++)
        cone[2][j] = 1;

    printf("\n🌀 Habilidade: Cone\n");
    exibirMatriz(cone);
}

// Habilidade Cruz
void habilidadeCruz() {
    int cruz[TAM_MESTRE][TAM_MESTRE] = {0};
    for (int j = 0; j < TAM_MESTRE; j++)
        cruz[1][j] = 1;

    cruz[0][2] = cruz[2][2] = 1;

    printf("➕ Habilidade: Cruz\n");
    exibirMatriz(cruz);
}

// Habilidade Octaedro
void habilidadeOctaedro() {
    int octaedro[TAM_MESTRE][TAM_MESTRE] = {0};
    octaedro[0][2] = 1;
    octaedro[1][1] = octaedro[1][2] = octaedro[1][3] = 1;
    octaedro[2][2] = 1;

    printf("🔷 Habilidade: Octaedro\n");
    exibirMatriz(octaedro);
}

// Função do Nível Mestre
void nivelMestre() {
    printf("\n🏅 Nível Mestre - Habilidades Especiais:\n");
    habilidadeCone();
    habilidadeCruz();
    habilidadeOctaedro();
}

// Menu principal
int main() {
    int opcao;

    do {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1. Nível Novato\n");
        printf("2. Nível Aventureiro\n");
        printf("3. Nível Mestre\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                nivelNovato();
                break;
            case 2:
                nivelAventureiro();
                break;
            case 3:
                nivelMestre();
                break;
            case 0:
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
