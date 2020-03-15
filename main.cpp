#include <iostream>
#include <ctime> 
#include <atomic> 
#include <thread>
#include "Timer.h"

using namespace std;

atomic_bool isstep(false);

void how2timer(int ms) {
    int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;   /// новая константа
       /* выведем константы "для наглядности" */
    //cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl;
    //cout << "CLOCKS_PER_MSEC: " << CLOCKS_PER_MSEC << endl;
    clock_t end_time = clock() + ms * CLOCKS_PER_MSEC ;  // время завершения
    while (clock() < end_time) {}  // цикл ожидания времени
    cout << "Время вышло!!!\n";  // сообщение о конце работы функции
    cout << isstep << '\n';
    if(isstep)
    how2timer(ms);
    else
    {
      return;      
    }    
}

void startTimer(){
  
  isstep = true;

  thread thr(how2timer, 5000);
  thr.detach();
  cout << "isstep\n";
  isstep = false;

}

struct  foo
{
   int j;
};


void temp(void* a){
   //int data = *(int*)a;
   auto t = (foo*)a;
   foo r = *t;
   cout << r.j << '\n';
}

int main(){

    /*
    startTimer();

    
   string h{""};

   while (h != "h")
   {
       cin >> h;
   }
   */
  unsigned i = 1024;
  Timer tm;
  foo f;
  f.j = 5;
  tm.obj = &f;
  tm.run = temp;
  tm.start(1000);
  
  return 0;
}