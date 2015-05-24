//
// SafeQueue.hpp for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP/ex5
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Fri Apr 17 11:07:44 2015 Martin Porrès
// Last update Sun May 24 17:27:21 2015 Martin Porrès
//

#ifndef			_SAFEQUEUE_HPP_
# define		_SAFEQUEUE_HPP_

#include		<queue>
#include		"Mutex.hpp"
#include		"ScopedLock.hpp"
#include		"ISafeQueue.hpp"

template <typename T>
class			SafeQueue : public ISafeQueue<T>
{
public:
  SafeQueue(void) : isEnd(false)
  {

  }

  ~SafeQueue(void)
  {

  }

  void			push(T value)
  {
    ScopedLock	lock(mutex);

    if (!isEnd)
      queue.push(value);
    else
      throw std::runtime_error("SafeQueue is finished");
  }

  bool			tryPop(T *value)
  {
    ScopedLock	lock(mutex);

    if (queue.empty())
      return (false);
    *value = queue.front();
    queue.pop();
    return (true);
  }

  bool			isFinished(void)
  {
    ScopedLock	lock(mutex);

    if (!isEnd)
      return (false);
    if (!queue.empty())
      return (false);
    return (true);
  }

  void			setFinished(void)
  {
    ScopedLock	lock(mutex);

    isEnd = true;
  }

  bool			isEmpty(void)
  {
    return (queue.empty());
  }

private:
  std::queue<T>		queue;
  Mutex			mutex;
  bool			isEnd;
};

#endif
