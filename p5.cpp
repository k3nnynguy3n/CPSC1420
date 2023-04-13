// Kenny Nguyen
// p5.cpp
// SU monopoly, the user will be able to choose how many players they would
// like to play with ranging from 2-6. The game is just like the regular
// monopoly but its Seattle University themed.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

struct PlayerInfo
{
  string name;
  double playerMoney;
  int location;
};

struct gameBoard
{
  string propertyName;
  int owner;
  int price;
  int rent;
};

const char YES = 'y';
const char SPACE = ' ';
const int BOARD_SIZE = 45; 
const int PLAYERMIN = 2;
const int PLAYERMAX = 6;
const int startingCash = 1500; 
const int startingPlace = 1; 
const int INCOME_TAX = -200;
const int BONUS_CASH = 50;
const int GO_CASH = 200;
const int DICE_ROLL_MAX = 6;
const int DICE_ROLL_MIN = 1;
const int BONUS_ROLL_50MIN = 1;
const int BONUS_ROLL_50MAX = 3; 
const int ZERO = 0;
const int START = 0;
const int PLUSONE = 1;
const int MAXSIZE = 7;
const string CHANCE = "Chance";
const string GO = "Go";
const string TAX = "Income Tax";
const string FEES = "Fees";
const string CHAPEL = "Chapel of St. Ignatius";

void welcome();
void goodbye();
void checkLocation(PlayerInfo list[], int playerNum, gameBoard board[]);
void property(PlayerInfo list[], int playerNum, gameBoard board[]);
int getPlayers(int players); 
int fillBoard(gameBoard board[]);
int rollDice();
int winner(PlayerInfo list[], int numPlayers);
bool takeTurn(PlayerInfo list[], int playerNum, gameBoard board[], int count);


int main()
{
  gameBoard board[BOARD_SIZE];
  char ans = 'y';
  int numPlayers, turn;  
  bool gameOver = false; 
  int numPositions;
  
  srand(time(NULL));
  
  welcome();
  
  while(tolower(ans) == YES){
    numPlayers = -1;
    numPlayers = getPlayers(numPlayers);
    PlayerInfo players[MAXSIZE];
    cin.ignore();
    
    for(int i = 0; i < numPlayers; i++){
      cout << "Please a name for player" << SPACE << i + PLUSONE
           << ":" << SPACE;
      getline(cin, players[i].name);
      cout << endl; 
      players[i].playerMoney = startingCash;
      players[i].location = startingPlace;
    
    }
  
    numPositions = fillBoard(board);

    while(!gameOver){  
      gameOver = takeTurn(players, turn, board, numPositions);
      turn++;
      if(turn >= numPlayers){
        turn = 0; 
      }
    }
    
    cout << endl;
    cout << "Would you like to play again? (Y/N): ";
    cin >> ans;
    cout << endl << endl; 
  }
  
  goodbye();
  
  return 0;
}


void welcome()
{
  cout << endl << endl; 
  cout << "Welcome to SU Monopoly!";
  cout << endl;
  cout << "It like the original monopoly but its Seattle University themed";
  cout << endl << endl;
}


void goodbye()
{
  cout << "Goodbye! Thank you for playing!" << endl; 
  cout << endl << endl; 
}


int getPlayers(int players)
{
  while(players > PLAYERMAX || players < PLAYERMIN){
  cout << "How many players are playing? (2-6): ";
  cin >> players;
  cout << endl << endl; 
  }
  return players; 
}


int fillBoard(gameBoard board[])
{
  ifstream inFile;
  int count = 0; 

  inFile.open("/home/fac/sreeder/class/cs1420/p5input.dat");
  if(!inFile.fail()){
    while(count < BOARD_SIZE && getline(inFile, board[count].propertyName)){
      inFile >> board[count].owner >> board[count].price >> board[count].rent;
      inFile.ignore();      
      count++;
    } 
  }
  return count;       
}


int rollDice()
{
  int roll = (rand() % DICE_ROLL_MAX) + DICE_ROLL_MIN;
    
  return roll;
}


int winner(PlayerInfo list[], int numPlayers)
{
  int largest = 0;
  
  for(int i = 0; i < numPlayers; i++){
    if(list[i].playerMoney > list[largest].playerMoney){
      largest = i;
      }
  } 
  return largest; 
}


void checkLocation(PlayerInfo list[], int playerNum, gameBoard board[])
{
  int rollResult;
  
    if(board[list[playerNum].location].propertyName == GO){
      list[playerNum].playerMoney += GO_CASH;
      cout << "You landed on go" << endl; 
      cout << list[playerNum].name << SPACE << "You now have:" << SPACE << "$"
             << list[playerNum].playerMoney << endl;
      
    }else if(board[playerNum].propertyName == CHANCE){
      rollResult = rollDice();
      cout << "You rolled" << SPACE << rollResult << endl; 

      if(rollResult >= BONUS_ROLL_50MIN && rollResult <= BONUS_ROLL_50MAX){
        list[playerNum].playerMoney += BONUS_CASH;
        cout << "You recieved $50 in bonus money!" << endl;
        cout << "You now have:" << SPACE << "$" << list[playerNum].playerMoney
             << endl;

      }else if(rollResult <= BONUS_ROLL_50MIN && rollResult >= BONUS_ROLL_50MAX){
        int index = 0;
        string target;
        
        while(index < playerNum && board[index].propertyName != target){
          index++;
        }
        if(board[index].propertyName == target){
          list[playerNum].location = index; 
        }
        cout << "You have been moved to the Chapel of St. Ignatius" << endl; 
        cout << "Take a rest" << endl;
      } 

    }else if(board[playerNum].propertyName == TAX){
      list[playerNum].playerMoney += INCOME_TAX;
      cout << "You have to pay $200 to the bank" << endl;
      cout << "You now have:" << SPACE << "$" << list[playerNum].playerMoney
           << endl; 
      
    }else{
      property(list, playerNum, board); 
    }
}

  
void property(PlayerInfo list[], int playerNum, gameBoard board[])
{
  int location, owned;
  char buy;
  
  location = list[playerNum].location; 
  cout << "You landed on" << SPACE << board[location].propertyName << endl;

  if(board[location].owner == ZERO){
    if(list[playerNum].playerMoney > board[location].price){
      cout << "No one owns this property, would you like to purchase it?"
           << endl;
      cout << "The purchase price of this property is" << SPACE
           << "$" << board[location].price << endl;
      cout << "The rent for this property is" << SPACE
           << "$" << board[location].rent << endl;
      cout << "(Y/N):" << SPACE;
      cin >> buy;
      buy = tolower(buy);
      cin.get();
      
      if(buy == 'y'){
        owned = board[location].owner; 
        
        cout << "Congrats! you now own:" << SPACE
             << board[location].propertyName << endl;
        list[playerNum].playerMoney -= board[location].price;
        cout << "You now have:" << SPACE << "$" << list[playerNum].playerMoney;
        board[location].owner = playerNum; 
      }
      
    }else{
      cout << "You do not have enough money to purchase this property"
           << endl;  
    }
    
  }if(board[location].owner > ZERO){
    owned = board[location].owner; 
    if(owned > ZERO && playerNum != board[location].owner){
      cout <<  "This property is owner" << endl; 
      cout << "You have to pay rent to the owner" << endl;
      list[playerNum].playerMoney -= board[location].rent;
      list[owned].playerMoney += board[location].rent; 
      cout << "You now have:" << SPACE << "$" << list[playerNum].playerMoney;
      cout << endl; 
    }
  }if(board[location].owner < ZERO){
    cout << "This property can not be owned" << endl; 
  }
}


bool takeTurn(PlayerInfo list[], int playerNum, gameBoard board[], int count)
{
  int rollOne, rollTwo, totalRoll;   
  cout << endl << endl;
  cout << list[playerNum].name << "'s turn!" << endl;
  cout << "Press enter to roll the dice!";
  cin.get();
  cout << endl;
  cout << "You currently have:" << SPACE << "$" << list[playerNum].playerMoney << endl;
  rollOne = rollDice();
  cout << "Your first roll is" << SPACE << rollOne << endl;
  rollTwo = rollDice();
  cout << "Your second roll is" << SPACE << rollTwo << endl;
  totalRoll = rollOne + rollTwo;
  cout << "You moved a total of" << SPACE << totalRoll << SPACE
       << "spaces" << endl;
  list[playerNum].location += totalRoll;
  cout << "You are now located at:" << SPACE << list[playerNum].location << endl;
  cout << endl << endl;
  
  if(list[playerNum].location >= BOARD_SIZE){
    list[playerNum].location = (list[playerNum].location + totalRoll) - count;
    list[playerNum].playerMoney += GO_CASH;
    
  }else{
    list[playerNum].location += totalRoll; 
  }
  
  checkLocation(list, playerNum, board);
  
  if(list[playerNum].playerMoney <= 0){
    winner(list, count);  
    return true;
  }
  
  for(int i = 0; i < count; i++){
    if(playerNum == list[playerNum].location){
      cout << "Here are your following properties:" << endl; 
      cout << board[i].propertyName << endl; 
    }
  }
  
  return false;
}

//print total properties owned by the player at the end of their turn
//fix land on fees, income tax, etc
//fix chance roll 
// board goes over board size
