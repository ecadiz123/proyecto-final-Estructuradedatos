#ifndef HASH_TABLE_T
#define HASH_TABLE_T

typedef int value_t;
typedef int key_t;

struct element_t
{
    key_t key;
    value_t value;
};

class HashTable{
    public:
        virtual bool empty() = 0;
        virtual int size() = 0;
        virtual element_t find(key_t) = 0;
        virtual void insert(element_t) = 0;
        virtual void remove(key_t) = 0;
};

#endif