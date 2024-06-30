#include "QueueADT.hpp"
#include <cstdlib>
struct node
{
  elemento_fila e;

  node *next;
};

class ListQueue : public QueueADT
{
private:
  node *_front = NULL;
  node *_back = NULL;
  int _size = 0;

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
