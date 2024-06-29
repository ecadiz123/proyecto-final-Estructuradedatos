#include <cstdio>
#include <cstdlib>

#include "ListQueue.hpp"
ListQueue::ListQueue()
{
  _front = NULL;
  _back = NULL;
  _size = 0;
}
ListQueue::~ListQueue()
{
  // destructor fila memoria dinamica
  node *borrador, *recorredor;
  recorredor = _front;
  borrador = recorredor;
  while (_size != 0)
  {
    recorredor = (*recorredor).next;
    free(borrador);
    borrador = recorredor;
    _size--;
  }
}
bool ListQueue::empty()
{ // definir si la fila esta vacia
  if (_front == NULL)
  {
    return true; // == 1
  }
  else
    return false; // == 0
}
int ListQueue::size()
{ // definir tamanio de la fila

  return _size;
}
elemento_fila ListQueue::front()
{ // consulta elemnto de al frente

  if (_front != NULL)
  {
    return (*_front).e;
  }
  else
    return 0; // Devuelve rut con valor 0
}

elemento_fila ListQueue::back()
{ // consulta elemento de al final

  if (_back != NULL)
  {
    return (*_back).e;
  }
  else
    return 0; // Devuelve rut con vvalor 0
}
void ListQueue::enqueue(elemento_fila el) // ingresa elemento a la fila
{
  // crear nodo
  node *nuevo; // puntero

  nuevo = (node *)malloc(sizeof(node)); //memoria asignada manualmente
  (*nuevo).e = el;                      // elemento dentro del nodo se iguala a input
  (*nuevo).next = NULL;                 // se inicializa el next en NULL
  if (_front == NULL)                   // front va a ser NULL solo en el caso de una fila vacia.
  {
    //caso fila vacia
    _front = nuevo; // front queda en el nuevo
    _back = nuevo;  // back apunta a nuevo
    _size++;
  }
  else
  {   
    // caso de una fila con elementos
    (*_back).next = nuevo; // el ultimo elemento se hace apuntar al nuevo
    _back = nuevo;         // puntero back ahora apunta al nuevo
    _size++;
  }
}
void ListQueue::dequeue() // elimina elemento de al frente de la fila
{

  // se crea un nodo aux para borrar.
  if (_front != NULL)
  {
    node *borrar;
    borrar = _front;
    _front = _front->next;
    free(borrar);
    _size--;
  }
}
