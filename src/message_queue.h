#ifndef H_MESSAGE_QUEUE_MCG
#define H_MESSAGE_QUEUE_MCG

#include <deque>
#include <mutex>
#include <condition_variable>

using namespace std;

template <typename T>
class message_queue
{

private:

  deque<T> _deque;
  mutex _mutex;
  condition_variable _wake_condition;

public:
  
  void send(T &&);
  T receive();

};

#endif
