#include <iostream>

class Student
{
    public:
        Student();
        Student(int x, int y);
        ~Student();

        int timeNeed;
        int ClockTick;
        int QueueTime;
        int idleTime;
};
