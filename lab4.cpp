// Kenny Nguyen
// lab4.cpp
// The purpose of this lab is to request two integers from the users an
// and then be able to differentiate which input is larger and finally 
// decide if the first input is a multiple of the second integer

#include <iostream>
using namespace std;

int main()
{
  int int1, int2;

  cout<< endl << endl;

  cout << "Welcome! Please enter two integers (not 0): ";
  cin >> int1 >> int2;
  cout << endl;

  if(int1 > int2){
    if(int1 % int2 == 0){
      cout << int1 << " is a multiple of " << int2
           << " and the other factor is " << int1/int2 << ".";
    }else{
        cout << int2 << " is NOT a multiple of " << int1; 
    }
  }else{
    if(int2 % int1 == 0){ 
      cout << int2 << " is a multiple of " << int1
         << " and the other factor is " << int2/int1 << "."; 
    }else{
      cout << int1 << " is NOT a multiple of " << int2 << ".";
    }
  }
  cout << endl << endl;  
  return 0;
}
