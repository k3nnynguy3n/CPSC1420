// Kenny Nguyen 
// p1x.cpp
// The purpose of this program is to create a word game by collecting
// the inputs from the user and repeat if the user would like to play again

#include <iostream>
#include <string>
using namespace std;

int main()
{
 
  int age,year;
  string name,place,school,profession,animal,petName;
  bool p1xgame = true;
  char ansr;
  
  cout << endl << endl; 
    
  cout << "Welcome! Please enter a one word answer for every prompt";    

  while(p1xgame){
    cout << endl << endl; 

    cout << "Please enter a name: ";
    cin >> name;
  
    cout << "Please enter an age: ";
    cin >> age;
  
    cout << "Please enter a place: ";
    cin >> place;
  
    cout << "Please enter a school: ";
    cin >> school;
  
    cout << "Please enter a year: ";
    cin >> year;

    cout << "Please enter a profession: ";
    cin >> profession;
  
    cout << "Please enter an animal: ";
    cin >> animal;
  
    cout << "Please enter a name for the animal: ";
    cin >> petName;

    cout << endl << endl;
  
    cout << "Once upon a time, " << name << " lived in " << place
       << " at the age of " <<  age << ". " << endl;
    cout << name << " went to school at " << school  << " and graduated in "
       << year << " to become a " << profession << ". " << endl;
    cout << name << " got a little lonely so " << name << " got a " << animal
       << " and named it " << petName << ".";

    cout << endl << endl;

    cout << "Would you like to play again? (Type Y for Yes or N for No) ";
    cin >> ansr;

    if(ansr == 'Y'){
      p1xgame = true;
      
    } else{
        p1xgame = false;

        cout << endl << endl;
        
        cout << "Goodbye, thank you for playing! ";

        cout << endl; 
    }
  } 

  cout << endl << endl;
  
  return 0;
}    
