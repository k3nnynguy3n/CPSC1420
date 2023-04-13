// Kenny Nguyen
// lab15.cpp

#include <iostream>
#include <fstream>
#include <string> 
#include <iomanip> 

using namespace std;

int linearSearch(const string list[], int count, string target);

const string FILENAME = "/home/fac/sreeder/class/cs1420/lab15input.dat";
const int MAX = 75;
const char SPACE = ' ';
const char YES = 'y'; 
const int COL_SPACE = 6;
const int NOT_FOUND = -1; 

int main()
{
  string words[MAX];
  string searchWord;
  int count = 0;
  int result; 
  ifstream inFile;
  char ans = 'y';
 
  inFile.open(FILENAME);
  if(inFile.fail()){
    cout << "File problem...exiting program...press enter...";
    cin.get();
    return 0;
  }
  
  while(count < MAX && inFile >> words[count]){
    count++;
  }
    inFile.close();

    cout << endl << endl;

    cout << "Index:" << setw(COL_SPACE) << "Word:" << endl;  

    
    for(int i = 0; i < count; i++){
      cout << right << setw(COL_SPACE) << i << SPACE << left
           << setw(COL_SPACE) << words[i] << endl; 
    }
    while(tolower(ans) == YES){
          cout << endl << endl;
          cout << "Word?: ";
          getline(cin, searchWord);
          result = linearSearch(words, count, searchWord);
          if(result != NOT_FOUND){
            cout << "There was a match!" << endl;
            cout << "Your word is" << SPACE << "'" << searchWord << "'" << SPACE
                 << "found at index" << SPACE << result << '.' << endl;
          }else{
            cout << "Sorry, your word" << SPACE << "'" << searchWord << "'"
                 << SPACE << "was not found" << "." << endl; 
          }    
          cout << "Search again? (Y/N):" << SPACE;
          cin >> ans;
          cin.ignore();
    }
    cout << endl;
    cout << "Goodbye!"; 
    cout << endl << endl;
    
    return 0;
}

int linearSearch(const string list[], int count, string target)
{
  int index = 0;
  
  while(index < count && list[index] != target){
    index++;
  }
  
  if(list[index] == target){
    return index;
  }
    return -1;
}
