#include "HashTable.hpp"
#define MAX 100 // 'm'

class HashEncadenado : public HashTable{
    private:
        int _size;
        
        element_tablahash * _container[MAX];//Define arreglo de fichas, es un arreglo de punteros que apuntan a fichas
        int hash(key_tablahash k);
    public:
       HashEncadenado();
        ~HashEncadenado();
        bool empty();
        int size();
        element_tablahash find(key_tablahash k);
        void insert(element_tablahash e);//Inserta elemento dentro de arreglo, crea un nodo donde el puntero del arreglo queda apuntando
        void remove(key_tablahash k);
        
};