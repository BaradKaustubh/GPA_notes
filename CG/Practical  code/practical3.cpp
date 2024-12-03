#include <graphics.h>
#include <conio.h>

void drawLineDDA(int startX, int startY, int endX, int endY) {
    float currentX = startX, currentY = startY;
    int totalSteps = abs(endX-startX) > abs(endY-startY) ? abs(endX-startX) : abs(endY-startY);
    float xIncrement = (endX-startX)/(float)totalSteps;
    float yIncrement = (endY-startY)/(float)totalSteps;
    while(totalSteps-- >= 0) {
        putpixel(currentX, currentY, WHITE);
        currentX += xIncrement;
        currentY += yIncrement;
    }
}

int main() {
    int graphDriver = DETECT, graphMode;
    initgraph(&graphDriver, &graphMode, (char*)"");
    drawLineDDA(100, 100, 400, 300);
    getch();
    closegraph();
    return 0;
}
