// Kenny Nguyen
// lab9.cpp

#include <iostream>

using namespace std;

void input(string& val1, string& val2);

void output(string val1, string val2);

void swapStr(string& val1, string& val2);

int main()
{
  string val1, val2;
  
  input(val1, val2);
  output(val1, val2);
  swapStr(val1, val2);
  output(val1, val2);
  
  return 0; 
}


void input(string& val1, string& val2)
{  
  cout << endl << endl; 
  cout << "Please enter two single words: ";
  cin >> val1 >> val2;
  cout << endl << endl;
}


void output(string val1, string val2)
{ 
  cout << "String1 is " << val1 << " and String2 is " << val2;
  cout << endl << endl; 
}


void swapStr(string& val1, string& val2)
{ 
  string temp = val1;
  val1 = val2;
  val2 = temp; 
}
