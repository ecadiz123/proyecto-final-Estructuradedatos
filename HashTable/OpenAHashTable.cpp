#include "OpenAHashTable.hpp"
#include <cstdlib>

HashTable::HashTable(){

}
HashTable::~HashTable(){

}
int hash(key_t k)//función hash
{
    return  k%MAX;
}

bool HashTable::empty(){

    
}
int HashTable::size(){

}
element_t HashTable::find(key_t k)//función de busqueda
{

}
void HashTable::insert(element_t e)//funcion de insertar
{
    int posicion = hash(e.key);
    if (_container[posicion]==NULL)
    {
        element_t *l=(element_t*)malloc(sizeof(element_t));
        *l=e;
        l->next=NULL;
    }else{

        
        element_t *l=(element_t*)malloc(sizeof(element_t));
        l->next =  _container[posicion];
        _container[posicion] = l;
        /*
        Este insert tiene orden 1, a diferencia de colocar al final y hacer recorrer para insertar
        */

    }
    
}
void HashTable::remove(key_t k)//función de eliminar
{

}
