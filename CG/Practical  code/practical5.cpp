#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawCircle(int x, int y, int r) {
    int cx = 0;
    int cy = r;
    while(cy >= cx) {
        putpixel(x + cx, y + cy, WHITE);
        putpixel(x - cx, y + cy, WHITE);
        putpixel(x + cx, y - cy, WHITE);
        putpixel(x - cx, y - cy, WHITE);
        putpixel(x + cy, y + cx, WHITE);
        putpixel(x - cy, y + cx, WHITE);
        putpixel(x + cy, y - cx, WHITE);
        putpixel(x - cy, y - cx, WHITE);
        cx++;
        cy = sqrt(r * r - cx * cx);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    drawCircle(250, 250, 200);
    getch();
    closegraph();
    return 0;
}
