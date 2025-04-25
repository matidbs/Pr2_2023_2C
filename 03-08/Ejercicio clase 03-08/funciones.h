#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void ingresoMaterias(char mNombres[][30]);
void ingresoAsistencias(int *vIngresos, int mIngresosXDia[][31]);
void materiasSinAsistencias(int *vIngresos, char mNombres[][30]);
void materiaMasAsistencias(int *vIngresos, char mNombres[][30]);
void asistenciasXDiaAgosto(int mIngresosXDia[][31]);

void ingresoMaterias(char mNombres[][30]){
    int nroMateria;
    for(int i=0; i<20; i++){
        cout<<"INGRESE EL NUMERO DE LA MATERIA: ";
        cin>>nroMateria;
        cout<<"INGRESE EL NOMBRE DE LA MATERIA: ";
        cin.ignore();
        cin.getline(mNombres[nroMateria-1], 30);
    }
}

void ingresoAsistencias(int *vIngresos, int mIngresosXDia[][31]){
    int legajo, nroMateria, dia;
    cout<<"LEGAJO: ";
    cin>>legajo;
    while(legajo!=0){
        cout<<"NUMERO MATERIA: ";
        cin>>nroMateria;
        cout<<"DIA: ";
        cin>>dia;
        vIngresos[nroMateria-1]++;
        mIngresosXDia[nroMateria-1][dia-1]++;
        cout<<"LEGAJO: ";
        cin>>legajo;
    }
}

void materiasSinAsistencias(int *vIngresos, char mNombres[][30]){
    for(int i=0; i<20; i++){
        if(vIngresos[i]==0){
            cout<<"LA MATERIA "<<mNombres[i]<<" NO TUVO ASISTENCIAS"<<endl;
        }
    }
}

void materiaMasAsistencias(int *vIngresos, char mNombres[][30]){
int matMaxAsistencias;
for (int i=0; i<20; i++){
    if (i==0){
        matMaxAsistencias = i;
    }else if (vIngresos[i]>vIngresos[i-1]){
        matMaxAsistencias = i;
    }

}
cout<<"LA MATERIA "<<mNombres[matMaxAsistencias]<<" FUE LA QUE TUVO MAYOR ASISTENCIA"<<endl;

}
void asistenciasXDiaAgosto(int mIngresosXDia[][31],char mNombres[][30]){

    for (int i=0; i<20;i++){
    cout<<"ASISTENCIAS POR DIA DE "<<mNombres[i]<<":"<<endl;
    for (int x=0;x<31;x++){
        cout<<"DIA "<<x+1<<": "<<mIngresosXDia[i][x]<<endl;
    }
    }
}

#endif // FUNCIONES_H_INCLUDED
