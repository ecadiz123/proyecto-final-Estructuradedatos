#ifndef QUEUEADT_H
#define QUEUEADT_H
#include <string>
typedef std::string elemento_t;//filas van a guardar el nombre de las personas por lo que se usa string
class QueueADT {
 public:
  virtual bool empty() = 0;
  virtual int size() = 0;
  virtual elemento_t front() = 0;
  virtual elemento_t back() = 0;
  virtual void enqueue(elemento_t) = 0;
  virtual void dequeue() = 0;
};
#endif
