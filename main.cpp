#include "HashTable/HashEncadenado.hpp"
#include "queue/ListQueue.hpp"
#include <iostream>

/*
4 funciones de la app
consultar fila de espera
añadir a fila de espera

consultar ficha
añadir/eliminar/modificar ficha

*/
void consultafilas(ListQueue *urgencia, ListQueue *normal) // imprime al paciente que ahora le toca
{
    if ((*urgencia).empty() == true) // Caso donde no hay urgencia
    {
        std::cout << "\n"
                  << "Ahora es el turno de:\n"
                  << (*normal).front() << "\n\n";

        (*normal).dequeue();
    }
    else if ((*urgencia).empty() != false) // Caso donde hay urgencia

    {

        std::cout << "\n"
                  << "Ahora es el turno de:\n"
                  << (*urgencia).front() << "\n\n";
        (*urgencia).dequeue();
    }
    else // caso fila vacia
    {
        std::cout << "\n"
                  << "No hay personas en espera" << "\n\n";
    }
}

void ingresofilaespera(ListQueue *urgencia, ListQueue *normal) // funcion que añade a alguien a la fila de espera
{
    elemento_fila rut;
    int ingresofila, turno;

    std::cout << "Ingrese rut paciente" << "\n";

    std::cin >> rut;
    fflush(stdin); // limpia buffer

    std::cout << "Ingrese a que fila lo desea enviar" << "\n";

    std::cout << "1. Atencion Normal" << "\n";
    std::cout << "2. Atencion de Urgencia" << "\n";

    std::cin >> ingresofila;
    fflush(stdin); // limpia buffer
    if (ingresofila == 1)
    {
        (*normal).enqueue(rut);
    }
    else
        (*urgencia).enqueue(rut);
}

void printficha(element_tablahash ficha) // Función para printear ficha
{
    std::cout << "Rut:" << "\n"; // imprime rut

    std::cout << ficha.key << "-" << ficha.digitoverificador << "\n";

    std::cout << "Motivo de consulta" << "\n";

    std::cout << ficha.motivoconsulta << "\n";
    std::cout << "Antecedentes dentales" << "\n";

    std::cout << ficha.antecedentesdentales << "\n";
    std::cout << "Pieza a tratar:" << "\n";

    std::cout << ficha.piezaatratar << "\n";
}
void consultaficha(HashEncadenado *fichasguardadas) // funcion para consultar fichas
{

    element_tablahash fichaaux; // ficha auxiliar
    key_tablahash rutk;
    std::cout << "Ingrese rut sin digito verificador ni puntos " << "\n";
    std::cin >> rutk;
    fflush(stdin); // limpia buffer
    fichaaux = (*fichasguardadas).find(rutk);
    if (fichaaux.key != 0)
    { // caso donde hay ficha
        printficha(fichaaux);
    }
    else
    { // Caso donde no encuentra ficha es decir find devuelve key=0
        std::cout << "No se encontro ficha" << "\n";
    }
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
    std::cout << "Ingrese motivo de consulta:" << "\n";
    getline(std::cin,fichaaux.motivoconsulta);//get line es una funcion de libreria <string>, obtiene toda la linea en vez de una palabra
    fflush(stdin);
    std::cout << "Ingrese antecedentes dentales" << "\n";
    getline(std::cin,fichaaux.antecedentesdentales);
    fflush(stdin);
    std::cout << "Ingrese piezas a tratar" << "\n";
    std::cin >> fichaaux.piezaatratar;
    fflush(stdin);
    (*fichasguardadas).insert(fichaaux);
}
void eliminaficha(HashEncadenado *fichas) // funcion para eliminar fichas
{

    key_tablahash rut;
    std::cout << "Ingrese Rut sin digito verificador" << "\n";
    std::cin >> rut;
    fflush(stdin);
    (*fichas).remove(rut);

    std::cout << "Se ha eliminado ficha de rut: " << rut << "\n";
}

void modificarficha(HashEncadenado *fichas)
{

    // primero preguntar que ficha desea cambiar
    key_tablahash rut;

    std::cout << "Ingrese Rut sin digito verificador de ficha a modificar" << "\n";
    std::cin >> rut;
    element_tablahash fichaaux;

    fichaaux = (*fichas).find(rut); // se copian elementos a ficha aux
    (*fichas).remove(rut);          // ahora se elimina ficha vieja de tabla
    std::cout << "Ingrese numero de elemento a modificar" << "\n";
    std::cout << "1. Pieza a tratar" << "\n";

    std::cout << "Ingrese numero de elemento a modificar" << "\n";

    int modificar;
    std::cin >> modificar;
    fflush(stdin);
    switch (modificar)
    {
    case 1:

        std::cout << "Pieza a tratar de ficha:" << fichaaux.piezaatratar << "\n";

        std::cout << "Ingrese nueva pieza" << "\n";

        std::cin >> fichaaux.piezaatratar;
        fflush(stdin);
        break;

    default:
        break;
    }
    // ingresar nueva ficha modificada
    (*fichas).insert(fichaaux);
}
int main()
{
    HashEncadenado fichas;      // tabla donde se van a guardar las fichas
    ListQueue normal, urgencia; // fila de urgencia y la fila normal

    int ingreso;

    // variables fila
    elemento_fila rut;
    int ingresofila, turno;

    // variables fichas
    int inputficha;     // input switch al trabajar con ficha
    key_tablahash rutk; // llave a ingresar para posicion
    int modificar;      // input switch al querer modificar fichas
    std::cout << "Bienvenido" << "\n";
    do // se repite hasta que salga
    {
        std::cout << "Ingrese que desea hacer" << "\n";
        std::cout << "1.Organizar clientes en espera" << "\n";
        std::cout << "2.Trabajar con fichas" << "\n";
        std::cout << "3. Salir" << "\n";
        std::cout << "(Ingrese solo numeros)" << "\n";

        std::cin >> ingreso;
        fflush(stdin); // limpia buffer
        switch (ingreso)
        {
        case 1: // FILA

            std::cout << "Ingrese que desea hacer" << "\n";
            std::cout << "1. Ver quien debe pasar" << "\n";
            std::cout << "2. Ingresar pacientes" << "\n";

            std::cin >> turno;
            fflush(stdin); // limpia buffer

            {
                switch (turno)
                {
                case 1: // quien debe pasar siguiente

                    consultafilas(&urgencia, &normal); // pasa por referncia porque es una función
                    break;
                case 2:                                    // Ingreso de pacientes
                    ingresofilaespera(&urgencia, &normal); // pasa por referencia porque es una función

                    break;
                default:
                    std::cout << "Error no siguio instrucciones" << "\n";
                    break;
                }
                break;
            case 2: // FICHAS (HASH)

                std::cout << "Ingrese que desea hacer" << "\n";

                std::cout << "1. Consultar ficha" << "\n";
                std::cout << "2. Ingresar/modificar/eliminar ficha" << "\n";
                std::cin >> inputficha;
                fflush(stdin); // limpia buffer
                {
                    if (inputficha == 1)
                    { // consulta ficha

                        consultaficha(&fichas);
                    }
                    else if (inputficha == 2)
                    { // ingreso/modifica/elimina ficha

                        std::cout << "Ingrese que desea hacer" << "\n";

                        std::cout << "1. Ingresar Ficha" << "\n";
                        std::cout << "2. Eliminar Ficha" << "\n";
                        std::cout << "3. Modificar Ficha" << "\n";
                        std::cin >> modificar;
                        fflush(stdin); // limpia buffer

                        switch (modificar)
                        {
                        case 1: // Ingresar ficha
                            nuevaficha(&fichas);
                            break;
                        case 2: // Eliminar ficha

                            eliminaficha(&fichas);
                            break;
                        case 3: // Modificar ficha
                            // para modificar
                            modificarficha(&fichas);
                            break;
                        default:
                            std::cout << "Error no siguio instrucciones" << "\n";
                            break;
                        }
                    }
                }

                break;
            case 3:
                // no pasa nada solo termina ejecucion
                return 0;
                ;
            default:

                std::cout << "Error no siguio instrucciones" << "\n";

                break;
            }
        }

    } while (ingreso != 3);
}
