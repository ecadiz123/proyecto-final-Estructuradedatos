#include "HashTable/HashEncadenado.hpp"
#include "queue/ListQueue.hpp"
#include <iostream>

int main()
{

    HashEncadenado fichas;      // tabla donde se van a guardar las fichas
    ListQueue normal, urgencia; // fila de urgencia y la fila normal
    int ingreso;

    // variables fila
    std::string nombre;
    int ingresofila, turno;

    // variables fichas

    std::cout << "Bienvenido" << "\n";
do
{
    /* code */


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

            break;
        case 3:
            return 0;
        default:

            std::cout << "Error no siguio instrucciones" << "\n";

            return 1;
            break;
        }
    }

} while (ingreso!=3);}