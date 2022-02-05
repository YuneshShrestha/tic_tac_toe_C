#include <stdio.h>
#include <stdlib.h>
int board[3][3], flag = 1;
int winner;
void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 10)
            {
                printf("X ");
            }
            else if (board[i][j] == 11)
            {
                printf("O ");
            }
            else
            {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}
void checkWinner()
{
    int i = 0, j = 0;
    // Diagnol 1 check
    if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2])
    {
        winner = board[i][j];
        flag = 0;
    }
    // Diagonal check 2
    else if (board[i][j + 2] == board[i + 1][j + 1] && board[i][j + 2] == board[i + 2][j])
    {
        winner = board[i][j + 2];
        flag = 0;
    }
    // vertical checking
    else if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
    {
        winner = board[i][j];
        flag = 0;
    }
    else if (board[i][j + 1] == board[i + 1][j + 1] && board[i][j + 1] == board[i + 2][j + 1])
    {
        winner = board[i][j + 1];
        flag = 0;
    }
    else if (board[i][j + 2] == board[i + 1][j + 2] && board[i][j + 2] == board[i + 2][j + 2])
    {
        winner = board[i][j + 2];
        flag = 0;
    }
    // horizontal checking
    else if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
    {
        winner = board[i][j];
        flag = 0;
    }
    else if (board[i + 1][j] == board[i + 1][j + 1] && board[i + 1][j] == board[i + 1][j + 2])
    {
        winner = board[i + 1][j];
        flag = 0;
    }
    else if (board[i + 2][j] == board[i + 2][j + 1] && board[i + 2][j] == board[i + 2][j + 2])
    {
        winner = board[i + 2][j];
        flag = 0;
    }
}
int main()
{
    int count = 0, player = 10, choice;
    char playerName;
    // Initialize the board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ++count;
        }
    }
    printBoard();
    while (count > 0 && flag == 1)
    {
        if (player == 10)
        {
            playerName = 'X';
        }
        else
        {
            playerName = '0';
        }

        if (count > 2)
        {
            printf("\nPlayer %c's Turn: (Pick Your Choice): ", playerName, count);
        }
        else
        {
            printf("\nPlayer %c's Turn: (Final Move): ", playerName);
        }
        scanf("%d", &choice);
        if (choice > 9 || choice < 1)
        {
            printf("Invalid choice\n");
            continue;
        }
        else
        {
            // Changing state
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == choice)
                    {
                        board[i][j] = player;
                        // Toggle Player
                        if (player == 10)
                        {
                            player = 11;
                            count--;
                            checkWinner();
                        }
                        else
                        {
                            player = 10;
                            count--;
                            checkWinner();
                        }

                        break;
                    }
                }
            }
            // Clear Screen Everytime
            system("cls");
            // Printing the board
            printBoard();
            if (flag == 0 && count >= 0)
            {
                if (winner == 10)
                {
                    printf("\nX is Winner!!!\n");
                }
                else
                {
                    printf("\nO is Winner!!!\n");
                }
            }
            else if (count == 0 && flag == 1)
            {
                printf("\nDraw Game!!!\n");
            }
        }
    }

    return 0;
}