// Kenny Nguyen 
// p1.cpp
// The purpose of this program is to create a word game by collecting
// the inputs from the user

#include <iostream>
#include <string>
using namespace std;

int main()
{
  int age,year;
  string name,place,school,profession,animal,petName;

  cout << endl << endl; 
    
  cout << "Welcome! Please enter a one word answer for every prompt";    

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
  
  cout << "Please enter a name: ";
  cin >> petName;

  cout << endl << endl;
  
  cout << "Once upon a time, " << name << " lived in " << place
       << " at the age of " <<  age << ". " << endl;
  cout << name << " went to school at " << school  << " and graduated in "
       << year << " to become a " << profession << ". " << endl;
  cout << name << " got a little lonely so " << name << " got a " << animal
       << " and named it " << petName << ".";

  cout << endl << endl;

  cout << "Thank you for playing my game! Goodbye!";

  cout << endl << endl; 
  return 0;
}    
