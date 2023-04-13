// Kenny Nguyen
// lab10.cpp

#include <iostream>
#include <fstream> 

using namespace std;

const string F_NAME = "/home/fac/sreeder/class/cs1420/lab10input.dat";
const int ARR_SIZE = 30;
const int ZERO = 0;
const int TWO = 2;



int main()
{
  ifstream infile;
  int num;
  int evenCount = 0;
  int oddCount = 0;
  int negCount = 0; 
  int evenNUM[ARR_SIZE] = {0};
  int oddNUM[ARR_SIZE] = {0};
  int negNUM[ARR_SIZE] = {0};
  
  cout << endl << endl;
 
  infile.open(F_NAME);
  if(infile.fail()){
    cout << "file failure...exiting program...press enter...";
    cin.get();
    return 0;
  }
  
  while(infile >> num){
    if(num > ZERO){
      if(num % TWO == ZERO){
        evenNUM[evenCount] = num;
        evenCount++;
      }else{
        oddNUM[oddCount] = num;
        oddCount++;
      }
    }if(num < ZERO){
      negNUM[negCount] = num;
      negCount++;   
    }
  }
  
  cout << "Even Numbers:" << endl;
  for(int i = 0; i < evenCount; i++){
    cout << "The index is " << i << " and the number is " << evenNUM[i];
    cout << endl;
  }
  cout << endl << endl;

  cout << "Odd Numbers:" << endl;
  for(int i = 0; i < oddCount; i++){
    cout << "The index is " << i << " and the number is " << oddNUM[i];
    cout << endl;
  }
  cout << endl << endl;
  
  cout << "Negative numbers:" << endl;
  for(int i = 0; i < negCount; i++){ 
    cout << "The index is " << i << " and the number is " << negNUM[i];
    cout << endl;
  }
  cout << endl << endl;
  
  infile.close();

  cout << endl << endl;
  
  return 0;
}
