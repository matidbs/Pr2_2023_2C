#pragma once

///Solo va la declaracion de la clase

class Contador{
    private:
        int _valor;
        int _conteo;
    public:
        Contador(int cant,int valorConteo);
        void incrementar();
        void decrementar();
        void setValor(int cant);
        int getValor();
        int pedirValorInicio();
        int pedirValorConteo();
        void operator ++ (int){
           _valor++;
        }
        void operator -- (int){
            _valor--;
        }
        void operator += (int a){
            _valor+=a;
        }
        void operator -= (int a){
            _valor-=a;
        }
        bool operator < (int a){
            return _valor<a;
        }
        bool operator > (int a){
            return _valor>a;
        }
        bool operator > (Contador &obj){
            return _valor>obj.getValor();
        }
};


