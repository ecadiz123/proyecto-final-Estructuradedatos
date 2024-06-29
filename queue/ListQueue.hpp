#include "QueueADT.hpp"

struct node{
  elemento_fila e;

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
  elemento_fila front();
  elemento_fila back();
  void enqueue(elemento_fila);
  void dequeue();
  
};
