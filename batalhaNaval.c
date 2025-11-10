#include <stdio.h>

int main(){

int i, j; // variáveis para os loops
    int tabuleiro[10][10]; // matriz 10x10 representando o tabuleiro

    // 1. Inicializa o tabuleiro com água (valor 0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }

    // 2. Cria dois navios, cada um com tamanho 3
    int navio_horizontal[3] = {3, 3, 3}; // navio horizontal
    int navio_vertical[3] = {3, 3, 3};   // navio vertical

    // 3. Define onde os navios vão começar no tabuleiro
    int linha_horizontal = 2; // linha do navio horizontal
    int coluna_horizontal = 4; // coluna onde ele começa

    int linha_vertical = 6; // linha inicial do navio vertical
    int coluna_vertical = 1; // coluna do navio vertical

    // 4. Posiciona o navio horizontal (verifica se ele cabe)
    if (coluna_horizontal + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }
    } else {
        printf("Erro: o navio horizontal sairia do tabuleiro.\n");
    }

    // 5. Posiciona o navio vertical (verifica se ele cabe e não se sobrepõe)
    if (linha_vertical + 3 <= 10) {
        int sobreposicao = 0; // variável para verificar sobreposição

        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 3) {
                sobreposicao = 1; // há sobreposição
            }
        }

        if (sobreposicao == 0) { // se não houve sobreposição
            for (i = 0; i < 3; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        } else {
            printf("Erro: o navio vertical se sobrepõe ao outro navio.\n");
        }
    } else {
        printf("Erro: o navio vertical sairia do tabuleiro.\n");
    }

    // 6. Exibe o tabuleiro
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}