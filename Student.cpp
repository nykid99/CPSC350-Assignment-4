#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
    timeNeed = 0;
    ClockTick = 0;
    QueueTime = 0;
    idleTime = 0;

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
