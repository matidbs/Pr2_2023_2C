#include <iostream>
#include <cstring>

using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
    public:
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
        void setFechaLimite (Fecha fL){
            Fecha = fL;
        }
};

class Tarea{
    private:
        int id;
        char descripcion[100];
        int dificultad;
        Fecha fechaLimite;
        int estado;
    public:
        void setId(int i){
            id=i;
        }
        int getId(){return id;}
        void Cargar(){
            cout<<"ID: ";
            cin>>id;
            cout<<"DESCRIPCION: ";
            cin.ignore();
            cin.getline(descripcion, 100);
            cout<<"DIFICULTAD (1-ALTA, 2-MEDIA, 3-BAJA): ";
            cin>>dificultad;
            cout<<"FECHA: ";
            fechaLimite.Cargar();
            cout<<"ESTADO: ";
            cin>>estado;
        }
        void Mostrar(){
            cout<<"ID: "<<id<<endl;
            cout<<"DESCRIPCION: "<<descripcion<<endl;
            cout<<"DIFICULTAD: "<<dificultad<<endl;
            cout<<"FECHA: ";
            fechaLimite.Mostrar();
            cout<<endl;
            cout<<"ESTADO: "<<estado<<endl;
        }

};

class ListaDeTareas{
    private:
        Tarea lista[10];
        int cantidad;
    public:
        ListaDeTareas(){
            cantidad=0;
        }
        void agregarTarea(Tarea reg){
            if(cantidad<10){
                lista[cantidad]=reg;
                cantidad++;
            }
        }
        void listarTareas(){
            for(int i=0; i<cantidad; i++){
                lista[i].Mostrar();
            }
        }
        void modificarFecha(){
            ArchivoTareas arcTarea;
            cout<<"INGRESE LA ID A MODIFICAR: ";
            int id;
            cin>>id;
            int pos=arcTarea.buscarPorID(id);
            if (pos<0){
                cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
                return;
            }
            Tarea reg;
            reg = arcTarea.buscarRegistro(pos);
            Fecha aux;
            cout<<"INGRESE LA FECHA NUEVA: ";
            aux.Cargar();
            reg.setFechaLimite(aux);
            arcTarea.modificarRegistro(reg,pos);

        }
};

class ArchivoTareas{
    private:
        char nombre[40];
    public:
        ArchivoTareas(const char *n="tareas.dat"){
            strcpy(nombre, n);
        }
        bool agregarRegistro(Tarea reg){
            FILE *pTarea;
            pTarea=fopen(nombre, "ab");
            if(pTarea==NULL){
                return false;
            }
            bool grabo=fwrite(&reg, sizeof (Tarea), 1, pTarea);
            fclose(pTarea);
            return grabo;
        }
        bool listarTareas(){
            FILE *pTarea;
            Tarea aux;
            pTarea=fopen(nombre, "rb");
            if(pTarea==NULL){
                cout<<"ERROR DE ARCHIVO"<<endl;
                return false;
            }
            while(fread(&aux, sizeof (Tarea), 1, pTarea)==1){
                aux.Mostrar();
                cout<<endl;
            }
            fclose(pTarea);
            return true;
        }
//        Tarea buscarPorID(int id){
//            FILE *pTarea;
//            Tarea aux;
//            pTarea=fopen(nombre, "rb");
//            if(pTarea==NULL){
//                aux.setId(-2);
//                return aux;
//            }
//            while(fread(&aux, sizeof(Tarea), 1, pTarea)){
//                if(aux.getId()==id){
//                    fclose(pTarea);
//                    return aux;
//                }
//            }
//            fclose(pTarea);
//            aux.setId(-1);
//            return aux;
//        }
            int buscarPorID(int id){
            FILE *pTarea;
            Tarea aux;
            pTarea=fopen(nombre, "rb");
            if(pTarea==NULL){
                aux.setId(-2);
                return aux;
            }
            while(fread(&aux, sizeof(Tarea), 1, pTarea)){
                if(aux.getId()==id){
                    int pos=(ftell(pTarea)/sizeof (Tarea))-1
                    fclose(pTarea);
                    return pos;
                }
            }
            fclose(pTarea);
            return -1;
        }


        Tarea buscarRegistro(int pos){
            FILE *pTarea;
            Tarea aux;
            pTarea=fopen(nombre, "rb");
            if(pTarea==NULL){
                aux.setId(-2);
                return aux;
            }
            fseek(pTarea, pos * sizeof (Tarea), 0);
            fread(&aux, sizeof(Tarea), 1, pTarea);
            fclose(pTarea);
            return aux;
        }
        int getCantidad(){
            FILE *pTareas;
            pTareas=fopen(nombre, "rb");
            if(pTareas==NULL){
                return -1;
            }
            fseek(pTareas, 0, 2);
            int tam=ftell(pTareas);
            fclose(pTareas);
            return tam/sizeof(Tarea);
        }
        void modificarRegistro(Tarea reg,int pos){
            FILE *pTareas;
            pTareas = fopen(nombre,"rb+");
            if (pTareas==nullptr){
                return;
            }
            fseek(pTareas,pos * sizeof(Tarea),0);
            bool modifico = fwrite(&reg,sizeof(Tarea),1,pTareas);
            fclose(pTareas);
            return modifico;
        }
};

/*
    void limpiarArchivos(const char *n){
    FILE *p;
    p=fopen(n,"wb");
    if(p=NULL){
        return false;
    }
    fclose(p);
    return;
    }

    void bajaFisica(){
    ArchivoAlumnos arcBaja("alumnos.bjf");
    ArchivoAlumnos arcAlumnos;
    Alumno reg;
    limpiarArchivo("alumnos.bjf);
    int cantR = arcAlumnos.getCantidadArchivos();
    for (int i=0;i<cantR;i++){
        reg = arcAlumno.leerRegistro(i);
        if(reg.getEstado()==TRUE){
            arcBaja.grabarRegistro(reg);
        }
    }
    limpiarArchivo("alumnos.dat");
    cantR = arcBaja.getCantidadArchivos();
    for(int i=0;i<cantR;i++){
        reg = arcBaja.leerRegistro(i);
        arcAlumnos.grabarRegistro(reg);
        }
    }

*/
bool grabarTarea(Tarea reg);
void altaTarea(){
    Tarea reg;
    reg.Cargar();
    grabarTarea(reg);
}
void listarTareas();
void buscarTareaPorId();

int main()
{
    ArchivoTareas arcTareas;

    int cantReg=arcTareas.getCantidad();
    for(int i=0; i<cantReg; i++){
        arcTareas.buscarRegistro(i).Mostrar();
        cout<<endl;
    }
    return 0;
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1 - ALTA TAREA"<<endl;
        cout<<"2 - LISTAR TAREAS"<<endl;
        cout<<"3 - BUSCAR TAREA POR ID"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"--------------"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                {
                    Tarea reg;
                    reg.Cargar();
                    arcTareas.agregarRegistro(reg);
                }
                break;
            case 2:
                arcTareas.listarTareas();
                break;
            case 3:
                buscarTareaPorId();
                break;
            case 0:
                return 0;
        }
    system("pause");
    }
    return 0;
}

bool grabarTarea(Tarea reg){

}

/***
ARMAR LA CLASE ArchivoTarea PARA ADMINISTRAR EL ARCHIVO DE TAREAS
*/

void buscarTareaPorId(){
    ArchivoTareas arc;
    cout<<"INGRESE LA ID A BUSCAR: ";
    int id;
    cin>>id;
    system("cls");
    Tarea aux= arc.buscarPorID(id);
    if(aux.getId()>0){
        aux.Mostrar();
    }
    else{
        cout<<"NO EXISTE EL ID EN EL ARCHIVO O NO SE PUDO ABRIR"<<endl;
    }
}

void listarTareas(){

}
