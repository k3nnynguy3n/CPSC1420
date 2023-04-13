// Kenny Nguyen
// p4.cpp
// Memory game, to play this game there will be a layout of cards where the
// player will have to pick two cards if they match they will be removed from
// the board. However if they do not match the user will have a short moment
// to memorize the cards and their position before taking a guess again.

#include <iostream>
#include <ctime>
#include <fstream> 
#include <cstdlib>
#include <iomanip> 

using namespace std;

const string FILE1 = "/home/fac/sreeder/class/cs1420/p4data1.dat";
const string FILE2 = "/home/fac/sreeder/class/cs1420/p4data2.dat";
const char BEGINNER = 'b';
const char EXPERT = 'e';
const char SPACE = ' ';
const char UNDERSCORE = '_';
const char ASTERISK = '*';
const char L_Bracket = '[';
const char R_Bracket = ']'; 
const char YES = 'y';
const int CLEAR = 50; 
const int BEGINNER_T = 5;
const int EXPERT_T = 3;
const int ROWS = 3;
const int COLS = 4;
const int WINNER = 6;
const int COLSPACE = 4; 
const int MIN = 0;
const int MAX = 1; 
const int DEFAULT = -1;

void welcome();
void goodbye();
void wait(int seconds);
void clearScreen();
void display(const char board[][COLS], int c1row = -1, int c1col = -1,
             int c2row = -1, int c2col = -1);
void getPick1(char board[][COLS], int& c1row, int& c1col);
void getPick2(char board[][COLS], int& c2row, int& c2col, int c1row, int c1col);
bool readFile(char board[][COLS], string fileName, bool switchboard);
int difficulty();
int matchFunction(char board[][COLS], int time);

int main()
{
  bool switchBoard = true; 
  char board[ROWS][COLS]; 
  char ans = 'y';
  string fileName;
  int pairs = 0;
  int turns = 0;
  int timer;  
  int r1 = DEFAULT;
  int r2 = DEFAULT;
  int c1 = DEFAULT;
  int c2 = DEFAULT;
     
  welcome();

  while(tolower(ans) == YES){
    
    timer = difficulty();
    turns = 0;
    pairs = 0;

    if(switchBoard){
      fileName = FILE1;
      switchBoard = false;
      readFile(board, fileName, switchBoard);
    }else{
      fileName = FILE2;
      switchBoard = true;
      readFile(board, fileName, switchBoard);
    }

    while(WINNER != pairs){
      clearScreen();
      display(board);
      getPick1(board, r1, c1);
      clearScreen();
      display(board, r1, c1); 
      getPick2(board, r2, c2, r1, c1);
      clearScreen();
      display(board, r1, c1, r2, c2);

      if(board[r1][c1] == board[r2][c2]){
        pairs += 1;
        board[r1][c1] = UNDERSCORE;
        board[r2][c2] = UNDERSCORE;
        cout << endl << "Yay! It's a match!" << endl;
        wait(timer);
        clearScreen();
        
      }else{
        cout << endl << "No match, try again :(" << endl;
        wait(timer);
        clearScreen();
      }
      turns++;
    }
    
    cout << endl << "Congrats! You matched all the cards! You win!" << endl;
    cout << "It took you " << turns << " to match all the cards" << endl;
    cout << "Do you want to play again? (y/n): ";
    cout << endl; 
    cin >> ans;
    cout << endl; 
  }
  
  goodbye();

  return 0;
}


void welcome()
{
  cout << endl << endl;
  cout << "Welcome to the memory game!" << endl << endl;
  cout << "In this game you will be presented with a board of cards" << endl;
  cout << "cards will be faced down and your job is to find the pairs" << endl;
  cout << "depending on difficulty the cards will be revealed for a" << endl;
  cout << "set amount of time" << endl << endl;
  cout << "Good luck and have fun!" << endl << endl;
}


void goodbye()
{
  cout << endl << endl;
  cout << "Goodbye, thank you for playing!" << endl;
  cout << endl << endl;
}


void wait(int seconds)
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;
  while (clock() < endwait){}
}


void clearScreen()
{
  for(int i = 0; i < CLEAR; i++)
    cout << endl << endl; 
}


int difficulty()
{
  char pick = 'y';
  int time; 

  while((tolower(pick) != BEGINNER && (tolower(pick) != EXPERT))){
    cout << "What difficulty would you like to play on?" << endl;
    cout << "Beginner or Expert? (B/E): ";
    cin >> pick;
    cout << endl << endl; 
  }
  
  if(tolower(pick) == BEGINNER){
    time = BEGINNER_T;
  }else{
    time = EXPERT_T;
  }
  
  return time;
  
}


bool readFile(char board[][COLS], string fileName, bool switchBoard)
{
  ifstream inFile;

  if(!switchBoard){
    fileName = FILE1;
  }else{
    fileName = FILE2;
  }
  
  inFile.open(fileName);
  if(inFile.fail()){
    cout << "file error...exiting program...press enter...";
    cin.get();
    return 0;
  }
  
  for(int r = 0; r < ROWS; r++){
    for(int c = 0; c < COLS; c++){
      inFile >> board[r][c]; 
    }
  }
  
  inFile.close(); 

  return false;
}


void display(const char board[][COLS], int c1row, int c1col,
             int c2row, int c2col)
{
  for(int e = 0; e < COLS; e++){
    cout << setw(COLSPACE) << e; 
  }
  cout << endl;
  
  for(int i = 0; i < ROWS; i++){
    cout << i << SPACE; 
    for(int k = 0; k < COLS; k++){
      cout << L_Bracket;
      
      if(i == c1row && k == c1col){
        cout << board[i][k];
      }else if(i == c2row && k == c2col){
        cout << board[i][k]; 
      }else if(board[i][k] == UNDERSCORE){
        cout << board[i][k]; 
      }else{
        cout << ASTERISK; 
      }
      cout << R_Bracket << SPACE; 
    }
    cout << endl;
  }
}


void getPick1(char board[][COLS], int& c1row, int& c1col)
{
  cout << endl << "Pick your first card" << endl;
  
  cout << "Row?: ";
  cin >> c1row;
  
  cout << "Column?: ";
  cin >> c1col;
  cout << endl; 

  while(c1row >= ROWS || c1col >= COLS || board[c1row][c1col] == UNDERSCORE){
    cout << "Invalid Coordinates" << endl;
    cout << "Row?: ";
    cin >> c1row;
    
    cout << "Column?: ";
    cin >> c1col;
    cout << endl; 
  }
}


void getPick2(char board[][COLS], int& c2row, int& c2col, int c1row, int c1col)
{
  cout << endl << "Pick your second card" << endl;

  cout << "Row?: ";
  cin >> c2row;

  cout << "Column?: ";
  cin >> c2col;
  cout << endl;

  while(c1row >= ROWS || c1col >= COLS || board[c1row][c1col] == UNDERSCORE ||
        (c2row == c1row && c2col == c1col)){
    cout << "Invalid Coordinates" << endl;
    cout << "Row?: ";
    cin >> c2row;
    
    cout << "Column?: ";
    cin >> c2col;
    cout << endl;
  }
}

