// Kenny Nguyen
// lab16.cpp

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
const int ONE = 1; 
const int NAME_FIELD = 15;
const int AGE_FIELD = 6;
const int COFFEE_FIELD = 6;
const string FILELAB14 = "/home/fac/sreeder/class/cs1420/lab14input.dat";

void printOne(Person p);
void swapPerson(Person& val1, Person& val2);
void selectSort(Person list[], int numElements); 
Person oldestPerson(const Person list[], int numElements);
double averageAge(const Person list[], int numElements);
int totalCoffee(const Person list[], int numElements);
Person leastCoffee(const Person list[], int numElements);


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
  cout << "The oldest person is:" << endl;
  cout << left << setw(NAME_FIELD) << "Name:" << right << setw(AGE_FIELD)
       << "Age:" << SPACE << setw(COFFEE_FIELD) << "Coffee:";
  cout << endl;
  printOne(oldestPerson(clients, numElements));
  cout << endl << endl;
  cout << "The person that drinks the least amount of coffee is:" << endl;
  cout << left << setw(NAME_FIELD) << "Name:" << right << setw(AGE_FIELD)
       << "Age:" << SPACE << setw(COFFEE_FIELD) << "Coffee:";
  cout << endl;
  printOne(leastCoffee(clients, numElements));
  cout << endl << endl; 
  cout << "Entire list sorted by name" << endl << endl; 

  cout << left << setw(NAME_FIELD) << "Name:" << right << setw(AGE_FIELD)
       << "Age:" << SPACE << setw(COFFEE_FIELD) << "Coffee:";
  cout << endl;
  
  selectSort(clients, numElements); 
  for(int i = 0; i < numElements; i++){
    printOne(clients[i]);
  }
  cout << endl << endl;
  
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

Person leastCoffee(const Person list[], int numElements)
{
  int least = 0;

  for(int i = 1; i < numElements; i++)
    if(list[i].coffee < list[least].coffee)
      least = i;
  
  return list[least]; 
}

Person oldestPerson(const Person list[], int numElements)
{
  int oldest = 0;
  
  for(int i = 1; i < numElements; i++)
    if(list[i].age > list[oldest].age)
      oldest = i; 
  
  return list[oldest];
}

void swapPerson(Person& val1, Person& val2)
{
  Person temp = val1;
  val1 = val2;
  val2 = temp; 
}

void selectSort(Person list[], int numElements)
{
  int idx;

  for(int i = 0; i < numElements; i++){
    idx = i;
    for(int k = i + ONE ; k < numElements; k++){
      if(list[k].name < list[idx].name){
        idx = k; 
      }
    }
    if(idx != i){
      swap(list[idx], list[i]);
    }
  }
}
