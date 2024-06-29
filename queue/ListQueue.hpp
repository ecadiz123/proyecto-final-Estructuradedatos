#include "QueueADT.hpp"

struct node{
  elemento_t e;

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
  void enqueue(elemento_t el);
  void dequeue();
  
};
