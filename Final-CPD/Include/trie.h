#ifndef TRIE_H
#define TRIE_H

#include "../include/Registro.h"
#include <iostream>
#include <cstdio>
#include <cstring>

#define BUFFER_MAX 400
#define NAME_MAX 200

using namespace std;

class Trie
{
	public:
		void saveTrie(string Issue, long position, fstream& trieBin);
		void searchByName(string Issue, fstream& trieBin);
	private:
		typedef struct{
			long file_position;
			char letter;
			long left_pos;
			long son_pos;
			long right_pos;
		} Trie_node;
		long insertBin();
};

#endif // TRIE_H
