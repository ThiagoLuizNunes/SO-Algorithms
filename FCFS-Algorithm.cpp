#include <iostream>
#include<sstream>
#include <vector>
#include <string>
#include "Fila.h"
#include "TimeMethods.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Fila myFila;
  createFile(&myFila);

  int inst, number, x = 0;
  vector<int> myVector;

  cout << "Digite o número de instancias: " << endl;
  cin >> inst;

  do{
    cin >> number;
    myVector.push_back(number);
    x++;
  }while(x < inst*2);

  cout << endl;

  int y=0;
  for (size_t i = 0; i < 4; i++) {
    int start, process;
    start = myVector.at(y);
    process = myVector.at(y+1);

    int res = insertFila(&myFila, start, process);
    y = y+2;
  }

  cout << "FILA: " << endl;
  printFila(&myFila);

  float averageBackTime = backTime(&myFila);
  float averageWaitTime = waitTime(&myFila);

  cout << "Average back time : " << averageBackTime << endl;
  cout << "Average wait time : " << averageWaitTime << endl;
  cout << endl;

  return 0;
}
