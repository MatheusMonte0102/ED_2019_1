#include "xpaint.h"

void snowflake(int x, int y, int tamanho){
    if(tamanho < 10)
        return;
    float angulo = 54;
    int i = 0;
    for(; i < 5; i++){
        int xf = x + tamanho * xm_cos(angulo);
        int yf = y - tamanho * xm_sin(angulo);
        xs_color(WHITE);
        xd_thick_line(x, y, xf, yf, 5);
        x_step("floquinho");
        snowflake(xf, yf, tamanho / 3);
        angulo += 72;
    }
}

int main(){
    int largura = 1000;
    int altura = 1000;
    x_open(largura, altura);
    x_clear(BLACK);
    int x = largura / 2;
    int y = altura / 2;
    float angulo = 54;
    int tamanho = 350;
    snowflake(x, y, tamanho);
    x_save("floquinho");
    x_close();

    return 0;
}