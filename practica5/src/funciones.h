#include <iostream>
#include <cmath>
using namespace std;

void update_data(int comparaciones, int& min, int& max, int& med){
    if (min == -1) min = comparaciones;
    else if (comparaciones < min) min = comparaciones;
    if (max == -1) max = comparaciones;
    else if (comparaciones > max) max = comparaciones;
    med += comparaciones;
}

template<class T>
void print_it (const vector<T>& seq, int a = -1, int b = -1) {
    for (int i=0; i < seq.size(); i++){
        if ((i == a) || (i == b))
            cout << " -" << seq[i] << "- ";
        else
            cout << "  " << seq[i] << "  ";
    }
    cout << endl;
}

template<class T>
void seleccion (vector<T>& seq, int mode){
    for (int i=0; i < seq.size(); i++){
        int minimo = i;
        for (int j=i+1; j<seq.size(); j++){
            if (seq[j] < seq[minimo])
                minimo = j;
        }
        if (mode == 1) print_it(seq, i, minimo);
        T x = seq[minimo];
        seq[minimo] = seq[i];
        seq[i] = x;
        if (mode == 1) print_it(seq);
    }
}

template<class T>
void sacudida (vector<T>& seq, int mode){
    int ini = 1;
    int fin = seq.size()-1;
    int cam = seq.size();
    bool cambio = 1;
    while ((ini <= fin) && cambio){
        cambio = 0;
        for (int j=fin; j>=ini; j--) {
            if (seq[j] < seq[j-1]){
                cambio = 1;
                if (mode == 1) {cout << "< "; print_it(seq,j,j-1);}
                T x = seq[j-1];
                seq[j-1] = seq[j];
                seq[j] = x;
                cam = j;
            }
        }
        ini = cam + 1;
        for (int j=ini; j<=fin; j++){
            if (seq[j] < seq[j-1]){
                cambio = 1;
                if (mode == 1) {cout << "> "; print_it(seq,j,j-1);}
                T x = seq[j-1];
                seq[j-1] = seq[j];
                seq[j] = x;
                cam = j;
            }
        }
        fin = cam-1;
    }
    if (mode == 1) {cout << "> "; print_it(seq);}
}

template<class T>
void mergeSort (vector<T>& seq, int mode){
    if (seq.size() <= 2){
        // Ordenación adhoc
        if ((seq.size() == 2) && (seq[0] > seq[1])){
            T tmp = seq[0];
            seq[0] = seq[1];
            seq[1] = tmp;
        }
    }
    else{
        // 'X' e 'Y' contienen cada una de las mitades de 'A'
        std::vector<T> X(&seq[0], &seq[seq.size()/2]);
        std::vector<T> Y(&seq[(seq.size()/2)], &seq[seq.size()]);
        // Llamo recursivamente la función con cada una de las mitades
        mergeSort(X, mode);
        mergeSort(Y, mode);
        if (mode == 1) {cout << "izq ";print_it(X);}
        if (mode == 1) {cout << "der ";print_it(Y);}
        // Fusiono ambas mitades
        fusionar (X, Y, seq);
        if (mode == 1) {cout << "seq ";print_it(seq);cout<<'\n';}
    }
}

template<class T>
void fusionar (vector<T>& X, vector<T>& Y, vector<T>& seq){
    int k = 0;
    int a = 0;
    int b = 0;
    while ((k < seq.size()) && (a!=X.size()) && (b!=Y.size())){
        if (X[a] < Y[b]){
            seq[k++] = X[a++];
        }
        else
            seq[k++] = Y[b++];
    }
    // Si se acabó X relleno con Y
    if ((a>=X.size()) && (k<seq.size())){
        while(seq.size() != k)
            seq[k++] = Y[b++];
    }
    // Si se acabó Y relleno con X
    if ((b>=Y.size()) && (k<seq.size())){
        while(seq.size() != k)
            seq[k++] = X[a++];
    }
}

template<class T>
void quickSort (vector<T>& seq, int mode, int ini, int fin){
   int i=ini;
   int f=fin;
   T p=seq[(i+f)/2];
   if (mode == 1){
       cout << "-------" << endl;
       cout << "ini #" << i+1 << endl;
       cout << "fin #" << f+1 << endl;
       cout << "Pivote #" << ((i+f)/2)+1 << endl;
   }
   while(i<=f){
       while (seq[i] < p) i++;
       while (p < seq[f]) f--;
       if (mode == 1){cout << '\t'; print_it(seq, i,f);}
       if (i <= f){
           T x = seq[i];
           seq[i] = seq[f];
           seq[f] = x;
           i++; f--;
       }
   }
   if (ini < f) quickSort(seq, mode, ini, f);
   if (i < fin) quickSort(seq, mode, i, fin);
}

template<class T>
void incDec (vector<T>& seq, int mode, double alfa){
    double del = (double)seq.size();
    while (del > 1){
        del = del * alfa;
        deltasort(seq, mode, del);
        if (mode==1) print_it(seq);
    }
}

template<class T>
void deltasort (vector<T>& seq, int mode, double del){
    for (int i = round(del); i < seq.size(); i++){
        T x = seq[i];
        double j = (double)i;
        while((j>=del) && (x < seq[round(j-del)]) ){
            seq[round(j)] = seq[round(j-del)];
            j = j-del;
        }
        seq[round(j)] = x;    
    }
}
