#include "ListQueue.hpp"
#include <string>
#include <iostream>
int main(){

ListQueue fila;


std:: string s="Hola como esta";

fila.enqueue(s);

std::cout<< fila.front()<<"\n";


}