#include "Contador.h"

///Solo van las definiciones de los metodos

Contador::Contador(int cant=0,int valorConteo=1){
    _valor=cant;
    _conteo=valorConteo;
}

void Contador::incrementar(){
    _valor+=_conteo;
}

void Contador::decrementar(){
//    if(valor>0){
//        valor--;
//    }
    setValor(_valor-=_conteo);
}

void Contador::setValor(int cant){
    if(cant>=0){
        _valor=cant;
    }
}

int Contador::getValor(){
    return _valor;
}

//void Contador::operator ++ (){
//    _valor++;
//}
//
//void Contador::operator -- (){
//    _valor--;
//}
//
//void Contador::operator += (){
//    _valor+=_conteo;
//}
//
//void Contador::operator -= (){
//    _valor-=_conteo;
//}
//
//bool Contador::operator > (int a){
//    if (_valor>a){
//        return true;
//    }else {
//        return false;
//    }
//}
//
//bool Contador::operator <(int a){
//    if (_valor<a){
//        return true;
//    } else {
//        return false;
//    }
//}
