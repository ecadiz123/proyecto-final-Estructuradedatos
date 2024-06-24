#include "HashTable.hpp"
#define MAX 100 // 'm'

class HashEncadenado : public HashTable{
    private:
        int _size;
        
        element_t * _container[MAX];//Define arreglo de fichas, es un arreglo de punteros que apuntan a fichas
        int hash(key_t);
    public:
       HashEncadenado();
        ~HashEncadenado();
        bool empty();
        int size();
        element_t find(key_t);
        void insert(element_t);//Inserta elemento dentro de arreglo, crea un nodo donde el puntero del arreglo queda apuntando
        void remove(key_t);
        
};