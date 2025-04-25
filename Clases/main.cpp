#include <iostream>

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

int verificarPuntero (FILE *p){
    if (p==NULL){
    system("cls");
    cout<<"ERROR: NO SE ABRIO EL PUNTERO"<<endl;
    return -1;
    }
}

class Fecha{
private:
    int _dia;
    int _mes;
    int _anio;
public:
    void cargarFechaLimite(){
        cout<<"DIA: ";
        cin>>_dia;
        cout<<"MES: ";
        cin>>_mes;
        cout<<"ANIO: ";
        cin>>_anio;
    }
    int getDia(){
        return _dia;
    }
    int getMes(){
        return _mes;
    }
    int getAnio(){
        return _anio;
    }
};

class Tarea{
    private:
        int _id;
        char _descripcion[100];
        int _dificultad;
        Fecha fechalimite;
        int _estado;
    public:
        void cargarTarea(){
            cout<<"CARGAR ID: ";
            cin>>_id;
            cout<<"CARGAR DESCRIPCION: ";
            cargarCadena(_descripcion,40);
            cout<<"CARGAR DIFICULTAD(1-BAJA,2-MEDIA,3-ALTA): ";
            cin>>_dificultad;
            cout<<"CARGAR FECHA LIMITE: "<<endl;
            fechalimite.cargarFechaLimite();
            cout<<"Estado (1-PENDIENTE,2-HECHO): ";
            cin>>_estado;
        }
//        void setEstadoTarea(){
//            int opc;
//            cout<<"ESTADO DE TAREA: ";
//            if (_estado==false){
//                cout<<"PENDIENTE";
//            }else {
//                cout<<"HECHO";
//            }
//            cout<<endl<<"CAMBIAR ESTADO DE TAREA: "<<endl;
//            cout<<"1 - HECHO"<<endl;
//            cout<<"2 - PENDIENTE"<<endl;
//            cin>>opc;
//            if (opc==1){
//                _estado = true;
//            }else if (opc==2) {
//                _estado = false;
//            }
//        }
//        void verTarea(){
//            cout<<"ID: "<<_id<<endl;
//            cout<<"DESCRIPCION: "<<_descripcion<<endl;
//            cout<<"DIFICULTAD: ";
//            switch (_dificultad){
//            case 1:
//                cout<<"BAJA"<<endl;
//                break;
//            case 2:
//                cout<<"MEDIA"<<endl;
//                break;
//            case 3:
//                cout<<"ALTA"<<endl;
//                break;
//            }
//            cout<<"FECHA LIMITE: "<<fechalimite.getDia()<<"/"<<fechalimite.getMes()<<"/"<<fechalimite.getAnio()<<endl;
//            cout<<"ESTADO DE TAREA: ";
//                if (_estado==false){
//                cout<<"PENDIENTE";
//                }else {
//                cout<<"HECHO";
//                }
//            cout<<endl;
//        }
        void mostrarTareasLista(){
            cout<<_id<<"    "<<_descripcion<<"              ";
            switch (_dificultad){
            case 1:
                cout<<"BAJA";
                break;
            case 2:
                cout<<"MEDIA";
                break;
            case 3:
                cout<<"ALTA";
                break;
            }
            cout<<"           "<<fechalimite.getDia()<<"/"<<fechalimite.getMes()<<"/"<<fechalimite.getAnio()<<"       ";
            if (_estado==1){
                cout<<"PENDIENTE";
                }else if(_estado==2) {
                cout<<"HECHO";
                }
        }
        int getId(){
            return _id;
        }


};

class ListaDeTareas{
    private:
        Tarea tarea;
        int _contTareas=0;
    public:
        ListaDeTareas (){
        FILE *p;
        verificarPuntero(p);
        p=fopen("tareas.dat","rb");
        while(fread (&tarea,sizeof(Tarea),1,p)==1){
                _contTareas++;
            }
        }
        void cargarUnaTarea(){
            FILE *p;
            verificarPuntero(p);
            if (_contTareas<=10){
            tarea.cargarTarea();
            p=fopen("tareas.dat","ab");
            fwrite(&tarea,sizeof(Tarea),1,p);
            fclose(p);
            _contTareas++;
            }
        }
        void mostrarListaTareas(){
            FILE *p;
            verificarPuntero(p);
            p=fopen("tareas.dat","rb");
            while(fread (&tarea,sizeof(Tarea),1,p)==1){
            tarea.mostrarTareasLista();
            cout<<endl;
            }
            fclose(p);
            system("pause");
            }
        int getContador(){
            return _contTareas;
            }
        void IngresarTareaID (){
            int id,opc,aux;
            bool menu = true;
            FILE *p;

            cout<<"INGRESE ID: ";
            cin>>id;

            //Busqueda de ID//
            p=fopen("tareas.dat","rb");
                fread(&tarea,sizeof(Tarea),1,p);
                aux = tarea.getId();
            while (id!=aux){
                fread(&tarea,sizeof(Tarea),1,p);
                aux = tarea.getId();            }
            system("cls");

            while (menu==true){
            cout<<"1 - VER TAREA"<<endl;
            cout<<"2 - CAMBIAR ESTADO TAREA"<<endl;
            cout<<"3 - SALIR"<<endl;
            cout<<"OPC: ";
            cin>>opc;
            system("cls");

            switch(opc){
            case 1:
                tarea.mostrarTareasLista();
                system("pause");
                system("cls");
                break;
//          case 2:
//                tarea.setEstadoTarea();
//                system("cls");
//                break;
            case 3:
                fclose(p);
                menu = false;
                break;
            }
        }
        }

};

int main(){
   ListaDeTareas obj;
   int opc;
   while (true){
    system("cls");
    cout<<"1 - CARGAR TAREA"<<endl;
    cout<<"2 - MOSTRAR LISTA TAREAS"<<endl;
    cout<<"3 - INGRESAR ID TAREA"<<endl;
    cout<<"4 - SALIR"<<endl;
    cout<<obj.getContador();
    cin>>opc;
    system("cls");
    switch (opc){
        case 1:
            obj.cargarUnaTarea();
            break;
        case 2:
            obj.mostrarListaTareas();
            break;
        case 3:
           obj.IngresarTareaID();
            break;
        case 4:
            return 0;
            break;
        default:
            break;
   }
   }
return 0;}

/*
fopern f:file open: abrir
Se utiliza para crear un vinculo entre el programa y el archivo
Los parametros son el nombre y la extension (la ruta absoluta es opcional)
y el modo de apertura
Modos de apertura:  ab - append binary (abre el archivo en modo escritura, si no existe, lo crea)
                    rb - read binary (abre el archivo en modo lectura, no crea archivos)
                    wb - write binary (crea un archivo vacio y lo abre en modo escritura)
fclose: -f: file -close: cerrar
Es necesario cerrar siempre el archivo, por ejemplo, si hacemos un return, debe cerrarse antes del mismo
fwrite: -f: file -write: escribir
Parametros:
-Direccion de memoria donde esta la informacion que quiero escribir en el archivo
-Cantidad de bytes a partir del archivo de la direccion de memoria que quiero guardar en el archivo
-Cantidad de registros que quiero guardar
-Puntero FILE sobre el que se realizo la apertura del archivo
Devuelve como valor la cantidad de registros que pudo guardar correctamente
fread: -f: file -read: leer
Parametros:
-Direccion de memoria donde esta la informacion que quiero escribir la informacion
que leo en el archivo
-Cantidad de bytes a leer en el archivo
-Cantidad de registros que quiero guardar
-Puntero FILE sobre el que se realizo la apertura del archivo
Para verificar si el puntero es valido, hay que ver si el
*/
/*
int main {
FILE *p;

// Para escribir
p=fopen("tareas.dat","ab");
Tarea reg;
reg.Cargar();
                 Tipo de dato
fwrite(&reg,sizeof (Tarea),1,p);
//

// Para leer          Cambiamos el modo de apertura
p=fopen("tareas.dat","rb");
fread(&reg,sizeof (Tarea),1,p);
reg.Mostar();
//Para mostrar un segundo registro
fread(&reg,sizeof (Tarea),1,p);
reg.Mostar();
//

fclose(p);
return 0;}

while (fread(&reg,sizeof (Tarea),1,p)!=0){
    reg.Mostrar();
}
*/
