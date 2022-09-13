#include <iostream>
#include <fstream>
#include <sstream>
#include "../Include/Registro.h"

#define NUM_ARQ 2

using namespace std;

void HandleInputFiles(){
    int i;
    string linha;
    vector<Registro> data_in[NUM_ARQ];
    vector <ifstream> entrada;
    vector <string> NamesFiles({"Lista_Avengers.csv", "Daredevil.csv", "Lista_Fantastic-Four.csv",
                                "Lista_Spider-Man.csv", "Lista_X-Men.csv", "Planilha_Comics.xlsx"});

    for(i=0;i<NUM_ARQ;i++)
        entrada[i].open("Data/"+NamesFiles[i]);
        while (getline(entrada[i], linha))      // Le linha a linha
        {
            Registro reg(linha);                // Cria registro
            data_in[i].push_back(reg);          // Coloca num vetor de registros
        }
}
