#include <iostream>
#include <string>
#include "DoubleGenList.h"
using namespace std;

template <class T>
class GenQueue{

public:
  GenQueue();
  GenQueue(int maxSize);
  ~GenQueue();
  GenListNode<T> *front; //front and back from GenListNode
  GenListNode<T> *back;
  unsigned int size;
  void insert(T d);
  T remove();
  T peek();
  bool isFull();
  bool isEmpty();
  int getSize();
};


template <class T>
GenQueue<T>::GenQueue(){
  ///default
};

template <class T>
GenQueue<T>::GenQueue(int maxSize){
};

template <class T>
GenQueue<T>::~GenQueue(){
  //gotta figure this one out
};

template <class T>
void GenQueue<T>::insert(T d){

  GenListNode<T> *temp = new GenListNode<T>(d);
  if(front == NULL){
    front = temp;
  }
  else{
    back->next = temp;
    temp->prev = back;
  }
  back = temp;
  size++;

}

template <class T>
T GenQueue<T>::remove(){
  GenListNode<T> *dFront = front;
  if(isEmpty()){
    cout << "Queue is empty unable to remove" << endl;
  }
  else{
    if(front == back){
      front = NULL;
      back = NULL;
    }
    else{

      front->next->prev = NULL; //the next onewill have a prev of NULL;
      front = front->next;

    }
  }
  size--;
  return dFront->data;
  free(dFront);
}

template <class T>
T GenQueue<T>::peek(){
  return front->data;
}

template <class T>
bool GenQueue<T>::isFull(){
  return size != 0;
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return size == 0;
}

template <class T>
int GenQueue<T>::getSize(){
  return size;
}
