#include "../Include/Registro.h"
#include "../Include/trie.h"

#define NUM_ARQ 1       //Número de arquivos de entrada
#define REG_BIN "binarios/registros.bin"

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

    for(i=0;i<NUM_ARQ;i++){
///------------------------------------------------------------
        aux = "binarios/" + NamesFiles[i] + "/" + "reg_" + NamesFiles[i]+".bin";
        regBin.open(aux, fstream::in | fstream::out | fstream::binary);
        if(!regBin.is_open()){
            cerr << "Could not open the file - '"
             << aux << "'" << endl;
            exit(EXIT_FAILURE);
        }
///------------------------------------------------------------
        aux = "binarios/" + NamesFiles[i] + "/" + "trie_" + NamesFiles[i]+".bin";
        trieBin.open(aux, fstream::in | fstream::out | fstream::binary);
        if(!regBin.is_open()){
            cerr << "Could not open the file - '"
             << aux << "'" << endl;
            exit(EXIT_FAILURE);
        }

        trieBin.seekg(0, trieBin.end);
        file_size = trieBin.tellg();
        trieBin.seekg(0, trieBin.beg);

        if(lerDadosBrutos || file_size == 0){
            aux = "data/"+NamesFiles[i]+".csv";
            entrada.open(aux, fstream::in);
            if(!entrada.is_open()){
                cerr << "Could not open the file - '"
                 << aux << "'" << endl;
                exit(EXIT_FAILURE);
            }
            getline(entrada, linha);             //despreza a primeira linha
            while (getline(entrada, linha)){     // Le linha a linha
                Registro reg(linha);             // Cria registro
                trie.saveTrie(reg.getIssue(), reg_to_bin(reg, regBin), trieBin);   //adiciona na trie
                //ArqInv                         //adiciona no arquivo invertido
                cout << reg.getIssue() << " | " << aux << endl;        //debug
            }
            if(trie.searchByName("Avengers Vol 1 14", trieBin), regBin)
                cout << "achou" << endl;
        }
        entrada.close();
        regBin.close();
        trieBin.close();
    }
}

long reg_to_bin(Registro reg, fstream& regBin){
    long file_position =(long)regBin.tellg();
    regBin.write((char*)&reg, sizeof(reg));
    return file_position;
}
