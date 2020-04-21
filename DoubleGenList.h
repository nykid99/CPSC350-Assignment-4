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
public:
  GenListNode<T> *front; //front and back from GenListNode
  GenListNode<T> *back;
  unsigned int size;
  DoubleGenList();//default constructor
  DoubleGenList(int d); // overloaded constructor
  ~DoubleGenList(); // destructor

  T getFront();
  void insertFront(T data);
  void insertBack(T data);
  T removeFront();
  int search(int val);// will return position
  int removeAtpos(int pos);

  unsigned int getSize();
  bool isEmpty();
  void printList();
};

template <typename T>
DoubleGenList<T>::DoubleGenList(){
	front = NULL;
	back = NULL;
  size = 0;
};

template <typename T>
DoubleGenList<T>::~DoubleGenList(){

};


template <typename T>
DoubleGenList<T>::DoubleGenList(int d){
  size = d;
  front = NULL;
  back = NULL;
};


template <typename T>
bool DoubleGenList<T>::isEmpty(){
  return size == 0;
}





template <typename T>
T DoubleGenList<T>::getFront(){
  return front->data;
}

template <typename T>
void DoubleGenList<T>::insertFront(T data){
  GenListNode<T> *node = new GenListNode<T>(data);
  //check if empty
  if(isEmpty()){
    back = node;
  }
  else{
    front->prev = node;
    node->next = front;

    //not empty
  }
  size++;
}

template <typename T>
void DoubleGenList<T>::insertBack(T data){
  GenListNode<T> *node = new GenListNode<T>(data);
  //check if empty
  if(isEmpty()){
    front = node;
  }
  else{
    node->prev = back;
    back->next = node;

    //not empty
  }
  size++;
}

template <typename T>
T DoubleGenList<T>::removeFront(){
  int temp = front->data; //stores the value
  GenListNode<T> *ft = front; //second node to keep a track of the pointer.
  front = front->next;
  ft->next = NULL;
  delete ft;

  size--;
  return temp;
}



template <typename T>
int DoubleGenList<T>::search(int val){
  int position = -1; //negative position doesn't exist valuenotfound
  GenListNode<T> *curr = front;

  while(curr != NULL){
    //iterate and attempt to find the value
    position++;

    if(curr->data == val){
      break;//found it!
    }
    else{
      curr = curr->next;
      //go to the next once
    }
  }
  if(curr == NULL){
    position = -1;
  }
}
template <typename T>
int DoubleGenList<T>::removeAtpos(int pos){
  //error checking
  int idx = -1;
  GenListNode<T> *curr = front;
  GenListNode<T> *prev = front;

  //now lets loop until position
  while(idx != pos){
    prev = curr;
    curr = curr->next;
    idx++;
  }
  //we found the position of the node to be deleted
  prev->next = curr->next;
  curr->next = NULL;
  int temp = curr->data;
  delete curr;
  size--;
  return temp;

}

template <typename T>
unsigned int DoubleGenList<T>::getSize(){
  return size;

}


template <typename T>
void DoubleGenList<T>::printList(){
  GenListNode<T> *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}
