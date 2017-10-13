#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "Sequencer.h"

//max choice number in menu
const int MAX = 5;

  //name: Sequencer (default constructor)
  //pre: A linked list (DNA) is available
  //post: A linked list (DNA) where m_head and m_tail points to NULL
  //      m_size is also populated with SizeOf
Sequencer::Sequencer(string fileName){
  m_fileName = fileName;
  readFile();
  m_dna.SizeOf();

  int choice = 0;
  
  //loops program's menu and asks user for choice from menu. then perfroms choice until user picks 5
  do{
    mainMenu();
    
    //validates choice between 1 and 5
    choice = getValidInt(MAX);

    //switch statement to do what user picked from menu
    switch(choice){
      //displays strand
    case 1:
      m_dna.Display(1);
      break;
      //displays pairs
    case 2:
      m_dna.Display(2);
      break;
      //finds matches
    case 3:
      cout << "\n";
      m_dna.NumAmino("TTG","Tryptophan");
      m_dna.NumAmino("TTT","Phenylalanine");
      cout << "\n";
      break;
      //displays all trinucleotides
    case 4:
      m_dna.Sequence();
      cout << "\n";
      break;
      //exit
    case 5:
      cout << "DNA removed from memory" << endl;
      break;
    }

  }while(choice != 5);

}


  //name: Sequencer (destructor)
  //pre: There is an existing linked list (DNA)
  //post: A linked list (DNA) is deallocated (including nucleotides) to have no memory leaks!
Sequencer::~Sequencer(){
  m_dna.Clear();
}


  //name: readFile
  //pre: Valid file name of characters (Either A, T, G, or C)
  //post: Populates the LinkedList (DNA)
void Sequencer::readFile(){
  char line;
  ifstream myfile;
  myfile.open(m_fileName.c_str());
  //inserts each letter using function
  while(myfile >> line){
    m_dna.InsertEnd(line);
  }
  
 
  myfile.close();

}


  //name: mainMenu
  //pre: Populated LinkedList (DNA)
  //post: None
void Sequencer::mainMenu(){
  cout << "What would you like to do?" << endl;
  cout<< "1.Display DNA (Leading Strand)\n" <<
    "2.Display DNA (Base Pairs)\n" <<
    "3.Inventory Basic Amino Acids\n" <<
    "4.Sequence Entire DNA Strand\n" <<
    "5.Exit" << endl;
}
//gets valid num fer menu choice
int Sequencer::getValidInt(int max){
  int n = 0;
  do{

    cout << "Pick a number between 1 and " << max << ": ";
    cin >> n;

  }while(n < 1 or n > 5);

  return n;
}
