// Kenny Nguyen
// p2.cpp
// The purpose of this program is to play the childrens game Hi Ho Cherry-O
// To play this game you need to pick all the cherries off of your tree before
// your oppenent does, but there will be obstacles in the way

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
  bool p1turn = true; 
  string p1name,p2name;
  int spin;
  int bucket1 = 0;
  int bucket2 = 0;
  int tree1 = 10;
  int tree2 = 10;
  const int ONECHERRY = 1;
  const int TWOCHERRY = 2;
  const int SPILLEDBUCKET = 3;
  const int FOURCHERRY = 4;
  const int DOG = 5;
  const int THREECHERRY = 6;
  const int BIRD = 7;
  const int MAX_SPIN = 7;
  const int MIN_SPIN = 1;
  const int WIN = 10;
  const int MAX_CHERRIES = 10;
  
  cout << endl << endl;

  cout << "Welcome to the game Hi-Ho Cherry-O";
  cout << endl;
  cout << "The objective is to collect cherries from the tree to your bucket";
  cout << endl; 
  cout << "The first person to get to 10 cherries in their bucket wins";
  
  cout << endl << endl; 
  
  cout << "Please enter your name Player 1: ";
  getline (cin, p1name);
  
  cout << endl;
  
  cout << "Please enter your name Player 2: ";
  getline (cin, p2name);
  
  cout << endl << endl;
  
  while(bucket1 < 10 && bucket2 < 10){
    if(p1turn){
      cout << p1name << " its your turn!" << endl;
    }else{
      cout << p2name << " its your turn!" << endl; 
    }
    
    cout << "Please press enter to roll your dice" << endl;
    cout << "Waiting...";
    cin.get();
    cout << endl << endl; 
    
    srand((int)time(0));
    spin = (rand() % MAX_SPIN) + MIN_SPIN;
    cout << "You rolled " << spin << endl;
    
    
    if(spin == ONECHERRY){
      if(p1turn){
        bucket1 += 1;
        tree1 -= 1;
        if(bucket1 > MAX_CHERRIES){
          bucket1 = MAX_CHERRIES;
        }else{
          bucket1 = bucket1;
        }
      
      }else{
        bucket2 += 1;
        tree2 -= 1;
        if(bucket2 > MAX_CHERRIES){
          bucket2 = MAX_CHERRIES;
        }else{
          bucket2 = bucket2;
        }
      }
    
    
      cout << "You moved one cherry from the tree to your bucket." << endl;
      cout << p1name << " you have " << bucket1 << " cherries." << endl;
      cout << p2name << " you have " << bucket2 << " cherries.";
      cout << endl << endl;
    
    
    }else if(spin == TWOCHERRY){
      if(p1turn){
        bucket1 += 2;
        tree1 -= 2;
        if(bucket1 > MAX_CHERRIES){
          bucket1 = MAX_CHERRIES;
        }else{
          bucket1 = bucket1;
        }
        
      }else{
        bucket2 += 2;
        tree2 -= 2;
        if(bucket2 > MAX_CHERRIES){
          bucket2 = MAX_CHERRIES;
        }else{
          bucket2 = bucket2;
        }
      }
    
    
      cout << "You moved two cherries from the tree to your bucket." << endl; 
      cout << p1name << " you have " << bucket1 << " cherries." << endl;
      cout << p2name << " you have " << bucket2 << " cherries.";
      cout << endl << endl;
  
  
    }else if(spin == SPILLEDBUCKET){
      if(p1turn){
        bucket1 = bucket1 - bucket1;
        tree1 = tree1 + bucket1;
        
        
      }else{
        bucket2 = bucket2 - bucket2;
        tree2 = tree2 + bucket2;
      }

      
      cout << "Oh no! All of the cherries in your bucket have spilled." << endl;
      cout << p1name << " you have " << bucket1 << " cherries." << endl;
      cout << p2name << " you have " << bucket2 << " cherries.";
      cout << endl << endl;
    
 
    }else if(spin == FOURCHERRY){
      if(p1turn){
        bucket1 += 4;
        tree1 -= 4;
        if(bucket1 > MAX_CHERRIES){
          bucket1 = MAX_CHERRIES;
        }else{
          bucket1 = bucket1;
        }

      }else{
        bucket2 += 4;
        tree2 -= 4;
        if(bucket2 > MAX_CHERRIES){
          bucket2 = MAX_CHERRIES;
        }else{
          bucket2 = bucket1;
        }
      }
      
    
      cout << "You moved four cherries from the tree to your bucket." << endl; 
      cout << p1name << " you have " << bucket1 << " cherries." << endl;
      cout << p2name << " you have " << bucket2 << " cherries.";
      cout << endl << endl;

      
    }else if(spin == DOG){
      if(p1turn){
        if(bucket1 >= TWOCHERRY){
          bucket1 = bucket1 - TWOCHERRY;
        }else if(bucket1 == ONECHERRY){
          bucket1 -= 1;
          tree1 += 1;
        }else{
          bucket1 = bucket1;
          tree1 = tree1;
        }
      }else{
        if(bucket2 >= TWOCHERRY){
          bucket2 = bucket2 - TWOCHERRY;
        }else if(bucket2 == ONECHERRY){
          bucket2 -= 1;
          tree2 += 1;
        }else{
          bucket2 = bucket2;
          tree1 = tree1;
        }  
      }
    

      cout << "Oh no! A dog just took two of your cherries." << endl;  
      cout << p1name << " you have " << bucket1 << " cherries." << endl;
      cout << p2name << " you have " << bucket2 << " cherries.";
      cout << endl << endl;

    
    }else if(spin == THREECHERRY){
      if(p1turn){
        bucket1 += 3;
        tree1 -= 3;
        if(bucket1 > MAX_CHERRIES){
          bucket1 = MAX_CHERRIES;
        }else{
          bucket1 = bucket1;
        }
        
        
      }else{
        bucket2 += 3;
        tree2 -= 3;
        if(bucket2 > MAX_CHERRIES){
          bucket2 = MAX_CHERRIES;
        }else{
          bucket2 = bucket2;
        }
      }
    
    
      cout << "You moved three cherries from the tree to your bucket." << endl; 
      cout << p1name << " you have " << bucket1 << " cherries." << endl;
      cout << p2name << " you have " << bucket2 << " cherries.";
      cout << endl << endl;
      
      
    }else if(spin == BIRD){
      if(p1turn){
        if(bucket1 >= TWOCHERRY){
          bucket1 = bucket1 - TWOCHERRY;
        }else if(bucket1 == ONECHERRY){
          bucket1 -= 1;
          tree1 += 1;
        }else{
          bucket1 = bucket1;
          tree1 = tree1;
        }
      }else{
        if(bucket2 >= TWOCHERRY){
          bucket2 = bucket2 - TWOCHERRY;
        }else if(bucket2 == ONECHERRY){
          bucket2 -= 1;
          tree2 += 1;
        }else{
          bucket2 = bucket2;
          tree1 = tree1;
        }
      }
  
  
      cout << "Oh no! A bird just took two of your cherries." << endl;
      cout << p1name << " you have " << bucket1 << " cherries." << endl;
      cout << p2name << " you have " << bucket2 << " cherries.";
      cout << endl << endl;
    }
    
    if(p1turn){
      p1turn = false;
    }else{
      p1turn = true;
    }
  }
  
  if(bucket1 >= WIN){
    cout << "Congratulations " << p1name << " you won!";
  }else{
      cout << "Congratulations " << p2name << " you won!";
  }
  
  cout << endl << endl;
  
  cout << "Goodbye!";
  
  cout << endl << endl;
  
  return 0; 
}

