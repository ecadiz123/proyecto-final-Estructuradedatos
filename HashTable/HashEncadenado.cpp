#include "HashEncadenado.hpp"
#include <cstdlib>

HashEncadenado:: HashEncadenado(){
    this->_size=0;
    //caso para inicializar el arreglo con NULL en partes vacias.
    for (int i = 0; i < MAX; i++)
    {
        _container[i]=NULL;//como es puntero y no nodo no hay que inicializar atributos
    }
    
}
HashEncadenado::~HashEncadenado(){


}
int HashEncadenado :: hash(key_t k)//función hash
{
    return  k%MAX;
}

bool HashEncadenado::empty(){
if (_size==0)
return true;
else
return false;
    
}
int HashEncadenado::size(){
return _size;
}
element_t HashEncadenado::find(key_t k)//función de busqueda

{

element_t *lugararreglo=NULL;
for ( int i = 0; i < MAX; i++)
{
    if(_container[i]->key==k)
    lugararreglo= _container[i];// se guarda direccion que indica en que parte del arreglo está
}

if (lugararreglo==NULL)//caso donde no se encontró ficha
{
    return *lugararreglo;//retorna un valor NULL

}else//caso donde está en el arreglo ahora hay que buscar en la fila.
{

element_t *recorredor=lugararreglo;
while (recorredor!=NULL)
{
    if (k=recorredor->key)
    {
        return *recorredor;
    }
    recorredor= (*recorredor).next;  



}
}




}
void HashEncadenado::insert(element_t e)//funcion de insertar
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
void HashEncadenado::remove(key_t k)//función de eliminar
{
    int indicearreglo=hash(k);
    element_t *pos=_container[indicearreglo];//posicion en el arreglo
    if(pos!=NULL)//caso donde hay elemento en el arreglo, si no hay, simplemente no hace nada
    {

        //no se usa find y se recorre independiente para tener un puntero disponible que apunte al anterior ya que la tabla usa fila y no lista.
            element_t *anterior=NULL,*borrando=pos;
            while ((*borrando).key!=k)//no recorre mientras la llave corresponda a la que se quiere buscar.
            {
                anterior=borrando;
                borrando=(*borrando).next;

            }
            
        
        if (anterior==NULL)//caso donde esta al inicio del arreglo el elemento y no tuvo que recorrer
        {
            _container[indicearreglo]=(*borrando).next;//apunta al siguiente, si no hay nada, apunta a un NULL que ya estaba definido en insert
            free(borrando);
        }else//caso donde esta entremedio de la lista o al final, es dedcir anterior tiene valor
        {
            (*anterior).next=(*borrando).next;//si hay algo después el anterior apunta a este elemento, si esta al final, por el insert debería haber un NULL
            free(borrando);

        }
        


    }

}
