#include <bits/stdc++.h>
#include <stdlib.h>
#include <windows.h>

#define N 9
bool played=false;
using namespace std;

void setcolor(unsigned short color);
bool is_play();

class SudokuPlay
{
	private:
		string player;
	
		
    public:
        int size;
    SudokuPlay(int s)
    {
        size = s;
    }
    
    void name(){
    	cout<<"\nEnter the player name : ";
    	cin>>player;
	}
    
    void rules();
    
    
    bool CompletelySolved(int grid[N][N]);
    
    int solve_sudoku(int board[N][N] , int length);
    
    void set_default(int grid[N][N], int output[N][N]);
   
    bool is_safe(int request[N][N], int row, int col, int num);
    
    
    //Find the location of empty element in given sudoku grid
    int new_empty_location(int request[N][N])
    {
        int i,j;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (request[i][j] == 0)
                {
                    
                    return (i * size) + j; //empty location returns
                }
            }
        }
        return -1;
    }
    
    //Find result
    bool test_sudoku(int output[N][N])
    {
        int location = new_empty_location(output);
        if (location == -1)
        {
            //When sudoku is complete
            return true;
        }
        
        int row = 0 , col = 0 , num = -1;
        if (location != 0)
        {
            
            row = location / size;  //Get element row
            col = location % size;  //Get element column
        }
        for (num = 1; num <= 9; num++)
        {
            if (is_safe(output, row, col, num) == true)
            {
                //Set this number of location [row][col] 
                output[row][col] = num;
                if (test_sudoku(output) == true)
                {
                    // When sudoku is solved 
                    return true;
                }
                //reset value
                output[row][col] = 0;
            }
        }
        return false;
    }
    //Display grid elements
    void display_data(int request[N][N],int count)
    {
        int i,j;
        cout << "      1 2 3   4 5 6   7 8 9 \n";
        cout << "   ++=======================++" << endl;
        for (i = 0; i < size; ++i)
        {
        	cout<<i+1<<"  ||";
            for (j = 0; j < size; ++j)
            {
            	if(j==3 || j==6)
            		cout<<" |";
            	if(request[i][j]==0){
            		setcolor(12);
                	cout <<" "<< request[i][j];
                	setcolor(7);
				}
				else {
					setcolor(1);
					cout<<" "<<request[i][j];
					setcolor(7);
				}
            }
            cout<<" ||  ";
            if(i == 2 || i == 5){
         		cout << endl
         			<<"   ";
         		for(int k = 0; k<N; k++)
           			cout << "---";
      		}
            cout << "\n";
        }
        cout << "   ++=======================++" << endl;
        cout<<"   PROGRESS : "<<count<<"/81 "<<endl;
    }
    //This is create sudoku problem in given length of element
    bool create_sudoku(int grid[N][N], int output[N][N], int length)
    {
        if (length <= 0)
        {
            return true;
        }
        //To get a random row and column
        int row = rand() % N;
        int col = rand() % N;
        if (grid[row][col] == 0)
        {
            //To get a number from (1 to 9)
            int num = (rand() % (N)) + 1;
            int c = 0;
            
            for (c = 0; c < size; c++)
            {
                if (is_safe(grid, row, col, num) == true)
                {
                    grid[row][col] = num;
                    output[row][col] = num;
                    if (create_sudoku(grid, output, length - 1) == true)
                    {
                        
                        return true;
                    }
                    //reset values
                    grid[row][col] = 0;
                    output[row][col] = 0;
                }
                num++;
                if (num > 9)
                {
                    num = 1;
                }
            }
        }
        else
        {
            if (create_sudoku(grid, output, length) == true)
            {
                // When sudoku is created 
                return true;
            }
        }
        return false;
    }


    void generate_sudoku(int box[N][N], int sudoku[N][N], int length)
    {
    	
        set_default(box, sudoku);
        if (create_sudoku(box, sudoku, length) == true)
        {
            
            if (test_sudoku(sudoku) == true)
            { 
                cout << "\nSolve the sudoku puzzle of initial " << length << " elements\n\n"
					 << player << " Let's start\n";
                
                int c=solve_sudoku(box , length);
                
                if(c==-1){
				
                cout << "\n Solution is : \n"<<endl;
                display_data(sudoku,81);
            	}
            }
            else
            {
                //Created sudoku are no solution, Try again ..
                generate_sudoku(box, sudoku, length);
            }
        }
        else
        {
            cout << "\n Sudoku are not create \n";
        }
    }
};

///               END OF CLASS  "SudokuPlay"                .


//Function to print the rules of the game .
void SudokuPlay::rules()
{
	cout<<"\n\t\t\t\t\t\tRULES :\n"<<endl
		<<"Sudoku is played on a 9x9 grid. Player has to fill vacant grids(here are 0) such that following 3 rules are obeyed : \n"
		<<"\n1. Each digit from 1-9 should appear in a row once.\n"
		<<"2. Each digit from 1-9 should appear in a column once.\n"
		<<"3. On dividing the 9x9 grid into 9 equal parts (i.e,3x3 9 grids)\n"
		<<"   each part should have all digits from 1 - 9 occur once."<<endl
		<<"\n*NOTE : User CANNOT change the data after inserting the value in a specified position."
		<<endl;
}

// Function to set default vlues with zero.
void SudokuPlay::set_default(int grid[N][N], int output[N][N])
{
    int i,j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = 0;
            output[i][j] = 0;
        }
    }
}


//Function that checks given number is suitable to particular row and column or not
bool SudokuPlay::is_safe(int request[N][N], int row, int col, int num)
{
    int i,j;
    // To check given number is present in given row and column or not
    for (i = 0; i < size; ++i)
    {
        if (request[row][i] == num || request[i][col] == num)
        {
            return false;
        }
    }
        
    //To check given number is present in 3x3 sub grid or not
    int s_row = row - row%3 , s_col = col - col%3;
	for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (request[s_row + i][s_col + j] == num)
            {
                return false;
            }
        }
    }
        
    return true;
}
    

bool SudokuPlay::CompletelySolved (int grid[N][N]){
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return false;

    return true;
}

int SudokuPlay::solve_sudoku(int board[N][N],int len)
{
    
    int ch, row, col, num, l = len;
    while(true){
        display_data(board,l);
        cout << endl << endl;
        cout << "NOTE : Unable to solve? Enter -1 as row, col to view the solution at any moment."<<endl;
        cout << "Enter row (1-9): ";
        cin >> row;
        cout << "Enter column (1-9): ";
        cin >> col;
        
		if(row == -1 || col == -1){
            cout << "\nPuzzle not solved. Better luck next time!   " << player<<endl;
            return -1;
        }

		cout << "Enter number (1-9): ";
        cin >> num;
        
        if (CompletelySolved(board))
            break;
        row--;
        col--;
        //to check the move is safe or not.
        if (!is_safe(board, row, col, num)) {
            cout<<endl;
            setcolor(12);
            cout << "----- INVALID MOVE. Try again. -----";
            setcolor(7);
			cout<<endl<< endl;
            continue;
        }
        board[row][col] = num;
        l++;
    }

    // Check if the user has solved it correctly or not
    bool solved = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                solved = false;
                break;
            }
        }
    }

    if (solved) {
    	played=true;
        cout << "Bravo! Congratulations! "<<player <<" You have solved the puzzle." << endl;
        display_data(board,81);
    }
    else {
    	played=true;
        cout << "\nPuzzle not solved. Better luck next time!!! " <<player<<endl;
    }
    return 0;

}


bool is_play(){
	if(played) return true;
	return false;
}

// void setcolor(unsigned short color)                 
// {                                                   
// 	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
// 	SetConsoleTextAttribute(hcon,color);
// }

void playSudoku()           
{
    
    int n, box[N][N], sudoku[N][N], len;
    
    SudokuPlay obj(N);
    while (1)
    {
        cout<<endl;
        setcolor(11);
    	cout << ":::: SUDOKU MENU ::::" << endl;
    	cout<<"1. Start the Game "<<endl;
    	cout<<"2. Rules "<<endl;
    	cout<<"3. Want to play another game."<<endl;
    	cout<<"4. QUIT GAME "<<endl;
        setcolor(7);
        cout<<"Enter key : ";
        cin>>n;
        switch (n)
        {
        case 1:
        	len = rand()%(40-33 +1)+33; // RANDOMLY selects num between 33 to 39
        	obj.rules();
        	obj.name();
        	obj.generate_sudoku(box,sudoku,len);
        	played=true;
            break;
        case 2:
        	obj.rules();
        	break;
        case 3:
        		if(is_play()){
        			len = rand()%(39-33 +1)+33;
        			obj.generate_sudoku(box,sudoku,len);
				}else{
					cout<<"\nGame is not played .\n";
				}
				break;
        case 4:
        	cout<<"\nGAME OVER \n";
            return ;
            break;
        
        default:
        cout<<"\nInvalid Choice!\n"<<endl;
            break;
        }
    }
    return;
}
