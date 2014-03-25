#include "message_queue.h"
#include <mutex>

template <typename T>
void message_queue<T>::send(T && val)
{
  {
    std::lock_guard<std::mutex> lock(_mutex);
    _deque.push_front(std::move(val));
  }
  
  _wake_condition.notify_one();
}

template <typename T>
T message_queue<T>::receive()
{
  std::unique_lock<std::mutex> lock(_mutex);
  _wake_condition.wait(lock, [this]{return !_deque.empty();});
  T val = std::move(_deque.back());
  _deque.pop_back();

  return val;
}
