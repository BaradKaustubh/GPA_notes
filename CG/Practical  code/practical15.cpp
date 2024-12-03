#include <algorithm>
#include <graphics.h>

typedef struct
{
    int x, y;
} Pt;

int cwMinX = 10, cwMinY = 10, cwMaxX = 200, cwMaxY = 200;

void clipLine(Pt &p)
{
    p.x = std::max(cwMinX, std::min(p.x, cwMaxX));
    p.y = std::max(cwMinY, std::min(p.y, cwMaxY));
}

void drawPoly(Pt v[], int vc)
{
    for (int i = 0; i < vc; i++)
    {
        Pt p1 = v[i], p2 = v[(i + 1) % vc];
        clipLine(p1);
        clipLine(p2);
        line(p1.x, p1.y, p2.x, p2.y);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    Pt polyV[5] = {{50, 150}, {200, 50}, {300, 200}, {150, 250}, {50, 150}};
    int vc = 5;
    setcolor(WHITE);
    rectangle(cwMinX, cwMinY, cwMaxX, cwMaxY);
    setcolor(GREEN);
    drawPoly(polyV, vc);
    getch();
    closegraph();
    return 0;
}
