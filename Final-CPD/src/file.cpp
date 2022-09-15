#include "../Include/Registro.h"

#define NUM_ARQ 2       //Número de arquivos de entrada

using namespace std;

void HandleInputFiles(){
    int i, index = 0;
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
            Registro reg(linha);                // Cria registro
            //trie                              //adiciona na trie
            //ArqInv                            //adiciona no arquivo invertido

            ///std::cout << reg << endl;        //debug

            index++;
        }
        entrada.close();
    }

}
