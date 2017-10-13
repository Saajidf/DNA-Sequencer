/*
 *Title: DNA.cpp
 *Date: 2/22/2017
 *Author: Saajid Farooq
 *Description: This is the DNA Class for the sequencer
*/

#include "DNA.h"

  //name: DNA (default constructor)
  //pre: None
  //post: A linked list (DNA) where m_head and m_tail points to NULL
DNA::DNA(){
  m_head = NULL;
  m_tail = NULL;
  m_size = 0;
}

  //name: ~DNA (destructor)
  //pre: There is an existing linked list
  //post: A linked list (DNA) is deallocated (including all dynamically 
  //     allocated nucleotides) 
  //     to have no memory leaks!
DNA::~DNA(){
  Clear();
}


  //name: InsertEnd
  //pre: Takes in a char. Creates new node (nucleotide). 
  //     Requires a linked list (strand of DNA)
  //post: Adds a new node (nucleotide) to the end of the linked list (strand of DNA).
void DNA::InsertEnd(char payload){
  //temp node
  Nucleotide * newNode = new Nucleotide;
  newNode->m_payload = payload;
  newNode->m_next = NULL;
  //if headd is empty first node is head
  if(m_head == NULL){
    m_head = newNode;
    m_tail = newNode;
  }
  //else adds to end and changes tail value and mnext val
  else{

    Nucleotide *temp = m_head;
  
    while(temp->m_next != NULL){
      temp = temp->m_next;
    }
   
    temp->m_next = newNode;

  }


}


  //name: Display
  //pre: Outputs the dna strand(s); Pass it 1 for just the nucleotides; 
  //     2 for the nucleotides and it's complement (base pair)
  //post: None
void DNA::Display(int numStrand){

  Nucleotide * CURR = m_head;
  //if one prints each payload
  if(numStrand == 1){
    
    while(CURR != NULL){
      cout << CURR->m_payload << endl;
      CURR = CURR->m_next;
    }
  }
  //if 2 prints each payload and matches pair depending on the char
  else if(numStrand == 2){
    for(CURR = m_head; CURR != NULL; CURR = CURR -> m_next){
      cout << CURR -> m_payload;
      switch(CURR -> m_payload){
      case 'A':
	cout << " - T" << endl;
	break;
      case 'C':
	cout << " - G" << endl;
	break;
      case 'T':
	cout << " - A" << endl;
	break;
      case 'G':
	cout << " - C" << endl;
	break;
      }
    }
  }
 
}


  //name: NumAmino
  //pre: Takes in an amino acid name and its trinucleotide codon
  //     Trinucleotides are just three nucleotides in a row.
  //post: Searches the linked list for specific sequence; outputs results
void DNA::NumAmino(string name, string trinucleotide){
  //temp var to keep track of trinucleotides
  string tri;
  //count of found matches
  int count = 0;
  int size = 0;
  
  Nucleotide *CURR;
  // loops through linked list
  for(CURR = m_head; CURR != NULL; CURR = CURR -> m_next){
    //if tri is less than 3 char add nex char to tri then iterate size
    if(size < 3){
      tri += CURR->m_payload;
      size ++;
      //if size is three after char added tri is translated and then compared to the trinucleotide, iterates count if same
      if(size == 3){
	if(Translate(tri) == trinucleotide)
	  count++;
      }
      
    }

    //clears tri and size then adds next char to tri and size++
    else{
      tri = "";
      tri += CURR->m_payload;
      
      size = 1;
    } 
  }
  // cout count of trinucleotides found
  cout << trinucleotide << ": " << count << " identified" << endl;

}


  //name: Sequence
  //pre: Takes in full genetic code of one polynucleotide and looks at 
  //     one trinucleotide at a time.
  //     Known amino acids are displayed, others are unknown. Stored in dynamic array.
  //post: Displays either name of amino acid or unknown for each trinucleotide
void DNA::Sequence(){
  string tri;
  
  Nucleotide *CURR;
  
  int size = 0;
  //creates dynamic array
  string *arr = new string[m_size/3];
  unsigned int arrIndex = 0;
  

  //loops through linked list
  for(CURR = m_head; CURR != NULL; CURR = CURR -> m_next){
    // if tri length is less than 3 then adds char of current node starting from head to tri
    if(size < 3){
      tri += CURR->m_payload;
      size ++;
      //if length is 3 after adding then the translation is added to dynamic array
      if(size == 3){
	arr[arrIndex] = Translate(tri);
	arrIndex ++;
      }

    }
    //else clears tri and then adds next char to tri
    else{
      tri = "";
      tri += CURR->m_payload;

      size = 1;
    }
  }


  cout << "\nTrinucleotides:\n" << endl;
  for(int c = 0; c < m_size/3;c++)
    cout << arr[c] << endl;
  //deletes array
  delete[] arr;
}

  //name: Translate (Provided)
  //pre: Takes in three nucleotides (must be G,C,T, or A)
  //post: Translates a trinucleotide to its amino acid
string DNA::Translate(const string trinucleotide){
  if((trinucleotide=="ATT")||(trinucleotide=="ATC")||(trinucleotide=="ATA"))
    return ("Isoleucine");
  else if((trinucleotide=="CTT")||(trinucleotide=="CTC")||(trinucleotide=="CTA")||
          (trinucleotide=="CTG")|| (trinucleotide=="TTA")||(trinucleotide=="TTG"))
    return ("Leucine");
  else if((trinucleotide=="GTT")||(trinucleotide=="GTC")||
          (trinucleotide=="GTA")||(trinucleotide=="GTG"))
    return ("Valine");
  else if((trinucleotide=="TTT")||(trinucleotide=="TTC"))
    return ("Phenylalanine");
  else if((trinucleotide=="ATG"))
    return ("Methionine");
  else if((trinucleotide=="TGT")||(trinucleotide=="TGC"))
    return ("Cysteine");
  else if((trinucleotide=="GCT")||(trinucleotide=="GCC")||
          (trinucleotide=="GCA")||(trinucleotide=="GCG"))
    return ("Alanine");
  else if((trinucleotide=="GGT")||(trinucleotide=="GGC")||
          (trinucleotide=="GGA")||(trinucleotide=="GGG"))
    return ("Glycine");
  else if((trinucleotide=="CCT")||(trinucleotide=="CCC")||
          (trinucleotide=="CCA")||(trinucleotide=="CCG"))
    return ("Proline");
  else if((trinucleotide=="ACT")||(trinucleotide=="ACC")||
          (trinucleotide=="ACA")||(trinucleotide=="ACG"))
    return ("Threonine");
  else if((trinucleotide=="TCT")||(trinucleotide=="TCC")||
          (trinucleotide=="TCA")||(trinucleotide=="TCG")||
          (trinucleotide=="AGT")||(trinucleotide=="AGC"))
    return ("Serine");
  else if((trinucleotide=="TAT")||(trinucleotide=="TAC"))
    return ("Tyrosine");
  else if((trinucleotide=="TGG"))
    return ("Tryptophan");
  else if((trinucleotide=="CAA")||(trinucleotide=="CAG"))
    return ("Glutamine");
  else if((trinucleotide=="AAT")||(trinucleotide=="AAC"))
    return ("Asparagine");
  else if((trinucleotide=="CAT")||(trinucleotide=="CAC"))
    return ("Histidine");
  else if((trinucleotide=="GAA")||(trinucleotide=="GAG"))
    return ("Glutamic acid");
  else if((trinucleotide=="GAT")||(trinucleotide=="GAC"))
    return ("Aspartic acid");
  else if((trinucleotide=="AAA")||(trinucleotide=="AAG"))
    return ("Lysine");
  else if((trinucleotide=="CGT")||(trinucleotide=="CGC")||(trinucleotide=="CGA")||
          (trinucleotide=="CGG")||(trinucleotide=="AGA")||(trinucleotide=="AGG"))
    return ("Arginine");
  else if((trinucleotide=="TAA")||(trinucleotide=="TAG")||(trinucleotide=="TGA"))
    return ("Stop");
  else
    cout << "returning unknown" << endl;
  return ("Unknown");
}

  
  //name: IsEmpty
  //pre: Takes in a linked list (DNA)
  //post: Checks to see if the linked list (strand of DNA) is empty or not
bool DNA::IsEmpty(){
  //ternary statement isEmpty
  return (m_size == 0? true:false);
}


  //name: SizeOf
  //pre: Takes in a linked list (DNA)
  //post: Populates m_size with the total number of nucleotides loaded
void DNA::SizeOf(){
  Nucleotide *CURR = m_head;
  int size = 0;
  // loops through list and adds to size
  for(CURR = m_head; CURR != NULL; CURR = CURR -> m_next){
    size++;
  }
  m_size = size;
  
}


  //name Clear
  //pre: Takes in a linked list (DNA)
  //post: Clears out the linked list (all nodes too)
void DNA::Clear(){
 
  Nucleotide *pDel = m_head;

  //Traverse the list and delete the node one by one from the head 
  while (pDel != NULL) {
    // take out the head node 
    m_head = m_head-> m_next;
    delete pDel;
    // update the head node 
    pDel = m_head;
  }
  // Reset the head and tail node 
  m_tail = m_head = NULL;
}
 
