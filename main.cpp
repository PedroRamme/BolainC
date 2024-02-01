#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>

const int RAIO = 30;
const int SPEED_VAR = 2;
const int CHAO_Y = 650;
const int POSY_INITIAL = 50;
void paintCircle(int posX, int posY, int color);
void drawCircle(int posX, int posY, int RGB);
void eraseCircle(int posX, int posY);
void updateCircle(int posX, int posY, int RGB);
int atualizaVelocidadeHorizontal(int horizontal_speed);
void drawScenario(int x1, int y1, int x2, int y2, int y3);
void stars();
void init();

/*
 INICIO
*/

int main()
{
    init();

    int tamanhoXMax = getmaxx();
    int tamanhoYMax = getmaxy();
    int posY = POSY_INITIAL;
    int posX = 50;
    int speed = 0;
    int indoParaBaixo = 1;
    int horizontal_speed = 0;

    cleardevice();
    stars();
    drawScenario(0, CHAO_Y, tamanhoXMax, tamanhoYMax, 675);

    while (true)
    {
        int randcolor = rand() % 15;
        if (GetAsyncKeyState(VK_SPACE))
        {
            break;
        }

        horizontal_speed = atualizaVelocidadeHorizontal(horizontal_speed);        // Aumenta a velocidade horizontal caso as teclas RIGHT ou LEFT forem precionadas

        speed = speed + (SPEED_VAR * indoParaBaixo);            // Aumenta velocidade se estiver indo pra baixo ou diminui se estiver indo pra cima (pois foi multiplicado por -1)

        posY = posY + (speed * indoParaBaixo);                  // Incrementa posição no Y

        if (posY >= (CHAO_Y - RAIO))                            // Se chegou no fundo
        {
            speed = speed - SPEED_VAR;
            indoParaBaixo = -1;
            posY = CHAO_Y - RAIO;

            if (speed <= 0){
                speed = 0;
            }
        }
        if (speed <= 0)                                         // Se zerou a velocidade
        {
            indoParaBaixo = 1;
        }

        posX = posX + horizontal_speed;


        if(posX >= tamanhoXMax - RAIO || posX <= 0 + RAIO){     // Se bateu nas bordas da tela, inverte a direcao

            if(posX >= tamanhoXMax - RAIO){
                posX = tamanhoXMax - RAIO;
            }
            else if(posX <= 0 + RAIO){
                posX = 0 + RAIO;
            }

            horizontal_speed = -horizontal_speed;
        }

        printf("\n%i\n%i", speed, posY);
        updateCircle(posX, posY, randcolor);

    }
    //    delay(5000);
    closegraph();
    return 0;
}



void updateCircle(int posX, int posY, int RGB)
{
    drawCircle(posX, posY, RGB);
    delay(33);
    eraseCircle(posX, posY);
}

void drawCircle(int posX, int posY, int RGB)
{
    paintCircle(posX, posY, RGB );
    setfillstyle(SOLID_FILL, RGB);
    floodfill(posX, posY, RGB);

}

void eraseCircle(int posX, int posY)
{
    paintCircle(posX, posY, BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(posX, posY, BLACK);

}

void paintCircle(int posX, int posY, int color)
{
    setcolor(color);
    circle(posX, posY, RAIO);

}

int atualizaVelocidadeHorizontal(int horizontal_speed){

    if(GetAsyncKeyState(VK_RIGHT)){
        horizontal_speed = horizontal_speed + 2;

    }
    if(GetAsyncKeyState(VK_LEFT)){
        horizontal_speed = horizontal_speed - 2;

    }

    return horizontal_speed;

}
void stars(){

    for(int i = 0; i < 500; i++){

        putpixel(rand() % 1280, rand() % CHAO_Y, rand() % 15);
    }

}
void drawScenario(int x1, int y1, int x2, int y2, int y3)
{
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(x1, y1, x2, y3);
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(x1, y3, x2, y2);

}

void init()
{
    initwindow(1280, 720);

}
