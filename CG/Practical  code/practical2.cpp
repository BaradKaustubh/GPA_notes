#include <conio.h>
#include <graphics.h>

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    ellipse(300, 150, 0, 360, 100, 50);
    rectangle(100, 300, 300, 400);

    int points[] = {400, 200, 450, 150, 500, 200, 475, 250, 425, 250, 400, 200};
    drawpoly(6, points);

    int points2[] = {150, 100, 200, 50, 250, 100, 150, 100};
    drawpoly(4, points2);

    getch();
    closegraph();
    return 0;
}
