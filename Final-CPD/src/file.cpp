#include "../Include/Registro.h"
#include "../Include/trie.h"

#define NUM_ARQ 2       //Número de arquivos de entrada
#define REG_BIN "binarios/registros.bin"

using namespace std;

void HandleInputFiles(){
    Trie trie;
    int i;
    long index = 0;
    string linha, aux;
    ifstream entrada;
    vector <string> NamesFiles({"Lista_Avengers.csv", "Lista_Daredevil.csv", "Lista_Fantastic-Four.csv",
                                "Lista_Spider-Man.csv", "Lista_X-Men.csv", "Planilha_Comics.xlsx"});

    for(i=0;i<NUM_ARQ;i++){
        aux = "Data/"+NamesFiles[i];
        entrada.open(aux);
        if(!entrada.is_open()){
            cerr << "Could not open the file - '"
             << aux << "'" << endl;
            exit(EXIT_FAILURE);
        }
        getline(entrada, linha);             //despreza a primeira linha
        while (getline(entrada, linha)){     // Le linha a linha
            Registro reg(linha);             // Cria registro
            trie.saveTrie(reg.getIssue(), reg_to_bin(reg));   //adiciona na trie
            //ArqInv                         //adiciona no arquivo invertido

            ///std::cout << reg << endl;        //debug

            index++;
        }
        entrada.close();
    }
    trie.searchByName("Daredevil Vol 1 1");
}

long reg_to_bin(Registro reg){
    fstream regBin(REG_BIN);
    if(!regBin.is_open()){
            cerr << "Could not open the file - '"
             << REG_BIN << "'" << endl;
            exit(EXIT_FAILURE);
        }
    regBin.write((char*)&reg, sizeof(reg));
    return (long)regBin.tellg();
}
