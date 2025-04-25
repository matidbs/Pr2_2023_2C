#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <ctime>

int generarNumeroAleatorio (){
int num;
    srand(time(NULL));
    for (int i=0;i<1 ;i++ ){
       num = rand()%9+1;}
        return num;
}

void dibujarTablero (int mTateti[][3]){
for (int x=0;x<3;x++){
        for (int y=0;y<3;y++){
            if (mTateti[x][y]==1){
                cout<<"X";
            } else if (mTateti[x][y]==2){
                cout<<"O";
            }else if (mTateti[x][y]==0){
                cout<<" ";
            }
            if (y!=2){
            cout<<" "<<char(179)<<" ";}
        }
        cout<<endl;
        if (x!=2){
        cout<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<endl;}
    }
}

void cargarOpcion (int opc,int m[][3],int cont){
    if (cont%2!=0){
    m[0][opc-1]=1;
    }else {
    m[0][opc-1]=2;
    }
}

int pedirOpcion (int i, int *vNum){
int jug,contIguales = 0;
    cout<<"Ingrese opcion: ";
    cin>>jug;
    return jug;
}

void verificarResultado (int mT[][3],bool *win){

int contHPj1=0,contHPj2=0;
int contVPj1=0,contVPj2=0;

//Contador Horizontal
for (int i=0;i<3;i++){
for (int x=0;x<3;x++){

    if (mT[i][x]==1){
        contHPj1++;
    }
    if (mT[i][x]==2){
        contHPj2++;
    }

}
    if (contHPj1==3){
    system("cls");
    cout<<"GANA X"<<endl;
    dibujarTablero(mT);
    *win = true;
}
    if (contHPj2==3){
    system("cls");
    cout<<"GANA O"<<endl;
    dibujarTablero(mT);
    *win = true;
}
contHPj1=0;
contHPj2=0;
} //For Externo


//Contador Vertical
for (int i=0;i<3;i++){
    for (int x=0;x<3;x++){

    if (mT[x][i]==1){
        contVPj1++;
    }
    if (mT[x][i]==2){
        contVPj2++;
    }
}
    if (contVPj1==3){
    system("cls");
    cout<<"GANA X"<<endl;
    dibujarTablero(mT);
    *win = true;
    }
    if (contVPj2==3){
    system("cls");
    cout<<"GANA O"<<endl;
    dibujarTablero(mT);
    *win = true;
    }
contVPj1=0;
contVPj2=0;
}

//Contador diagonal
if (mT[0][0]==1&&mT[1][1]==1&&mT[2][2]==1){
    system("cls");
    cout<<"GANA X"<<endl;
    dibujarTablero(mT);
    *win = true;
}
if (mT[0][2]==1&&mT[1][1]==1&&mT[2][0]==1){
    system("cls");
    cout<<"GANA X"<<endl;
    dibujarTablero(mT);
    *win = true;
}

if (mT[0][0]==2&&mT[1][1]==2&&mT[2][2]==2){
    system("cls");
    cout<<"GANA O"<<endl;
    dibujarTablero(mT);
    *win = true;
}
if (mT[0][2]==2&&mT[1][1]==2&&mT[2][0]==2){
    system("cls");
    cout<<"GANA O"<<endl;
    dibujarTablero(mT);
    *win = true;
}
}

void dosJugadores (int opcJug, int mTateti[][3]){
bool win=false;
int contIguales = 0;
int vNum[9]={0};

    for (int i=1;i<=9;i++){
    while (true){
    contIguales = 0;
    dibujarTablero(mTateti);
    opcJug = pedirOpcion(i,vNum);
    for (int x=0;x<9;x++){
        if (opcJug==vNum[x]){
            contIguales++;
        }
    }
    if (contIguales==0&&opcJug<=9){
        vNum [i] = opcJug;
        break;
    }
    system("cls");
    }
    cargarOpcion(opcJug,mTateti,i);
    verificarResultado(mTateti,&win);

    if (win==true){
        system("pause");
        break;
    }
    system("cls");
    }
    if (win!=true){
        dibujarTablero(mTateti);
        system("pause");
    }
}

void unJugador(int opcJug, int mTateti[][3]){
bool win=false;
int vNum[9]={0};
int contIguales = 0;

    for (int i=1;i<=9;i++){
    if (i%2!=0){
    while (true){
    contIguales = 0;
    dibujarTablero(mTateti);
    opcJug = pedirOpcion(i,vNum);
    for (int x=0;x<9;x++){
        if (opcJug==vNum[x]){
            contIguales++;
        }
    }
    if (contIguales==0&&opcJug<=9){
        vNum [i] = opcJug;
        break;
    }
    system("cls");
    }
    }
    if (i%2==0){
    while (true){
    contIguales = 0;
    dibujarTablero(mTateti);
    opcJug = generarNumeroAleatorio();
    for (int x=0;x<9;x++){
        if (opcJug==vNum[x]){
            contIguales++;
        }
    }
    if (contIguales==0){
        vNum [i] = opcJug;
        break;
    }
    system("cls");
    }
    }
    cargarOpcion(opcJug,mTateti,i);
    verificarResultado(mTateti,&win);
    if (win==true){
        system("pause");
        break;
    }
    system("cls");
    }
}

#endif // FUNCIONES_H_INCLUDED
