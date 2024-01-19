#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<windows.h>

//GetAsyncKeyState(VK_UP)

const int RAIO = 30;
const int SPEED_VAR = 1;
const int CHAO_Y = 400;

void paintCircle(int posX, int posY, int color);
void drawCircle(int posX, int posY);
void eraseCircle(int posX, int posY);
void updateCircle(int posX, int posY);
void drawScenario(int x1, int y1, int x2, int y2);
void init();

/*
 INICIO
*/
int main()
{
    init();

    int tamanhoXMax = getmaxx();
    int tamanhoYMax = getmaxy();
    int posY = 50;
    int posX = 50;
    int speed = 0;
    int indoParaBaixo = 1;

    cleardevice();
    drawScenario(0,CHAO_Y,tamanhoXMax,CHAO_Y);


    while(true) {



        if(GetAsyncKeyState(VK_SPACE)){
            break;
        }

        if(GetAsyncKeyState(VK_RIGHT)){
            //aumentar a velocidade para a direita
            //se bater na parede, inverte a direção mas mantem a velocidade.
            //posX = posX + 100;
        }
        if(GetAsyncKeyState(VK_LEFT)){
            //aumentar a velocidade para a esquerda
            //posX = posX - 100;
        }


        //Aumenta velocidade se estiver indo pra baixo ou diminui se estiver indo pra cima (pois foi multiplicado por -1)
        speed = speed + (SPEED_VAR * indoParaBaixo);

        printf("%i - %i - %i \n", posY, speed, (posY + speed));

        // Incrementa posição no Y
        posY = posY + (speed * indoParaBaixo);



        //Se chegou no fundo
        if (posY >= (CHAO_Y - RAIO)) {
            indoParaBaixo = -1;
            posY = CHAO_Y - RAIO;
        }

        //Se zerou a velocidade
        if (speed <= 0) {
            indoParaBaixo = 1;
        }

        updateCircle(posX, posY);

    }
//    delay(5000);
    closegraph();
    return 0;

}





void updateCircle(int posX, int posY) {
    drawCircle(posX, posY);
    delay(33);
    eraseCircle(posX, posY);
}

void drawCircle(int posX, int posY) {
    paintCircle(posX, posY, WHITE);
}

void eraseCircle(int posX, int posY) {
    paintCircle(posX, posY, BLACK);
}

void paintCircle(int posX, int posY, int color) {
    setcolor(color);
    circle(posX, posY, RAIO);
    line(posX, posY, posX + 1, posY + 1);
}



void drawScenario(int x1, int y1, int x2, int y2){
    line(x1, y1, x2, y2);
}

void init() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
}
