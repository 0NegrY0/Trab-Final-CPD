#include "../include/Registro.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;


void openLista(){
        fstream listaBin;
        listaBin.open("listaBin.bin", ios::out | ios::in | ios::binary);

}


long saveList(Registro data, fstream listaBin){

    long filePosition;
    filePosition = listaBin.tellg();

    listaBin.write(reinterpret_cast<char*>(&data), sizeof(Registro));

    
    return filePosition;
}

void closeLista(fstream listaBin){
    listaBin.close();
}
