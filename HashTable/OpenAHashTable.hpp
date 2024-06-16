#include "HashTable.hpp"
#define MAX 100 // 'm'

class OpenAHashTable : public HashTable{
    private:
        int _size;
        element_t * _container[MAX];
        int hash(key_t);
    public:
        OpenAHashTable();
        ~OpenAHashTable();
        bool empty();
        int size();
        element_t find(key_t);
        void insert(element_t);
        void remove(key_t);
};