#ifndef TRIE_H
#define TRIE_H

#include "../include/Registro.h"
#include <iostream>
#include <cstdio>
#include <cstring>

#define NAME_MAX 256

using namespace std;

typedef struct{
    long file_position;
    char letter;
    long left_pos;
    long son_pos;
    long right_pos;
} Trie_node;

void saveTrie(char name[], long position, fstream& trieBin);
void searchByIssue(char nomeProcurado[], fstream& trieBin, fstream& regBin);
void teste(Trie_node search_node, fstream& trieBin, fstream& regBin);
#endif // TRIE_H