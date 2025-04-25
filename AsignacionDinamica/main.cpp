#include <iostream>
#include <cstring>

using namespace std;

//Crear un vector dinamico de 10 elementos y luego agregarle desde una
//Funcion 5 elementos mas

void cargarVector (int *vec,int tam){
    for (int i=0;i<tam;i++){
        vec[i]=i+1;
    }
}

void mostrarVector(int *vec,int tam){
    for (int i=0;i<tam;i++){
        cout<<vec[i]<<endl;
    }
}

int* copiarVector (int tam,int *vCop,int *vPeg){
    for (int i=0;i<tam;i++){
        vPeg[i] = vCop[i];
    }
    return vPeg;
}

int* agregarElementos(int *v,int &tam){
    int *vAux=new int [tam];
    if (vAux==nullptr){
        exit(-1);
    }
    copiarVector(tam,v,vAux);
    delete[]v;
    int ctam =tam+ 5;
    v=new int[ctam];
    if(v==nullptr){
        exit (-2);
    }
    for (int i=0;i<tam;i++){
        v[i]=vAux[i];
    }
    for (int i=tam;i<ctam;i++){
        v[i]=i+99;
    }
    delete[] vAux;
    mostrarVector(v,ctam);
    tam=ctam;
    return v;
}

//Clase para manejar cadenas de caracteres
//Hacer un metodo para concatenar palabras//

class Cadena{
private:
    char *palabra;
    int tam;
public:
    Cadena (const char *p){
        tam=strlen(p)+1;
        palabra=new char [tam];
        if (palabra==nullptr)exit (-1);
        strcpy(palabra,p);
    }
    void mostraPalabra(){
        cout<<palabra;
    }
    void cambiarPalabra(const char*p){
        delete[]palabra;
        tam=strlen(p)+1;
        palabra=new char[tam];
        if (palabra==nullptr)exit(-2);
        strcpy(palabra,p);
    }
    void agregarLetra (char p){
        char *aux=new char [tam];
        if (aux==nullptr)exit(-3);
        strcpy(aux,palabra);
        delete[]palabra;
        palabra=new char[tam+1];
        if(palabra==nullptr)exit(-3);
        strcpy(palabra,aux);
        delete[]aux;
        palabra[tam-1]=p;
        palabra[tam]='\0';
        tam+=1;
    }
    void concatenarPalabra(const char*p){
        char *aux=new char [tam];
        if (aux==nullptr)exit(-3);
        strcpy(aux,palabra);
        delete[]palabra;
        tam += strlen(p);
        palabra=new char [tam];
        strcpy(palabra,aux);
        strcat(palabra,p);
        delete[]aux;
    }
    ~Cadena(){
        delete[]palabra;
    }
    void operator += (char p){
        char *aux=new char [tam];
        if (aux==nullptr)exit(-3);
        strcpy(aux,palabra);
        delete[]palabra;
        palabra=new char[tam+1];
        if(palabra==nullptr)exit(-3);
        strcpy(palabra,aux);
        delete[]aux;
        palabra[tam-1]=p;
        palabra[tam]='\0';
        tam+=1;
    }
    void operator += (const char* p){
        char *aux=new char [tam];
        if (aux==nullptr)exit(-3);
        strcpy(aux,palabra);
        delete[]palabra;
        tam += strlen(p);
        palabra=new char [tam];
        strcpy(palabra,aux);
        strcat(palabra,p);
        delete[]aux;
    }
    bool operator == (const char* c1){
        if (strcmp(palabra,c1)==0){
            cout<<"LA CADENA ES IGUAL"<<endl;
            return true;
        }
        cout<<"LA CADENA ES DISTINTA"<<endl;
        return false;
    }
};


int main(){
    Cadena obj("HOLAA");
    obj.mostraPalabra();
    cout<<endl;
    obj==("HOLA");
//    obj.mostraPalabra();

return 0;}

//
//int main(){
//    Cadena obj("Hola");
//    obj.mostraPalabra();
//    cout<<endl;
//    obj.concatenarPalabra(" mundo");
//    obj.mostraPalabra();
//return 0;}

/*
int main(){
    int tam;
    cout<<"TAMANIO DEL VECTOR: ";
    cin>>tam;
    int *vec;
    vec= new int [tam];
    if (vec==NULL){
        cout<<"NO SE PUDO RESERVAR LA MEMORIA"<<endl;
    }
    cargarVector(vec,tam);
    mostrarVector(vec,tam);
    system("pause");
    system("cls");
    vec = agregarElementos(vec,tam);
    delete[]vec;
    cout<<tam;
return 0;}
*/
/*
delete --> Elimina una sola posicion del vector
delete[] -->Para todos los elementos de un vector

*/
/*
    int tam;
    cout <<"INGRESE EL TAMANIO DEL VECTOR: ";
    cin>>tam;
    int *vec;
    vec=new int [tam];
    if (vec==NULL){
        cout<<"NO SE PUDO RESERVAR LA MEMORIA"<<endl;
        return -1;
    }
    cargarVector (vec,tam);
    mostrarVector(vec,tam);
    delete[] vec;
*/
