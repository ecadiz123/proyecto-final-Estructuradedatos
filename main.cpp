#include "HashTable/HashEncadenado.hpp"
#include "queue/ListQueue.hpp"
#include <iostream>

void printficha(element_t ficha) // Función para printear ficha
{
    std::cout << "Rut:" << "\n"; // imprime rut

    std::cout << ficha.rut << "-" << char(ficha.digitoverificador);

    std::cout << "Motivo de Consulta:" << "\n"; // imprime motivo de consulta

    std::cout << ficha.motivodeconsulta << "\n";

    std::cout << "Antecedentes Dentales:" << "\n";

    std::cout << ficha.antecedentesdentales << "\n";

    std::cout << "Piezas a tratar:" << "\n";

    std::cout << ficha.piezasatratar << "\n";
}

/*
4 funciones de la app
consultar fila de espera
añadir a fila de espera

consultar ficha
añadir/eliminar/modificar ficha

*/
void consultafilas(ListQueue *urgencia, ListQueue *normal) // imprime al paciente que ahora le toca
{
    if ((*urgencia).empty() == true)
    {
        std::cout << (*normal).front() << "\n";

        (*normal).dequeue();
    }
    else
    {

        std::cout << (*urgencia).front() << "\n";
        (*urgencia).dequeue();
    }
}

void ingresofilaespera(ListQueue *urgencia, ListQueue *normal) // clase que añade a alguien a la fila de espera
{
    std::string nombre;
    int ingresofila, turno;

    std::cout << "Ingrese nombre y apellido junto de paciente" << "\n";

    std::cin >> nombre;
    fflush(stdin); // limpia buffer

    std::cout << "Ingrese a que fila lo desea enviar" << "\n";

    std::cout << "1. Atencion Normal" << "\n";
    std::cout << "2. Atencion de Urgencia" << "\n";

    std::cin >> ingresofila;
    fflush(stdin); // limpia buffer
    if (ingresofila == 1)
    {
        (*normal).enqueue(nombre);
    }
    else
        (*urgencia).enqueue(nombre);
}

int main()
{
    HashEncadenado guardadodeficha; // tabla donde se van a guardar las fichas
    ListQueue normal, urgencia;     // fila de urgencia y la fila normal
    
    int ingreso;

    // variables fila
    std::string nombre;
    int ingresofila, turno;

    // variables fichas
    element_t fichaaux;
    int ingresoficha;
    key_t rut; // llave para buscar ficha
    int modificar;
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
        case 1:

            std::cout << "Ingrese que desea hacer" << "\n";
            std::cout << "1. Ver quien debe pasar" << "\n";
            std::cout << "2. Ingresar pacientes" << "\n";

            std::cin >> turno;
            fflush(stdin); // limpia buffer

            {
                switch (turno)
                {
                case 1: // quien debe pasar siguiente

                    consultafilas(&urgencia, &normal);//pasa por referncia porque es una función
                    break;
                case 2: // Ingreso de pacientes
                    ingresofilaespera(&urgencia, &normal);//pasa por referencia porque es una función

                    break;
                default:
                    std::cout << "Error no siguio instrucciones" << "\n";
                    break;
                }
                break;
            case 2:

                std::cout << "Ingrese que desea hacer" << "\n";

                std::cout << "1. Consultar ficha" << "\n";
                std::cout << "2. Ingresar/modificar/eliminar ficha" << "\n";
                std::cin >> ingresoficha;
                fflush(stdin); // limpia buffer
                {

                    switch (ingresoficha)
                    {
                    case 1: // consulta ficha

                        std::cout << "Ingrese rut sin digito verificador" << "\n";
                        std::cin >> rut;
                        fflush(stdin); // limpia buffer
                        fichaaux = guardadodeficha.find(rut);
                        if (fichaaux.rut != 0) // Si no encuentra la ficha devuelve una ficha sin rellenar de rut 0
                            printficha(fichaaux);
                        else
                            std::cout << "No se encontro ficha" << "\n";

                        break;
                    case 2: // ingreso/modifica/elimina ficha

                        std::cout << "Ingrese que desea hacer" << "\n";

                        std::cout << "1. Ingresar Ficha" << "\n";
                        std::cout << "2. Eliminar Ficha" << "\n";
                        std::cout << "3. Modificar Ficha" << "\n";
                        std::cin >> modificar;
                        fflush(stdin); // limpia buffer
                        switch (modificar)
                        {
                        case 1: // Ingresar ficha

                            // se volvio requerimiento usar fflush para limpiar el buffer de entrada al trabajar con tantas strings
                            std::cout << "Ingrese Rut sin puntos ni digito verificador" << "\n";
                            std::cin >> fichaaux.rut;
                            fflush(stdin);
                            std::cout << "Ingrese digito verificador" << "\n";
                            std::cin >> fichaaux.digitoverificador;
                            fflush(stdin);
                            std::cout << "Ingrese motivo de consulta" << "\n";
                            std::cin >> fichaaux.motivodeconsulta;
                            fflush(stdin);
                            std::cout << "Ingrese antecedentes dentales" << "\n";
                            std::cin >> fichaaux.antecedentesdentales;
                            fflush(stdin);
                            std::cout << "Ingrese piezas a tratar" << "\n";
                            std::cin >> fichaaux.piezasatratar;
                            fflush(stdin);
                            guardadodeficha.insert(fichaaux);

                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        default:
                            break;
                        }
                        break;
                    default:
                        break;
                    }
                }

                break;
            case 3:
                return 0;
            default:

                std::cout << "Error no siguio instrucciones" << "\n";

                break;
            }
        }

    } while (ingreso != 3);
}
