#include "HashTable.hpp"
#define MAX 100 // 'm'

class HashTable : public TablaHash{
    private:
        int _size;
        
        element_t * _container[MAX];//Define arreglo de fichas
        int hash(key_t);
    public:
        HashTable();
        ~HashTable();
        bool empty();
        int size();
        element_t find(key_t);
        void insert(element_t);//pensar en arreglo de listas con if
        void remove(key_t);
        
};