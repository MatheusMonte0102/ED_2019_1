#include "xpaint.h"

void arvore(int x, int y, float angulo, int tamanho){
    if(tamanho < 3)
        return;
    if ((tamanho > 10) && (tamanho < 45)) {
        xs_color(RED);
        xd_filled_circle(x, y, 1);
    }
    
    int xf = x + tamanho * xm_cos(angulo);
    int yf = y - tamanho * xm_sin(angulo);
    if(tamanho > 180)
        xs_color(make_xcolor(165, 42, 42));
    else
        xs_color(GREEN);
    
    xd_thick_line(x, y, xf, yf, xm_rand(3, 7));
    x_step("arvore_minha");
    
    arvore(xf, yf, angulo + xm_rand(17, 23), tamanho - xm_rand(15, 25));
    arvore(xf, yf, angulo - xm_rand(23, 29), tamanho - xm_rand(17, 23));
}

int main(){
    int largura = 2000;
    int altura = 2000;
    x_open(largura, altura);
    x_clear(BLACK);
    float angulo = 90;
    int x = largura / 2;
    int y = altura;
    int tamanho = 250;
    arvore(x, y, angulo, tamanho);
    x_save("arvore_minha");
    x_close();
    return 0;
}