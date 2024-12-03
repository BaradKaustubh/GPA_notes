#include <graphics.h>
#include <math.h>

typedef struct
{
    float x, y, z;
} P3D;

void prj(P3D p, int *sx, int *sy) 
{
    *sx = p.x + p.z / 2;
    *sy = p.y + p.z / 2;
}

void trns(P3D p[], int np, float tx, float ty, float tz, float s)
{
    for (int i = 0; i < np; i++)
    {
        p[i].x = p[i].x * s + tx;
        p[i].y = p[i].y * s + ty;
        p[i].z = p[i].z * s + tz;
    }
}

void drCube(P3D v[])
{
    int sx[8], sy[8];
    for (int i = 0; i < 8; i++)
        prj(v[i], &sx[i], &sy[i]);
    for (int e = 0; e < 4; e++)
    {
        line(sx[e], sy[e], sx[(e + 1) % 4], sy[(e + 1) % 4]);
        line(sx[e + 4], sy[e + 4], sx[(e + 1) % 4 + 4], sy[(e + 1) % 4 + 4]);
        line(sx[e], sy[e], sx[e + 4], sy[e + 4]);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    P3D cv[8] = {
        {25, 25, 100}, {125, 25, 100}, {125, 125, 100}, {25, 125, 100},
        {25, 25, 200}, {125, 25, 200}, {125, 125, 200}, {25, 125, 200}
    };
    setcolor(WHITE);
    drCube(cv);
    trns(cv, 8, 50, 50, 50, 1);
    setcolor(RED);
    drCube(cv);
    trns(cv, 8, 0, 0, 0, 1.5);
    setcolor(GREEN);
    drCube(cv);
    getch();
    closegraph();
    return 0;
}