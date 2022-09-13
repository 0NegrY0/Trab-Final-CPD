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
    
     //debug/////////////////////////////////////////

    for(int i = 0; i < tokens.size(); i ++){
        std::cout << tokens[i] << '\n'; 
    }

    ////////////////////////////////////////////////

    for(int i = 0; i < tokens.size(); i ++){
        switch(i%12){
            case 0:
                strcpy(Registro.issue, tokens[i]);
                 break;
            case 1:
                strcpy(Registro.type, tokens[i]);
                break;
            case 2:
                strcpy(Registro.story_title, tokens[i]);
                break;
            case 3:
                strcpy(Registro.storyline, tokens[i]);
                break;

            case 4:
                strcpy(Registro.event, tokens[i]);
                break;
            case 5:
              strcpy(Registro.cover_data, tokens[i]);
                break;
            case 6:
              strcpy(Registro.release_date, tokens[i]);
                break;
            case 7:
               strcpy(Registro.writer, tokens[i]);
                break;
            case 8:
               strcpy(Registro.penciler, tokens[i]);
                break;
            case 9:
              strcpy(Registro.main_characters, tokens[i]);
                break;
            case 10:
              strcpy(Registro.antagonists, tokens[i]);
                break;
            case 11:
               strcpy(Registro.supporting characters, tokens[i]);
                break;
    }
}
}
