#include "../Include/ArqInv.h"
#include <iostream>
#include <fstream>

#define PREVIOUS 0
#define CURRENT 1
#define POSTERIOR 2
#define POSITION 3

using namespace std;

void ArqInv::InsertionInvArq(Registro reg, string NameFile){

    fstream arq_inv("../" + NameFiles + "/arq_inv.bin", ofstream::binary);
    invWriter auxW[POSITION];
    invIssue auxI[POSITION];
    //int issuePtr[POSITION], writerPtr[POSITION];
    //int prox_issue[POSITION];
    bool address_void;
    int adress[POSITION];

    if(arq_inv.is_open()){
        while(arq_inv.eof()){ //enquanto o arq estiver aberto
            if(arq_inv.read((char*)auxW[CURRENT],sizeof(invWriter))){//se o arq não estiver vazio
                if(auxW[CURRENT].code=="0"){
                    if(auxW[CURRENT].writer == reg.writer){ //se for o mesmo writer
                        if(auxW[CURRENT].issuePtr == -1) //se o endereço está vazio
                            address_void = true;
                        if(address_void){

                        }
                        else{   //endereço não está vazio
                            arq_inv.seekg(auxW[CURRENT].issuePtr);
                            arq_inv.read((char*)aux)
                        }

                    }
                    else{

                    }

                }
                else{

                }
            }
            else{
                aux = "0-"+reg.writer;
                arq_inv.write(aux, sizeof(string)*aux.length);
                address_void[0] = arq_inv.tellg(); //possível erro de tipos

            }
        }
    }
}

