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

element_t *borrador;
int i=0;
while (_size!=0)
{
   _container[i];
   if (_container[i]->next!=NULL)//si hay lista en el espacio
   {
    element_t *borradoraux=NULL;//se va a usar un aux para borrar
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
    if(_container[i]!=NULL && _container[i]->key==k)
    lugararreglo= _container[i];// se guarda direccion que indica en que parte del arreglo está
}

if (lugararreglo==NULL)//caso donde no se encontró ficha
{
    element_t vacio;
    vacio.rut=0;
    return vacio; ;// retorna una ficha sin rellenar de rut 0

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
        _size++;
    }else{

        
        element_t *l=(element_t*)malloc(sizeof(element_t));
        l->next =  _container[posicion];
        _container[posicion] = l;
        /*
        Este insert tiene orden 1, a diferencia de colocar al final y hacer recorrer para insertar
        */
        _size++;
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
                _size--;

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
