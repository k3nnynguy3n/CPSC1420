// Kenny Nguyen
// p3.cpp
// Chutes and Ladders
// An online version of the board game Chutes and Ladders, to play you will
// need to spin the spinner and move the amount of spaces according to the
// spinner but some spaces on the board have a either a ladder or a chute which
// will either advance you even further or send you backwards, first player to
// 100 wins without going over. 
 
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

using namespace std;

void welcome();
void goodbye();
int taketurn(string, int);
int spin();
int checklocation(int);

const int MAX_SPIN = 6;
const int MIN_SPIN = 1;
const int GAMEWON = 100;
const char YES = 'y'; 

int main()
{
  bool p1turn = true;
  int p1loc = 0;
  int p2loc = 0; 
  string p1name;
  string p2name = "Computer"; 
  char ans = 'y'; 
  
  srand(time(0));

  cout << endl << endl; 

  while(tolower(ans) == YES){ 
    p1loc = 0;
    p2loc = 0;
    welcome();
    cout << "Please enter your name: ";
    getline(cin >> ws, p1name);
    while(p1loc != GAMEWON && p2loc != GAMEWON){
      if(p1turn){
        p1loc = taketurn(p1name, p1loc);
        p1turn = false;
      }else{
        p2loc = taketurn(p2name, p2loc);
        p1turn = true;
      }
    }
    if(p1loc == GAMEWON)
      cout << "CONGRATULATIONS!!! " << p1name << " YOU WON!!!";
    cout << endl << endl;
    if(p2loc == GAMEWON)
      cout << "CONGRATULATIONS!!! " << p2name << " YOU WON!!"; 
    cout << endl << endl;
    
    cout << "Would you like to play again? (Y/N): ";
    cin >> ans;
    cout << endl << endl;
  }
  goodbye();
  
  return 0;
}

void welcome()
{
  cout << "Welcome to Chutes and Ladders!";
  cout << endl;
  cout << "To play you must spin the spinner by clicking enter when requested";
  cout << endl;
  cout << "you will land on a number from 1 to 6 and that will be the amount"; 
  cout << endl;
  cout << "of spaces that you will move, some spaces will have chutes or";
  cout << endl;
  cout << "ladders that will either advance you ahead or send you backwards";
  cout << endl;
  cout << "The first person to the 100 space without going over wins!";
  cout << endl << endl;
  cout << "You will be going against the computer, good luck!";
  cout << endl << endl;  
}


void goodbye()
{
  cout << "Goodbye! Thank you for playing!" << endl << endl << endl; 
}


int taketurn(string playerName, int loc)
{ 
  cout << endl << endl << playerName << " it is your turn!" << endl;
  cout << playerName << " you are currently on square " << loc << ".";
  cout << endl;
  cout << "Please press enter to spin the spinner!" << endl;
  cout << "Waiting...";
  cin.get();
  int spinner = spin();
  cout << endl << endl; 
  cout << "You spun on " << spinner << endl;
  cout << "You moved " << spinner << " spaces!" << endl;

  
  if(loc + spinner > GAMEWON){
    cout << "You must land on 100 exactly to win" << endl;
  }else{  
    loc += spinner;
    int chuteLadder = checklocation(loc);
    loc += chuteLadder;
    
    if(chuteLadder > 0){
      cout << "Yay! You landed on a Ladder!" << endl;
      cout << "You will move " << chuteLadder << " spots foward." << endl;
      
    }else if(chuteLadder < 0){
      cout << "Oh No, you landed on a chute! " << endl;
      cout << "You will move " << chuteLadder << " spots foward." << endl;
      
    }else{
      cout << "You did not land on a chute or a ladder." << endl; 
    }
    
    cout << "You are now on " << loc << "." << endl;
  }
  
  return loc;   
}


int spin()
{  
  int spin = (rand() % MAX_SPIN) + MIN_SPIN;
   
  return spin;
}


int checklocation(int loc)
{ 
  if(loc == 1)
    return 37;
  else if(loc == 4)
    return 10;
  else if(loc == 9)
    return 12;
  else if(loc == 23)
    return 21;
  else if(loc == 28)
    return 56;
  else if(loc == 36)
    return 8;
  else if(loc == 51)
    return 15;
  else if(loc == 71)
    return 19;
  else if(loc == 80)
    return 20;
  else if(loc == 98)
    return -20;
  else if(loc == 95)
    return -20;
  else if(loc == 93)
    return -20;
  else if(loc == 87)
    return -63;
  else if(loc == 64)
    return -4;
  else if(loc == 62)
    return -43;
  else if(loc == 56)
    return -3;
  else if(loc == 49)
    return -38;
  else if(loc == 48)
    return -22;
  else if(loc == 16)
    return -10;
  else
    return 0;  
}
