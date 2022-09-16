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
    fstream regBin, trieBin;
    vector <string> NamesFiles({"Lista_Avengers", "Lista_Daredevil", "Lista_Fantastic-Four",
                                "Lista_Spider-Man", "Lista_X-Men"});

    for(i=0;i<NUM_ARQ;i++){
///------------------------------------------------------------
        aux = "Data/"+NamesFiles[i]+".csv";
        entrada.open(aux);
        if(!entrada.is_open()){
            cerr << "Could not open the file - '"
             << aux << "'" << endl;
            exit(EXIT_FAILURE);
        }
///------------------------------------------------------------

        aux = "binarios/" + NamesFiles[i] + "/" + "reg_" + NamesFiles[i]+".bin";
        regBin.open(aux);
        if(!regBin.is_open()){
            cerr << "Could not open the file - '"
             << aux << "'" << endl;
            exit(EXIT_FAILURE);
        }
///------------------------------------------------------------
        aux = "binarios/" + NamesFiles[i] + "/" + "trie_" + NamesFiles[i]+".bin";
        trieBin.open(aux);
        if(!regBin.is_open()){
            cerr << "Could not open the file - '"
             << aux << "'" << endl;
            exit(EXIT_FAILURE);
        }
///------------------------------------------------------------
        getline(entrada, linha);             //despreza a primeira linha
        while (getline(entrada, linha)){     // Le linha a linha
            Registro reg(linha);             // Cria registro
            trie.saveTrie(reg.getIssue(), reg_to_bin(reg, regBin), trieBin);   //adiciona na trie
            //ArqInv                         //adiciona no arquivo invertido
            ///std::cout << reg << endl;        //debug
            index++;
        }
        trie.searchByName("Avengers Vol 1 5", trieBin);
        entrada.close();
        regBin.close();
        trieBin.close();
    }
}

/*void init_files(string folder, string NameFile, string dot_ext){
    string aux;
    aux = folder + "/" + NameFiles + dot_ext;
    entrada.open(aux);
    if(!entrada.is_open()){
        cerr << "Could not open the file - '" << aux << "'" << endl;
        exit(EXIT_FAILURE);
    }
}*/

long reg_to_bin(Registro reg, fstream& regBin){
    long file_position =(long)regBin.tellg();
    regBin.write((char*)&reg, sizeof(reg));
    return file_position;
}
