#include <string>
#include <iostream>
#include <stdlib.h>     /* atof, atoi */
#include <vector>

#include "matricula.h"
#include "celda.h"
#include "fDispersion.1.h"
#include "fExploracion.1.h"
#include "tabla.h"

int     argv_to_int(char* str);
double  pedir_factor (void);
int     pedir_pruebas(int n);

float usage (std::string name){
    system("clear");
    std::cout <<    "P3: Implementación de búsqueda mediante Tabla Hash"                        << '\n' <<
                    name << " <nCeldas> <nBloques> <fDispersión> <fExploración>"                << "\n\n" <<
                    "<nCeldas>          Número de posiciones de la tabla hash"                  << '\n' <<
                    "<nBloques>         Número de claves que se pueden almacenar en cada celda" << '\n' <<
                    "<fDispersión>      Función de dispersión"                                  << '\n' <<
                    "                       1 módulo"                                           << '\n' <<
                    "                       2 suma"                                             << '\n' <<
                    "                       3 pseudo-aleatoria"                                 << '\n' <<
                    "<fExploración>     Función de Exploración"                                 << '\n' <<
                    "                       1 lineal"                                           << '\n' <<
                    "                       2 cuadrática"                                       << '\n' <<
                    "                       3 dispersión doble"                                 << '\n' <<
                    "                       4 re-dispersión"                                    << '\n';

}

int main (int argc, char* argv[]){
    if (argc != 5){
        std::string name = argv[0];
        usage(name);
        return 0;
    } else {
        int     nCeldas  =  argv_to_int   (argv[1]);
        int     nBloques =  argv_to_int   (argv[2]);
        int     fDisper  =  argv_to_int   (argv[3]);
        int     fExplor  =  argv_to_int   (argv[4]);
        Tabla<Matricula> T(nCeldas, nBloques, fDisper, fExplor);
        double  factor   =  pedir_factor  ();
        int n = round(2 * factor * nCeldas * nBloques);
        srand(time(NULL));
        std::vector<Matricula> banco;
        banco.resize(n);
        for(int i = 0; i < (n / 2); i++){
            bool insertado = T.insertar(banco[i]);
        }
        int nPruebas = pedir_pruebas(n);
        int in_min = 1;
        int in_max = 1;
        int in_total = 0;
        srand(time(NULL));
        for (int i = 0; i < nPruebas; i++) {
            int indice = rand() % (n / 2);
            T.buscar(banco[indice], in_min ,in_max, in_total);
        }
        int bu_min = -1;
        int bu_max = 1;
        int bu_total = 0;
        for (int i = 0; i < nPruebas; i++) {
            int indice = (n/2)-1 + rand()%(n/2);
            T.buscar(banco[indice], bu_min, bu_max, bu_total);
        }
        std::cout << std::endl;
        std::cout   <<  "Celdas:         " << nCeldas << '\n' <<
                        "Bloques:        " << nBloques<< '\n' <<
                        "Carga:          " << factor*100 << "%\n" <<
                        "Pruebas:        " << nPruebas << '\n' << std::endl;
        std::cout   <<  "Inserción:\n"     <<
                        "min:             " << 1 << '\n' <<
                        "medio:           " << in_total/nPruebas << '\n' <<
                        "max:             " << in_max << '\n'<< std::endl;
        std::cout   <<  "Busquedas:\n"     <<
                        "min:             " << bu_min << '\n' <<
                        "medio:           " << bu_total/nPruebas << '\n' <<
                        "max:             " << bu_max << '\n'<< std::endl;
    }
}

double pedir_factor (void){
    double factor;
    std::cout << std::endl << "Factor: ";
    std::cin  >> factor;
    return factor;
}

int pedir_pruebas(int n){
    std::cout << "Numero de pruebas (0 - "<< (n/2) << "): ";
    int pruebas;
    std::cin >> pruebas;
    return pruebas;
}


int argv_to_int(char* str){
    int val = atoi(str);
    return val;
}
