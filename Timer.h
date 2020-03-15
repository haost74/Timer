#include <atomic>
#include <ctime>

class Timer{

  public:
     Timer();
     void (*run)(void*);
     void start(int ms);
     void stop(); 
     void* obj;    

  private:
    std::atomic<bool> isstep;
    const int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;
};