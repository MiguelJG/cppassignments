#include <iostream>
#include <vector>
#include <string>

#include "AVL.h"
#include "DNI.h"

int DNI::comp_ = 0;

void update_data(int comparaciones, int& min, int& max, int& med);

void result (int min, int max, int med, int p);
int main (void){
    srand(time(NULL));
    int opcion = 0;
    do{
        std::cout << "0 - Salir" << std::endl;
        std::cout << "1 - Modo desmostración (DNI)" << std::endl;
        std::cout << "2 - Modo desmostración (int)" << std::endl;
        std::cout << "3 - Modo estadística" << std::endl;
        std::cout << std::endl << ">> ";
        std::cin  >> opcion;
    }while((opcion != 1) && (opcion != 2) && (opcion != 3) &&(opcion != 0));
    switch(opcion){
        // Salir
        case 0:
            break;
        // Modo demostración
        case 1:{
            std::cout << "~ Modo demostración (DNI) ~" << std::endl << std::endl;
            ArbolAVL<DNI> arbol;
            do{
                std::cout << arbol;
                std::cout << "\n\n\n";
                std::cout << "0 - Salir" << std::endl;
                std::cout << "1 - Insertar clave" << std::endl;
                std::cout << "2 - Eliminar clave" << std::endl;
                std::cout << std::endl << ">> ";
                std::cin  >> opcion;
                if (opcion == 1 || opcion == 2){
                    int dato;
                    std::cout << ">> ";
                    std::cin  >> dato;
                        switch(opcion){
                            case 1:
                                arbol.Insertar(dato);
                                break;
                            case 2:
                                arbol.Eliminar(dato);
                                break;
                        }
                }
            }while((opcion == 1) || (opcion == 2));
            break;
        }
        case 2:{
            std::cout << "~ Modo demostración (int) ~" << std::endl << std::endl;
            ArbolAVL<int> arbol;
            do{
                system("clear");
                std::cout << arbol;
                std::cout << "\n\n\n";
                std::cout << "0 - Salir" << std::endl;
                std::cout << "1 - Insertar clave" << std::endl;
                std::cout << "2 - Eliminar clave" << std::endl;
                std::cout << std::endl << ">> ";
                std::cin  >> opcion;
                if (opcion == 1 || opcion == 2){
                    int dato;
                    std::cout << ">> ";
                    std::cin  >> dato;
                    switch(opcion){
                        case 1:
                            arbol.Insertar(dato);
                            break;
                        case 2:
                            arbol.Eliminar(dato);
                            break;
                    }
                }
            }while((opcion == 1) || (opcion == 2));
            break;
        }
        case 3:{        // Modo estadística
            std::cout << "~ Modo estadística ~" << std::endl << std::endl;
            // Pedir datos
            int n, nPruebas;
            std::cout << "Tamaño del árbol (número de nodos del árbol) >> ";
            std::cin >> n;
            std::cout << "Número de repeticiones de inserción/búsqueda que se realiza en el experimento >> ";
            std::cin >> nPruebas;
            std::cout << std::endl << std::endl;
            // Crear banco e insertar la mitad a un Arbol AVL
            std::vector<DNI> banco(2*n);
            ArbolAVL<DNI>  arbol;
            for (int i=0; i<n; i++)
                arbol.Insertar(banco[i]);
            // BUSQUEDA
            DNI::comp_ = 0;
            int min = 999999;
            int acumulado = 0;
            int maximo = 0;
            for (int i = 0; i < nPruebas; i++){
              DNI::comp_ = 0;
                NodoAVL<DNI>* tmp = arbol.buscar(banco[i]);
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
            for (int i = n; i < (n+nPruebas); i++){
                DNI::comp_ = 0;
                NodoAVL<DNI>* tmp = arbol.buscar(banco[i]);
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



void update_data(int comparaciones, int& min, int& max, int& med)
{
    if (min == -1) min = comparaciones;
    else if (comparaciones < min) min = comparaciones;

    if (max == -1) max = comparaciones;
    else if (comparaciones > max) max = comparaciones;

    med += comparaciones;

}


void result (int min, int max, int med, int p)
{
    std::cout << "min " << min << ", max " << max << ", media " << (float)med/(float)p << std::endl;
}
