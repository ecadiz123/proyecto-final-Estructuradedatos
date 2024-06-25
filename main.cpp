#include "HashTable/HashEncadenado.hpp"
#include "queue/ListQueue.hpp"
#include <iostream>

int main()
{

    HashEncadenado fichas;      // tabla donde se van a guardar las fichas
    ListQueue normal, urgencia; // fila de urgencia y la fila normal
    int ingreso;






//variables fila
    std::string nombre;


//variables fichas

    std::cout << "Bienvenido" << "\n";
    std::cout << "Ingrese que desea hacer" << "\n";

    std::cout << "1.Organizar clientes en espera" << "\n";
    std::cout << "2.Trabajar con fichas" << "\n";

    std::cout << "(Ingrese solo numeros)" << "\n";

    std::cin >> ingreso;
    switch (ingreso)
    {
    case 1:
       
    std::cin >> nombre;





        break;
    case 2:

        break;
    default:

        std::cout << "Error no siguió instrucciones" << "\n";

        return 1;
        break;
    }
}