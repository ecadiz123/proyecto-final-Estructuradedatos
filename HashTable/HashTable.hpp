#ifndef HASH_TABLE_T
#define HASH_TABLE_T
#include <string>
#include <cstdlib>

#define _charsize 200//tamaño de los arreglos de char a utilizar, si se quieren cambiar se puede directamente aqui
typedef int value_t;
typedef int key_tablahash; // en este caso int portque es el rut sin ultimo digito

struct element_tablahash // Datos de la ficha
{

    
    char digitoverificador;
    key_tablahash key; //va a ser el rut sin digito verificador
    
    char motivoconsulta[_charsize];
    int sizemotivo;//variable que ayuda al printeo 
    char antecedentesdentales[_charsize];
    int sizeantecedentes;//variable que ayuda al printeo
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