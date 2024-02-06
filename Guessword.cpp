#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

class WordGuessingGame {
private:
    std::vector<std::string> words; // List of words to be guessed
    std::string selectedWord; // The word to be guessed
    std::string displayedWord; // Word with some letters hidden
    int maxAttempts; // Maximum number of attempts allowed
    int attemptsLeft; // Number of attempts remaining
    bool isGameOver; // Flag to track if the game is over

public:
    WordGuessingGame() : isGameOver(false) {
        // Initialize the list of words
        words = {
        "apple", "banana", "orange", "grape", "pineapple", "watermelon",
        "cat", "dog", "bird", "fish", "rabbit", "turtle", "hamster", "parrot",
        "car", "bicycle", "motorcycle", "bus", "train", "airplane", "boat",
        "computer", "phone", "television", "camera", "headphones", "keyboard", "mouse",
        "chair", "table", "couch", "bed", "desk", "dresser", "mirror",
        "book", "newspaper", "magazine", "notebook", "calendar", "pen", "pencil",
        "shoes", "socks", "pants", "shirt", "jacket", "dress", "hat",
        "pizza", "hamburger", "sandwich", "salad", "pasta", "soup", "steak"
    };

        getRandomWord();
    }
    
    void getRandomWord() {
        srand(time(0));
        selectedWord = words[rand() % words.size()];

        // Initialize displayedWord with all letters hidden
        displayedWord = selectedWord;
        for (char& c : displayedWord) {
            c = '_';
        }
        int randInt = rand()%displayedWord.length();
        displayedWord[randInt] = selectedWord[randInt];
        maxAttempts = displayedWord.length() > 5? 5: displayedWord.length()-1;
        attemptsLeft = maxAttempts;
    }

    // Method to reveal a random letter of the word
    void revealRandomLetter() {
        if(attemptsLeft == 2 && displayedWord[0] == '_') {
            displayedWord[0] = selectedWord[0];
            return;
        }
        int randomIndex = -1;
        while (randomIndex == -1 || displayedWord[randomIndex] != '_') {
            randomIndex = rand() % selectedWord.length();
        }
        displayedWord[randomIndex] = selectedWord[randomIndex];
    }
    
    void restartStatement() {
        char ch;
        std::cout << std::endl << "Would You like to play agian?(Y/N): ";
        std::cin >> ch;
        if(ch == 'N' || ch == 'n') {
            isGameOver = true;
        }
    }

    // Method to play the game
    void playGame() {
        setcolor(5);
        std::cout << "Welcome to Word Guessing Game!" << std::endl;
        std::cout << "Guess the word. Here's a clue: " << displayedWord << std::endl;
        setcolor(7);
        // Main game loop
        while (!isGameOver) {
            std::cout << "Attempts left: " << attemptsLeft << std::endl;
            std::string guess;
            std::cout << "Enter your guess: ";
            std::cin >> guess;

            if (guess == selectedWord) {
                setcolor(3);
                std::cout << "Congratulations! You guessed the word correctly: " << selectedWord << std::endl;
                setcolor(7);
                restartStatement();
                if(!isGameOver) {
                    getRandomWord();
                    std::cout << "Guess the word. Here's a clue: " << displayedWord << std::endl;
                }
            } else {
                std::cout << "Incorrect guess. ";
                revealRandomLetter(); // Reveal a random letter
                attemptsLeft--;

                if (attemptsLeft == 0) {
                    std::cout << "Out of attempts. The word was: " << selectedWord << std::endl;
                    restartStatement();
                    if(!isGameOver) {
                        getRandomWord();
                    std::cout << "Guess the word. Here's a clue: " << displayedWord << std::endl;
                    }
                } else {
                    std::cout << "Clue: " << displayedWord << std::endl;
                }
            }
        }
        //cout << "Thanks for Playing our game!";
    }
};
void playguess()
{
    int n;
    cout << endl;
    setcolor(11);
        cout << ":::: WORD GUESSING GAME MENU ::::" << endl;
        cout << "1. Start the Game" << endl;
        cout << "2. Rules" << endl;
        cout << "3. Exit " << endl;
        setcolor(7);
        cout << "Enter : ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            WordGuessingGame game = WordGuessingGame(); // Create a game with 5 maximum attempts
            game.playGame();
            break;
        }
        case 2:
        {
            setcolor(12);
            cout<<" **** Rules to play word guessing game ****"<<endl;
            cout<<"1) The game starts off by choosing a random word from a predefined list/array of words"<<endl;
            cout<<"2) On each wrong answer the game reveals a random letter from the word and except for the revealed letter every other letter is represented by and underscore(_)"<<endl;
            cout<<"3) You have to guess the word within a maximum of 5 attempts and if the length of the word is less than or equal to 5 you get a maximum attempts of one less than the length of the word to be guessed"<<endl;
            setcolor(7);
            break;
        }
        case 3:
        {
            return;
            break;
        }
        default:{
            cout << "Invalid Choice" << endl;
            break;
        }
        }
    }

/*int main() {
    WordGuessingGame game = WordGuessingGame(); // Create a game with 5 maximum attempts
    game.playGame();
    return 0;
}*/