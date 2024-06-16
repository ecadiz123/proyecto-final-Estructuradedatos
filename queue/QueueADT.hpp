#ifndef QUEUEADT_H
#define QUEUEADT_H
typedef int element_t;
class QueueADT {
 public:
  virtual bool empty() = 0;
  virtual int size() = 0;
  virtual element_t front() = 0;
  virtual element_t back() = 0;
  virtual void enqueue(element_t) = 0;
  virtual void dequeue() = 0;
};
#endif
