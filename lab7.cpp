//Kenny Nguyen
//lab7.cpp
//The purpose of this program is to create a pattern using the number given
//by the user

#include <iostream>
#include <iomanip>

using namespace std;

const int max = 9;
const int min = 3;
const int colspace = 3;
const char space = ' ';

int main()
{
  int num;

  cout << endl << endl;

  while(num < 3 || num > 9){
    cout << "Please enter two numbers from 3 or 9: ";
    cin >> num;
    cin.get();
  }
  cout << "Pattern 1:";
  cout << endl << endl;
  for(int i = 0; i < num; i++){
    cout << num;
  }
  cout << endl << endl; 
  cout << "Press enter to continue...";
  cin.get();
  cout << endl << endl;
  
  
  cout << "Pattern 2:";
  cout << endl << endl; 
  for(int i = 0; i < num; i++){
    cout << num << endl;
  }
  cout << endl;
  cout << "Press enter to continue...";
  cin.get();
  cout << endl << endl;


  cout << "Pattern 3:";
  cout << endl << endl;
  cout << "   ";
  for(int i = 1; i <= num; i++){
    cout << setw(colspace) << i;
  }
  cout << endl;
  
  for(int k = 1; k <= num; k++){
    cout << setw(colspace) << k;
    for(int n = 1; n <= num; n++){
      cout << setw(colspace) << k * n;
    }
    cout << endl;
  }
  cout << endl;
  cout << "Press enter to continue...";
  cin.get();
  cout << endl << endl;
  
  cout << "Pattern 4:";
  cout << endl << endl;
  for(int i = 1; i <= num; i++){
    for(int k = 1; k <= i; k++){
      cout << space << i;     
    }
    cout << endl;
  }
  cout << endl;
  cout << "Press enter to continue...";
  cin.get();
  cout << endl << endl;


  cout << "Pattern 5:";
  cout << endl << endl;
  for(int i = 1; i <= num; i++){
    for(int s = 1; s < i; s++){
      cout << space;
    }
    cout << i << endl;
  }
  for(int i = num - 1; i > 0; i--){
    for(int s = 1; s < i; s++){
      cout << space;
    }
    cout << i << endl;
  }
  cout << endl;
  cout << "Press enter to continue...";
  cin.get();
  cout << endl << endl;


  cout << "Pattern 6:";
  cout << endl << endl;
  for(int s =1; s < num; s++)
    cout << space;
  cout << 1 << endl;

  for(int r = 2; r <= num; r++){
    for(int s = 1; s < num - r + 1; s++)
      cout << space;
  cout << r;
  for(int s = 1; s <= r * 2 - 3; s++)
    cout << space;
  cout << r << endl;
  }

  for(int r = num - 1; r >= 2; r--){
    for(int s = 1; s < num - r + 1; s++)
      cout << space;
    cout << r;
    for(int s = 1; s <= r * 2 - 3; s++)
      cout << space;
    cout << r << endl;
  }
  for(int k = 1; k < num; k++)
    cout << space;
  cout <<  1 << endl;
  return 0;
}
