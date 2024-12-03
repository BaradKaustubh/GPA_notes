// 2D Rotation
#include <graphics.h>
#include <conio.h>
#include <cmath>

void drawPoly(int p[][2], int n)
{
    for (int v = 0; v < n; v++)
    {
        line(p[v][0], p[v][1],
             p[(v + 1) % n][0], p[(v + 1) % n][1]);
        line(p[v][0] + 1, p[v][1] + 1,
             p[(v + 1) % n][0] + 1, p[(v + 1) % n][1] + 1);
    }
}

void rot(int p[][2], int n, float a)
{
    float r = a * M_PI / 180;
    float c = cos(r);
    float s = sin(r);

    for (int v = 0; v < n; v++)
    {
        int x = p[v][0];
        int y = p[v][1];
        p[v][0] = round(x * c - y * s);
        p[v][1] = round(x * s + y * c);
    }
}

int main()
{
    int d = DETECT, m;
    initgraph(&d, &m, (char *)"");

    int x = getmaxx() / 2;
    int y = getmaxy() / 2;
    int s[4][2] = {
        {x - 50, y - 50},
        {x + 50, y - 50},
        {x + 50, y + 50},
        {x - 50, y + 50}};

    setcolor(WHITE);
    drawPoly(s, 4);
    rot(s, 4, 30);
    setcolor(GREEN);
    drawPoly(s, 4);

    getch();
    closegraph();
    return 0;
}