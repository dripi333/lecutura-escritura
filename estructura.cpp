#include <iostream>
#include <string>
#include <fstream>
//#include <cstring>
//#include <sstream>
#include "estructura.h"
using namespace std;

 char dem = ';';
void libreria::leer()
{
    FILE *pf;
    fstream archivo;
    //ofstream fs("libreria.csv");
    string texto;

    archivo.open("libreria.csv",ios::in);


    if(archivo.fail()){
        cout<<"No abre, creando archivo...";
        exit(1);
    }

    while(!archivo.eof()){
            getline(archivo,texto,';');
    cout <<texto<<" ";
    }
    /*pf = fopen("libreria.csv","r+");
    fseek(pf,99,SEEK_SET);
    fputs(" Hola",pf);
    fclose(pf);*/
    archivo.close();

}

void libreria::escribir()
    {
    fstream archivo;
    archivo.open("libreria.csv",ios::app);

    if(archivo.fail()){
        cout <<"No abre";
        exit(1);
    }
    libros l;
    cout<<"Ingrese el numero de libro"<<endl;
    cin>>l.num;
    cin.clear();
    cin.ignore();
    cout<<"Ingrese el titulo"<<endl;
    getline(cin,l.titulo);
    cout<<"Ingrese el autor"<<endl;
    getline(cin,l.autor);
    cout<<"Ingrese la editorial"<<endl;
    getline(cin, l.editorial);

    char opc;

    cout << "Guardar? s/n: " <<endl;
    cin >> opc;

    if(opc == 's' or opc == 'S'){
        archivo<<l.num<<dem<<l.titulo<<dem<<l.autor<<dem<<l.editorial<<"\n";
        cout << "Registro guardado"<<endl;
        archivo.close();
        libreria::menu();
    }else{
        cout<<"No se guardo"<<endl;
        libreria::menu();
    }
}

void libreria::menu()
{
    int opc;
    do{
            cout<<"\n\n";
    cout<<"1. Mostrar registros"<<endl;
    cout<<"2. Registrar"<<endl;
    cout<<"3. Salir"<<endl;
    cout <<"4. Buscar" <<endl;
    cout<<"Seleccione una opcion: ";

    cin >> opc;
    cin.clear();
    cin.ignore();


    switch (opc){
    case 1:
        libreria::leer();
        break;
    case 2:
        libreria::escribir();
        break;
    case 0:
        exit(1);
    case 4:
        libreria::buscar();
        break;
    }
    }while(opc != 0);
}
void libreria::buscar(){

    fstream archivo;
    string l;
    string x;

    cout << "Ingrese el id a buscar"<<endl;
    cin >> x;
    cin.clear();
    cin.ignore();
    archivo.open("libreria.csv", ios::in|ios::out);
    while(getline(archivo, l)){
        if(l.find(x) != string::npos){
            cout << l <<endl;

        }
    }

}

/*bool libreria::abrir(fstream x)
{
    fstream archivo = x;

    archivo.open("libreria.csv",ios::in|ios::out);
    if(archivo.fail()){
        return true;
    }
    return false;
}*/




