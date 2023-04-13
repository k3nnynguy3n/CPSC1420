// Kenny Nguyen
// lab2.cpp
// The purpose of this code is to get a user input and calculate the user input
// to get an output

#include <iostream>
using namespace std;


int main()
{
  string word;
  int num1, num2;
  float fnum1, fnum2;

  cout << endl << endl;

  cout << "Please enter a word: ";
  cin >> word;

  cout << "The word is: " << word << endl;

  cout << "Please enter in two whole numbers";
  cin >> num1 >> num2;

  cout << "The division of " << num1 << " and " << num2 << " is " << num1/num2
       << endl << "The modulus of " << num1 << " and " << num2 << " is "
       << num1%num2 << endl;

  cout << "Please enter two floating point numbers: ";
  cin >> fnum1 >> fnum2;

    cout << "The division of " << fnum1 << " and " << fnum2 << " is "
         << fnum1/fnum2 << endl;   
  return 0;
}

