#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int tamanhoXMax = getmaxx();
    int y = 50;

    while(1){

    if(y >300){
        circle(50, 370, 30);
    }
    for(int i = y; i<370; i++){
        circle(50, i, 30);
        delay(1);
        cleardevice();
        line(0,400,tamanhoXMax,400);
    }
    for(int j = 370; j>y; j--){
        circle(50, j, 30);
        delay(1);
        cleardevice();
        line(0,400,tamanhoXMax,400);
    }
    y += 50;

    }

    delay(500000);
    closegraph();
    return 0;
}
