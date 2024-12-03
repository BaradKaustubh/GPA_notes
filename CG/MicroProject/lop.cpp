#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
const int COLOR_RED = COLOR(255, 51, 51);
const int COLOR_ORANGE = COLOR(255, 153, 51);
const int COLOR_YELLOW = COLOR(255, 255, 102);
const int COLOR_GREEN = COLOR(102, 255, 102);
const int COLOR_BLUE = COLOR(51, 153, 255);
const int COLOR_INDIGO = COLOR(102, 0, 204);
const int COLOR_VIOLET = COLOR(255, 102, 255);
const int WINDOW_WIDTH = 660;
const int WINDOW_HEIGHT = 550;
void drawDisk(const int &x, const int &y, const int &size) {
    static const int colors[] = {COLOR_RED, COLOR_ORANGE, COLOR_YELLOW, COLOR_GREEN, COLOR_BLUE, COLOR_INDIGO, COLOR_VIOLET};
    for (int i = 0; i < 20; ++i) {
        setfillstyle(SOLID_FILL, COLOR(
                                     GetRValue(colors[size - 1]) - i * 3,
                                     GetGValue(colors[size - 1]) - i * 3,
                                     GetBValue(colors[size - 1]) - i * 3));
        bar(x - size * 20, y + i, x + size * 20, y + i + 1);
    }
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    for (int i = 0; i < 3; ++i) {
        line(x - size * 20 + 5, y + 3 + i, x + size * 20 - 5, y + 3 + i);
        setcolor(COLOR(255, 255, 255));
    }
    setcolor(WHITE);
    for (int i = 0; i < 2; ++i) {
        rectangle(x - size * 20 - i, y - i, x + size * 20 + i, y + 20 + i);
    }
    for (int i = 0; i < 5; ++i) {
        line(x - size * 20 - 2, y - 2 + i, x - size * 20 + 5, y - 2 + i);
        line(x - size * 20 - 2 + i, y - 2, x - size * 20 - 2 + i, y + 5);
        line(x + size * 20 + 2, y - 2 + i, x + size * 20 - 5, y - 2 + i);
        line(x + size * 20 + 2 - i, y - 2, x + size * 20 + 2 - i, y + 5);
    }
}
inline int getTowerIndex(const int &x) {
    if (x < WINDOW_WIDTH / 3) return 0;
    if (x < 2 * WINDOW_WIDTH / 3) return 1;
    return 2;
}
int getTopDisk(int towers[3][7], const int &tower) {
    for (int i = 6; i >= 0; --i)
        if (towers[tower][i]) return towers[tower][i];
    return 0;
}
void drawTowers(int towers[3][7], const int &numDisks, char *moveText, const int &moveCount) {
    static const int towerX[3] = {WINDOW_WIDTH / 6, WINDOW_WIDTH / 2, 5 * WINDOW_WIDTH / 6};
    const int towerBaseHeight = WINDOW_HEIGHT - 140;
    const int btnX = WINDOW_WIDTH - 140;
    cleardevice();
    setfillstyle(SOLID_FILL, COLOR(10, 15, 35));
    bar(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    for (int i = 0; i < 100; ++i) {
        const int brightness = rand() % 256;
        putpixel(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT, COLOR(brightness, brightness, brightness));
    }
    int btnY = 12;
    setfillstyle(SOLID_FILL, COLOR(60, 179, 113));
    bar(btnX, btnY, btnX + 120, btnY + 30);
    for (int i = 0; i < 30; ++i) {
        setcolor(COLOR(60 + i, 179 + i / 2, 113 + i / 2));
        line(btnX, btnY + i, btnX + 120, btnY + i);
    }
    setcolor(WHITE);
    rectangle(btnX, btnY, btnX + 120, btnY + 30);
    rectangle(btnX - 1, btnY - 1, btnX + 121, btnY + 31);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(btnX + 10, btnY + 5, "Auto Solve");
    btnY += 40;
    setfillstyle(SOLID_FILL, COLOR(220, 60, 60));
    bar(btnX, btnY, btnX + 120, btnY + 30);
    for (int i = 0; i < 30; ++i) {
        setcolor(COLOR(220 + i / 2, 60 + i / 2, 60 + i / 2));
        line(btnX, btnY + i, btnX + 120, btnY + i);
    }
    setcolor(WHITE);
    rectangle(btnX, btnY, btnX + 120, btnY + 30);
    rectangle(btnX - 1, btnY - 1, btnX + 121, btnY + 31);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(btnX + 30, btnY + 5, "Reset");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 25; ++j) {
            setfillstyle(SOLID_FILL, COLOR(180 + j * 2, 180 + j * 2, 180 + j * 2));
            bar(towerX[i] - 45, towerBaseHeight + j, towerX[i] + 45, towerBaseHeight + j + 1);
        }
        setcolor(COLOR(220, 220, 220));
        for (int b = 0; b < 3; ++b)
            rectangle(towerX[i] - 46 + b, towerBaseHeight - 1 + b, towerX[i] + 46 - b, towerBaseHeight + 26 - b);
        setfillstyle(SOLID_FILL, COLOR(200, 200, 200));
        bar(towerX[i] - 10, WINDOW_HEIGHT / 4, towerX[i] + 10, towerBaseHeight);
        setcolor(COLOR(240, 240, 240));
        line(towerX[i] - 10, WINDOW_HEIGHT / 4, towerX[i] - 10, towerBaseHeight);
        setcolor(COLOR(160, 160, 160));
        line(towerX[i] + 10, WINDOW_HEIGHT / 4, towerX[i] + 10, towerBaseHeight);
        setfillstyle(SOLID_FILL, COLOR(180, 180, 180));
        bar(towerX[i] - 20, WINDOW_HEIGHT / 4 - 15, towerX[i] + 20, WINDOW_HEIGHT / 4);
        for (int t = 0; t < 2; ++t) {
            setcolor(COLOR(220 - t * 30, 220 - t * 30, 220 - t * 30));
            rectangle(towerX[i] - 20 - t, WINDOW_HEIGHT / 4 - 15 - t, towerX[i] + 20 + t, WINDOW_HEIGHT / 4 + t);
        }
        for (int j = 0; j < numDisks; ++j)
            if (towers[i][j]) drawDisk(towerX[i], towerBaseHeight - 35 - j * 28, towers[i][j]);
        setcolor(WHITE);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        char label[15];
        sprintf(label, "Tower %c", 'A' + i);
        rectangle(towerX[i] - 40, towerBaseHeight + 35, towerX[i] + 40, towerBaseHeight + 60);
        rectangle(towerX[i] - 41, towerBaseHeight + 34, towerX[i] + 41, towerBaseHeight + 61);
        outtextxy(towerX[i] - 35, towerBaseHeight + 40, label);
    }
    setcolor(COLOR(255, 215, 0));
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    rectangle(WINDOW_WIDTH / 2 - 200, 40, WINDOW_WIDTH / 2 + 200, 75);
    rectangle(WINDOW_WIDTH / 2 - 202, 38, WINDOW_WIDTH / 2 + 202, 77);
    outtextxy(WINDOW_WIDTH / 2 - 190, 50, moveText);
    char stepCountText[20];
    sprintf(stepCountText, "Moves: %d", moveCount);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    rectangle(10, 10, 120, 40);
    rectangle(8, 8, 122, 42);
    outtextxy(15, 15, stepCountText);
}
inline bool isMoveValid(int towers[3][7], const int &from, const int &to, const int &disk) {
    const int topDisk = getTopDisk(towers, to);
    return (topDisk == 0 || topDisk > disk);
}
void moveDisk(int towers[3][7], const int &from, const int &to, const int &disk) {
    for (int i = 0; i < 7; ++i) {
        if (towers[from][i] == disk) {
            towers[from][i] = 0;
            break;
        }
    }
    for (int i = 0; i < 7; ++i) {
        if (towers[to][i] == 0) {
            towers[to][i] = disk;
            break;
        }
    }
}
void solveTowerOfHanoi(int towers[3][7], const int &n, const int &from, const int &to, const int &aux, const int &numDisks, int &moveCount) {
    if (n == 1) {
        const int disk = getTopDisk(towers, from);
        moveDisk(towers, from, to, disk);
        ++moveCount;
        char msg[50];
        sprintf(msg, "Auto-moving disk from Tower %c to %c", 'A' + from, 'A' + to);
        drawTowers(towers, numDisks, msg, moveCount);
        delay(800);
        return;
    }
    solveTowerOfHanoi(towers, n - 1, from, aux, to, numDisks, moveCount);
    solveTowerOfHanoi(towers, 1, from, to, aux, numDisks, moveCount);
    solveTowerOfHanoi(towers, n - 1, aux, to, from, numDisks, moveCount);
}
int main() {
    int numDisks;
    printf("Enter number of disks (1-7): ");
    scanf("%d", &numDisks);
    if (numDisks < 1 || numDisks > 7) {
        printf("Invalid input! Please enter 1-7 disks.\n");
        return 1;
    }
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int towers[3][7] = {{0}};
    for (int i = 0; i < numDisks; ++i) towers[0][i] = numDisks - i;
    int moveCount = 0;
    int selectedTower = -1;
    int x, y;
    drawTowers(towers, numDisks, "Click source and destination towers", moveCount);
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x >= WINDOW_WIDTH - 140 && x <= WINDOW_WIDTH - 20 && y >= 12 && y <= 42) {
                memset(towers, 0, sizeof(towers));
                for (int i = 0; i < numDisks; ++i) towers[0][i] = numDisks - i;
                moveCount = 0;
                selectedTower = -1;
                solveTowerOfHanoi(towers, numDisks, 0, 2, 1, numDisks, moveCount);
                continue;
            }
            if (x >= WINDOW_WIDTH - 140 && x <= WINDOW_WIDTH - 20 && y >= 52 && y <= 82) {
                memset(towers, 0, sizeof(towers));
                for (int i = 0; i < numDisks; ++i) towers[0][i] = numDisks - i;
                moveCount = 0;
                selectedTower = -1;
                drawTowers(towers, numDisks, "Game Reset! Click source and destination towers", moveCount);
                continue;
            }
            const int clickedTower = getTowerIndex(x);
            if (selectedTower == -1) {
                const int topDisk = getTopDisk(towers, clickedTower);
                if (topDisk > 0) {
                    selectedTower = clickedTower;
                    char msg[50];
                    sprintf(msg, "Selected Tower %c", 'A' + clickedTower);
                    drawTowers(towers, numDisks, msg, moveCount);
                }
            } else {
                const int disk = getTopDisk(towers, selectedTower);
                if (isMoveValid(towers, selectedTower, clickedTower, disk)) {
                    moveDisk(towers, selectedTower, clickedTower, disk);
                    ++moveCount;
                    char msg[50];
                    sprintf(msg, "Moved disk from Tower %c to %c", 'A' + selectedTower, 'A' + clickedTower);
                    drawTowers(towers, numDisks, msg, moveCount);
                }
                selectedTower = -1;
            }
        }
        if (towers[2][numDisks - 1] != 0) {
            for (int i = 0; i < 50; ++i) {
                const int x = rand() % WINDOW_WIDTH;
                const int y = rand() % WINDOW_HEIGHT;
                const int color = rand() % 15 + 1;
                setcolor(color);
                circle(x, y, rand() % 5 + 1);
                delay(20);
            }
            char solvedText[50];
            sprintf(solvedText, "Puzzle Completed in %d Moves!", moveCount);
            setcolor(COLOR(255, 215, 0));
            settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
            rectangle(WINDOW_WIDTH / 2 - 250, 90, WINDOW_WIDTH / 2 + 250, 130);
            rectangle(WINDOW_WIDTH / 2 - 252, 88, WINDOW_WIDTH / 2 + 252, 132);
            outtextxy(WINDOW_WIDTH / 2 - 240, 100, solvedText);
            break;
        }
        delay(30);
    }
    getch();
    closegraph();
    return 0;
}