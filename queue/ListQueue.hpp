#include "QueueADT.hpp"
#include <string>
struct node{
  std::string e;

  node *next;
};

class ListQueue : public QueueADT{
 private:
  node *_front;
  node *_back;
  int _size;
 public:
  ListQueue();
  ~ListQueue();
  bool empty();
  int size();
  element_t front();
  element_t back();
  void enqueue(element_t);
  void dequeue();
  
};
