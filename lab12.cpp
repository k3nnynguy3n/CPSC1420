// Kenny Nguyen
// lab12.cpp

#include <iostream>
#include <iomanip>
#include <fstream> 

using namespace std;

const int MAXVAL = 50;
const string F_NAME = "/home/fac/sreeder/class/cs1420/lab12input.dat";

void printVal(const double arr[], int numVal);

double total(const double arr[], int numVal);

int readFile(double arr[]);


int main()
{
  double catalog[MAXVAL] = {0};
  int count;
  
  cout << endl << endl;
  count = readFile(catalog);
  if(count == 0){
    cout << "file error...exiting program...press enter to continue...";
    cin.get();
    return 0;
  }
  
  printVal(catalog, count);
  cout << endl;
  cout << "The total of all the numbers in the file is: " << total(catalog, count);
  cout << endl << endl << endl;
  
  return 0;
}


void printVal(const double arr[], int numVal)
{
  const int ICOL = 5;
  const int NCOL = 8;
  const int NUM = 3;

  cout << setw(ICOL) << "Index:" << setw(NCOL) << "Value:" << endl;

  for(int i = 0; i < numVal; i++)
    cout << setw(ICOL) << i << setw(NCOL) << fixed << showpoint
         << setprecision(NUM) << arr[i] << endl; 
}


double total(const double arr[], int numVal)
{
  double total = 0;

  for(int i = 0; i < numVal; i++)
    total += arr[i];
    
  return total; 
}


int readFile(double arr[])
{
  double num;
  ifstream infile;
  int counter = 0;
  
  infile.open(F_NAME);
  
  while(infile >> num){
    arr[counter] = num;
    counter++;
  }
  infile.close();
  
  return counter;
}

