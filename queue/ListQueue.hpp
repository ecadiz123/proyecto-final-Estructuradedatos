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
  elemento_t front();
  elemento_t back();
  void enqueue(elemento_t);
  void dequeue();
  
};
