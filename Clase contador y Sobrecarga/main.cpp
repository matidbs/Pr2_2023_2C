#include <iostream>
#include "Contador.h"

///OPERADOR DE AMBITO (::)
///Para miembros PRIVADOS, usamos "_nombre"

/*const int TAMANIOX=800;
const int TAMANIOY=600;
*/

using namespace std;

int pedirValorInicio (){
int inicio;
    cout<<"Ingrese valor INICIO de CONTADOR: ";
    cin>>inicio;
    return inicio;
}

int pedirValorConteo (){
int conteo;
    cout<<"Ingrese valor CONTEO de CONTADOR: ";
    cin>>conteo;
    return conteo;
}

int main(){
    Contador obj(1,2);
    bool a = obj>2;
    cout<<a;
//    cout<<obj.getValor();
//int opc,inicio,conteo;
//        cout<<"Establecer VALORES CONTADOR 1: "<<endl;
//        inicio = pedirValorInicio();
//        conteo = pedirValorConteo();
//        Contador cont1 (inicio,conteo);
//        system ("cls");
//        cout<<"Establecer VALORES CONTADOR 2: "<<endl;
//        inicio = pedirValorInicio();
//        conteo = pedirValorConteo();
//        Contador cont2 (inicio,conteo);
//        system ("cls");
//    while (true){
//    cout<<"................................................"<<endl;
//    cout<<"1 - INCREMENTAR CONTADOR 1"<<endl;
//    cout<<"2 - DECREMENTAR CONTADOR 1"<<endl;
//    cout<<"3 - INCREMENTAR CONTADOR 2"<<endl;
//    cout<<"4 - DERCREMENTAR CONTADOR 2"<<endl;
//    cout<<"5 - SALIR"<<endl;
//    cout<<"................................................"<<endl;
//    cout<<"VALOR DEL CONTADOR 1: "<<cont1.getValor()<<endl;
//    cout<<"VALOR DEL CONTADOR 2: "<<cont2.getValor()<<endl;
//    cout<<"................................................"<<endl;
//    cout<<"OPC: ";
//    cin>>opc;
//    switch (opc){
//    case 1:
//        cont1++;
//        break;
//    case 2:
//        cont1--;
//        break;
//    case 3:
//        cont2.incrementar();
//        break;
//    case 4:
//        cont2.decrementar();
//        break;
//    case 5:
//        return 0;
//        break;
//    }
//    system("cls");
//    }
}
