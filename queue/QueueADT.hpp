#ifndef QUEUEADT_H
#define QUEUEADT_H
typedef int elemento_fila;// se va a usar el rut para designar a la persona

class QueueADT {
 public:
  virtual bool empty() = 0;
  virtual int size() = 0;
  virtual elemento_fila front() = 0;
  virtual elemento_fila back() = 0;
  virtual void enqueue(elemento_fila ) = 0;
  virtual void dequeue() = 0;
};
#endif
