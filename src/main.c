#include <jogo.h>
#include <input.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maca.h"
#include "cobra.h"

int velocidade = 0;

void MENU_DIFICULDADE(){
    
    abre_janela(640, 480);
    while (janela_esta_aberta())
    {
        toca_som_em_loop("assets/AurbanniAudio_-_Electro_Dance_Music_80s.mp3");
        desenha_imagem(320, 240, "assets/854dcd215dbeb47334fdd8024a051954.png");
        fonte("assets/ubuntu.ttf", 40);
        cor(PRETO);
        desenha_texto(200, 240, "SNAKE GAME");
        desenha_texto(140, 300, "Defina a dificuldade:");
        fonte("assets/ubuntu.ttf", 20);
        desenha_texto(80, 330, "Facil - ENTER");
        desenha_texto(200, 330, "Medio - ESPACO");
        desenha_texto(360, 330, "Dificil - SETA BAIXO");
    
        if (tecla_acabou_de_ser_apertada(ENTER))
        {
            velocidade = 80000000;

            fecha_janela();
            return;
        }
        if (tecla_acabou_de_ser_apertada(ESPACO))
        {
            velocidade = 40000000;
            
            fecha_janela();
            return;
        }
        if (tecla_acabou_de_ser_apertada(BAIXO))
        {
            velocidade = 20000000;
            
            fecha_janela();
            return;
        }  
    }
}

int main() {
    int fruta_aleatoria = 0, x, y, score = 0;
    Tabela_jogadores apelido;
    bool gameOver = false;
    int ranking = 0;
    printf("Digite seu apelido: ");
    fgets(apelido.nome, 20, stdin);
    
    MENU_DIFICULDADE();

    if(velocidade != 0){
        abre_janela(640, 480);
        Cobra *cobra = cria_cobra();
        Fruta *maca = cria_fruta();
    
        while (janela_esta_aberta()) {

            toca_som_em_loop("assets/AurbanniAudio_-_Electro_Dance_Music_80s.mp3");

            if(gameOver){
                MENU_GAMEOVER();
            }
            else{
                gameOver = atualiza_cobra(cobra);
                desenha_cobra(cobra);
                
                if (tecla_acabou_de_ser_apertada(CIMA)){
                    if(cobra->direcao != BAIXO){
                        cobra->direcao = CIMA;
                    }
                }
                if (tecla_acabou_de_ser_apertada(BAIXO)){ 
                    if(cobra->direcao != CIMA){
                        cobra->direcao = BAIXO;
                    }
                }

                if (tecla_acabou_de_ser_apertada(ESQUERDA)){
                    if(cobra->direcao != DIREITA){
                        cobra->direcao = ESQUERDA;
                    }
                } 

                if (tecla_acabou_de_ser_apertada(DIREITA)){
                    if(cobra->direcao != ESQUERDA){
                        cobra->direcao = DIREITA;
                    }
                }

                int i=0;
                while(i < velocidade){
                    i++;
                }

                while (fruta_aleatoria == 0)
                {
                x = (rand() % 64)*10;
                y = (rand() % 48)*10;
                fruta_aleatoria = 1;
                }
                desenha_fruta(x, y);

                if (cobra->segmentos[0].x == x && cobra->segmentos[0].y == y){
                    toca_som("assets/Arcade Action 02.mp3");
                    cobra->tamanho++;
                    fruta_aleatoria = 0;
                    score++;
                }

            fonte("assets/ubuntu.ttf", 20);
            cor(VERDE);
            desenha_texto(10, 20, "Score:%d", score);
        }
    }
    
    fecha_janela();
}
}