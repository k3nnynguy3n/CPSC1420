// Kenny Nguyen
// lab5.cpp
// The purpose of this lab is to request two integers from the users an
// and then be able to differentiate which input is larger and finally 
// decide if the first input is a multiple of the second integer
// additionally if the user would like to run the program again they can

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
    cout << "Welcome! Please enter two integers (not 0): ";
    cin >> int1 >> int2;
    cout << endl;

    if(int1 > int2){
      if(int1 % int2 == 0){
        cout << int1 << " is a multiple of " << int2
             << " and the other factor is " << int1/int2 << ".";
      }else{
        cout << int1 << " is NOT a multiple of " << int2;
      }
    }else{
      if(int2 % int1 == 0){
        cout << int2 << " is a multiple of " << int1
             << " and the other factor is " << int2/int1 << ".";
      }else{
        cout << int2 << " is NOT a multiple of " << int1 << ".";
      }
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
