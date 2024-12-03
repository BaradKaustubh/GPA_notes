#include <graphics.h>
#include <conio.h>

void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1-x0), dy = abs(y1-y0);
    int sx = x0<x1 ? 1:-1, sy = y0<y1 ? 1:-1;
    int err = dx-dy;
    
    while(1) {
        putpixel(x0, y0, WHITE);
        if(x0==x1 && y0==y1) break;
        int e2 = 2*err;
        if(e2 > -dy) {err -= dy; x0 += sx;}
        if(e2 < dx) {err += dx; y0 += sy;}
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    drawLine(100, 100, 400, 300);
    getch();
    closegraph();
    return 0;
}
