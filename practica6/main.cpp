#include <iostream>
#include <vector>

#include "ABB.h"
#include "DNI.h"

int DNI::comp_ = 0;

void update_data(long int comparaciones, long int& min, long int& max, long int& med);

void result (long int min, long int max, long int med, long int p);
int main (void){
    srand(time(NULL));
    // Menu principal
    long int opcion = 0;
    do{
        //system("clear");
        std::cout << "0 - Salir" << std::endl;
        std::cout << "1 - Modo desmostración" << std::endl;
        std::cout << "2 - Modo estadística" << std::endl;
        std::cout << std::endl << ">> ";
        std::cin  >> opcion;
    }while((opcion != 1) && (opcion != 2) && (opcion != 0));
    switch(opcion){
        // Salir
        case 0:
            break;
        // Modo demostración
        case 1:{
            //system("clear");
            std::cout << "~ Modo demostración ~" << std::endl << std::endl;
            ABB<long int> arbol;
            do{
                //system("clear");
                std::cout << arbol;
                std::cout << "\n\n\n";
                std::cout << "0 - Salir" << std::endl;
                std::cout << "1 - Insertar clave" << std::endl;
                std::cout << "2 - Eliminar clave" << std::endl;
                std::cout << std::endl << ">> ";
                std::cin  >> opcion;
                if (opcion == 1 || opcion == 2){
                    long int dato;
                    std::cout << ">> ";
                    std::cin  >> dato;
                    if (opcion == 1)
                        arbol.insertar(dato);
                    else
                        arbol.eliminar(dato);
                }
            }while((opcion == 1) || (opcion == 2));
            break;
        }
        case 2:{
            //system("clear");
            std::cout << "~ Modo estadística ~" << std::endl << std::endl;
            // Pedir datos
            long n, nPruebas;
            std::cout << "Tamaño del árbol (número de nodos del árbol) >> ";
            std::cin >> n;
            std::cout << "Número de repeticiones de inserción/búsqueda que se realiza en el experimento >> ";
            std::cin >> nPruebas;
            std::cout << std::endl << std::endl;
            // Crear banco e insertar la mitad a un ABB
            std::vector<DNI> banco(2*n);
            ABB<DNI>  arbol;
            for (long int i = 0; i < n; i++)
                arbol.insertar(banco[i]);
            // BUSQUEDA
            DNI::comp_ = 0;
            long int min = 0;
            long int acumulado = 0;
            long int maximo = 0;
            for (long int i = 0; i < nPruebas; i++){
                DNI::comp_ = 0;
                NodoBB<DNI>* tmp = arbol.buscar(banco[i]);
                if (i == 0){
                    min    = DNI::comp_;
                    maximo = DNI::comp_;
                }
                update_data(DNI::comp_, min, maximo, acumulado);
            }
            std::cout << "Búsqueda:     " << std::endl;
            result(min, maximo, acumulado, nPruebas);
            // INSERCIÓN
            DNI::comp_ = 0;
            min = 0;
            acumulado = 0;
            maximo = 0;
            for (long int i = n; i < (n+nPruebas); i++){
                DNI::comp_ = 0;
                arbol.insertar(banco[i]);
                if (i == n){
                    min    = DNI::comp_;
                    maximo = DNI::comp_;
                }
                update_data(DNI::comp_, min, maximo, acumulado);
            }
            std::cout << "Inserción:    " << std::endl;
            result(min, maximo, acumulado, nPruebas);
            break;
        }
    }
}



void update_data(long int comparaciones, long int& min, long int& max, long int& med){
    if (min == -1)
      min = comparaciones;
    else if (comparaciones < min)
      min = comparaciones;
    if (max == -1)
      max = comparaciones;
    else if (comparaciones > max)
      max = comparaciones;
    med += comparaciones;
}


void result (long int min, long int max, long int med, long int p){
    std::cout << "min " << min << ", max " << max << ", media " << (float)med/(float)p << std::endl;
}
