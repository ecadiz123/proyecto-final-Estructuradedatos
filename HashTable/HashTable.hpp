#ifndef HASH_TABLE_T
#define HASH_TABLE_T
#include <string>
typedef int value_t;
typedef int key_tablahash; // en este caso int portque es el rut sin ultimo digito

struct element_tablahash // Datos de la ficha
{

    
    char digitoverificador;
    key_tablahash key; //va a ser el rut
    std::string motivoconsulta;
    std::string antecedentesdentales;

    int piezaatratar;//las piezas dentales tienen numero
    element_tablahash *next;
};

class HashTable
{
public:
    virtual bool empty() = 0;
    virtual int size() = 0;
    virtual element_tablahash find(key_tablahash) = 0;
    virtual void insert(element_tablahash) = 0;
    virtual void remove(key_tablahash) = 0;
};

#endif