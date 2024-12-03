#include <stdio.h>
#include <graphics.h>
#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int xmin, ymin, xmax, ymax;

int getCode(int x, int y)
{
    int code = INSIDE;
    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;
    return code;
}

void clip(int x1, int y1, int x2, int y2)
{
    int code1 = getCode(x1, y1), code2 = getCode(x2, y2);
    while (!(code1 == 0 && code2 == 0) && !(code1 & code2))
    {
        int ix, iy, outside = code1 ? code1 : code2;
        if (outside & TOP)
        {
            ix = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
            iy = ymax;
        }
        else if (outside & BOTTOM)
        {
            ix = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
            iy = ymin;
        }
        else if (outside & RIGHT)
        {
            iy = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
            ix = xmax;
        }
        else
        {
            iy = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
            ix = xmin;
        }
        if (outside == code1)
        {
            x1 = ix;
            y1 = iy;
            code1 = getCode(x1, y1);
        }
        else
        {
            x2 = ix;
            y2 = iy;
            code2 = getCode(x2, y2);
        }
    }
    if (code1 == 0 && code2 == 0)
    {
        line(x1, y1, x2, y2);
        printf("Line from (%d,%d) to (%d,%d)\n", x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    xmin = 10;
    ymin = 10;
    xmax = 200;
    ymax = 200;
    rectangle(xmin, ymin, xmax, ymax);
    clip(5, 5, 150, 250);
    getch();
    closegraph();
    return 0;
}
