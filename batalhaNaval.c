#include <stdio.h>

#define TAM 10
#define HAB 7  // tamanho das matrizes de habilidade

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1. INICIALIZA TABULEIRO COM ÁGUA
    
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // 0 = água
        }
    }

    // 2. POSICIONAR NAVIOS (VALOR 3)
   
    // Navio horizontal
    int linha_h = 2, coluna_h = 4;
    for (i = 0; i < 3; i++) {
        if (coluna_h + i < TAM) {
            tabuleiro[linha_h][coluna_h + i] = 3;
        }
    }

    // Navio vertical
    int linha_v = 6, coluna_v = 1;
    for (i = 0; i < 3; i++) {
        if (linha_v + i < TAM) {
            tabuleiro[linha_v + i][coluna_v] = 3;
        }
    }

    // Navio diagonal ↘
    int linha_d1 = 0, coluna_d1 = 0;
    for (i = 0; i < 3; i++) {
        if (linha_d1 + i < TAM && coluna_d1 + i < TAM) {
            tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
        }
    }

    // Navio diagonal ↙
    int linha_d2 = 0, coluna_d2 = 9;
    for (i = 0; i < 3; i++) {
        if (linha_d2 + i < TAM && coluna_d2 - i >= 0) {
            tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
        }
    }

    // 3. MATRIZES DAS HABILIDADES (CRIADAS DINAMICAMENTE)
    
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    int centro = HAB / 2; // sempre 3

    // HABILIDADE: CONE
    
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            // Largura aumenta conforme desce
            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // HABILIDADE: CRUZ
    
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // HABILIDADE: OCTAEDRO (LOSANGO)
    
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {

            int dist_linha = i - centro;
            if (dist_linha < 0) dist_linha = -dist_linha; 

            int dist_coluna = j - centro;
            if (dist_coluna < 0) dist_coluna = -dist_coluna;

            // Forma de losango
            if (dist_linha + dist_coluna <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // 4. APLICAR HABILIDADE NO TABULEIRO
    
    // ---- posições onde as habilidades vão aparecer no tabuleiro ----
    int origem_cone_l = 5, origem_cone_c = 5;
    int origem_cruz_l = 1, origem_cruz_c = 7;
    int origem_octa_l = 7, origem_octa_c = 2;

    // Aplicar CONE
    
    int inicio_linha = origem_cone_l - centro;
    int inicio_coluna = origem_cone_c - centro;

    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (cone[i][j] == 1) {
                int linha_tab = inicio_linha + i;
                int coluna_tab = inicio_coluna + j;

                if (linha_tab >= 0 && linha_tab < TAM &&
                    coluna_tab >= 0 && coluna_tab < TAM) {

                    if (tabuleiro[linha_tab][coluna_tab] == 0)
                        tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    }

    // Aplicar CRUZ
    
    inicio_linha = origem_cruz_l - centro;
    inicio_coluna = origem_cruz_c - centro;

    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (cruz[i][j] == 1) {
                int linha_tab = inicio_linha + i;
                int coluna_tab = inicio_coluna + j;

                if (linha_tab >= 0 && linha_tab < TAM &&
                    coluna_tab >= 0 && coluna_tab < TAM) {

                    if (tabuleiro[linha_tab][coluna_tab] == 0)
                        tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    }

    // Aplicar OCTAEDRO
    
    inicio_linha = origem_octa_l - centro;
    inicio_coluna = origem_octa_c - centro;

    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (octaedro[i][j] == 1) {
                int linha_tab = inicio_linha + i;
                int coluna_tab = inicio_coluna + j;

                if (linha_tab >= 0 && linha_tab < TAM &&
                    coluna_tab >= 0 && coluna_tab < TAM) {

                    if (tabuleiro[linha_tab][coluna_tab] == 0)
                        tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    }

    // 5. EXIBIR TABULEIRO FINAL

    printf("\n=== TABULEIRO FINAL ===\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {

            if (tabuleiro[i][j] == 0) printf("0 ");
            else if (tabuleiro[i][j] == 3) printf("3 ");
            else if (tabuleiro[i][j] == 5) printf("5 ");
        }
        printf("\n");
    }

    return 0;
}