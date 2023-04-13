// Kenny Nguyen
// lab6.cpp
// The purpose of this program is to request two integers from the user where
// one of the inputs given has to be a multiple of the other and then repeat
// if the user would like to

#include <iostream>
#include <cctype>

using namespace std;

const char YES = 'y';

int main()
{
  int int1, int2;
  char ansr = YES;
  
  cout<< endl << endl;
  
  while(tolower(ansr) == YES){
    cout << "Welcome! Please enter two integers (not 0) "
         << "one input must be a multiple of the other "
         << "input: ";
    cin >> int1 >> int2;
    
    while(int1 % int2 && int2 % int1 != 0){
      cout << "This pair does not work as a multiple, please enter"
           << " a new pair of numbers: ";
      cin >> int1 >> int2;
    }
    if(int1 > int2 && int1 % int2 == 0){
      cout << int1 << " is a multiple of " << int2
           << " and the other factor is " << int1/int2 << ".";
    }else{
        cout << int2 << " is a multiple of " << int1
             << " and the other factor is " << int2/int1 << ".";
    }
    cout << endl << endl;
    
    cout << "Would you like to run the program again? "
         << "(Y for Yes and N for No) ";
    cin >> ansr;
    
    cout << endl << endl;
  }
  cout << "Goodbye!";
  cout << endl << endl;
  
  return 0;
}



