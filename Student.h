// # Cpsc350-Assignment-4
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the header file for student class


#include <iostream>

class Student
{
    public:
        Student(); //default constructor
        Student(int x, int y); //overloaded constructor
        ~Student();

        int timeNeed; //time need for each student
        int ClockTick; //entry time for each student
        int QueueTime; // time in queue for each student
        int idleTime; //time idle in the queue for each student
};
