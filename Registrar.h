// # Cpsc350-Assignment-4
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
// This is the header file for the Registrar.h class


#include <string>
#include "Student.h"
#include "GenQueue.h"
using namespace std;


class Registrar
{

    public:
        Registrar();
        Student* *window;
        void infoGetter(string fileName);
        bool TimeIncrementer(int c);
        double getMeanWait();
        double getMedianWait();
        int getLongestWait();
        int getWaitOverTen();
        double getMeanIdle();
        int getLongestIdle();
        int getNumIdleOverFive();
        int stringToInteger(string convert);



        GenQueue<Student*> RegistrarQueue;
        GenQueue<int> waitTimeList;
        GenQueue<int> idleTimeList;

        int numOfWindows;
        int numOfStudentsLine = 0;
        int studentNumTotal = 0;

        double meanStudentWait;
        double medianStudentWait;
        double LongestStudentWait;
        int overTenCount;
        int meanIdleTime;
        int medianIdleTime;
        int LongestIdleTime;
        int studentEnqueueTime;
        int studentWindowTime;
        int studentTick;
        int lineId;
        int waitTimeCount = 0;
};
