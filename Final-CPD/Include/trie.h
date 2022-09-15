#ifndef TRIE_H
#define TRIE_H

#include "../include/Registro.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <bits/types/FILE.h>  //TALVEZ MUDAR DPS

#define BUFFER_MAX 400
#define NAME_MAX 200

using namespace std;


class Trie
{
	public:
		
		void saveTrie(char name[NAME_MAX], long position, FILE *trie_tree);
		void searchByName(char nomeProcurado[NAME_MAX]);
	
	

	private:
		typedef struct{
		
			long file_position;
			char letter;

			long left_pos;
			long son_pos;
			long right_pos;
		} Trie_node


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
