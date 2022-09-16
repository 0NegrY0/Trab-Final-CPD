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

Registro leLista(long fileId, fstream listaBin){
    bool found = false;
    reg procurado;

    while( !found )
    {
        listaBin.read((char *)&procurado, sizeof procurado);
        if( listaBin.eof() )  // eof bit gets set only after EOF is read from file
        break;

        if(procurado.id = fileId)     //MUDAR
        {
        // handle found record
        found = true;
        }
    }
    if( !found )
    {
        cerr << "Could not find the id - " << filePosition << "on the list" << endl;
        exit(EXIT_FAILURE);
    }
    else{
        std::cout << procurado << endl;
    }

}


void closeLista(fstream listaBin){
    listaBin.close();
}
