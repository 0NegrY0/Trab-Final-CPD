#include "../include/Registro.h"

#include <iostream>
#include <sstream>

//////////////////////////////////
/// CONSTRUTORES E DESTRUTORES ///
//////////////////////////////////

Registro::Registro(std::string linha)
{
    std::vector<std::string> tokens;              //vetor de string para salvar os tokens
    std::stringstream check1(linha);          //stringstream class check
    std::string aux;                         //criação de uma string intermediária

    while(getline(check1, aux, ';')){    //Separador: ';'
        tokens.push_back(aux);          //armezena os tokens no vector de string tokens
    }
    for(int i = 0; i < tokens.size(); i ++){
        switch(i%12){
            case 0:
                issue = tokens[i];
                break;
            case 1:
                type = tokens[i];
                break;
            case 2:
                story_title = tokens[i];
                break;
            case 3:
                storyline = tokens[i];
                break;
            case 4:
                event = tokens[i];
                break;
            case 5:
                cover_date = tokens[i];
                break;
            case 6:
                release_date = tokens[i];
                break;
            case 7:
                writer = tokens[i];
                break;
            case 8:
                penciler = tokens[i];
                break;
            case 9:
                main_characters = tokens[i];
                break;
            case 10:
                antagonists = tokens[i];
                break;
            case 11:
                supporting_characters = tokens[i];
                break;
        }
    }
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
