#ifndef REGISTRO_H
#define REGISTRO_H

#include "ArqInv.h"
#include "trie.h"

#include <iostream>
#include <fstream>
#include <vector>

#define NAME_MAX 256

using namespace std;

typedef struct{
    char issue[NAME_MAX];
    char type[NAME_MAX];
    char story_title[NAME_MAX];
    char storyline[NAME_MAX];
    char event[NAME_MAX];
    char cover_date[NAME_MAX];
    char release_date[NAME_MAX];
    char writer[NAME_MAX];
    char penciler[NAME_MAX];
    char main_characters[NAME_MAX];
    char antagonists[NAME_MAX];
    char supporting_characters[NAME_MAX];
}Registro;


void HandleInputFiles();
void csv_to_reg(Registro& reg, char linha[]);
long writeRegBin(Registro reg, fstream& regBin);
void readRegBin(Registro& reg, long file_position, fstream& regBin);
void printReg(Registro reg);

#endif // REGISTRO_H