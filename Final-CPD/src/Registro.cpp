#include "../include/Registro.h"

#include <iostream>
#include <sstream>

//////////////////////////////////
/// CONSTRUTORES E DESTRUTORES ///
//////////////////////////////////

Registro::Registro(std::string linha)
{
    std::vector<std::string> row;
    std::string word;

    std::istringstream iss(linha);
    while (getline(iss, word, ';')) {
        row.push_back(word);
    }
    
    issue = row[0];

    type = row[1];

    story_tile = row[2];

    storyline = row[3];

    event = row[4];

    cover_date = row [5];

    release_date = row [6];

    writer = row [7];

    penciler = row[8];

    main_characters = row[9];

    antagonists = row[10];

    supporting_characters = row [11];
    
}

Registro::~Registro()
{
    //destrutor
}

/// GET
std::string Registro::getIssue()
{
    return issue;
}

std::string Registro::getType()
{
    return type;
}

std::string Registro::getStoryLine()
{
    return storyline;
}

std::string Registro::getEvent()
{
    return event;
}

std::string Registro::getCoverDate()
{
    return cover_date;
}
std::string Registro::getReleaseDate()
{
    return release_date;
}
std::string Registro::getWriter()
{
    return writer;
}
std::string Registro::getPenciler()
{
    return penciler;
}
std::string Registro::getMainCharacters()
{
    return main_characters;
}
std::string Registro::getAntagonists()
{
    return antagonists;
}
std::string Registro::getSupportingCharacters()
{
    return supporting_characters;
}



/// IMPRESSAO
std::vector<std::string> strPOSICAO = {"GOL", "ZAG", "LESQ", "LDIR", "VOL", "MESQ", "MCEN", "MDIR", "MOFE", "PESQ", "PDIR", "2ATA", "CA"};

std::ostream& operator<<(std::ostream& os, const Registro& reg)
{
    os << "-> " << reg.nome << " | " << strPOSICAO[reg.posicao] << " | clube: " << reg.clube << std::endl
    << "   idade: " << reg.idade << " | nac: " << reg.nacionalidade << " | valor " << reg.valor << " mi EUR";
    return os;
}
