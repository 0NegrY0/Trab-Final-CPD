#include "../include/Registro.h"


#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

void csv_to_reg(Registro& reg, char linha[]){
    int i=0;
    char* auxstr = new char [strlen(linha)+1];
    strcpy(auxstr, linha);

    char* cstr = strtok (auxstr,";");//Separador: ';'
    while (cstr!=0){
        switch(i%12){
            case 0:
                strcpy(reg.issue,cstr);
                break;
            case 1:
                strcpy(reg.type,cstr);
                break;
            case 2:
                strcpy(reg.story_title,cstr);
                break;
            case 3:
                strcpy(reg.storyline,cstr);
                break;
            case 4:
                strcpy(reg.event,cstr);
                break;
            case 5:
                strcpy(reg.cover_date,cstr);
                break;
            case 6:
                strcpy(reg.release_date,cstr);
                break;
            case 7:
                strcpy(reg.writer,cstr);
                break;
            case 8:
                strcpy(reg.penciler,cstr);
                break;
            case 9:
                strcpy(reg.main_characters,cstr);
                break;
            case 10:
                strcpy(reg.antagonists,cstr);
                break;
            case 11:
                strcpy(reg.supporting_characters,cstr);
                break;
        }
        cstr = strtok(NULL,";");
        i++;
    }
}

void printReg(Registro reg){
    cout << "Issue - " << reg.issue  << "\nType - " << reg.type << "\nStory Title - " << reg.story_title << "\nStoryLine - " << reg.storyline
    << "\nEvent - " << reg.event << "\nCover Date - " << reg.cover_date  << "\nRelease Date - " << reg.release_date
    << "\nWriter - " << reg.writer << "\nPenciler - " << reg.penciler << "\nMain characters - " << reg.main_characters
    << "\nAntagonists - " << reg.antagonists << "\nSupporting Characters - " << reg.supporting_characters << endl;
}