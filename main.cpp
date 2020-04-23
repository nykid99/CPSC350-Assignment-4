// # Cpsc350-Assignment-4
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the header file for the DoubleGenList template class


#include <iostream>
#include <string>
#include <fstream>
#include "Registrar.h"
using namespace std;


int main(int argc, char *argv[]){
  string fileName = argv[1]; //stores argument as a string
  bool RedLight = false;
  int TickTime = 0;
  Registrar r;


  ifstream inFile;
  string line;
  r.lineId = 0; //this is used to determine which type of information it is.
  inFile.open(fileName);
  if(!inFile.is_open()){
    cout << "file does not exist" << endl;
    cout << "Shutting down system" << endl;
    exit(1);
  }
  getline(inFile, line);
  r.numOfWindows = stoi(line); // this gets the first line which is the number of windows open
  r.window = new Student*[r.numOfWindows]; // array created for students

  for (int i = 0; i < r.numOfWindows; ++i){ //this creates a window full of students without default info
    Student* student = new Student();
    r.window[i] = student;
  }

  while (getline(inFile, line)){ //used switch instead of if statements because if didn't break
    switch(r.lineId){
      case(0):
      {
        r.studentEnqueueTime = stoi(line);
        r.lineId++;
        break;
      }
      case(1):{
        if(line != ""){
          r.numOfStudentsLine = stoi(line);
          for(int i = 0; i<r.numOfStudentsLine; ++i){
            getline(inFile, line);
            r.studentWindowTime = stoi(line);
            Student* student = new Student(r.studentWindowTime, r.studentEnqueueTime); //now it has the right amount of students in
            r.RegistrarQueue.insert(student);//student is entered into the queue
          }
          r.lineId--;
        }
        break;
      }
      default:{
        break;
      }
    }
  }
  while(RedLight == false){
    if(r.RegistrarQueue.isEmpty()){ //this part of the code checks if no one's in the queue
      int match = 0;
      for(int i = 0; i < r.numOfWindows; ++i){
        if(r.window[i]->timeNeed < 1){ //time needed is checked
          match++;
        }
      }
      if(match == r.numOfWindows){ //if each student in window has a time needed of 0, program is stopped
        RedLight = true;
      }

    }

    for(int i = 0; i < r.numOfWindows; ++i){   //puts students in the window at the right time
      Student* tempStudent = r.RegistrarQueue.peek();
      if(TickTime == tempStudent->ClockTick){
        r.waitTimeList.insert(tempStudent->idleTime);
        r.window[i] = tempStudent;
        r.RegistrarQueue.remove();
      }
    }

    if(!r.RegistrarQueue.isEmpty()){ // increases idle time in the queue
      for(int i = 0; i < r.RegistrarQueue.size; ++i){
        GenListNode<Student*> *start = r.RegistrarQueue.front;
        while(start != NULL){
          if(start->data->idleTime >= 0){
            start->data->idleTime++;
          }
        }
      }
    }
    TickTime++; //time increased

    //for every loop, idleTime and time needed at the window must be updated accordingly
  }
  for(int i = 0; i < r.numOfWindows; ++i){//this checks the windows that never had people and make them enter the idle Time
    if (r.window[i]->idleTime > 0){
        r.idleTimeList.insert(r.window[i]->idleTime);
    }
  }

  //couts for the results
  int overTen = r.getWaitOverTen();
  double medWaitTime = r.getMedianWait();
  double meanWaitTime = r.getMeanWait();
  int longWait = r.getLongestWait();
  int longestIdle = r.getLongestIdle();
  int meanIdle = r.getMeanIdle();
  int longestWait = r.getLongestWait();
  int idleOver5 = r.getNumIdleOverFive();

  cout << "The mean student wait time:" << meanWaitTime<<endl;
  cout << "The median student wait time:" << medWaitTime <<endl;
  cout << "The longest student wait time:" << longWait <<endl;
  cout << "The number of students waiting for over 10 minutes" << overTen <<endl;
  cout << "The mean window idle time" << meanIdle <<endl;
  cout << "The longest window idle time" << longestIdle <<endl;
  cout << "The number of idle times over 5:" << idleOver5 << endl;



  return 0;
}
