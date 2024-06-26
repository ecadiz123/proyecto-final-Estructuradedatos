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
    if (urgencia->empty() == true)
    { // si no hay urgencia
        if (normal->empty() == true)
        { // si no hay nadie en ambas, es decir vacio
            std::cout << "\n"
                      << "No hay personas en espera" << "\n";
        }
        else
        { // Caso donde no hay urgencia
            std::cout << "\n"
                      << "Ahora es el turno de:\n"
                      << (*normal).front() << "\n";
            (*normal).dequeue();
        }
    }
    else
    { // Caso donde hay urgencia
        std::cout << "\n"
                  << "Ahora es el turno de urgencia:\n"
                  << (*urgencia).front() << "\n";
        (*urgencia).dequeue();
    }
}

void ingresofilaespera(ListQueue *urgencia, ListQueue *normal) // funcion que añade a alguien a la fila de espera
{
    elemento_fila rut;
    int ingresofila;

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
    std::cout << "Rut:" << "\n";

    std::cout << ficha.key << "-" << ficha.digitoverificador << "\n";

    std::cout << "\n"
              << "Motivo de consulta:" << "\n";
    for (int i = 0; i <= ficha.sizemotivo; i++)
    {
        std::cout << ficha.motivoconsulta[i];
    }
    // for permiten imprimir especificamente la cantidad de caracteres usados y no de mas

    std::cout << "\n"
              << "Antecedentes dentales" << "\n";

    for (int i = 0; i <= ficha.sizeantecedentes; i++)
    {
        std::cout << ficha.antecedentesdentales[i];
    }
    // for permiten imprimir especificamente la cantidad de caracteres usados y no mas
    std::cout << "\n"
              << "Pieza a tratar:" << "\n";

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
    for (int i = 0; i <= _charsize; i++)
    {
        fichaaux.antecedentesdentales[i] = ' ';
        fichaaux.motivoconsulta[i] = ' ';
    } // for para inicializar arreglos de caracteres a utilizar

    std::string stringaux, stringaux2; // se va a usar dos string aux para usar el getline
    // se volvio requerimiento usar fflush para limpiar el buffer de entrada al trabajar con strings
    std::cout << "Ingrese Rut sin digito verificador" << "\n";
    std::cin >> fichaaux.key;
    fflush(stdin);

    std::cout << "Ingrese digito verificador" << "\n";
    std::cin >> fichaaux.digitoverificador;
    fflush(stdin);

    std::cout << "Ingrese motivo de consulta:" << "\n";
    getline(std::cin, stringaux); // get line es una funcion de libreria <string>, obtiene toda la linea en vez de una palabra
    fflush(stdin);
    fichaaux.sizemotivo = stringaux.length();
    stringaux.copy(fichaaux.motivoconsulta, fichaaux.sizemotivo, 0); // metodo copy de string transfiere toda la string a un arreglo char

    std::cout << "Ingrese antecedentes dentales" << "\n";
    getline(std::cin, stringaux2);
    fflush(stdin);
    fichaaux.sizeantecedentes = stringaux2.length();
    stringaux2.copy(fichaaux.antecedentesdentales, fichaaux.sizeantecedentes, 0); // metodo copy de string transfiere toda la string a un arreglo char

    std::cout << "Ingrese pieza a tratar" << "\n";
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

    std::cout << "Se ha eliminado ficha de rut: " << rut << "\n\n";
}

void modificarficha(HashEncadenado *fichas)
{

    std::string stringaux; // string auxiliar para los getline
    // primero preguntar que ficha desea cambiar
    key_tablahash rut;

    std::cout << "Ingrese Rut sin digito verificador de ficha a modificar" << "\n";
    std::cin >> rut;
    fflush(stdin);
    element_tablahash fichaaux;

    fichaaux = (*fichas).find(rut); // se copian elementos a ficha aux
    if (fichaaux.key == 0)
    {
        //Caso donde no existe ficha indicada

        std::cout << "Error no hay ficha con ese rut en el sistema." << "\n";
    }
    else
    {
        //caso donde si existe ficha indicada
        (*fichas).remove(rut); // ahora se elimina ficha vieja de tabla
        std::cout << "Ingrese numero de elemento a modificar" << "\n";
        std::cout << "1. Pieza a tratar" << "\n";
        std::cout << "2. Motivo de consulta" << "\n";
        std::cout << "3. Antecedentes dentales" << "\n";

        std::cout << "Ingrese numero de elemento a modificar" << "\n";

        int modificar;
        std::cin >> modificar;
        fflush(stdin);
        if (modificar == 1)
        {
            std::cout << "Pieza a tratar de ficha:" << fichaaux.piezaatratar << "\n";
            std::cout << "Ingrese nueva pieza" << "\n";
            std::cin >> fichaaux.piezaatratar;
            fflush(stdin);
        }
        else if (modificar == 2)
        {
            std::cout << "Motivo de consulta en ficha:" << fichaaux.motivoconsulta << "\n";
            std::cout << "Ingrese nuevo motivo" << "\n";
            getline(std::cin, stringaux);
            fflush(stdin);
            fichaaux.sizemotivo = stringaux.length();
            stringaux.copy(fichaaux.motivoconsulta, fichaaux.sizemotivo, 0); // metodo copy de string transfiere toda la string a un arreglo char
        }
        else if (modificar == 3)
        {
            std::cout << "Antecedentes ingresados: " << fichaaux.antecedentesdentales << "\n";
            std::cout << "Ingrese antecedente anterior junto con nuevo(Max 200 caracteres): " << "\n";
            getline(std::cin, stringaux);
            fflush(stdin);
            fichaaux.sizeantecedentes = stringaux.length();
            stringaux.copy(fichaaux.antecedentesdentales, fichaaux.sizeantecedentes, 0); // metodo copy de string transfiere toda la string a un arreglo char
        }

        // ingresar nueva ficha modificada
        (*fichas).insert(fichaaux);
    }
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
        std::cout << "\n\n\n"
                  << "Ingrese que desea hacer" << "\n";
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

            switch (turno)
            {
            case 1: // quien debe pasar siguiente

                consultafilas(&urgencia, &normal); // pasa por referncia porque asi funciona mejor
                break;
            case 2:                                    // Ingreso de pacientes
                ingresofilaespera(&urgencia, &normal); // pasa por referencia porque edita algo

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
                switch (inputficha)
                {

                case 1:
                { // consulta ficha

                    consultaficha(&fichas);
                }
                break;
                case 2:
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
                        std::cout << "Error no siguio instrucciones " << "\n";
                        break;
                    }
                }
                break;
                default:
                    std::cout << "Error no siguio instrucciones" << "\n";
                    break;
                }
            }

            break;
        case 3:
            // no pasa nada solo termina ejecucion
            return 0;
            break;

        default:

            std::cout << "Error no siguio instrucciones" << "\n";

            break;
        }

    } while (ingreso != 3);
}
