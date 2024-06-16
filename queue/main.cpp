#include <iostream>
#include "ArrayQueue.hpp"
#include "ListQueue.hpp"

int main(int argc, char const *argv[])
{
  ListQueue fila;
  fila.enqueue(10);

  fila.enqueue(5);
  fila.enqueue(20);
  fila.enqueue(30);
  fila.enqueue(8);
  std::cout <<"La fila contiene "<<fila.size() <<" elementos (empty: "<< fila.empty()<<")\n";

  fila.printlist();
  fila.dequeue();
  fila.dequeue();
  fila.dequeue();
  fila.dequeue();
  fila.dequeue();

  std::cout <<"La fila contiene "<<fila.size() <<" elementos (empty: "<< fila.empty()<<")\n";
  fila.printlist();
  fila.dequeue();
  return 0;
}
