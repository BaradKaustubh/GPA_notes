#include <stdio.h>

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int checkWin();
void displayBoard();

int main()
{
    int player = 1, choice, result = -1;
    char mark;

    do
    {
        displayBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 9 && board[choice - 1] == choice + '0')
        {
            board[choice - 1] = mark;
        }
        else
        {
            printf("Invalid move!\n");
            player--;
        }

        result = checkWin();
        player++;
    } while (result == -1);

    displayBoard();
    if (result == 1)
        printf("Player %d wins!\n", --player);
    else
        printf("It's a draw!\n");

    return 0;
}

void displayBoard()
{
    printf("\n %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n\n", board[6], board[7], board[8]);
}

int checkWin()
{
    int winLines[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (int i = 0; i < 8; i++)
    {
        if (board[winLines[i][0]] == board[winLines[i][1]] && board[winLines[i][1]] == board[winLines[i][2]])
            return 1;
    }
    for (int i = 0; i < 9; i++)
        if (board[i] >= '1' && board[i] <= '9')
            return -1;
    return 0;
}
