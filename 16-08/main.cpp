/*
https://codeshare.io/WdnRnM
a) Cargar y mostrar el vector con 3 materias (completo)

b) Mostrar las materias con más de 5 docentes

c) Cambiar la cantidad de profesores en las materias que tengan más de 500 alumnos. Si tiene menos de 10 docentes,
cambiar la cantidad a 10. Si tiene más de 10 no hacer modificaciones.

d) Modificar la clase de manera tal de no permitir cursos con más de 500 alumnos. Si la cantidad es mayor a ese número poner como valor 500
*/

#include <iostream>
#include <cstring>

using namespace std;

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

class Materia{
    private:
        int numeroMateria;
        char nombre[30];
        int cantidadAlumnos;
        int cantidadDocentes;
    public:
        ///METODOS SET:
        ///Nos permiten asignar valores a las propiedades
        ///Podemos poner validaciones para no permitir valores erroneos
        void setNumeroMateria(int numeroMateria){
            if(numeroMateria>0 && numeroMateria<21) this->numeroMateria = numeroMateria;
        }
        void setNombre(const char *n){
            strcpy(nombre,n);
        }
        void setCantidadAlumnos(int cA){cantidadAlumnos=cA;}
        void setCantidadDocentes(int cD){cantidadDocentes=cD;}
        int getNumeroMateria(){return numeroMateria;}
        const char *getNombre(){return nombre;}
        int getCantidadAlumnos(){return cantidadAlumnos;}
        int getCantidadDocentes(){return cantidadDocentes;}
        void Cargar(){
            cout<<"NUMERO MATERIA: ";
            cin>>numeroMateria;
            cout<<"NOMBRE: ";
            cargarCadena(nombre, 29);
            cout<<"CANTIDAD ALUMNOS: ";
            cin>>cantidadAlumnos;
            cout<<"CANTIDAD DOCENTES: ";
            cin>>cantidadDocentes;
        }
        void Mostrar(){
            cout<<"NUMERO MATERIA: "<<numeroMateria<<endl;
            cout<<"NOMBRE: "<<nombre<<endl;
            cout<<"CANTIDAD ALUMNOS: "<<cantidadAlumnos<<endl;
            cout<<"CANTIDAD DOCENTES: "<<cantidadDocentes<<endl;
        }
        void MostrarMateriasMas5Docentes(){
            if (cantidadDocentes>5){
            cout<<"NUMERO MATERIA: "<<numeroMateria<<endl;
            cout<<"NOMBRE: "<<nombre<<endl;
            cout<<"CANTIDAD ALUMNOS: "<<cantidadAlumnos<<endl;
            cout<<"CANTIDAD DOCENTES: "<<cantidadDocentes<<endl;
            }
        }
};

int main()
{
    Materia obj[3];
    int opc;
    while (true){
        cout<<"1 - CARGAR MATERIAS"<<endl;
        cout<<"2 - MOSTRAR MATERIAS"<<endl;
        cout<<"3 - MOSTRAR MATERIAS CON MAS DE 5 DOCENTES"<<endl;
        cout<<"4 - AJUSTAR CANTIDAD DE ALUMNOS/PROFESORES"<<endl;
        cout<<"    (ALUMNOS>500, DOCENTES => 10)"<<endl;
        cout<<"5 - SALIR"<<endl;
        cin>>opc;

    switch (opc){
        case 1:
            for(int i=0;i<3;i++){
            obj.Cargar[i]();
            }
            break;
        case 2:
            for(int i=0;i<3;i++){
            obj.Mostrar[i]();
            }
            break;
        case 3:
            for(int i=0;i<3;i++){
            obj.MostrarMateriasMas5Docentes[i]();
            }
            break;
        case 4:

            break;
        case 5:

            break;
    }
    }

    cargarMaterias (obj, 3);
    mostrarMaterias(obj, 3);

    return 0;
}

/*
void cargarMaterias(materia *v);
void mostrarMaterias(materia *v);
void cargarIngresos(float *vH, int mat[][31]);
void materiasSinAccesos(char materias[][30], float *vH);
void materiaMasHoras(char materias[][30], float *vH);
void accesosMarzo(char materias[][30], int m[][31]);
int buscarMaximo(float *v, int tam=5);
int buscarMaximo(int *v, int tam);
//void funcionInutil(){cout<<"NO RECIBE NADA"<<endl;}
void funcionInutil(int aux=5){cout<<"RECIBE INT"<<endl;}
void funcionInutil(float aux=1.5){cout<<"RECIBE FLOAT"<<endl;}
void cargarMateria(materia *reg){
    cout<<&(reg->numeroMateria);
}*/


