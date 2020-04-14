#include <iostream>
#include <string>
#include "GenListNode.h"
using namespace std

template <class T>
class GenQueue{
public:
  GenQueue(); //default constructor
  GenQueue(int maxSize); //overloaded constructor
  ~GenQueue();

//core functions
  void insert(chard d); //enqueue
  char remove(); //deququq

  //aux functions
  char peek();
  bool isFull();
  bool isEmpty();
  int getSize();

  int front;
  int remainder;
  int mSize;
  int numElements;

  char *myQueue; // array
};


template <class T>
GenQueue::GenQueue(){
  ///default
};

template <class T>
GenQueue::GenQueue(int maxSize){
  myQueue = new char(int maxSize);
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
};

template <class T>
GenQueue::~GenQueue(){
  //gotta figure this one out
};

template <class T>
void GenQueue::insert(char d){
  myQueue[++rear] = d;
  ++numElements;
}

template <class T>
char GenQueue::remove(){
  char c = '\0';
  c = myQueue[front];
  ++front;
  --numElements;
  return c;
}

template <class T>
char GenQueue::peek(){
  return myQueue[front];
}

template <class T>
bool GenQueue::isFull(){
  return (numElements == size);
}

template <class T>
bool GenQueue::isEmpty(){
  return (numElements == 0);
}

template <class T>
int GenQueue::getsize(){
  return numElements;
}
