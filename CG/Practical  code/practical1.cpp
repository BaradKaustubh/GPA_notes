#include <conio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*)"");
    putpixel(200, 200, RED);
    line(100, 100, 300, 300);
    setcolor(GREEN);
    circle(220, 220, 180);
    getch();
    closegraph();
    return 0;
}