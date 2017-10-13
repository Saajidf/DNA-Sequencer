/*
 *Title: Sequencer.h
 *Date: 2/22/2017
 *Author: Saajid Farooq
 *Description: This is the Sequencer class for the DNA sequencer
*/

#ifndef SEQUENCER_H
#define SEQUENCER_H

#include "DNA.h"

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Sequencer {
 public:
  //name: Sequencer (default constructor)
  //pre: A linked list (DNA) is available
  //post: A linked list (DNA) where m_head and m_tail points to NULL
  //      m_size is also populated with SizeOf
  Sequencer(string fileName);
  //name: Sequencer (destructor)
  //pre: There is an existing linked list (DNA)
  //post: A linked list (DNA) is deallocated (including nucleotides) to have no memory leaks!
  ~Sequencer();
  //name: readFile
  //pre: Valid file name of characters (Either A, T, G, or C)
  //post: Populates the LinkedList (DNA)
  void readFile();
  //name: mainMenu
  //pre: Populated LinkedList (DNA)
  //post: None
  void mainMenu();
  //name: getvalidint
  //pre: int representing max number
  //post: user valid input from 1 to max num
  int getValidInt(int max);
 private:
  DNA m_dna;
  string m_fileName;
};

#endif
