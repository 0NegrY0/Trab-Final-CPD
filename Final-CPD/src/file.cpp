#include "../Include/Registro.h"
#include "../Include/trie.h"

#define NUM_ARQ 5       //Número de arquivos de entrada
#define REG_BIN "binarios/registros.bin"
#define TRIE_BIN "binarios/trie.bin"

using namespace std;

void HandleInputFiles(){
    bool lerDadosBrutos = true;
    Trie trie;
    int i, file_size;
    string linha, aux;
    ifstream entrada;
    fstream regBin, trieBin;
    vector <string> NamesFiles({"Lista_Avengers", "Lista_Daredevil", "Lista_Fantastic-Four",
                                "Lista_Spider-Man", "Lista_X-Men"});

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
                Registro reg(linha);             // Cria registro
                trie.saveTrie(reg.getIssue(), reg_to_bin(reg, regBin), trieBin);   //adiciona na trie
                //ArqInv                         //adiciona no arquivo invertido
                cout << reg.getIssue() << " | " << aux << endl;        //debug
            }
            entrada.close();
        }
    }
    regBin.close();
    trieBin.close();
}

long reg_to_bin(Registro reg, fstream& regBin){
    long file_position =(long)regBin.tellg();
    regBin.write((char*)&reg, sizeof(reg));
    return file_position;
}
