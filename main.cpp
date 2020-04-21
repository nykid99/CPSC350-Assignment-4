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

  r.infoGetter(fileName);
  while(RedLight == false){
    if(r.RegistrarQueue.isEmpty()){ //this part of the code checks if the students still need time and if they don't, it stops the clock
      int match = 0;
      for(int i = 0; i < r.numOfWindows; ++i){
        if(r.window[i]->timeNeed < 1){
          match++;
        }
      }
      if(match == r.numOfWindows){
        RedLight = true;
      }

    }

    for(int i = 0; i < r.numOfWindows; ++i){
      if(!r.RegistrarQueue.isEmpty()){ //assuming someone is still waiting in line
        Student* tempStudent = r.RegistrarQueue.peek();

        if(tempStudent->ClockTick <= TickTime){
          if(r.window[i]->idleTime > 0){
            r.idleTimeDoubleList.insertBack(r.window[i]->idleTime);
          }
          r.waitTimeDoubleList.insertBack(r.window[i]->QueueTime);
        }

      }
    }
    //increment times
  }
  //now we must check the status of windows that never had people

  //couts



  return 0;
}
