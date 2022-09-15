#ifndef TRIE_H
#define TRIE_H

#include "../include/Registro.h"
#include <iostream>
#include <cstdio>
#include <cstring>
//#include <bits/types/FILE.h>  //TALVEZ MUDAR DPS

#define BUFFER_MAX 400
#define NAME_MAX 200

using namespace std;


class Trie
{
	public:
	    void iniciaTrie();
		void saveTrie(char name[NAME_MAX], long position, fstream trieBin);
		void searchByName(char nomeProcurado[NAME_MAX], fstream trieBin);
	private:
		typedef struct{
			long file_position;
			char letter;

			long left_pos;
			long son_pos;
			long right_pos;
		} Trie_node;
};

#endif // TRIE_H
