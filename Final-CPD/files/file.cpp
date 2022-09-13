#include <iostream>
#include <fstream>

#include "../Include/Registro.h"
#include "../Include/TabelaHash.h"

#define NUM_ARQ 2

void HandleInputFiles(){
    int i;
    std::string linha;
    std::vector<Registro> data_in[NUM_ARQ];
    std::vector <std::ifstream> entrada;
    std::vector <std::string> NamesFiles({"Lista_Avengers.csv", "Daredevil.csv", "Lista_Fantastic-Four.csv",
                                    "Lista_Spider-Man.csv", "Lista_X-Men.csv", "Planilha_Comics.xlsx"});

    for(i=0;i<NUM_ARQ;i++)
        entrada[i].open("Data/"+NamesFiles[i]);
        while (std::getline(entrada[i], linha))  // Le linha a linha
        {
            Registro reg(linha);                    // Cria registro
            data_in[i].push_back(reg);              // Coloca num vetor de registros
        }

}


void separaLinha(std::string Linha){

    std::vector<std::string> tokens;            //vetor de string para salvar os tokens

    std::stringstream check(Linha);         //stringstream class check

    std::string intermed;                       //criação de uma string intermediária

    while(getline(check, intermed, ';')){
        tokens.push_back(intermed);
    }
}
