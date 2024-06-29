#include "HashEncadenado.hpp"
#include <iostream>
void printficha(element_tablahash ficha) // Función para printear ficha
{
    std::cout << "Rut:" << "\n"; // imprime rut

    std::cout << ficha.key << "-" << char(ficha.digitoverificador) << "\n";

   
    std::cout << "Piezas a tratar:" << "\n";

    std::cout << ficha.piezaatratar << "\n";
}
void nuevaficha(HashEncadenado *fichasguardadas) // funcion para ingresar nueva ficha a guardar
{
    element_tablahash fichaaux;
    // se volvio requerimiento usar fflush para limpiar el buffer de entrada al trabajar con strings
    std::cout << "Ingrese Rut sin digito verificador" << "\n";
    std::cin >> fichaaux.key;
    fflush(stdin);
    std::cout << "Ingrese digito verificador" << "\n";
    std::cin >> fichaaux.digitoverificador;
    fflush(stdin);

    std::cout << "Ingrese piezas a tratar" << "\n";
    std::cin >> fichaaux.piezaatratar;
    fflush(stdin);
    (*fichasguardadas).insert(fichaaux);
}
int main()
{
    HashEncadenado fichas;
    key_tablahash k;
    nuevaficha(&fichas);

    std::cout << "Rut:" << "\n";
    std::cin >> k;
    fflush(stdin);
    printficha((fichas).find(k));

    std::cout << "Anda bien" << "\n";
}