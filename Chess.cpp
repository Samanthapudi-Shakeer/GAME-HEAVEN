#include <bits/stdc++.h>
#include <windows.h>
#include <unordered_map>
#include "ChessPieces.cpp"

using namespace std;

void setcolor(unsigned short color);

Pawn pawn[16];    //  0-7 white    8-15 black
Rook rook[4];     //  0-1 white    2-3 black
Bishop bishop[4]; //  0-1 white    2-3 black
Knight knight[4]; //  0-1 white    2-3 black
Queen queen[2];   //  0   white    1   black
King king[2];     //  0   white    1   black

class Chess
{
private:
    char board[8][8];
    string player1, player2;
    bool gamePlayed;
    bool Over;

public:
    unordered_map<string, ChessPieces *> position;

    Chess();
    ~Chess();

    void displayBoard();

    void resetBoard();

    void setPieces();

    void setBoard();

    void menu();

    void playGame();

    string getCordinate(int a, int b);

    int getCordinatex(char a);

    int getCordinatey(char a);

    bool isValid(string);

    bool makeMove(int);
};

Chess::Chess()
{
    cout << "    ======================================\n";
    cout << "       _____ _    _ ______  _____ _____\n";
    cout << "      / ____| |  | |  ____|/ ____/ ____|\n";
    cout << "     | |    | |__| | |__   |(___ |(___ \n";
    cout << "     | |    |  __  |  __|  \\___ \\\\___ \\ \n";
    cout << "     | |____| |  | | |____ ____) |___) |\n";
    cout << "      \\_____|_|  |_|______|_____/_____/\n\n";
    cout << "    ======================================\n\n";

    gamePlayed = false;
    Over = false;
}

Chess::~Chess()
{
    cout << "Game Over!" << endl;
}

void Chess::displayBoard()
{
    setcolor(6);
    cout << "    a   b   c   d   e   f   g   h  " << endl;
    setcolor(7);
    cout << "  |---|---|---|---|---|---|---|---|" << endl;

    for (int i = 0; i < 8; ++i)
    {
        setcolor(6);
        cout << 8 - i;
        setcolor(7);

        cout << " | ";
        for (int j = 0; j < 8; ++j)
        {

            if (isupper(board[i][j]) && board[i][j] != ' ')
            {
                setcolor(240);
            }
            if (islower(board[i][j]) && board[i][j] != ' ')
            {
                setcolor(7);
            }
            cout << board[i][j];
            setcolor(7);
            cout << " | ";
        }
        cout << endl;
        cout << "  |---|---|---|---|---|---|---|---|" << endl;
    }
}

void Chess::resetBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void Chess::menu()
{
    cout << "Welcome!" << endl;
    int n;

    while (1)
    {
        cout << endl;
        setcolor(11);
        cout << ":::: CHESS MENU ::::" << endl;
        cout << "1. Start the Game" << endl;
        cout << "2. Rules" << endl;
        cout << "3. Exit " << endl;
        setcolor(7);
        cout << "Enter : ";
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "\nEnter Player 1 Name : ";
            cin >> player1;
            cout << "Enter Player 2 Name : ";
            cin >> player2;
            cout << endl;
            playGame();
            break;
        case 2:
            cout << "\n          ********Rules********" << endl
                 << "The (K)ing may move one square in any direction." << endl
                 << "The (B)ishops can move diagonally." << endl
                 << "The (R)ook may move in a straight line." << endl
                 << "The (Q)ueen can move in any direction." << endl
                 << "The k(N)ight can move in a 'L' jumping over pieces." << endl
                 << "The (P)awn on its first move can move 1 or 2 squares.\n"
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
}

void Chess::playGame()
{
    resetBoard();
    setPieces();
    setBoard();

    for (int i = 0;; i++)
    {
        displayBoard();
        cout << "\nPress -1 to End Game." << endl;
        cout << endl;
        (i % 2 == 0) ? cout << "[White] " : cout << "[Black] ";
        string t = (i % 2 == 0) ? player1 : player2;
        cout << t << "'s Turn" << endl;

        if (!makeMove(i))
        {
            i--;
        }

        if (Over)
        {
            cout << "\nThe Game was a DRAW!" << endl;
            break;
        }

        if (gamePlayed)
        {
            displayBoard();
            cout << endl;
            setcolor(13);
            cout << "Congratulations! " << t << " You Have Won.";
            setcolor(7);
            cout << endl;
            break;
        }
    }
}

void Chess::setPieces()
{
    for (int i = 0; i < 8; i++)
    {
        pawn[i].color = 'w';
        pawn[i].symbol = 'P';
        pawn[i].initialx = 6;
        pawn[i].initialy = i;

        position.insert({getCordinate(6, i), &pawn[i]});

        pawn[i + 8].color = 'b';
        pawn[i + 8].symbol = 'p';
        pawn[i + 8].initialx = 1;
        pawn[i + 8].initialy = i;

        position.insert({getCordinate(1, i), &pawn[i + 8]});

        if (i < 2)
        {
            rook[i].color = 'w';
            rook[i].symbol = 'R';
            rook[i].initialx = 7;
            rook[i].initialy = i * 7;

            position.insert({getCordinate(7, i * 7), &rook[i]});

            rook[i + 2].color = 'b';
            rook[i + 2].symbol = 'r';
            rook[i + 2].initialx = 0;
            rook[i + 2].initialy = i * 7;

            position.insert({getCordinate(0, i * 7), &rook[i + 2]});

            bishop[i].color = 'w';
            bishop[i].symbol = 'B';
            bishop[i].initialx = 7;
            bishop[i].initialy = (i * 3) + 2;

            position.insert({getCordinate(7, (i * 3) + 2), &bishop[i]});

            bishop[i + 2].color = 'b';
            bishop[i + 2].symbol = 'b';
            bishop[i + 2].initialx = 0;
            bishop[i + 2].initialy = (i * 3) + 2;

            position.insert({getCordinate(0, (i * 3) + 2), &bishop[i + 2]});

            knight[i].color = 'w';
            knight[i].symbol = 'N';
            knight[i].initialx = 7;
            knight[i].initialy = (i * 5) + 1;

            position.insert({getCordinate(7, (i * 5) + 1), &knight[i]});

            knight[i + 2].color = 'b';
            knight[i + 2].symbol = 'n';
            knight[i + 2].initialx = 0;
            knight[i + 2].initialy = (i * 5) + 1;

            position.insert({getCordinate(0, (i * 5) + 1), &knight[i + 2]});

            queen[i].color = (i % 2 == 0) ? 'w' : 'b';
            queen[i].symbol = (i % 2 == 0) ? 'Q' : 'q';
            queen[i].initialx = (i % 2 == 0) ? 7 : 0;
            queen[i].initialy = 3;

            position.insert({getCordinate(queen[i].initialx, queen[i].initialy), &queen[i]});

            king[i].color = (i % 2 == 0) ? 'w' : 'b';
            king[i].symbol = (i % 2 == 0) ? 'K' : 'k';
            king[i].initialx = (i % 2 == 0) ? 7 : 0;
            king[i].initialy = 4;

            position.insert({getCordinate(king[i].initialx, king[i].initialy), &king[i]});
        }
    }
}

void Chess::setBoard()
{
    for (int i = 0; i < 8; i++)
    {
        board[pawn[i].initialx][pawn[i].initialy] = pawn[i].symbol;
        board[pawn[i + 8].initialx][pawn[i + 8].initialy] = pawn[i + 8].symbol;
        if (i < 2)
        {
            board[rook[i].initialx][rook[i].initialy] = rook[i].symbol;
            board[rook[i + 2].initialx][rook[i + 2].initialy] = rook[i + 2].symbol;

            board[bishop[i].initialx][bishop[i].initialy] = bishop[i].symbol;
            board[bishop[i + 2].initialx][bishop[i + 2].initialy] = bishop[i + 2].symbol;

            board[knight[i].initialx][knight[i].initialy] = knight[i].symbol;
            board[knight[i + 2].initialx][knight[i + 2].initialy] = knight[i + 2].symbol;

            board[queen[i].initialx][queen[i].initialy] = queen[i].symbol;

            board[king[i].initialx][king[i].initialy] = king[i].symbol;
        }
    }
}

string Chess::getCordinate(int a, int b)
{
    string ans = "";
    string no1 = "abcdefgh", no2 = "12345678";

    ans += no1[b];
    ans += no2[7 - a];
    return ans;
}

int Chess::getCordinatey(char a)
{
    return a - 97;
}

int Chess::getCordinatex(char a)
{
    return 8 - (a - '0');
}

bool Chess::isValid(string m)
{
    return (0 <= getCordinatex(m[1]) && getCordinatex(m[1]) < 8) && (0 <= getCordinatey(m[0]) && getCordinatey(m[0]) < 8);
}

bool Chess::makeMove(int x)
{
    string m, t;
    cout << "Enter the source piece coordinate (e.g. 'e4'): ";
    cin >> m;
    cout << "Enter the destination coordinate (e.g. 'e5'): ";
    cin >> t;

    if (m == "-1" || t == "-1")
    {
        Over = true;
        return false;
    }

    if (m == t)
    {
        setcolor(12);
        cout << "\nYou can't move to the same position!\n"
             << endl;
        setcolor(7);
        return false;
    }

    if (!isValid(m) || !isValid(t))
    {
        setcolor(12);
        cout << "\nInvalid Selection of Move!\n"
             << endl;
        setcolor(7);
        return false;
    }

    char move_color = (x % 2 == 0) ? 'w' : 'b';

    if (position.count(m) == 0)
    {
        setcolor(12);
        cout << "\nNo Piece found at the source coordinate\n"
             << endl;
        setcolor(7);
        return false;
    }
    else
    {
        ChessPieces *temp = position[m];
        if (move_color != temp->color)
        {
            setcolor(12);
            cout << "\nYou can only move your piece only!\n"
                 << endl;
            setcolor(7);
            return false;
        }

        ChessPieces *temp2;
        bool captured = false;

        if (position.count(t))
        {
            temp2 = position[t];
            if (tolower(temp2->symbol) == 'k' && temp2->color != move_color)
            {
                gamePlayed = true;
            }
            else if (temp2->color == move_color)
            {
                setcolor(12);
                cout << "\nYou can't capture your own piece!\n"
                     << endl;
                setcolor(7);
                return false;
            }
            if (temp2->color == 'w' || temp2->color == 'b')
                captured = true;
        }

        if (temp->isValidMove(temp->initialx, temp->initialy, getCordinatex(t[1]), getCordinatey(tolower(t[0])), captured))
        {
            if (captured)
            {
                setcolor(3);
                cout << endl
                     << temp->name << "[" << temp->color << "]"
                     << " Captured " << temp2->name << "[" << temp2->color << "]"
                     << "!\n"
                     << endl;
                setcolor(7);
            }

            board[temp->initialx][temp->initialy] = ' ';
            position.erase(m);
            position[t] = temp;

            temp->initialx = getCordinatex(t[1]);
            temp->initialy = getCordinatey(tolower(t[0]));

            board[temp->initialx][temp->initialy] = temp->symbol;

            return true;
        }
        else
        {
            gamePlayed = false;
            setcolor(12);
            cout << "\nInvalid Move!\n"
                 << endl;
            setcolor(7);
            return false;
        }
    }
    return true;
}

// void setcolor(unsigned short color)
// {
//     HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
//     SetConsoleTextAttribute(hcon, color);
// }

void playChess()
{
    Chess obj;
    obj.menu();
}
