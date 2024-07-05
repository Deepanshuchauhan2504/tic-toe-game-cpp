#include <iostream>
#include <stdlib.h>
#include <conio.h> 
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();
void guide();

int main()
{
    int player = 1, i, choice, option;
    char mark, choice1;

    do {
        system("cls"); // Use system("clear") for Unix/Linux, "cls" for Windows
        std::cout << "1. ENTER THE GAME\n2. USER GUIDE\n3. EXIT\n";
        std::cin >> option;

        switch(option) {
            case 1:
                do {
                    board();
                    player = (player % 2) ? 1 : 2;
                    std::cout << "Player " << player << ", enter a number: ";
                    std::cin >> choice;
                    mark = (player == 1) ? 'X' : 'O';

                    if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice) {
                        square[choice] = mark;
                    } else {
                        std::cout << "Invalid move! ";
                        player--;
                        getch();
                    }

                    i = checkwin();
                    player++;
                } while (i == -1);

                board();
                if (i == 1)
                    std::cout << "==>\aPlayer " << --player << " wins!\n";
                else
                    std::cout << "==>\aGame draw\n";
                break;

            case 2:
                guide();
                break;

            case 3:
                exit(0);
                break;

            default:
                std::cout << "Wrong Choice\n";
        }

        std::cout << "\nDo you want to continue? (y/n): ";
        std::cin >> choice1;
    } while (choice1 == 'y' || choice1 == 'Y');

    return 0;
}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

void board()
{
    system("cls"); // Use system("clear") for Unix/Linux, "cls" for Windows
    std::cout << "\n\n\tTic Tac Toe\n\n";
    std::cout << "Player 1 (X)  -  Player 2 (O)\n\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "\n";
    std::cout << "\t\t_____|_____|_____\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "\n";
    std::cout << "\t\t_____|_____|_____\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "\n";
    std::cout << "\t\t     |     |     \n\n";
}

void guide()
{
    system("cls"); // Use system("clear") for Unix/Linux, "cls" for Windows
    std::cout << "\nThe Tic Tac Toe game board looks like this:\n\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  1  |  2  |  3  \n";
    std::cout << "\t\t_____|_____|_____\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  4  |  5  |  6  \n";
    std::cout << "\t\t_____|_____|_____\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  7  |  8  |  9  \n";
    std::cout << "\t\t     |     |     \n\n";
    std::cout << "Players take turns marking a square. The player who succeeds in placing three of their marks in a\n";
    std::cout << "horizontal, vertical, or diagonal row wins the game.\n\n";
}
