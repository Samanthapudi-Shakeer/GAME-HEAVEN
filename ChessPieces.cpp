#include <bits/stdc++.h>
using namespace std;

class ChessPieces
{
private:
public:
    char color;
    string name;
    int initialx, initialy;
    char symbol;
    int point;
    virtual void aboutMe() = 0;
    virtual bool isValidMove(int, int, int, int, bool) = 0;
};

class Pawn : public ChessPieces
{
public:
    Pawn()
    {
        name = "Pawn";
        point = 1;
        symbol = 'p';
    }
    void aboutMe()
    {
        cout << "I am the Pawn" << endl;
    }

    bool isValidMove(int x1, int y1, int x2, int y2, bool captured) override
    {
        // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        int deltaX = x2 - x1;
        int deltaY = y2 - y1;
        cout << captured;
        if (((deltaY == 0 && x2 > x1 && deltaX < 2 && deltaX > 0) || (deltaY == 0 && x2 < x1 && deltaX > -2 && deltaX < 0)) && !captured)
        {
            return true;
        }
        else if (((deltaY == 0 && x2 > x1 && x1 == 1 && deltaX <= 2 && deltaX > 0) || (deltaY == 0 && x2 < x1 && x1 == 6 && deltaX >= -2 && deltaX < 0)) && !captured)
        {
            return true;
        }
        else if ((abs(deltaY) == 1 && x2 > x1 && deltaX == 1) || (abs(deltaY) == 1 && x2 < x1 && deltaX == -1) && captured)
        {
            return true;
        }

        return false;
    }

    ~Pawn() {}
};

class Rook : public ChessPieces
{
public:
    Rook()
    {
        name = "Rook";
        point = 5;
        symbol = 'r';
    }
    void aboutMe()
    {
        cout << "I am the Rook" << endl;
    }
    bool isValidMove(int x1, int y1, int x2, int y2, bool captured) override
    {
        int deltaX = x2 - x1;
        int deltaY = y2 - y1;

        if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0))
        {
            return true;
        }

        return false;
    }
    ~Rook() {}
};

class Bishop : public ChessPieces
{
public:
    Bishop()
    {
        name = "Bishop";
        point = 3;
        symbol = 'b';
    }
    void aboutMe()
    {
        cout << "I am the Bishop" << endl;
    }
    bool isValidMove(int x1, int y1, int x2, int y2, bool captured) override
    {
        int deltaX = x2 - x1;
        int deltaY = y2 - y1;

        if (abs(deltaX) == abs(deltaY))
        {
            return true;
        }

        return false;
    }
    ~Bishop() {}
};

class Knight : public ChessPieces
{
public:
    Knight()
    {
        name = "Knight";
        point = 3;
        symbol = 'n';
    }
    void aboutMe()
    {
        cout << "I am the Knight" << endl;
    }
    bool isValidMove(int x1, int y1, int x2, int y2, bool captured) override
    {
        int deltaX = abs(x2 - x1);
        int deltaY = abs(y2 - y1);

        if ((deltaX == 2 && deltaY == 1) || (deltaX == 1 && deltaY == 2))
        {
            return true;
        }

        return false;
    }
    ~Knight() {}
};

class Queen : public ChessPieces
{
public:
    Queen()
    {
        name = "Queen";
        point = 9;
        symbol = 'q';
    }
    void aboutMe()
    {
        cout << "I am the Queen" << endl;
    }
    bool isValidMove(int x1, int y1, int x2, int y2, bool captured) override
    {

        int deltaX = x2 - x1;
        int deltaY = y2 - y1;

        if (abs(deltaX) == abs(deltaY))
        {
            return true;
        }
        else if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0))
        {
            return true;
        }

        return false;
    }
    ~Queen() {}
};

class King : public ChessPieces
{
public:
    King()
    {
        name = "King";
        point = 0;
        symbol = 'k';
    }
    void aboutMe()
    {
        cout << "I am the King" << endl;
    }
    bool isValidMove(int x1, int y1, int x2, int y2, bool captured) override
    {

        int deltaX = abs(x2 - x1);
        int deltaY = abs(y2 - y1);

        if ((deltaX == 0 && deltaY == 1) || (deltaX == 1 && deltaY == 0) || (deltaX == 1 && deltaY == 1))
        {
            return true;
        }

        return false;
    }
    ~King() {}
};
