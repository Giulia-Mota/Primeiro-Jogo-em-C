#include <stdio.h>
#include <jogo.h>
#include "maca.h"


void desenha_fruta(int x, int y){
    cor(VERMELHO);
    desenha_retangulo(x, y, 10, 10);
}
