// Kenny Nguyen
// lab13.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX = 40;
const int ROWS = 5;
const int COL = 8;
const int COLSPACE = 6; 
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";

void printTable(int arr[][COL]); 
int sumTable(int arr[][COL]); 

int main()
{
  int twoDArr[ROWS][COL] = {0};
  ifstream infile;
  int num; 
  
  infile.open(FILENAME);
  if(infile.fail()){
    cout << "file error...exiting program...press enter...";
    cin.get();
    return 0;
  }
  for(int r = 0; r < ROWS; r++){
    for(int c = 0; c < COL; c++){
      infile >> num;
      twoDArr[r][c] = num;
    }
  }
  infile.close();
  cout << endl << endl;
  printTable(twoDArr);
  cout << endl << endl;
  cout << "The sum of all numbers is: " << sumTable(twoDArr);
  cout << endl << endl; 
  
  return 0;
}
void printTable(int arr[][COL])
{
  int rowSum, colSum;
  
   for(int r = 0; r < ROWS; r++){
    rowSum = 0;
    for(int c = 0; c < COL; c++) {
      cout << setw(COLSPACE) << arr[r][c];
      rowSum += arr[r][c];
    }
    cout << "    Sum of row is: " << rowSum << endl;
  }

  for(int c = 0; c < COL; c++) {
    colSum = 0;
    for (int r = 0; r < ROWS; r++) {
      colSum += arr[r][c];
    }
    cout << setw(COLSPACE) << colSum;
  }
  cout << " <- Sums of the columns";
}

int sumTable(int arr[][COL])
{
  int sum;
  
  for(int r = 0; r < ROWS; r++){
    for(int c = 0; c < COL; c++){
      sum += arr[r][c];
    }
  }
  return sum; 
}
