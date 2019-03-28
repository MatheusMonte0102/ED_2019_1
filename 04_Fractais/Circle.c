#include "xpaint.h"

void make_circle(int x, int y, int tamanho){
    if(tamanho < 5)
        return;
    float angulo = 90;
    int i = 0;
    for(; i < 6; i++){
        int xf = x + tamanho * xm_cos(angulo);
        int yf = y - tamanho * xm_sin(angulo);
        xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
        xd_circle(x, y, tamanho);
        x_step("circle");
        make_circle(xf, yf, tamanho / 3);
        angulo += 60;
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
    int tamanho = 250;
    make_circle(x, y, tamanho);
    x_save("circle");
    x_close();

    return 0;
}