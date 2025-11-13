#include <stdio.h>

int main(){

 int i, j; // variáveis de controle dos loops
    int tabuleiro[10][10]; // matriz 10x10 representando o tabuleiro

    // 1. Inicializa o tabuleiro com água (valor 0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }

    // 2. Cada navio tem tamanho fixo = 3
    // Valor 3 representa parte de um navio
    int tamanho_navio = 3;

    // ===============================
    // NAVIO 1 - HORIZONTAL
    // ===============================
    int linha_h = 2;    // linha inicial
    int coluna_h = 4;   // coluna inicial

    if (coluna_h + tamanho_navio <= 10) { // cabe no tabuleiro?
        for (i = 0; i < tamanho_navio; i++) {
            tabuleiro[linha_h][coluna_h + i] = 3;
        }
    } else {
        printf("Erro: o navio horizontal sairia do tabuleiro.\n");
    }

    // ===============================
    // NAVIO 2 - VERTICAL
    // ===============================
    int linha_v = 6;  // linha inicial
    int coluna_v = 1; // coluna inicial
    int sobreposicao = 0; // variável para verificar sobreposição

    if (linha_v + tamanho_navio <= 10) { // cabe no tabuleiro?
        // primeiro verifica sobreposição
        for (i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_v + i][coluna_v] == 3) {
                sobreposicao = 1;
            }
        }
        // se não há sobreposição, posiciona
        if (!sobreposicao) {
            for (i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_v + i][coluna_v] = 3;
            }
        } else {
            printf("Erro: o navio vertical se sobrepõe a outro.\n");
        }
    } else {
        printf("Erro: o navio vertical sairia do tabuleiro.\n");
    }

    // ===============================
    // NAVIO 3 - DIAGONAL PRINCIPAL (↘)
    // ===============================
    int linha_d1 = 0; // linha inicial
    int coluna_d1 = 0; // coluna inicial
    sobreposicao = 0;

    if (linha_d1 + tamanho_navio <= 10 && coluna_d1 + tamanho_navio <= 10) {
        // verifica sobreposição
        for (i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_d1 + i][coluna_d1 + i] == 3) {
                sobreposicao = 1;
            }
        }
        // se não há sobreposição, posiciona
        if (!sobreposicao) {
            for (i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
            }
        } else {
            printf("Erro: o navio diagonal (↘) se sobrepõe a outro.\n");
        }
    } else {
        printf("Erro: o navio diagonal (↘) sairia do tabuleiro.\n");
    }

    // ===============================
    // NAVIO 4 - DIAGONAL SECUNDÁRIA (↙)
    // ===============================
    int linha_d2 = 0;  // linha inicial
    int coluna_d2 = 9; // começa do canto superior direito
    sobreposicao = 0;

    if (linha_d2 + tamanho_navio <= 10 && coluna_d2 - tamanho_navio + 1 >= 0) {
        // verifica sobreposição
        for (i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_d2 + i][coluna_d2 - i] == 3) {
                sobreposicao = 1;
            }
        }
        // se não há sobreposição, posiciona
        if (!sobreposicao) {
            for (i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
            }
        } else {
            printf("Erro: o navio diagonal (↙) se sobrepõe a outro.\n");
        }
    } else {
        printf("Erro: o navio diagonal (↙) sairia do tabuleiro.\n");
    }

    // EXIBIÇÃO DO TABULEIRO
    
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}