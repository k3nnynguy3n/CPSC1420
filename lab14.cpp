// Kenny Nguyen
// lab14.cpp

#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;

struct Person{
  string name;
  int age;
  int coffee; 
};

const char SPACE = ' ';
const int MAX = 150;
const int NAME_FIELD = 15;
const int AGE_FIELD = 6;
const int COFFEE_FIELD = 6;
const string FILELAB14 = "/home/fac/sreeder/class/cs1420/lab14input.dat";

void printOne(Person p);
double averageAge(const Person list[], int numElements);
int totalCoffee(const Person list[], int numElements);

int main()
{
  Person clients[MAX];
  int numElements = 0; 
  ifstream infile;

  cout << endl << endl; 
  infile.open(FILELAB14);
  if(infile.fail()){
    cout << "file error...exiting program...press enter...";
    cin.get();
    return 0;
  }
  while(infile >> clients[numElements].name){
    infile >> clients[numElements].age >> clients[numElements].coffee;
    numElements++;
  }
  infile.close();
   
  cout << left << setw(NAME_FIELD) << "Name:" << right << setw(AGE_FIELD)
       << "Age:" << SPACE << setw(COFFEE_FIELD) << "Coffee:";
  cout << endl; 
  
  for(int i = 0; i < numElements; i++){
    printOne(clients[i]);
  }
  cout << endl;
  cout << "The average age is: " << averageAge(clients, numElements);
  cout << endl << endl;
  cout << "The total amount of coffee is: " << totalCoffee(clients, numElements);
  cout << endl << endl << endl; 
  
  return 0;
}

void printOne(Person p)
{
  cout << left << setw(NAME_FIELD) << p.name;
  cout << right << setw(AGE_FIELD) << p.age;
  cout << SPACE;
  cout << left << setw(COFFEE_FIELD) << p.coffee;
  cout << endl; 
}

double averageAge(const Person list[], int numElements)
{
  double avg = 0.0;
  
  for(int i = 0; i < numElements; i++){ 
    avg += list[i].age;
  }
  avg = avg/numElements; 

  return avg; 
}

int totalCoffee(const Person list[], int numElements)
{
  int total;
  
    for(int i = 0; i <  numElements; i++)
      total += list[i].coffee;
  
  return total; 
}
