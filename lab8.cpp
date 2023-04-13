// Kenny Nguyen
// lab8.cpp
// Purpose of this program is to have the summation of the input be outputted
// and then ask if the user would like to repeat using functions.

#include <iostream>

using namespace std;

void welcome();
int input();
int summation(int val);
void goodbye();
const char YES = 'y';

int main()
{
  char ans = 'y';
  int num;
  
  welcome();
  while(tolower(ans) == YES){
    input();
    summation(num);
    cout << "Do you want to run the program again? (Y/N): ";
    cin >> ans;
    cout << endl << endl;
  }
  goodbye();
  
  return 0;
} 
  

void welcome()
{
  cout << endl << endl;
  cout << "Welcome to lab8!";
  cout << endl << endl;
}


int input()
{
  const int MAX = 25;
  const int MIN = 5;
  cout << "Please enter an integer from 5 to 25: ";
  cin >> num;
  while(num > MAX || num < MIN){ 
    cout << "Please enter an integer from 5 to 25: ";
    cin >> num;
  }
  return 0;
}
      
int summation(int val)
{
  for(int i = 0; i < num; i++){
    val += i;
  }
  cout << val;
  cout << endl << endl;
  
  return 0;
}


void goodbye()
{
    cout << "Goodbye, have a good one!";
    cout << endl << endl << endl;
}

