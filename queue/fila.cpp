#include <iostream>
#include <string>
#include <cstdlib>
#include "ListQueue.hpp"
int main (){

ListQueue fila,fila2;

fila.enqueue(123);
fila.enqueue(321);

std::cout<< "Valor true: "<< true<<"\n";
std::cout<< "Valor false: "<< false<<"\n";
std::cout << "Valor empty con elementos : "<< fila.empty()<<"\n";

std::cout << "Valor empty sin elementos : "<< fila2.empty()<<"\n";
if (fila2.front()== 0)
{
std::cout << "el front de la vacia es NULL"<<"\n";
}


}