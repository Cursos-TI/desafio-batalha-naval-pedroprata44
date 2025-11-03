#include <stdio.h>
#include <stdlib.h> // Para system("cls") ou system("clear") se necessário, mas vou evitar para manter o código puro.

// =======================================================
// VARIÁVEIS CONSTANTES
// =======================================================
#define TAMANHO_TABULEIRO 10 // Tabuleiro 10x10 para Níveis Aventureiro e Mestre

// Definição do tabuleiro para os níveis Aventureiro e Mestre.
// Inicializamos com 0 (água / posição livre)
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

// =======================================================
// NÍVEL NOVATO: POSICIONAMENTO BÁSICO (2x2)
// =======================================================

void nivel_novato() {
    printf("## 🏅 Nível Novato - Posicionamento Básico (2x2)\n");
    printf("-------------------------------------------------\n");
    
    // Tabuleiro 2x2 simulado para o nível Novato (usando apenas a saída de coordenadas)
    // Coordenadas baseadas em [linha][coluna] ou [Y][X]

    // Navio 1 (Vertical, 2 casas) - Posição base: (1, 0)
    int navio1_y = 1;
    int navio1_x = 0;

    printf("1. Navio Vertical (2 casas):\n");
    printf(" -> Coordenada 1: Linha %d, Coluna %d\n", navio1_y, navio1_x);
    // Próxima casa (movimento vertical)
    printf(" -> Coordenada 2: Linha %d, Coluna %d\n", navio1_y + 1, navio1_x);
    
    // Navio 2 (Horizontal, 2 casas) - Posição base: (3, 2)
    int navio2_y = 3;
    int navio2_x = 2;

    printf("\n2. Navio Horizontal (2 casas):\n");
    printf(" -> Coordenada 1: Linha %d, Coluna %d\n", navio2_y, navio2_x);
    // Próxima casa (movimento horizontal)
    printf(" -> Coordenada 2: Linha %d, Coluna %d\n", navio2_y, navio2_x + 1);

    printf("-------------------------------------------------\n\n");
}


// =======================================================
// NÍVEL AVENTUREIRO: TABULEIRO 10x10 E DIAGONAL
// =======================================================

// Função auxiliar para marcar a posição no tabuleiro (usada no Nível Aventureiro)
void marcar_posicao(int y, int x) {
    if (y >= 0 && y < TAMANHO_TABULEIRO && x >= 0 && x < TAMANHO_TABULEIRO) {
        // Requisito: Usar 3 para indicar posição ocupada
        tabuleiro[y][x] = 3; 
    }
}

void posicionar_navios_aventureiro() {
    // 1. Navio Vertical (3 casas)
    // Posição inicial: (1, 1) -> (Linha 1, Coluna 1)
    for (int i = 0; i < 3; i++) {
        marcar_posicao(1 + i, 1);
    }

    // 2. Navio Horizontal (4 casas)
    // Posição inicial: (5, 3)
    for (int j = 0; j < 4; j++) {
        marcar_posicao(5, 3 + j);
    }
    
    // 3. Navio Diagonal Principal (3 casas: \ )
    // Posição inicial: (8, 6)
    for (int k = 0; k < 3; k++) {
        marcar_posicao(8 - k, 6 + k); // Diminui Linha, Aumenta Coluna
    }
    
    // 4. Navio Diagonal Secundária (2 casas: / )
    // Posição inicial: (2, 7)
    for (int l = 0; l < 2; l++) {
        marcar_posicao(2 + l, 7 + l); // Aumenta Linha, Aumenta Coluna
    }
}

void exibir_tabuleiro_aventureiro() {
    printf("Tab. | 0 1 2 3 4 5 6 7 8 9\n");
    printf("---------------------------\n");
    
    // Estruturas de Repetição Aninhadas para percorrer a matriz (Requisito)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) { // Linhas (Y)
        printf(" %d   |", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) { // Colunas (X)
            // Requisito: 0 (água) e 3 (navio)
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void nivel_aventureiro() {
    printf("## 🏅 Nível Aventureiro - Tabuleiro 10x10 com Diagonais\n");
    printf("--------------------------------------------------------\n");
    
    // Posiciona os 4 navios no tabuleiro 10x10
    posicionar_navios_aventureiro();
    
    // Exibe o tabuleiro completo
    exibir_tabuleiro_aventureiro();

    printf("--------------------------------------------------------\n\n");
}

// =======================================================
// NÍVEL MESTRE: HABILIDADES ESPECIAIS (PADRÕES)
// =======================================================

// Função para exibir o tabuleiro de habilidades (usa 0 e 1)
void exibir_matriz_habilidade(int matriz[5][5]) {
    // O padrão de habilidades é centralizado em uma matriz 5x5
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Requisito: printf("%d ",matriz[i][j]);
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nivel_mestre() {
    printf("## 🏅 Nível Mestre - Habilidades Especiais (Padrões de Matriz)\n");
    printf("----------------------------------------------------------------\n");
    
    // --- 1. Habilidade: CONE (3x5) ---
    // Exemplo:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    printf("1. Habilidade: CONE\n");
    int cone[5][5] = {0};
    int centro = 2; // Centro da matriz 5x5
    
    // Loops aninhados para criar o padrão do Cone
    for (int i = 0; i < 5; i++) { // Linhas
        for (int j = 0; j < 5; j++) { // Colunas
            // Se a distância horizontal do centro for menor ou igual à distância
            // vertical do topo (invertida, pois i cresce para baixo), marca como 1.
            // Para i=0, j deve ser 2.
            // Para i=1, j pode ser 1, 2, 3.
            // Para i=2, j pode ser 0, 1, 2, 3, 4.
            if (abs(j - centro) <= i) {
                if (i < 3) { // Limita o Cone a 3 linhas (0, 1, 2)
                    cone[i][j] = 1;
                }
            }
        }
    }
    exibir_matriz_habilidade(cone);

    // --- 2. Habilidade: CRUZ (5x5) ---
    // Exemplo:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    printf("2. Habilidade: CRUZ\n");
    int cruz[5][5] = {0};
    
    // Loops aninhados para criar o padrão da Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Marca a linha central (i=2) E a coluna central (j=2)
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            }
        }
    }
    // Remove as pontas para corresponder ao exemplo dado (3x5 e 5x3)
    cruz[0][0] = cruz[0][4] = 0;
    cruz[4][0] = cruz[4][4] = 0;
    exibir_matriz_habilidade(cruz);


    // --- 3. Habilidade: OCTAEDRO (3x5) ---
    // Exemplo:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    printf("3. Habilidade: OCTAEDRO (Diamante)\n");
    int octaedro[5][5] = {0};
    
    // Loops aninhados para criar o padrão do Octaedro (ou Diamante)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // A condição é baseada na Distância de Manhattan (abs(i - centro) + abs(j - centro))
            // Para o Octaedro 5x5: distância deve ser <= 2
            if (abs(i - centro) + abs(j - centro) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }
    // O exemplo dado é 3x5, que corresponde à remoção das linhas extremas (0 e 4)
    for (int i = 1; i <= 3; i++) { // Linhas 1 a 3 (total 3 linhas)
        for (int j = 0; j < 5; j++) {
            // Exibe apenas as linhas 1, 2 e 3 da matriz 5x5 do Octaedro (Diamante)
            if (octaedro[i][j] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    printf("----------------------------------------------------------------\n\n");
}


// =======================================================
// FUNÇÃO PRINCIPAL
// =======================================================

int main() {
    printf("==================================================\n");
    printf("        🚢 Desafio Batalha Naval - Solução Completa\n");
    printf("==================================================\n\n");

    nivel_novato();
    
    // Reseta o tabuleiro (não estritamente necessário, mas boa prática)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    nivel_aventureiro();
    
    nivel_mestre();

    printf("==================================================\n");
    printf("        Todos os Níveis do Desafio Foram Implementados\n");
    printf("==================================================\n");
    
    return 0;
}