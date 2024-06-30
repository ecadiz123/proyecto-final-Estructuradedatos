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

element_tablahash *borrador;
int i=0;
while (_size!=0)
{
   _container[i];
   if (_container[i]->next!=NULL)//si hay lista en el espacio
   {
    element_tablahash *borradoraux=NULL;//se va a usar un aux para borrar
    borrador=_container[i];//borrador apunta al primero que esta en arreglo
    while(borrador->next!=NULL)//borra todo menos el ultimo de la lista
    {
        borradoraux=borrador->next;//aux guarda siguiente nodo
        free(borrador);//se borra nodo de lista
        borrador=borradoraux;//se recupera direccion siguiente nodo
        _size--;


    }
    free(borrador);//borra nodo que queda, el ultimo de la lista
    _size--;
   }else//si esta el elemento solo en el arreglo simplemente lo borra
   {
    borrador=_container[i];
    free(borrador);
    _size--;
   }
   
   i++;
   

}


}
int HashEncadenado :: hash(key_tablahash k)//función hash
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
element_tablahash HashEncadenado::find(key_tablahash k)//función de busqueda

{

element_tablahash *lugararreglo=_container[hash(k)];


if (lugararreglo==NULL)//caso donde no se encontró ficha en la posición
{
    element_tablahash vacio;
    vacio.key=0;
    return vacio; ;// retorna una ficha sin rellenar de key 0

}else
{
//caso donde está en el arreglo ahora hay que buscar en la fila.
element_tablahash *recorredor=lugararreglo;
while (recorredor!=NULL)//es null cuando llega al final de recorrer
{
    if (k=recorredor->key)
    {   //si lo que apunta recorredor tiene el key deseado, devuelve lo que apunta
        return *recorredor;
    }
    recorredor= (*recorredor).next;  //si no ocurre va al siguiente elemento



}
}




}
void HashEncadenado::insert(element_tablahash e)//funcion de insertar
{
    int posicion = hash(e.key);


    if (_container[posicion]==NULL)
    {
        element_tablahash *l=(element_tablahash*)malloc(sizeof(element_tablahash));
        *l=e;
        l->next=NULL;
        _container[posicion]=l;
        _size++;
    }else{

        
        element_tablahash *l=(element_tablahash*)malloc(sizeof(element_tablahash));
       *l=e;
        l->next =  _container[posicion];
        _container[posicion] = l;
        /*
        Este insert tiene orden 1, a diferencia de colocar al final y hacer recorrer para insertar
        */
        _size++;
    }
    
}
void HashEncadenado::remove(key_tablahash k)//función de eliminar
{
    int indicearreglo=hash(k);
    element_tablahash *pos=_container[indicearreglo];//puntero hacia elemento que esta en esa posicion
    if(pos!=NULL)//caso donde hay elemento en el arreglo, si no hay, simplemente no hace nada
    {

        //no se usa find y se recorre independiente para tener un puntero disponible que apunte al anterior ya que la tabla usa fila y no lista.
            element_tablahash *anterior=NULL,*borrando=pos;
            while ((*borrando).key!=k)//no recorre mientras la llave corresponda a la que se quiere buscar.
            {
                anterior=borrando;
                borrando=(*borrando).next;
                

            }
            
        
        if (anterior==NULL)//caso donde esta al inicio del arreglo el elemento y no tuvo que recorrer
        {
            _container[indicearreglo]=(*borrando).next;//apunta al siguiente, si no hay nada, apunta a un NULL que ya estaba definido en insert
            free(borrando);
            _size--;
        }else//caso donde esta entremedio de la lista o al final, es dedcir anterior tiene valor
        {
            (*anterior).next=(*borrando).next;//si hay algo después el anterior apunta a este elemento, si esta al final, por el insert debería haber un NULL
            free(borrando);
            _size--;
        }
        


    }

}
