# Proyecto final Asignatura Estructura de Datos
## Autores
Esteban Cadiz

Daniel Aravena 

Cristian Vasquez
## Resumen del programa
 Este proyecto consiste principalmente en una aplicion basada en C++ que es capaz de organizar ciertas funcionalidades de una clinica oodontologica. El fin de esta aplicación era poder tener un programa donde se utilizaran estructuras de datos, en este caso fila y tabla hash, hechas por alumnos de la clase de Estructura de Datos de la UCSC.
## Instrucciones de compilación
### Pre requisitos
Es necesario tener algún compilador de C++, el que se recomienda es GCC del pproyecto GNU
### Instrucciones
Primero descargue mediante ZIP o si tiene **git** instalado acceda a la carpeta donde desea tener el programa e ingrese en la terminal: 

``` 
git clone https://github.com/ecadiz123/proyecto-final-Estructuradedatos
```


Luego en su terminal de preferencia, acceda a la carpeta donde se encuentra el proyecto y corra el siguiente comando en la terminal (Este es el caso de GCC, puede variar dependiendo de su compilador)

Windows:
```
g++ .\main.cpp .\queue\ListQueue.cpp .\HashTable\HashEncadenado.cpp -o programadental.exe
```
Sistemas basados en UNIX (MacOS o Linux):

```
g++ main.cpp queue/ListQueue.cpp HashTable/HashEncadenado.cpp -o programadental
```
Finalmente ejecute el output de su programa mediante la terminal y siga instrucciones en pantalla


