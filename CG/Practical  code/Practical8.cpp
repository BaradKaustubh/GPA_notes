#include <graphics.h>
#include <conio.h>

void tr(int p[][2], int tx, int ty, float s, int np) {
    for(int i=0; i<np; i++) {
        p[i][0] = p[i][0]*s + tx;
        p[i][1] = p[i][1]*s + ty;
    }
}

void dr(int p[][2], int np, int c) {
    setcolor(c);
    for(int i=0; i<np; i++)
        line(p[i][0], p[i][1], p[(i+1)%np][0], p[(i+1)%np][1]);
}

int main() {
    int gd=DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    int sq[][2] = {{100,100}, {200,100}, {200,200}, {100,200}};
    
    dr(sq, 4, WHITE);
    tr(sq, 100, 100, 1, 4);
    dr(sq, 4, RED);
    tr(sq, 0, 0, 1.5, 4); 
    dr(sq, 4, GREEN);

    getch();
    closegraph();
    return 0;
}