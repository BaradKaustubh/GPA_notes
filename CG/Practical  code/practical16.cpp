#include <graphics.h>

void drawBezierCurve(int x[], int y[]) {
    for (float t = 0; t <= 1; t += 0.001) {
        float x0 = (1 - t) * (1 - t) * (1 - t) * x[0] +
                  3 * t * (1 - t) * (1 - t) * x[1] +
                  3 * t * t * (1 - t) * x[2] +
                  t * t * t * x[3];

        float y0 = (1 - t) * (1 - t) * (1 - t) * y[0] +
                  3 * t * (1 - t) * (1 - t) * y[1] +
                  3 * t * t * (1 - t) * y[2] +
                  t * t * t * y[3];

        putpixel(x0, y0, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x[] = {50, 200, 400, 550};
    int y[] = {300, 50, 550, 300};

    drawBezierCurve(x, y);

    getch();
    closegraph();
    return 0;
}