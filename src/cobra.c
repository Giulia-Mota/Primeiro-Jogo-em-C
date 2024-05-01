#include <jogo.h>
#include <input.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cobra.h"

#define TAM_SEGMENTO 10


Fruta *cria_fruta(){
    Fruta *maca = (Fruta*)malloc(sizeof(Fruta));
    return maca;
}

Cobra *cria_cobra(){
    Cobra *cobra = (Cobra*)malloc(sizeof(Cobra));
    cobra->segmentos[0].x = 320;
    cobra->segmentos[0].y = 240;    
    cobra->direcao = DIREITA;
    cobra->tamanho = 1;
    return cobra;
}

void MENU_GAMEOVER(){
    
    toca_som("assets/failure-drum-sound-effect-2-7184.mp3");
    desenha_imagem(320, 240, "assets/854dcd215dbeb47334fdd8024a051954.png");
                fonte("assets/ubuntu.ttf", 50);
                cor(VERMELHO);
                desenha_texto(210, 240, "Game Over");

                fonte("assets/ubuntu.ttf", 30);
                cor(AZUL_CLARO);
                desenha_texto(130, 300, "Aperte TAB para voltar ao menu");
                desenha_texto(140, 330, "Aperte ESC para sair do jogo");
                 if(tecla_acabou_de_ser_apertada(TAB)){
                    fecha_janela();
                    main();
                }
                 if(tecla_acabou_de_ser_apertada(ESC)){
                    fecha_janela();
                 }
    }

bool atualiza_cobra(Cobra *cobra){
    Segmento nova_cabeca;
    
    int tamanho_cobra = cobra->tamanho;
    nova_cabeca.x = cobra->segmentos[0].x;
    nova_cabeca.y = cobra->segmentos[0].y;

    if(cobra->direcao == CIMA){
        nova_cabeca.y -= TAM_SEGMENTO;
    }
    if(cobra->direcao == BAIXO){
        nova_cabeca.y += TAM_SEGMENTO;
    }
    if(cobra->direcao == DIREITA){
        nova_cabeca.x += TAM_SEGMENTO;
    }
    if(cobra->direcao == ESQUERDA){
        nova_cabeca.x -= TAM_SEGMENTO;
    }

    for(int i=tamanho_cobra-1; i>=0; i--){
        cobra->segmentos[i+1] = cobra->segmentos[i];
    }
    cobra->segmentos[0] = nova_cabeca;
    
    for(int i = 1; i < cobra->tamanho; i++){
        if(cobra->segmentos[0].x == cobra->segmentos[i].x && 
        cobra->segmentos[0].y == cobra->segmentos[i].y){
                
                return true;
                
        }
        }

    if (nova_cabeca.x <= -10 || nova_cabeca.y <= -10 || nova_cabeca.x >= 650 || nova_cabeca.y >= 490)
    {
           return true;
    }
    return false;
}

void desenha_cobra(Cobra *cobra){
    for(int i=0; i < cobra->tamanho; i++){
        int x = cobra->segmentos[i].x;
        int y = cobra->segmentos[i].y;
        cor(AZUL_CLARO);
        desenha_retangulo(x, y, TAM_SEGMENTO, TAM_SEGMENTO);
    }
}