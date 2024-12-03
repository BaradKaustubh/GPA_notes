#include <graphics.h>
#include <conio.h>
#include <cmath>

void dp(int p[][2], int n)
{
    for (int v = 0; v < n; v++)
        line(p[v][0], p[v][1], p[(v + 1) % n][0], p[(v + 1) % n][1]);
}

void rp(int p[][2], int n, int cx, int cy, float ad)
{
    float ar = ad * M_PI / 180;
    for (int v = 0; v < n; v++)
    {
        int rx = p[v][0] - cx;
        int ry = p[v][1] - cy;
        p[v][0] = rx * cos(ar) - ry * sin(ar) + cx;
        p[v][1] = rx * sin(ar) + ry * cos(ar) + cy;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    
    int sq[4][2] = {{50, 50}, {350, 50}, {350, 350}, {50, 350}};
    setcolor(WHITE);
    dp(sq, 4);
    
    rp(sq, 4, 200, 200, 45);
    setcolor(GREEN);
    dp(sq, 4);
    
    getch();
    closegraph();
    return 0;
}