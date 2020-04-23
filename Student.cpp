// # Cpsc350-Assignment-4
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the header file for the DoubleGenList template class


#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
    timeNeed = 0; //time need for each student
    ClockTick = 0; //entry time for each student
    QueueTime = 0; // time in queue for each student
    idleTime = 0; //time idle in the queue for each student

}
Student::Student(int x, int y)
{
  timeNeed = x;
  ClockTick = y;
  QueueTime = 0;
  idleTime = 0;
}

Student::~Student(){
};
