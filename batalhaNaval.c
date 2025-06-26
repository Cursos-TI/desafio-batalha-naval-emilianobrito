#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível aventureiro

// Definições de tamanho do tabuleiro e valores simbólicos
#define N 10         // Tamanho do tabuleiro (10x10)
#define NAVIO 3      // Tamanho fixo dos navios
#define AGUA 0       // Valor usado para representar água no tabuleiro

// Função para preencher todo o tabuleiro com água
void inicializar(int t[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            t[i][j] = AGUA;
}

// Função para exibir o tabuleiro no console
void exibir(int t[N][N]) {
    printf("   GAME BATALHA NAVAL\n\n   ");
    for (int j = 0; j < N; j++) printf("%d ", j);  // Números das colunas
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%2d ", i);                         // Número da linha
        for (int j = 0; j < N; j++)
            printf("%d ", t[i][j]);                // Conteúdo da célula (0 ou 3)
        printf("\n");
    }
}

// Função para verificar se o posicionamento do navio é válido
int validar(int t[N][N], int l, int c, int tam, char o) {
    // Verifica se os índices iniciais são válidos
    if (l < 0 || c < 0) return 0;

    // Verifica se o navio cabe na orientação informada sem sair do tabuleiro
    int dentro = (o == 'H' && c + tam <= N && l < N) ||                // Horizontal
                 (o == 'V' && l + tam <= N && c < N) ||                // Vertical
                 (o == 'D' && l + tam <= N && c + tam <= N) ||// Diagonal crescente
                 (o == 'A' && l + tam <= N && c - tam > -2 && c < N); // Diagonal decrescente

    if (!dentro) return 0;

    // Verifica se alguma posição já está ocupada por outro navio
    for (int i = 0; i < tam; i++) {
        int li = l + i; 
        if (o == 'H') li = l;
        // Calcula a coluna com base na orientação
        int co = (o == 'A') ? c - i : (o == 'H') ? c + i : (o == 'D') ? c + i : c;
        if (t[li][co] == NAVIO) return 0; // Já ocupado
    }
    return 1; // Posição válida
}

// Função que posiciona o navio no tabuleiro se for válido
int posicionar(int t[N][N], int l, int c, int tam, char o) {
    if (!validar(t, l, c, tam, o)) {
        printf("Erro: não foi possível posicionar o navio '%c' em [%d][%d].\n", o, l, c);
        return 0;
    }

    // Marca as posições do navio no tabuleiro
    for (int i = 0; i < tam; i++) {
        int li = l + i;
        if (o == 'H') li = l;
        int co = (o == 'A') ? c - i : (o == 'H') ? c + i : (o == 'D') ? c + i : c;
        t[li][co] = NAVIO;
    }
    return 1;
}

// Função principal
int main() {
    int tabuleiro[N][N];
    inicializar(tabuleiro); // Preenche com água

    // Posiciona quatro navios com diferentes orientações:
    posicionar(tabuleiro, 0, 0, NAVIO, 'H'); // Horizontal
    posicionar(tabuleiro, 0, 9, NAVIO, 'V'); // Vertical
    posicionar(tabuleiro, 7, 0, NAVIO, 'D'); // Diagonal crescente
    posicionar(tabuleiro, 7, 9, NAVIO, 'A'); // Diagonal decrescente

    exibir(tabuleiro); // Mostra o estado final do tabuleiro
    return 0;
}