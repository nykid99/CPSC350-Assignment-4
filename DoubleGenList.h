// # Cpsc350-Assignment-4
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the header file for the DoubleGenList template class

#include <iostream>
#include <string>
#include "GenListNode.h" //includes GenListNode
using namespace std;

template <typename T>
class DoubleGenList{ //this is the template class for the DoubleGenList
private:
  GenListNode *front; //front and back from GenListNode
  GenListNode *back;
  unsigned int size;
public:
  DoubleGenList();//default constructor
  DoubleGenList(T d) // overloaded constructor
  ~DoubleGenList(); // destructor

  T getFront();
  void insertFront(T data);
  void insertBack(T data);
  T removeFront();
  T removeBack();
  int search(int val);// will return position
  int removeAtpos(int pos);

  unsigned int getSize();
  bool isEmpty();
  void printList();
};

template <typename T>
T DoubleGenList<T>::getFront(){
  return front->data;
}

template <typename T>
void DoubleGenList<T>::insertFront(T data){
  
}
