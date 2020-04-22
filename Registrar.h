#include <string>
#include "Student.h"
#include "GenQueue.h"
using namespace std;


class Registrar
{
    private:

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

    public:
        Registrar();

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

        Student* *window;
        GenQueue<Student*> RegistrarQueue;
        DoubleGenList<int> waitTimeDoubleList;
        DoubleGenList<int> idleTimeDoubleList;

        // int *medArray;
        // int *idleArray;

        int numOfWindows;
        int numOfStudentsLine = 0;
        int studentNumTotal = 0;
};
