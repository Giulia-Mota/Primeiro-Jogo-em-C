typedef struct {
    int x;
    int y;
} Segmento;

typedef struct {
    Segmento segmentos[1000];
    int direcao;
    int tamanho;
} Cobra;

typedef struct {
    int x;
    int y;
} Fruta;

typedef struct{
    char nome[20];
    int score;
} Tabela_jogadores;

Fruta *cria_fruta();
Cobra *cria_cobra();
bool atualiza_cobra(Cobra *cobra);
void desenha_cobra(Cobra *cobra);
void MENU_GAMEOVER();
int main();