#include<bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
class RockPaperScissors {
public:
    enum Choice {
        ROCK,
        PAPER,
        SCISSORS
    };
    void playGame() {
        cout << "Welcome to Rock, Paper, Scissors!\n";
        while (true) {
            Choice player1 = getPlayerChoice(1);
            system("cls");
            Choice player2 = getPlayerChoice(2);

            cout << "\n\tPlayer 1 chose "<<printChoice(player1)<<"\t\t\tPlayer 2 chose "<<printChoice(player2);
            if(player1 == ROCK && player2 == ROCK)
            {
                cout <<R"(
                   _______                        ______
               ---'   ____)                     _(___   '---
                     (_____)                   (_____)
                     (_____)                   (_____)
                     (____)                     (____)
               ---.__(___)                        (___)__.---
               )";
            }
            else if(player1 == PAPER && player2 == ROCK)
            {
                cout <<R"(
                    _______                                ______
                ---'    ___)_____                        _(___   '---
                            ______)_                    (_____)
                             _______)                   (_____)
                            _______)                     (____)
                ---.____________)                         (___)__.---
                )";
            }
            else if(player1 == SCISSORS && player2 == ROCK)
            {
                cout << R"(
                    ______                                  ______
                ---'   ___)_______                        _(___   '---
                            ______)_                     (_____)
                       _____________)                    (_____)
                      (____)                              (____)
                ---.__(___)                                (___)__.---
                )";
            }
            if(player1 == ROCK && player2 == PAPER)
            {
                cout <<R"(
                   _______                             ______
               ---'   ____)                       ____(___   '---
                     (_____)                    _(_______
                     (_____)                   (_______
                     (____)                     (________
               ---.__(___)                         (__________.---
               )";
            }
            else if(player1 == PAPER && player2 == PAPER)
            {
                cout <<R"(
                    ______                                      ______
                ---'    ___)_____                          ____(___   '---
                            ______)_                     _(_______
                             _______)                   (_______
                            _______)                     (________
                ---.____________)                           (_________.---
                )";
            }
            else if(player1 == SCISSORS && player2 == PAPER)
            {
                cout << R"(
                    ______                                      ______
                ---'   ___)_______                         ____(___   '---
                            ______)_                     _(_______
                       _____________)                   (_______
                      (____)                             (________
                ---.__(___)                                 (_________.---
                )";
            }
            if(player1 == ROCK && player2 == SCISSORS)
            {
                cout <<R"(
                   _______                               ______
               ---'   ____)                       ______(___   '---
                     (_____)                    _(_____
                     (_____)                   (_________
                     (____)                           (____)
               ---.__(___)                             (___)___.---
               )";
            }
            else if(player1 == PAPER && player2 == SCISSORS)
            {
                cout <<R"(
                    ______                                        _______
                ---'    ___)_____                          ______(___    '---
                            ______)_                     _(______
                             _______)                   (_________
                            _______)                           (____)
                ---.____________)                               (___)____.---
                )";
            }
            else if(player1 == SCISSORS && player2 == SCISSORS)
            {
                cout << R"(
                    ______                                        _______
                ---'   ___)_______                         ______(___    '---
                            ______)_                     _(______
                       _____________)                   (_________
                      (____)                                   (____)
                ---.__(___)                                     (___)____.---
                )";
    
            }
            int result = determineWinner(player1, player2);
            if (result == 0) {
                cout << "\n\t\t\t\tIt's a tie!\n";
            } else if (result == 1) {
                cout << "\n\t\t\t\tPlayer 1 wins!\n";
            } else {
                cout << "\n\t\t\t\tPlayer 2 wins!\n";
            }
            cout << "Do you want to play again? (y/n): ";
            char playAgain;
            cin >> playAgain;
            if (playAgain != 'y' && playAgain != 'Y') {
                break;
            }
        }
        cout << "Thanks for playing!\n";
    }
private:
    string printChoice(Choice choice) {
        switch (choice) {
            case ROCK:
                return "Rock";
                break;
            case PAPER:
                return "Paper";
                break;
            case SCISSORS:
                return "Scissors";
                break;
            default:
            break;
        }
        }
    Choice getPlayerChoice(int playerNumber) {
        cout << "Player " << playerNumber << ", Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ";
        int choice;
        cin >> choice;
        if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Please enter a number between 1 and 3.\n";
            return getPlayerChoice(playerNumber);
        }
        return static_cast<Choice>(choice - 1);
    }
    int determineWinner(Choice player1, Choice player2) {
        if (player1 == player2) {
            return 0; // It's a tie
        } else if ((player1 == ROCK && player2 == SCISSORS) ||
                   (player1 == PAPER && player2 == ROCK) ||
                   (player1 == SCISSORS && player2 == PAPER)) {
            return 1; // Player 1 wins
        } else {
            return 2; // Player 2 wins
        }
    }
};
void playrock()
{
    RockPaperScissors rps;
    int n;
    cout << endl;
        cout << ":::: ROCK PAPER SCISSORS MENU ::::" << endl;
        cout << "1. Start the Game" << endl;
        cout << "2. Rules" << endl;
        cout << "3. Exit " << endl;
        cout << "Enter : ";
        cin >> n;

        switch (n)
        {
        case 1:
            rps.playGame();
            break;
        case 2:
        
            cout << "\n **** Rules for Rock Paper Scissors Game ****"<<endl;
            cout<<"Three different hand signals that stand for a rock, paper, and scissors are used in this game. "<<endl;
            cout<<"Scissors is a fist with the index and middle fingers fully extended toward the other player."<<endl;
            cout<<"Paper is a flat hand with fingers and thumb extended and the palm facing downward."<<endl;
            cout<<"Rock is a closed fist."<<endl;
            cout<<"Scissors defeat paper, scissors defeat rock, and scissors defeat paper. "<<endl;
            cout<<"Play continues until there is an obvious winner if both players give the same hand signal. Otherwise, it is a draw."<<endl;
        
            break;
        case 3:
            return;
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

/*int main()
{
	RockPaperScissors obj;
    obj.playGame();
}*/

