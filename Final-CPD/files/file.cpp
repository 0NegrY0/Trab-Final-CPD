#include <iostream>
#include <fstream>

#include "../Include/Registro.h"
#include "../Include/TabelaHash.h"

#define NUM_ARQ 2

void HandleInputFiles(){
    int i;
    std::string linha;
    std::vector<Registro> data_in[NUM_ARQ];
    std::vector <std::ifstream *> entrada;

    std::ifstream aux("Data/Lista_Avengers.csv"); // Abre arquivo de entrada
    entrada.push_back(&aux);
    aux.close();
    aux.open("Data/Daredevil.csv");
    entrada.push_back(&aux);

    for(i=0;i<NUM_ARQ;i++)
        while (std::getline(*(entrada[i]), linha))   // Le linha a linha
        {
            Registro reg(linha);             // Cria registro
            data_in[i].push_back(reg);    // Coloca num vetor de registros
        }

}
