#ifndef TRIE_H
#define TRIE_H

#include "../include/Registro.h"
#include <iostream>

#define NAME_MAX 200

using namespace std;

// Define the character size
#define CHAR_SIZE 128

// A class to store a Trie node
typedef unsigned long long int ullint;

class Trie
{
public:
    long file_position;
    char letter;

    long left_pos;
    long son_pos;
    long right_pos;

    void save_trie_tree(char name[NAME_MAX], long position, FILE *trie_tree);

    // Constructor
    /*Trie(){
        index = 0;
        this->isLeaf = false;
        for (int i = 0; i < CHAR_SIZE; i++)
            this->character[i] = nullptr;
    }



    void insert(string);
    bool deletion(Trie*&, string);
    bool search(string);
    bool haveChildren(Trie const*);*/
};

#endif // TRIE_H
