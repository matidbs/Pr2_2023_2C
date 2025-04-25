#include <iostream>
using namespace std;
///Hacer ejercicio 2 de ejercicios combinados, TP de matrices, funciones, etc (COMBINADOS).
#include "funciones.h"

int main(){

while (true){
int opc,opcJug,num;
bool win=false;
int mTateti[3][3]={0};

    cout<<"1- Jugar DOS jugadores"<<endl;
    cout<<"2- Jugar UN jugador"<<endl;
    cout<<"3- Salir"<<endl;
    cin>>opc;
    system("cls");

switch(opc){
case 1:
    //Pasar esto a una sola funcion
    dosJugadores(opcJug,mTateti);
    system("cls");
    break;
case 2:
    unJugador(opcJug,mTateti);
    system("cls");
    break;
case 3:
    return 0;
    break;
default:
    break;
}
}

return 0;}
