#ifndef REGISTRO_H
#define REGISTRO_H

#include "ArqInv.h"
#include "trie.h"

#include <iostream>
#include <fstream>
#include <vector>

class Registro
{
    public: // elementos que podem ser acessados externamente

        Registro(std::string str); // construtor

        ~Registro(); // destrutor

       std::string getIssue();
       std::string getType();
       std::string getStoryLine();
       std::string getEvent();
       std::string getCoverDate();
       std::string getReleaseDate();
       std::string getWriter();
       std::string getPenciler();
       std::string getMainCharacters();
       std::string getAntagonists();
       std::string getSupportingCharacters();

        // sobrecarrega operador de escrita para permitir impressao via streams (i.e. std::cout << registro)
        friend std::ostream& operator<<(std::ostream& os, const Registro& reg);

    private: // elementos que somente podem ser acessados dentro da classe
        typedef struct reg{
            std::string issue;
            std::string type;
            std::string story_title;
            std::string storyline;
            std::string event;
            std::string cover_date;
            std::string release_date;
            std::string writer;
            std::string penciler;
            std::string main_characters;
            std::string antagonists;
            std::string supporting_characters;
            
            long id;
            long position;
        }reg;
};

void HandleInputFiles();
long reg_to_bin(Registro reg);

#endif // REGISTRO_H
