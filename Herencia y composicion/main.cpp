#include <iostream>
#include <cstring>
#include <string>
/*
AGREGAR UNA PROPIEDAD POR COMPOSICION PARA EL DOMICILIO DEL ALUMNO
(CREAR LA CLASE DOMICILIO). EL DOMICILIO DEBE TENER:
NOMBRE DE LA CALLE,ALTURA,LOCALIDAD,PROVINCIA,CODIGO POSTAL.
*/
/*
PARA HEREDAR SE DEBE INDICAR (class [NOMBRE CLASE::[NOMBRE DE CLASE HERENCIA]
*/
using namespace std;

class Domicilio{
    private:
        int _altura;
        char _codigoPostal[30];
        char _nombreCalle[30];
        char _localidad[30];
        char _provincia[30];
    public:
        Domicilio(const char *n="nombre",int altura=0,const char *loc="localidad",const char *prov="provincia",const char *codPostal="codigo postal"){
            strcpy(_nombreCalle,n);
            _altura=altura;
            strcpy(_localidad,loc);
            strcpy(_provincia,prov);
            strcpy(_codigoPostal,codPostal);
        }
        void setNombreCalle (const char *n){
            strcpy(_nombreCalle,n);
        }
        void setAltura (int altura){
            _altura=altura;
        }
        void setLocalidad (const char *loc){
            strcpy(_localidad,loc);
        }
        void setProvincia (const char *prov){
            strcpy(_provincia,prov);
        }
        void setCodigoPostal (const char *codPostal){
            strcpy(_codigoPostal,codPostal);
        }
        const char *getNombreCalle (){
            return _nombreCalle;
        }
        int getAltura (){
            return _altura;
        }
        const char *getLocalidad (){
            return _localidad;
        }
        const char *getProvincia (){
            return _provincia;
        }
        const char *getCodigoPostal(){
            return _codigoPostal;
        }
        void MostrarDomicilio(){
        cout<<"Nombre Calle: "<<getNombreCalle()<<endl;
        cout<<"Altura: "<<getAltura()<<endl;
        cout<<"Localidad: "<<getLocalidad()<<endl;
        cout<<"Provincia: "<<getProvincia()<<endl;
        cout<<"Codigo postal: "<<getCodigoPostal()<<endl;
        }
};

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(){}
        Fecha(int d, int m, int a);
        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar(){
            cout<<dia<<"/"<<mes<<"/"<<anio;
        }
        void setDia(int d){if(d>=1 && d<=31)dia=d;}
        void setMes(const int m){mes=m;}
        void setAnio(int ani){anio=ani;}
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ~Fecha(){
        }
};

Fecha::Fecha(int d, int m, int a){
    dia=d;
    mes=m;
    anio=a;
}

class Persona{
    private:
        char nombre[30];
        char apellido[30];
        int dni;
        Fecha fechaNacimiento;
        Domicilio domicilio;
};

class Alumno{
    private:
        int legajo;

        Fecha fechaInscripcion;

        bool estado;
    public:
        void setDiaNacimiento(int dia){
            fechaNacimiento.setDia(dia);
        }
        void setDiaInscripcion(int dia){
            fechaInscripcion.setDia(dia);
        }
        Alumno(int dni=10, const char *n="nombre", Fecha fN = Fecha(30, 9, 2023),Domicilio dom = Domicilio ("Calle",10,"General Pacheco","Buenos Aires","1900")){
            Fecha aux;
            this->dni=dni;
            strcpy(this->nombre, n);
            fechaNacimiento=fN;
            domicilio = dom;
        }
        Fecha getFechaNacimiento(){return fechaNacimiento;}
        int getDni(){return dni;}
        void setFechaNacimiento(Fecha fN){fechaNacimiento = fN;}
        void setFechaNacimiento(int d, int m, int a){
            fechaNacimiento.setDia(d);
            fechaNacimiento.setMes(m);
            fechaNacimiento.setAnio(a);
        }
        const char *getNombre(){return nombre;}
        void setNombre(const char *n){strcpy(nombre, n);}
        const char *getApellido(){return apellido;}
        void setApellido(const char *a){strcpy(apellido, a);}
        void setDomicilio (Domicilio dom){
            domicilio=dom;
        }
        void setDomicilio(const char *n="nombre",int altura=0,const char *loc="localidad",const char *prov="provincia",const char *codPostal="codigo postal"){
            domicilio.setNombreCalle(n);
            domicilio.setAltura(altura);
            domicilio.setLocalidad(loc);
            domicilio.setProvincia(prov);
            domicilio.setCodigoPostal(codPostal);
        }
        void setNombreCalle(const char *n){
            domicilio.setNombreCalle(n);
        }
        void setAltura(int alt){
            domicilio.setAltura(alt);
        }
        void setLocalidad(const char *loc){
            domicilio.setLocalidad(loc);
        }
        void setProvincia(const char *prov){
            domicilio.setProvincia(prov);
        }
        void setCodigoPostal(const char *codPost){
            domicilio.setCodigoPostal(codPost);
        }
        const char *getNombreCalle(){
            domicilio.getNombreCalle();
        }
        int getAltura(){
            domicilio.getAltura();
        }
        const char *getNombreLocalidad(){
            domicilio.getLocalidad();
        }
        const char *getProvincia(){
            domicilio.getProvincia();
        }
        const char *getCodigoPostal(){
            domicilio.getCodigoPostal();
        }
        Domicilio getDomicilio(){
            domicilio.MostrarDomicilio();
        }
};

int main(){
    Alumno obj;
    obj.setDomicilio("PabloA",8,"Chivilcoy","Buenos Aires","7");
    obj.setAltura(1900);
    obj.getDomicilio();


return 0;}
