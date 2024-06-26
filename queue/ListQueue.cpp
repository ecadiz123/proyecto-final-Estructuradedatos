#include <cstdio>
#include <cstdlib>

#include "ListQueue.hpp"
ListQueue::ListQueue(){
  _front=NULL;
  _back=NULL;
  _size=0;
}
ListQueue::~ListQueue(){
 //destructor fila memoria dinamica
    node *borrador, *recorredor;
    recorredor=_front;
    borrador=recorredor;
    while (_size!=0)
    {
      recorredor=(*recorredor).next;
      free(borrador);
      borrador=recorredor;
      _size--;
    }
    
    





}
bool ListQueue::empty(){ //definir si la fila esta vacia
  if (_front==NULL)
  {
  return true; // == 1
  }  else
  return false; // == 0
  
}
int ListQueue::size(){ //definir tamanio de la fila
  
  return _size;
}
elemento_t ListQueue::front(){ //consulta elemnto de al frente

  if (_front==NULL)
  {
    return "0";
  }
  else
  return (*_front).e;
}
elemento_t ListQueue::back(){ // consulta elemento de al final
  
  if (_back==NULL)
  {
    return "0";
  }
  else
  return (*_back).e;
  
}
void ListQueue::enqueue(elemento_t e)//ingresa elemento a la fila
{
  //crear nodo
  node *nuevo;
  nuevo=(node*)malloc(sizeof(node));//es necesario inicializar manualmente despues de malloc
  (*nuevo).e= e;
  (*nuevo).next=NULL;
  if (_front!=NULL)//front va a ser NULL solo en el caso de una fila vacia.
  {
    //si front es distinto de NULL hay que enlazarlo al final de la fila.
    (*_back).next=nuevo;
    _back=nuevo;
    _size++;

  }else
  {
    _front=nuevo;
    _back=nuevo;
    _size++;
  }
  
}
void ListQueue::dequeue()//elimina elemento de al frente de la fila
{

  // se crea un nodo aux para borrar.
  if (_front!=NULL)
  {node *borrar;
  borrar=_front;
  _front=_front->next;
  free(borrar);
  _size--;
  }



}


