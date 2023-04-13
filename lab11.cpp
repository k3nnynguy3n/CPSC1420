// Kenny Nguyen
// lab11.cpp

#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;

const string F_NAME = "/home/fac/sreeder/class/cs1420/lab11input.dat"; 
const int SIZE = 40;
const int ROWS = 5;
const int COL = 8;
const int COLSPACE = 6;

int main()
{
  int twoDArr[ROWS][COL] = {0};
  ifstream infile;
  int num;
  int rowSum;
  int colSum;
  int sum;
  
  infile.open(F_NAME);
  if(infile.fail()){
    cout << "file error...exiting program...press enter...";
    cin.get();
    return 0;
  }
  
  for(int r = 0; r < ROWS; r++){
    for(int c = 0; c < COL; c++){
      infile >> num;
      twoDArr[r][c] = num;
      sum += num;
    }
  }

  for(int r = 0; r < ROWS; r++){
    rowSum = 0;
    for(int c = 0; c < COL; c++) {
      cout << setw(COLSPACE) << twoDArr[r][c];
      rowSum += twoDArr[r][c];
    }
    cout << "    Sum of row is: " << rowSum << endl;
  }

  for(int c = 0; c < COL; c++) {
    colSum = 0;
    for (int r = 0; r < ROWS; r++) {
      colSum += twoDArr[r][c];
    }
    cout << setw(COLSPACE) << colSum;
  }
  cout << " <- Sums of the columns";
    
  cout << endl << endl; 
  cout << "The sum of all numbers is: " << sum;
  cout << endl << endl; 
  
  return 0;
}
