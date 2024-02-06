#include <bits/stdc++.h>
#include <windows.h>
//Original File - Shakeer
#include "Rock.cpp"
#include "XOplay.cpp"
#include "SudokoPlay.cpp"
#include "Chess.cpp"
#include "16puzz.cpp"
#include "Guessword.cpp"
#include "SnakeLadders.cpp"


using namespace std;

void setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
}

void logo()
{
    cout << "WELCOME! TO " << endl
         << endl;

    string logo[5] = {
        " GGGGGGG    AAAAA   M     M  EEEEEEE    H     H   EEEEEEE   AAAAA    V    V  EEEEEEE   NN    N    ",
        "G          A     A  MM   MM  E          H     H   E        A     A   V    V  E         NN    N    ",
        "G   G G G  AAAAAAA  M M M M  EEEEE      HHHHHHH   EEEEE    AAAAAAA   V    V  EEEEE     N N   N    ",
        "G   G   G  A     A  M  M  M  E          H     H   E        A     A    V  V   E         N  N  N    ",
        " GGGGGGG   A     A  M     M  EEEEEEE    H     H   EEEEEEE  A     A     VV    EEEEEEE   N   NNN    "};

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < logo[i].size(); ++j)
        {
            if (j <= 37)
            {
                setcolor(11);
            }
            else
            {
                setcolor(12);
            }
            cout << logo[i][j];
            setcolor(7);
        }
        cout << endl;
    }
    cout << endl;
}

void playTicTacTie()
{
    XO *game = new XO();
    game->menu();
    delete game;
}

int main()
{

    logo();
    int n;
    while (1)
    {
        cout << endl;
        setcolor(12);
        cout << ":::: GAME__HEAVEN__MENU ::::" << endl;
        setcolor(7);
        cout<<endl;
        setcolor(5);
        cout << "1. Play Tic-Tac-Toe." << endl;
        cout << "2. Play Sudoko." << endl;
        cout << "3. Play Rock Paper Scissors Game."<<endl;
        cout << "4. Play Chess." << endl;
        cout << "5. Play Snake and Ladders." << endl;
        cout << "6. Play Word Guessing Game. "<<endl;
        cout << "7. Play 16 Puzzle Game." << endl;
        cout << "8. About Game Heaven." << endl;
        cout << "9. Exit the Game Heaven !"<<endl;
        setcolor(7);
        cout << "Enter Choice : ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << endl;
            playTicTacTie();
            break;
        case 2:
            playSudoku();
            break;
        case 3: 
            playrock();
            break;
        case 4:
            playChess();
            break;
        case 5:
            playsal();
            break;
        case 8:
            setcolor(11);
            cout << "\nAbout :: Game Heaven:" << endl;
            cout << "The Game Heaven project's main objective was to create an entertaining platform \n Provides players with smooth game switching.";
            setcolor(7);
            cout<<endl;
            cout<<endl;
            break;
        case 9:
            setcolor(12);
            cout << "\nEXITING... SUCCESSFULLY.";
            setcolor(7);
            return 0;
            break;
        case 6: 
            playguess();
            break;
        case 7:
            play16();
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    }

    return 0;
}
