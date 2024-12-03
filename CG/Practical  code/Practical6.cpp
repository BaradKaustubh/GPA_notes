#include <graphics.h>
#include <stdio.h>

void floodFill(int x, int y, int fill, int border)
{
    if (getpixel(x, y) != border && getpixel(x, y) != fill)
    {
        putpixel(x, y, fill);
        floodFill(x + 1, y, fill, border);
        floodFill(x - 1, y, fill, border);
        floodFill(x, y + 1, fill, border);
        floodFill(x, y - 1, fill, border);
    }
}

int main()
{
    int driver = DETECT, mode;
    initgraph(&driver, &mode, (char *)"");
    rectangle(25, 25, 275, 225);
    floodFill(26, 125, RED, WHITE);
    getch();
    closegraph();
    return 0;
}
