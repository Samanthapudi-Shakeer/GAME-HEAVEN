# include<bits/stdc++.h>

using namespace std;

class _16_Puzzle {
    const int optimalBoard[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 32};
    const int moves[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
    int** gameBoard;
    int size = 4;
    int spaceI, spaceJ;

public: 
    _16_Puzzle() {
        gameBoard = new int*[size];
        for(int i=0; i<size; i++) {
            gameBoard[i] = new int[size];
            for(int j=0; j<size; j++) {
                gameBoard[i][j] = optimalBoard[i][j];
            }
        }
        spaceI = 3;
        spaceJ = 3;
    }
    void generateNewBoard() {
        srand(time(0));
        int randI, randJ;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                randI = rand()%4;
                randJ = rand()%4;
                swap(gameBoard[i][j], gameBoard[randI][randJ]);
                if(gameBoard[randI][randJ] == 32) {
                    spaceI = randI;
                    spaceJ = randJ;
                }
            }
        }
    }
    void showBoard() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if(gameBoard[i][j] == 32) {
                    cout << "   ";
                }
                else {
                    cout << setw(2) << gameBoard[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    bool checkWinner() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if(gameBoard[i][j] != 4*i+j+1) {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkMove(int i) {
        return spaceI+moves[i][0] >= 0 && spaceI+moves[i][0] < 4 && spaceJ+moves[i][1] >= 0 && spaceJ+moves[i][1] < 4;
    }
    void playGame() {
        _16_Puzzle puzzle = _16_Puzzle();
        generateNewBoard();
        do {
            char m;
            showBoard();
            cout << "Enter where you want the gap to move (U/R/D/L): ";
            cin >> m;
            if(m == 'U' || m == 'u') {
                if(!checkMove(0)) {
                    system("cls");
                    cout << "Enter a valid move!" << endl;
                }
                else {
                    swap(gameBoard[spaceI][spaceJ], gameBoard[spaceI+moves[0][0]][spaceJ+moves[0][1]]);
                    spaceI+=moves[0][0];
                    spaceJ+=moves[0][1];
                }
            }
            else if(m == 'R' || m == 'r') {
                if(!checkMove(1)) {
                    system("cls");
                    cout << "Enter a valid move!" << endl;
                
                }
                else {
                    swap(gameBoard[spaceI][spaceJ], gameBoard[spaceI+moves[1][0]][spaceJ+moves[1][1]]);
                    spaceI+=moves[1][0];
                    spaceJ+=moves[1][1];
                }
            }
            else if(m == 'D' || m == 'd') {
                if(!checkMove(2)) {
                    system("cls");
                    cout << "Enter a valid move!" << endl;
                }
                else {
                    swap(gameBoard[spaceI][spaceJ], gameBoard[spaceI+moves[2][0]][spaceJ+moves[2][1]]);
                    spaceI+=moves[2][0];
                    spaceJ+=moves[2][1];
                }
            }
            else if(m == 'L' || m == 'l') {
                if(!checkMove(3)) {
                    system("cls");
                    cout << "Enter a valid move!" << endl;
                }
                else {
                    swap(gameBoard[spaceI][spaceJ], gameBoard[spaceI+moves[3][0]][spaceJ+moves[3][1]]);
                    spaceI+=moves[3][0];
                    spaceJ+=moves[3][1];
                }
            }
            else {
                system("cls");
                cout << "Enter a valid move!" << endl;
            }
        }while(!checkWinner());
        showBoard();
        cout << "You win!!" << endl;
    }
};
void play16()
{
    _16_Puzzle puz;
    int n;
        while (1)
    {
        cout << endl;
        cout << ":::: 16 PUZZLE GAME MENU ::::" << endl;
        cout << "1. Start the Game" << endl;
        cout << "2. Rules" << endl;
        cout << "3. Exit " << endl;
        cout << "Enter : ";
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "\nEntering Game :" << endl << endl;
            puz.playGame();
            break;
        case 2:
        setcolor(12);
            cout<<"****Rules to play 16-Puzzle Game ****"<<endl;
            cout<<"1) This is a puzzle game which has 16  grids in which there are 15 numbers from 1 to 15 and a space arranged in a 4X4 matrix"<<endl;
            cout<<"2) The game starts off by generating a random arrangement of these 15 numbers and the space"<<endl;
            cout<<"3) The player has to arrange all the numbers in the sequence from 1 to 15 and arrange the space in the last column of the last row"<<endl;
            cout<<"4) The player in each move gets a chance to move the space around the game board by giving the commands U/R/D/L"<<endl;
            cout<<"5) Please note that 50% of the boards generated are unsolvable...."<<endl;
            setcolor(7);
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
/*int main() {
    _16_Puzzle puzzle = _16_Puzzle();
    puzzle.playGame();
    return 0;
}*/
