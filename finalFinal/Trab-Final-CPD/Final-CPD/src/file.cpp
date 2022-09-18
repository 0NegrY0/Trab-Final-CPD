#include "../include/Registro.h"
#include "../include/trie.h"
#include "../include/ordenar.h"

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

#define NUM_ARQ 5       //Numero de arquivos de entrada
#define REG_BIN "binarios/registros.bin"
#define TRIE_BIN "binarios/trie.bin"

int primeira = 1;

using namespace std;

void HandleInputFiles(){
    bool lerDadosBrutos = true;
    Registro reg;
    int i, file_size;
    string linha, aux;
    ifstream entrada;
    fstream regBin, trieBin;
    vector <string> NamesFiles({"Lista Avengers", "Lista Daredevil", "Lista Fantastic Four",
                                "Lista Spider-Man", "Lista X-Men"});

    regBin.open(REG_BIN, fstream::in | fstream::out | fstream::binary);
    if(!regBin.is_open()){
        cerr << "Could not open the file - '" << REG_BIN << "'" << endl;
        exit(EXIT_FAILURE);
    }
    trieBin.open(TRIE_BIN, fstream::in | fstream::out | fstream::binary);
    if(!regBin.is_open()){
        cerr << "Could not open the file - '" << TRIE_BIN << "'" << endl;
        exit(EXIT_FAILURE);
    }
    trieBin.seekg(0, trieBin.end);
    file_size = trieBin.tellg();

    trieBin.seekg(0, trieBin.beg);
    regBin.seekg(0,regBin.beg);

    if(lerDadosBrutos || file_size == 0){
        for(i=0;i<NUM_ARQ;i++){
            aux = "data/"+NamesFiles[i]+".csv";
            entrada.open(aux, fstream::in);
            if(!entrada.is_open()){
                cerr << "Could not open the file - '" << aux << "'" << endl;
                exit(EXIT_FAILURE);
            }
            getline(entrada, linha);             //despreza a primeira linha
            while(getline(entrada, linha)){     // Le linha a linha
                csv_to_reg(reg, (char*)linha.c_str());             // Cria registro
                ///cout << reg.issue << " | " << aux << endl;        //debug
                saveTrie(reg.issue, writeRegBin(reg, regBin), trieBin);   //adiciona na trie
                //ArqInv                         //adiciona no arquivo invertido
            }
            entrada.close();
        }
    }
    searchByIssue("Avengers Vol 1 2", trieBin, regBin);
    regBin.close();
    trieBin.close();
}

long writeRegBin(Registro reg, fstream& regBin){
    long file_position = regBin.tellg();
    regBin.write((char*)&reg, sizeof(Registro));
    
    
    insertion(reg.release_date, file_position, primeira);
    primeira = 0;
    
    
    return file_position;
}

void readRegBin(Registro& reg, long file_position, fstream& regBin){
    regBin.seekg(file_position, regBin.beg);
    regBin.read((char*)&reg, sizeof(Registro));
}