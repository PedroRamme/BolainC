#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>

// GetAsyncKeyState(VK_UP)

const int RAIO = 30;
const int SPEED_VAR = 2;
const int CHAO_Y = 650;
int HORIZONTAL_SPEED = 0;
void paintCircle(int posX, int posY, int color);
void drawCircle(int posX, int posY);
void eraseCircle(int posX, int posY);
void updateCircle(int posX, int posY);
void atualizaVelocidadeHorizontal();
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
    drawScenario(0, CHAO_Y, tamanhoXMax, CHAO_Y);

    while (true)
    {

        if (GetAsyncKeyState(VK_SPACE))
        {
            break;
        }

        atualizaVelocidadeHorizontal();                         // Aumenta a velocidade horizontal caso as teclas RIGHT ou LEFT forem precionadas

        speed = speed + (SPEED_VAR * indoParaBaixo);            // Aumenta velocidade se estiver indo pra baixo ou diminui se estiver indo pra cima (pois foi multiplicado por -1)

        posY = posY + (speed * indoParaBaixo);                  // Incrementa posição no Y

        if (posY >= (CHAO_Y - RAIO))                            // Se chegou no fundo
        {
            indoParaBaixo = -1;
            posY = CHAO_Y - RAIO;
        }

        if (speed <= 0)                                         // Se zerou a velocidade
        {
            indoParaBaixo = 1;
        }
        posX = posX + HORIZONTAL_SPEED;

        if(posX >= tamanhoXMax - RAIO || posX <= 0 + RAIO){     // Se bateu nas bordas da tela, inverte a direcao

            HORIZONTAL_SPEED = -HORIZONTAL_SPEED;
        }

        updateCircle(posX, posY);

    }
    //    delay(5000);
    closegraph();
    return 0;
}



void updateCircle(int posX, int posY)
{
    drawCircle(posX, posY);
    delay(33);
    eraseCircle(posX, posY);
}

void drawCircle(int posX, int posY)
{
    paintCircle(posX, posY, GREEN);
}

void eraseCircle(int posX, int posY)
{
    paintCircle(posX, posY, BLACK);
}

void paintCircle(int posX, int posY, int color)
{
    setcolor(color);
    circle(posX, posY, RAIO);
    line(posX, posY, posX + 1, posY + 1);
}
void atualizaVelocidadeHorizontal(){

    if(GetAsyncKeyState(VK_RIGHT)){
        HORIZONTAL_SPEED = HORIZONTAL_SPEED + 2;
    }
    if(GetAsyncKeyState(VK_LEFT)){
        HORIZONTAL_SPEED = HORIZONTAL_SPEED - 2;
    }

}
void drawScenario(int x1, int y1, int x2, int y2)
{
    line(x1, y1, x2, y2);
}

void init()
{
    initwindow(1280, 720);

}
