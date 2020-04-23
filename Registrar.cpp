// # Cpsc350-Assignment-4
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the header file for the DoubleGenList template class


#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> //for sort
#include "Registrar.h"

using namespace std;

int stringToInteger(string convert){
  int x = 0;
  if(convert == "1"){
    int x = 1;
    cout << x << endl;
    cout << "string to integer was complete" << endl;


    return 1;
  }
}
Registrar::Registrar(){
  double meanStudentWait = 0;
  double medianStudentWait = 0;
  double LongestStudentWait = 0;
  int overTenCount = 0;
  int meanIdleTime = 0;
  int medianIdleTime = 0;
  int LongestIdleTime = 0;
  int studentEnqueueTime = 0;
  int studentWindowTime = 0;
  int numOfStudentsLine = 0;
  int studentNumTotal = 0;
  int lineId = 0;
  int numOfWindows = 0;;
  GenQueue<Student> studentQueue;
};

void Registrar::infoGetter(string fileName){ //gets the information from the files and then
  ifstream inFile;
  string line;
  lineId = 0; //this is used to determine which type of information it is.
  inFile.open(fileName);
  if(!inFile.is_open()){
    cout << "file does not exist" << endl;
    cout << "Shutting down system" << endl;
    exit(1);
  }
  getline(inFile, line);
  numOfWindows = stoi(line); // this gets the first line which is the number of windows open
  window = new Student*[numOfWindows]; // array created for students

  for (int i = 0; i < numOfWindows; ++i){ //this creates a window full of students without info
    Student* student = new Student();
    window[i] = student;
  }

  while (getline(inFile, line)){
    if(lineId == 0){
      studentEnqueueTime = stoi(line); //second line is the entry time for the student
      lineId++;
    }
    if(lineId == 1){ //moves on to the next line which is
      numOfStudentsLine = stoi(line);

      for (int i = 0; i < numOfStudentsLine; ++i){
        getline(inFile, line);
        studentWindowTime = stoi(line); //student time at window is stored

        Student* student = new Student(studentWindowTime, studentEnqueueTime); //new student with these infos from the textfile is created
        RegistrarQueue.insert(student); //inserted to the queue
        studentNumTotal++;//numbers incremented
        waitTimeCount++;
      }
      lineId--; //line id goes back to 0;
    }
  }
  inFile.close();//inFile is closed
}

double Registrar::getMeanWait(){
  double sum;
  double numWaitTime;
  double result;
  GenListNode<int> *start = waitTimeList.front;
  while(start != NULL){
    sum += start->data;
    start = start->next;
    numWaitTime++;

    result = sum/numWaitTime;

  }
  return result;
}
double Registrar::getMeanIdle(){
  double sum;
  double numIdleTime;
  double result;
  GenListNode<int> *start = idleTimeList.front;
  while(start != NULL){
    sum += start->data;
    start = start->next;
    numIdleTime++;

    result = sum/numIdleTime;

  }
  return result;
}

int Registrar::getWaitOverTen(){
  int numOfWaitOverTen;
  GenListNode<int> *start = waitTimeList.front;
  while(start != NULL){
    if(start->data > 10){
      numOfWaitOverTen++;
    }
    start = start->next;
  }
  return numOfWaitOverTen;
}

int Registrar::getLongestWait(){
  int longest;
  int current;
  GenListNode<int> *start = waitTimeList.front;
  while(start->next != NULL){
    start->data = current;
    if(start->data <start->next->data){
      start->next->data = longest;
      start = start->next;
    }
    else{
      start = start->next;
    }
  }
  return longest;

}

int Registrar::getLongestIdle(){
  int longest;
  int current;
  GenListNode<int> *start = idleTimeList.front;
  while(start->next != NULL){
    start->data = current;
    if(start->data <start->next->data){
      start->next->data = longest;
      start = start->next;
    }
    else{
      start = start->next;
    }
  }
  return longest;
}


double Registrar::getMedianWait(){
  double medResult = 0;

  GenListNode<int> *start = waitTimeList.front;
  while(start != NULL){
    start = start->next;
    waitTimeCount++;
  }
  start = waitTimeList.front;
  int medArray[waitTimeCount];

  for(int i = 0; i < waitTimeCount; ++i){
    medArray[i] = start->data;
    start = start->next;
  }
  int flag = sizeof(medArray)/sizeof(medArray[0]);
  sort(medArray,medArray+flag); //array is sorted here

  //sorting when it is odd
  if(sizeof(medArray) % 2 !=0){
    int indexOfMiddle = 0;

    indexOfMiddle = (waitTimeCount/2) + 1; //gets the index number of middle
    medResult = medArray[indexOfMiddle];

    return medResult;
  }
  //sorting when it is even
  else if(sizeof(medArray) % 2 == 0){
    //must find the average of middle two numbers
    int num1;
    int num2;
    num1 = medArray[waitTimeCount/2];
    num2 = medArray[(waitTimeCount/2) +1];
    medResult = double(num1) + double(num2);
    medResult /=2;

    return medResult;

  }
}

int Registrar::getNumIdleOverFive(){
  int count = 0;

  GenListNode<int> *start = idleTimeList.front;
  while(start != NULL){
    if(start->data > 5){
      count++;
    }
    start = start->next;

  }
  return count;
}
