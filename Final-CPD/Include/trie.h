#ifndef TABELASHASH_H
#define TABELASHASH_H

#include "../include/Registro.h"
#include <iostream>

using namespace std;

// Define the character size
#define CHAR_SIZE 128

// A class to store a Trie node
typedef unsigned long long int ullint;

class Trie
{
public:
    bool isLeaf;
    Trie* character[CHAR_SIZE];
    ullint index;

    // Constructor
    Trie(){
        index = 0;
        this->isLeaf = false;
        for (int i = 0; i < CHAR_SIZE; i++)
            this->character[i] = nullptr;
    }

    void insert(string);
    bool deletion(Trie*&, string);
    bool search(string);
    bool haveChildren(Trie const*);
};

#endif // TABELAHASH_H
