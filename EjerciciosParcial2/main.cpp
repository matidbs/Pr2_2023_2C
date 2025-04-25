#include <iostream>
#include <cstring>

using namespace std;

#include "archivoCabecera.h"

class Equipo10Jugadores{
private:
    int IdEquipo, categoria;
    char nombre[30];
    bool estado;
public:
    int getIdEquipo(){return IdEquipo;}
    int getCategoria(){return categoria;}
    const char *getNombre(){return nombre;}
    bool getEstado(){return estado;}

    void setIdEquipo(int id){IdEquipo=id;}
    void setCategoria(int n){categoria=n;}
    void setNombre(const char *n){strncpy(nombre,n,30);}
    void setEstado(bool e){estado=e;}
    void Mostrar(){}
};

class ArchivoEquipos10J{
private:
    char nombre[30];
public:
    ArchivoEquipos10J(const char *n="archivoEquipos10Jugadores.dat"){
        strcpy(nombre, n);
    }
    Equipo10Jugadores leerRegistro(int pos){
        Equipo10Jugadores reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Equipo10Jugadores);
    }
    bool grabarRegistro(Equipo10Jugadores reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};

int buscarCategoria(int id){
    ArchivoDeportes arcD("deportes.dat");
    Deporte reg;

    int cant=arcD.contarRegistros();

    for(int i=0;i<cant;i++){
        reg=arcD.leerRegistro(i);
        if(reg.getIdCtegoria()==id){
            return reg.getIdCtegoria();
        }
    }
    return -1;
}

void punto1(){
    int contJ,idDeporte;
    ArchivoEquipos10J arcE10J;
    Equipo10Jugadores regE10J;
    ArchivoEquipos arcE("equipos.dat");
    Equipo regE;
    ArchivoJugadores arcJ("jugadores.dat");
    Jugador regJ;

    int cantEquipos=arcE.contarRegistros();
    int cantJugadores=arcJ.contarRegistros();

    for (int i=0;i<cantEquipos;i++){
        regE=arcE.leerRegistro(i);
        if(regE.getEstado()){
                contJ=0;
            for(int j=0;j<cantJugadores;j++){
                regJ=arcJ.leerRegistro(j);
                if(regJ.getIdEquipo()==regE.getIdEquipo()&&regJ.getEstado()){
                    contJ++;
                    idDeporte=regJ.getIdDeporte();
                }
            }
            if(contJ>=10){
                regE10J.setNombre(regE.getNombre());
                regE10J.setIdEquipo(regE.getIdEquipo());
                regE10J.setCategoria(buscarCategoria(idDeporte));
                regE10J.setEstado(true);
                arcE10J.grabarRegistro(regE10J);
            }
        }
    }
}

bool contarClaustros(int id){
    ArchivoJugadores arcJ("jugadores.dat");
    Jugador reg;
    int cant=arcJ.contarRegistros();
    int vCont[4]={0};
    for(int i=0;i<cant;i++){
        if(reg.getIdDeporte()==id&&reg.getEstado()){
            vCont[reg.getClaustro()-1]++;
        }
    }

    if(vCont[0]>0&&vCont[1]>0&&vCont[2]>0&&vCont[3]>0){
        return true;
    }
    return false;
}

class DeporteClaustro{
private:
    int idDeporte, anioOrigen, idCategoria;
    char nombre[30];
    bool estado;
public:
   int getIdDeporte(){return idDeporte;}
   int getIdCtegoria(){return idCategoria;}
   const char *getNombre(){return nombre;}
   bool getEstado(){return estado;}
    void setIDDeporte(int id){idDeporte=id;}
    void setAnioOrigen(int a){anioOrigen=a;}
    void setIdCategoria(int id){idCategoria=id;}
    void setNombre(const char *n){strcpy(nombre,n);}

   void setEstado(bool e){estado=e;}
   void Mostrar(){

   }

};

class ArchivoDeportesClaustro{
private:
    char nombre[30];
public:
    ArchivoDeportesClaustro(const char *n){
        strcpy(nombre, n);
    }
    DeporteClaustro leerRegistro(int pos){
        DeporteClaustro reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(DeporteClaustro);
    }
    bool grabarRegistro(DeporteClaustro reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};

void puntoa(){
    ArchivoDeportes arcD("deportes.dat");
    Deporte reg;

    ArchivoDeportesClaustro ("deportesClaustro.dat");
    DeporteClaustro regC;

    int cant=arcD.contarRegistros();

    for(int i=0;i<cant;i++){
        reg=arcD.leerRegistro(i);
        if(contarClaustros(reg.getIdDeporte())==true){
            regC.setIDDeporte(reg.getIdDeporte());
            regC.setIdCategoria(reg.getIdCtegoria());
            regC.setAnioOrigen(reg.get)
        }
    }
}

void punto2(){
    ArchivoEquipos10J arcEquipo10J;
    Equipo10Jugadores reg;

    int cantR=arcEquipo10J.contarRegistros();

    Equipo10Jugadores *v;
    v=new Equipo10Jugadores[cantR];
    if(v==nullptr) exit(-2);
    for(int i=0;i<cantR;i++){
        v[i]=arcEquipo10J.leerRegistro(i);
    }
    for(int i=0;i<cantR;i++){
        v[i].Mostrar();
    }
}

int contarJugadores(int id){
    ArchivoJugadores arcJ("jugadores.dat");
    Jugador reg;
    int cantR=arcJ.contarRegistros();
    int cont=0;
    for(int i=0;i<cantR;i++){
        reg=arcJ.leerRegistro(i);
        if(reg.getIdEquipo()==id){
            cont++;
        }
    }
    return cont;
}

void cargarJugadores(Jugador *v,int id){
    ArchivoJugadores arcJ("jugadores.dat");
    Jugador reg;
    int pos=0;
    int cantR=arcJ.contarRegistros();
    for(int i=0;i<cantR;i++){
        reg=arcJ.leerRegistro(i);
        if(reg.getIdEquipo()==id){
            v[pos]=reg;
            pos++;
        }
    }
}

void mostrarVector(Jugador *v,int tam){
    for(int i=0;i<tam;i++){
        v[i].Mostrar();
    }
}

void puntoB(){
    ArchivoJugadores arcJ ("jugadores.dat");
    Jugador reg;
    Jugador *v;
    int id;
    cout<<"INGRESE UNA ID DE EQUIPO: ";
    cin>>id;
    int tam=contarJugadores(id);
    if(tam<=0){
        cout<<"NO HAY JUGADORES EN ESE EQUIPO"<<endl;
        return;
    }
    v=new Jugador[tam];
    if (v==nullptr){return;}
    cargarJugadores(v,id);
    mostrarVector(v,tam);
    delete[]v;
}

bool Jugador::operator > (int a){
    if(inscripcion.getAnio()>a){
        return true;
    }
    return false;
}

bool Jugador::operator == (int a){
    if(claustro==a){
        return true;
    }
    return false;
}


int main(){

    return 0;}
