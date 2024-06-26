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
    
    std::cout << ficha.piezasatratar<< "\n";
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
    int rut;
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
        switch (ingreso)
        {
        case 1:

            std::cout << "Ingrese que desea hacer" << "\n";
            std::cout << "1. Ver quien debe pasar" << "\n";
            std::cout << "2. Ingresar pacientes" << "\n";

            std::cin >> turno;

            {
                switch (turno)
                {
                case 2: // Ingreso de pacientes

                    std::cout << "Ingrese nombre y apellido junto de paciente" << "\n";

                    std::cin >> nombre;

                    std::cout << "Ingrese a que fila lo desea enviar" << "\n";

                    std::cout << "1. Atencion Normal" << "\n";
                    std::cout << "2. Atencion de Urgencia" << "\n";

                    std::cin >> ingresofila;
                    if (ingresofila == 1)
                    {
                        normal.enqueue(nombre);
                    }
                    else
                        urgencia.enqueue(nombre);

                    break;
                case 1: // quien debe pasar

                    if (urgencia.empty() == true)
                    {
                        std::cout << normal.front() << "\n";

                        std::cout << "1" << "\n";
                        normal.dequeue();

                        std::cout << "2" << "\n";
                    }
                    else
                    {

                        std::cout << urgencia.front() << "\n";
                        urgencia.dequeue();
                    }

                    break;
                default:
                    std::cout << "Error no siguio instrucciones" << "\n";
                    break;
                }
                break;
            case 2:

                std::cout << "Ingrese que desea hacer" << "\n";

                std::cout << "1. Consultar ficha" << "\n";
                std::cout << "2. Añadir/modificar/eliminar ficha" << "\n";
                std::cin >> ingresoficha;
                {

                    switch (ingresoficha)
                    {
                    case 1: // consulta ficha

                        std::cout << "Ingrese rut sin digito " << "\n";
                        std::cin >> rut;
                        fflush(stdin);//limpia buffer
                        fichaaux = guardadodeficha.find(rut);
                        if (fichaaux.rut!=0)//Si no encuentra la ficha devuelve una ficha sin rellenar de rut 0
                        
                        printficha(fichaaux);
                        break;
                    case 2: // ingreso/modifica/elimina ficha

                        std::cout << "Ingrese que desea hacer" << "\n";

                        std::cout << "1. Ingresar Ficha" << "\n";
                        std::cout << "2. Eliminar Ficha" << "\n";
                        std::cout << "3. Modificar Ficha" << "\n";
                        std::cin >> modificar;
                        switch (modificar)
                        {
                        case 1: // Ingresar ficha

                        //se volvio requerimiento usar fflush para limpiar el buffer de entrada al trabajar con strings
                        std::cout << "Ingrese Rut sin digito verificador" << "\n";
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
