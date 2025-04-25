#include <iostream>

using namespace std;

class Cola{
    private:
        int *v;
        int tam;
        int ppio;
        int fin;
    public:
        Cola(int t=1){
            if(t<=0)exit(-3);
            tam=t;
            v=new int [tam];
            if(v==nullptr)exit(-2);
            ppio=0;
            fin=0;
        }
        bool agregarElemento(int valor){
            if(fin==tam) return false;
            v[fin]=valor;
            fin++;
            return true;
        }
        bool sacarElemento(int &aux){
            if(ppio==fin) return false;
            aux=v[ppio];
            ppio++;
            return true;
        }
        ~Cola(){
            delete[]v; //El delete [] borra todos los elementos del vector
        }
};

class Pila{
    private:
        int *v;
        int tam;
        int fin;
    public:
        Pila(int t=1){
            if(t<=0)exit(-3);
            tam=t;
            v=new int [tam];
            if(v==nullptr)exit(-2);
            fin=0;
        }
        bool Agregar(int valor){
            if(fin==tam) return false;
            v[fin]=valor;
            fin++;
            return true;
        }
        bool Sacar(int &valor){
            if(fin==0) return false;
            fin--;
            valor=v[fin];
            return true;
        }
        ~Pila(){
            delete[]v;
        }
};

void cargar(Cola &obj){
    int valor;
    cout<<"INGRESE VALOR: ";cin>>valor;
    while(obj.agregarElemento(valor)){
        cout<<"INGRESE VALOR: ";cin>>valor;
    }
    cout<<"NO HAY MAS LUGAR"<<endl;
}

//void cargar(Pila &obj){
//    int valor;
//    cout<<"INGRESE VALOR: ";cin>>valor;
//    while(obj.agregarElemento(valor)){
//        cout<<"INGRESE VALOR: ";cin>>valor;
//    }
//    cout<<"NO HAY MAS LUGAR"<<endl;
//}
//
//void mostrar(Pila &obj){
//int valor;
//    cout<<"ELEMENTOS INGRESADOS: "<<endl;
//    while(obj.sacarElemento(valor)){
//        cout<<valor<<endl;
//    }
//    cout<<"ESTA VACIA"<<endl;
//}

void mostrar(Cola &obj){
int valor;
    cout<<"ELEMENTOS INGRESADOS: "<<endl;
    while(obj.sacarElemento(valor)){
        cout<<valor<<endl;
    }
    cout<<"ESTA VACIA"<<endl;
}

int main(){

    Pila a(5);

    Pila b(3);

    int x, val;

    x=1;

    while(a.Agregar(x))x++;

    while(a.Sacar(val)){

        b.Agregar(val);

    }

    while(b.Sacar(x))cout<<x;



	cout<<endl;

	system("pause");

	return 0;

}


//    if(obj.sacarElemento(valor)){
//    cout<<valor<<endl;
//    }else{
//        cout<<"La cola esta vacia"<<endl;
//    }
