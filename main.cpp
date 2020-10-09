#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "estructura.h"

using namespace std;

void leer();
int main(){
    libreria l;

    cout<<"Datos registrados hasta el momento: "<<endl;
    l.leer();

    l.menu();


    return 0;
}

