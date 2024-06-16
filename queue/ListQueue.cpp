#include <cstdio>
#include <cstdlib>
#include <iostream>
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
bool ListQueue::empty(){
  if (_front==NULL)
  {
  return true;
  }
  else
  return false;
  
}
int ListQueue::size(){
  
  return _size;
}
element_t ListQueue::front(){

  if (_front==NULL)
  {
    return 0;
  }
  else
  return (*_front).e;
}
element_t ListQueue::back(){
  
  if (_back==NULL)
  {
    return 0;
  }
  else
  return (*_back).e;
  
}
void ListQueue::enqueue(element_t e){
  //crear nodo
  node *nuevo;
  nuevo=(node*)malloc(sizeof(node));//es necesario inicializar manualmente despues de malloc
  (*nuevo).e= e;
  (*nuevo).next=NULL;
  if (_front!=NULL)//front va a ser NULL solo en el caso de una fila vacia.
  {
    //si front es distinto de null hay que enlazarlo al final de la fila.
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
void ListQueue::dequeue(){
  // nodo aux para borrar.
  if (_front!=NULL)
  {node *borrar;
  borrar=_front;
  _front=_front->next;
  free(borrar);
  _size--;}



}
void ListQueue::printlist(){

  node* x ;

  x=_front;
        std::cout <<"[ ";
        while(x != NULL){
            std::cout << (*x).e <<" ";
            x = (*x).next;
        }
        std::cout <<"]\n";
    };



