#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <map>
#include <ctime>

using namespace std;

// void setcolor(unsigned short color);

class snakeandladders
{
private:
    string name1, name2;
    int snakes[8] = {17, 54, 62, 64, 87, 93, 95, 98};
    int ladders[8] = {1, 4, 9, 21, 28, 51, 72, 80};

public:
    int boardSize;
    int player1Position;
    int player2Position;

    snakeandladders();

    void startgame();
    bool Snake(int position);
    bool Ladder(int position);
    bool Won(int position);
    void moveposition();
    void playSandL();
    int Die();
    void printBoard();
    int printRandomNumber(int position); // Corrected function signature
    ~snakeandladders();
};

snakeandladders::snakeandladders()
{
    boardSize = 100;
    player1Position = 0;
    player2Position = 0;

    // Constructor, you can initialize variables here if needed
}

snakeandladders::~snakeandladders()
{
    cout << "Please try another game" << endl;
}

int snakeandladders::Die()
{
    return (rand() % 6) + 1;
}

int snakeandladders::printRandomNumber(int position)
{
    srand(time(0));

    int random_number_1_to_n = rand() % position + 1;
    return random_number_1_to_n;
}

bool snakeandladders::Won(int position)
{
    return position >= boardSize;
}

bool snakeandladders::Snake(int position)
{
    for (int i = 0; i < 8; i++)
    { // Changed the loop limit to 8
        if (position == snakes[i])
        {
            return true;
        }
    }
    return false;
}

bool snakeandladders::Ladder(int position)
{
    for (int i = 0; i < 8; i++)
    { // Changed the loop limit to 8
        if (position == ladders[i])
        {
            return true;
        }
    }
    return false;
}

void snakeandladders::printBoard()
{
    cout << "\nSnake and Ladders Board:" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    for (int row = 9; row >= 0; row--)
    {
        cout << "| ";
        for (int col = 0; col < 10; col++)
        {
            int square = row * 10 + col + 1;
            // Print player positions
            if (player1Position == square && player2Position == square)
            {
                setcolor(14); // Set color to yellow
                cout << "P1P2";
                setcolor(7);
            }
            else if (player1Position == square)
            {
                setcolor(12); // Set color to red
                cout << "P1";
                setcolor(7);
            }
            else if (player2Position == square)
            {
                setcolor(10); // Set color to green
                cout << "P2";
                setcolor(7);
            }
            else
            {
                cout << square;
                if (square == 100)
                {
                    cout << "|";
                    continue;
                }
            }

            // Print snakes and ladders with colors
            if (Snake(square))
            {
                setcolor(3); // Set color to cyan for snakes
                cout << "S";
                setcolor(7);
                cout << "|";
            }
            else if (Ladder(square))
            {
                setcolor(13); // Set color to purple for ladders
                cout << "L";
                setcolor(7);
                cout << "|";
            }
            else
            {
                cout << " |";
            }
            cout << "\t";
        }
        cout << endl;
        cout << "----------------------------------------------------------------------------" << endl;
    }
    cout << endl;
}

// void setcolor(unsigned short color)
// {
//     HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
//     SetConsoleTextAttribute(hcon, color);
// }

void snakeandladders::playSandL()
{

    cout << "Welcome to Snake and Ladders!" << endl;
    cout << "Enter the names of player 1 : ";
    cin >> name1;
    cout << "Enter the names of player 2 : ";
    cin >> name2;
    string currentPlayer = name1;
    int y = 1;
    int n;

    while (y)
    {

        printBoard();
        cout << "press 0 to exit" << endl;
        cout << "press 1 to Roll the Dice [" << currentPlayer << "] : ";
        cin >> n;
        if (n == y)
        {
            y = 1;
        }
        else
        {
            y = 0;
            cout << "Exiting" << endl;
            break;
        }
        int roll = Die();
        cout << "Woww " << currentPlayer << " rolled a " << roll << ". ";

        if (currentPlayer == name1)
        {
            if (player1Position + roll <= boardSize)
            {
                player1Position += roll;
                if (Snake(player1Position))
                {
                    cout << endl;
                    setcolor(12);
                    cout <<currentPlayer<< " There is a Snake to bite you . Go back!";
                    setcolor(7);
                    cout << endl;
                    player1Position -= printRandomNumber(player1Position);
                }
                else if (Ladder(player1Position))
                {
                    cout << endl;
                    setcolor(5);
                    cout << "Hurray!!"<<currentPlayer<<"You have climbed a Ladder Going Fast Ahh!!";
                    setcolor(7);
                    cout << endl;
                    player1Position += printRandomNumber(boardSize - player1Position);
                }
                cout<<"\n";
                cout<<currentPlayer<< " you are at position " << player1Position << endl;
                if (Won(player1Position))
                {
                    cout << endl;
                    setcolor(13);
                    cout << "Congratulations! " << currentPlayer << " You Have Won.";
                    setcolor(7);
                    cout << endl
                         << endl;
                    break;
                }
                currentPlayer = name2;
            }
        }
        else
        {
            if (player2Position + roll <= boardSize)
            {
                player2Position += roll;
                if (Snake(player2Position))
                {
                    cout << endl;
                    setcolor(12);
                    cout <<currentPlayer<< " There is a Snake to bite you . Go back!";
                    setcolor(7);
                    cout << endl;
                    player2Position -= printRandomNumber(player2Position);
                    // printBoard();
                }
                else if (Ladder(player2Position))
                {
                    cout << endl;
                    setcolor(5);
                    cout << "Hurray!!"<<currentPlayer<<"You have climbed a Ladder Going Fast Ahh!!";
                    setcolor(7);
                    cout << endl;
                    player2Position += printRandomNumber(boardSize - player2Position);
                    // printBoard();
                }
                cout<<"\n";
                cout<<currentPlayer<< " you are at position " << player1Position << endl;
                if (Won(player2Position))
                {
                    cout << endl;
                    setcolor(13);
                    cout << "Congratulations! " << currentPlayer << " You Have Won.";
                    setcolor(7);
                    cout << endl
                         << endl;
                    break;
                }
                currentPlayer = name1;
            }
        }
    }
    return;
}

void playgame()
{
    snakeandladders game;
    game.playSandL();
}

void playsal()
{

    cout << "Welcome To SNAKE AND LADDERS ..." << endl;
    int n;

    while (1)
    {
        cout << endl;
        setcolor(11);
        cout << ":::: SNAKE AND LADDERS MENU ::::" << endl;
        cout << "1. Start the Game" << endl;
        cout << "2. Rules" << endl;
        cout << "3. Exit " << endl;
        setcolor(7);
        cout << "Enter Choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
            playgame();
            break;
        case 2:
            cout << "\n                    ********   Rules   ********" << endl
                 << "1. Players aim to reach or exceed the final square (100) on the game board." << endl
                 << "2. Ladders provide shortcuts and snakes acts as obstacles." << endl
                 << "3. Players take turns rolling a die, moving forward the number of squares indicated by the roll." << endl
                 << "4. Landing on the base of a ladder allows a player to climb to the top, advancing their position." << endl
                 << "5. Landing on the head of a snake forces a player to slide down to the tail, setting them back.\n"
                 << endl;
            break;
        case 3:
            return;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

    return;
}
