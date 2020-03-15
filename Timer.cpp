#include "Timer.h"


Timer::Timer(){
    isstep = false;
    run = nullptr;
}


void Timer::start(int ms){   
    isstep = true; 
    clock_t end_time = clock() + ms * CLOCKS_PER_MSEC ;  // время завершения
    while (clock() < end_time) {}
    if(isstep && run != nullptr){
        
        run(obj);
        start(ms);
    }
    else
    {
        return;
    }
}

void Timer::stop(){
    run = nullptr;
    isstep = false;
}

