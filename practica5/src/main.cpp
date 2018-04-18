#include <iostream>
#include <vector>

#include "funciones.h"
#include "DNI.h"

int DNI::comp_ = 0;


void result (int min, int max, int med, int p);
int main (void){
    srand(time(NULL));
    int opcion = 0;
    do{
        system("clear");
        std::cout << "1 - Modo desmostración" << std::endl;
        std::cout << "2 - Modo estadística" << std::endl;
        std::cout << std::endl << ">> ";
        std::cin  >> opcion;
    }while((opcion != 1) && (opcion != 2));
    // Modo demostración
    if (opcion == 1) {
        system("clear");
        std::cout << "~ Modo demostración ~" << std::endl << std::endl;
        int n, a;
        // Solicita parámetros ~~~~~~~~~~~~~~~~~~~~~~
        do{
            std::cout << "Tamaño de la secuencia a ordenar (max 25) >> ";
            std::cin  >> n;
            std::cout << std::endl;
        }while ((n<1) || (n>25));
        do{
            std::cout << "Algoritmo a ejecutar: " << std::endl;
            std::cout << " 1 - Selección" << std::endl;
            std::cout << " 2 - Por intercambio: Método de la sacudida" << std::endl;
            std::cout << " 3 - MergeSort" << std::endl;
            std::cout << " 4 - QuickSort" << std::endl;
            std::cout << " 5 - Por incrementos decrecientes" << std::endl << std::endl;
            std::cout << ">> ";
            std::cin  >> a;
        }while ((a<1) || (a>5));
        vector<DNI> seq(n);
        std::cout << "Secuencia original: " << std::endl;
        print_it(seq);
        std::cout << std::endl;
        // Ordenar mediante el método seleccionado ~~~~~~~~~~~~~~~~~~~~~~~
        switch(a){
            case 1:
                seleccion (seq, 1);
                break;
            case 2:
                sacudida (seq, 1);
                break;
            case 3:
                mergeSort (seq, 1);
                break;
            case 4:
                quickSort (seq, 1, 0, seq.size()-1);
                std::cout << '\t'; print_it(seq);
                break;
            case 5:
                double alfa;
                cout << "Constante de reduccion alfa (0-1) >> ";
                cin >> alfa;
                incDec(seq, 1, alfa);
                break;
        }
    }
    // Modo estadística
    else{
        system("clear");
        std::cout << "~ Modo estadística ~" << std::endl << std::endl;
        int n, p;
        // Solicitar parametros ~~~~~~~~~~~~~~~~~~~~~~
        do{
            std::cout << "Tamaño de la secuencia a ordenar >> ";
            std::cin  >> n;
        }while (n<1);
        do{
            std::cout << "Número de pruebas a realizar >> ";
            std::cin  >> p;
            std::cout << std::endl;
        }while (p<1);
        // Calcular estadísticas ~~~~~~~~~~~~~~~~~~~~~~
        // 1 Selección
        int min = -1, max = -1, med = 0;
        int counter = 0;
        while (counter < p){
            DNI::comp_ = 0;
            vector<DNI> seq(n);
            seleccion (seq, 2);
            update_data(DNI::comp_, min, max, med);
            counter++;
        }
        std::cout << "Selección:" << std::endl;
        result(min,max,med,p);
                // 2 Sacudida
        min = -1; max = -1; med = 0;
        counter = 0;
        while (counter < p){
            DNI::comp_ = 0;
            vector<DNI> seq(n);
            sacudida (seq, 2);
            update_data(DNI::comp_, min, max, med);
            counter++;
        }
        std::cout << "Sacudida:" << std::endl;
        result(min,max,med,p);
        // 3 MergeSort
        min = -1; max = -1; med = 0;
        counter = 0;
        while (counter < p){
            DNI::comp_ = 0;
            vector<DNI> seq(n);
            mergeSort (seq, 2);
            update_data(DNI::comp_, min, max, med);
            counter++;
        }
        std::cout << "MergeSort:" << std::endl;
        result(min,max,med,p);
        // 4 QuickSort
        min = -1, max = -1, med = 0;
        counter = 0;
        while (counter < p){
            DNI::comp_ = 0;
            vector<DNI> seq(n);
            quickSort(seq, 2, 0, seq.size()-1);
            update_data(DNI::comp_, min, max, med);
            counter++;
        }
        std::cout << "QuickSort" << std::endl;
        result(min,max,med,p);
        // 5 Incrementos decrecientes
        min = -1, max = -1, med = 0;
        counter = 0;
        double alfa;
        cout << "Constante de reduccion alfa (0-1) >> ";
        cin >> alfa;
        while (counter < p) {
            DNI::comp_ = 0;
            vector<DNI> seq(n);
            incDec(seq, 2, alfa);
            update_data(DNI::comp_, min, max, med);
            counter++;
        }
        std::cout << "Incrementos Decrecientes: " << std::endl;
        result(min,max,med,p);
    }
}

void result (int min, int max, int med, int p){
    std::cout << "min " << min << ", max " << max << ", media " << (float)med/(float)p << std::endl;
}
