#ifndef HASH_TABLE_T
#define HASH_TABLE_T
#include <string>
typedef int value_t;
typedef int key_t; // en este caso int portque es el rut sin ultimo digito

struct element_t // Datos de la ficha
{

    
    char digitoverificador;
    key_t key; //va a ser el rut

    std::string motivodeconsulta;
    std::string antecedentesdentales;
    int piezasatratar;//las piezas dentales tienen numero
    element_t *next;
};

class HashTable
{
public:
    virtual bool empty() = 0;
    virtual int size() = 0;
    virtual element_t find(key_t) = 0;
    virtual void insert(element_t) = 0;
    virtual void remove(key_t) = 0;
};

#endif