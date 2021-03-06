#include "Vector.h"
#include "List_Doble.h"
#include "Pila.h"
#include "Cola.h"
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"

int main(){
  cout << "             _ _     _____          _   _" << endl <<               
 					" /\\ /\\ _ __ (_) |_  /__   \\___  ___| |_(_)_ __   __ _" << endl <<   
					"/ / \\ \\ '_ \\| | __|   / /\\/ _ \\/ __| __| | '_ \\ / _` | " << endl <<
					"\\ \\_/ / | | | | |_   / / |  __/\\__ \\ |_| | | | | (_| | " << endl <<
 					" \\___/|_| |_|_|\\__|  \\/   \\___||___/\\__|_|_| |_|\\__, | " << endl <<
          "                                                 |___/ " << endl <<
          "-------------------------------------------------------" << endl;
  //Unit testing de Vector----------------------------------------------------------------------------
  cout << "UNIT TESTING CLASE VECTOR:" << endl;
  Vector/*<int>*/ dummy = Vector/*<int>*/(5);
  if(dummy._size() == 5)
    cout << KGRN <<  "_size() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "_size() incorrecto size: " << dummy._size() << endl << RST <<  "-------------------------------------------------------" << endl;
  dummy.resize(10);
  if(dummy._size() == 10)
    cout << KGRN <<  "resize() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "resize() incorrecto _size() " << dummy._size() << endl << RST <<  "-------------------------------------------------------" << endl;
  for(int i = 0; i < dummy._size(); i++){
    dummy.get(i) = i;
  }
  if(dummy.get(3) == 3)
    cout << KGRN <<  "get() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "get() incorrecto dummy.get(3): " << dummy.get(3) << endl << RST << "-------------------------------------------------------" << endl;
  dummy.push(9);
  if(dummy.get(0) == 9 &&  dummy._size() == 11)
    cout << KGRN << "push() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "push() incorrecto dummy.get(0) == 9: " << dummy.get(0) << "  dummy._size() == 11:" << dummy._size() << endl << RST << "-------------------------------------------------------" << endl;
  int temp = dummy.pop();
  if(dummy._size() == 10 && temp == 9)
    cout << KGRN << "pop() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "pop() incorrecto dummy._size() == 10: " << dummy._size() << " temp == 9" << temp<< endl << RST << "-------------------------------------------------------" << endl;
  dummy.push_back(9);
  if(dummy.get(dummy._size() - 1) == 9 &&  dummy._size() == 11)
    cout << KGRN << "push_back() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "push_back() incorrecto dummy.get(dummy._size() - 1) == 9: " << dummy.get(dummy._size() - 1) << " dummy._size() == 6" << dummy._size() << endl << RST << "-------------------------------------------------------" << endl;
  temp = 0;
  temp = dummy.pop_back();
  if(dummy._size() == 10 && temp == 9)
    cout << KGRN << "pop_back() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "pop_back() incorrecto dummy._size() == 5" << dummy._size() << " temp == 9" << temp  << endl << RST << "-------------------------------------------------------" << endl;

  
  //Unit testing de List_Double----------------------------------------------------------------------------
  cout << "UNIT TESTING CLASE LISTA:" << endl;
  dll_t<int> dummylista = dll_t<int>();
  dummylista.insert_head(new dll_node_t<int>(3));
  if(dummylista.get_size() == 1 && dummylista.get_head()->get_data() == 3)
    cout << KGRN <<  "get_size() ,insert_head y get_head() correctos" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "get_size() == 1 incorrecto size: " << dummylista.get_size() << " get_head() == 3 "<< dummylista.get_head()->get_data() << endl << RST <<  "-------------------------------------------------------" << endl;
  dummylista.insert_tail(new dll_node_t<int>(5));
  if(dummylista.get_size() == 2 && dummylista.get_tail()->get_data() == 5)
    cout << KGRN <<  "get_size() ,insert_tail y get_tail() correctos" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "get_size() == 2 incorrecto size: " << dummylista.get_size() << " get_head() == 5 "<< dummylista.get_head()->get_data() << endl << RST <<  "-------------------------------------------------------" << endl;
  if(dummylista.get_size() == 2 && dummylista.get_tail()->get_data() == 5)
    cout << KGRN <<  "get_size() ,insert_tail y get_tail() correctos" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "get_size() == 2 incorrecto size: " << dummylista.get_size() << " get_head() == 5 "<< dummylista.get_head()->get_data() << endl << RST <<  "-------------------------------------------------------" << endl;
  if(dummylista.extract_head()->get_data() == 3 )
    cout << KGRN <<  "extract_head() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "extract_head() == 3 incorrecto : " <<dummylista.extract_head()->get_data() <<  "-------------------------------------------------------" << endl;
  if(dummylista.extract_tail()->get_data() == 5 )
    cout << KGRN <<  "extract_tail() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "extract_tail() == 5 incorrecto : " <<dummylista.extract_head()->get_data() <<  "-------------------------------------------------------" << endl;
    if(dummylista.empty() == true )
    cout << KGRN <<  "empty() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "empty() == true incorrecto : " << dummylista.empty() <<  "-------------------------------------------------------" << endl;


  //Unit testing de Pila----------------------------------------------------------------------------
  cout << "UNIT TESTING CLASE Pila:" << endl;
  Pila dummypila =  Pila();
  if(dummypila.empty() == true )
    cout << KGRN <<  "empty() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "empty() == true incorrecto : " << dummypila.empty() <<  "-------------------------------------------------------" << endl;
  dummypila.push(3);
  dummypila.push(5);
  if(dummypila.top() == 5 )
    cout << KGRN <<  "push() y top() correctos" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "top() == 5 incorrecto : " << dummypila.top() <<  "-------------------------------------------------------" << endl;
  dummypila.pop();
  dummypila.pop();
  dummypila.push(4);
  if(dummypila.pop() == 4 )
    cout << KGRN <<  "pop() correcto." << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "pop() == 4 incorrecto : " << /*dummypila.pop()*/"" <<  "-------------------------------------------------------" << endl;


  //Unit testing de Cola----------------------------------------------------------------------------
  cout << "UNIT TESTING CLASE Cola:" << endl;
  Cola dummycola =  Cola();
  if(dummycola.empty() == true )
    cout << KGRN <<  "empty() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "empty() == true incorrecto : " << dummycola.empty() <<  "-------------------------------------------------------" << endl;
  dummycola.push(3);
  dummycola.push(5);
  if(dummycola.pop() == 3)
    cout << KGRN <<  "push() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "push() incorrecto : " << /*dummycola.pop()*/"" <<  "-------------------------------------------------------" << endl;
  if(dummycola.pop() == 5)
    cout << KGRN <<  "pop() correcto" << endl << RST << "-------------------------------------------------------" << endl;
  else
    cout << KRED << "pop() == 5 incorrecto : " << /*dummycola.pop()*/"" <<  "-------------------------------------------------------" << endl;

//Modificacion
   cout << endl << "-----MODIFICACION-----" << endl;
   Pila pilamod1 =  Pila();
   pilamod1.push(5);
   cout << "Push 5 y 6 en pila 1" << endl;
   pilamod1.push(6);
   cout << "Tamaño pila 1: " << pilamod1._size() << endl;
   cout << "Se crea la pila 2" << endl;
   Pila pilamod2 = Pila(pilamod1);
   cout << "Tamaño pila 2: " << pilamod2._size() << endl;
   int temp2 = pilamod2.pop();
   cout << "Pop del dato en pila 2: " << temp2 << " Tamaño pila 2: " << pilamod2._size() << " Tamaño pila 1: " << pilamod1._size() << endl;
   temp2 = pilamod1.pop();
   cout << "Pop del dato en pila 1: " << temp2 << " Tamaño pila 2: " << pilamod2._size() << " Tamaño pila 1: " << pilamod1._size() << endl;
   temp2 = pilamod2.pop();
   cout << "Pop del dato en pila 2: " << temp2 << " Tamaño pila 2: " << pilamod2._size() << " Tamaño pila 1: " << pilamod1._size() << endl;
   temp2 = pilamod1.pop();
   cout << "Pop del dato en pila 1: " << temp2 << " Tamaño pila 2: " << pilamod2._size() << " Tamaño pila 1: " << pilamod1._size() << endl;
}
