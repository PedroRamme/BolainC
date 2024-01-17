#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<windows.h>

//GetAsyncKeyState(VK_UP)

void paintCircle(int i, int color) {
    setcolor(color);
    circle(50, i, 30);
}

void drawCircle(int i) {
    paintCircle(i, WHITE);
}

void eraseCircle(int i) {
    paintCircle(i, BLACK);
}

void updateCircle(int i) {
    drawCircle(i);
    delay(1);
    eraseCircle(i);
}


void init() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
}

int main()
{
    init();

    int tamanhoXMax = getmaxx();
    int y = 50;
    int d = 1;


    setcolor(WHITE);
    line(0,400,tamanhoXMax,400);

    while(true){

        if(y >300){
            drawCircle(y);
        }

        for(int i = y; i<370; i++){
            updateCircle(i);
        }


        for(int i= 370; i>y; i--){
            updateCircle(i);
        }

        y += 50;

    }
    printf("saiu");
    delay(500000);
    closegraph();
    return 0;
}

