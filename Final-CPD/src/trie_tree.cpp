#include <bits/types/FILE.h>
#include <cstddef>
#include <cstdio>
#include <ios>
#include <istream>
#include <string.h>
#include <fstream>
#include <iostream>


#define BUFFER_MAX 400
#define NAME_MAX 200

using namespace std;

typedef struct{
    long file_position;
    char letter;

    long left_pos;
    long son_pos;
    long right_pos;
} Trie_node;

int iniciaTrie(){
    fstream trieBin;
    trieBin.open("trieBin.bin", ios::out | ios::in | ios::binary);

    if(trieBin.is_open()){
        return 0;
    }
    else{
        cout << "Erro ao abrir arquivo\n";
        return 1;
    }
}

void saveTrie(char name[NAME_MAX], long position, FILE *trie_tree, fstream trieBin){

    Trie_node search_node;

    Trie_node son_node;

    int file_size;
    int i = 0;
    int flag = 0;
    int erro;

    long son_position;
    long search_node_position;

    //DEIXAR LETRA EM MAIUSCULO
    strdup(name);

    erro = iniciaTrie();


    //verifica se o arquivo esta vazio

    
    //fseek(trie_tree, 0, SEEK_END);
    trieBin.seekg(0, trieBin.end);

    //file_size = ftell(trie_tree);
    file_size = trieBin.tellg();


    // Se o arquivo ja tiver nodos, e preciso buscar a posicao correta de insercao.
    // Caso contrario, a insercao e feita diretamente
    if(file_size != 0){
        //fseek(trie_tree, 0, SEEK_SET);
        trieBin.seekg(0, trieBin.beg);


        while(flag == 0 && name[i] != '\0'){
            //search_node_position = ftell(trie_tree);
            search_node_position = trieBin.tellg();
            

////////////////////////////////////////////////////////////////////////////////////////////////////////////

            //fread(&search_node, sizeof(Trie_node), 1, trie_tree);
            
            trieBin.read(reinterpret_cast<char*>(&search_node), sizeof(Trie_node));  

////////////////////////////////////////////////////////////////////////////////////////////////////////////


            // Caso a letra buscada coincida com a letra avaliada no nodo
            if(name[i] == search_node.letter){
                i++;

                // Se o nodo possuir filhos, a busca continua
                if(search_node.son_pos != -1){
                    //fseek(trie_tree, search_node.son_pos, SEEK_SET);
                    trieBin.seekg(search_node.son_pos, trieBin.beg);

                // Caso contrario, o filho e atualizado e passa-se a inserir o restante do nome na arvore
                } 
                
                else {
                    if(name[i] != '\0'){
                        //fseek(trie_tree, 0, SEEK_END);
                        trieBin.seekg(0, trieBin.end);

                        //search_node.son_pos = ftell(trie_tree);
                        search_node.son_pos = trieBin.tellg();

                        //fseek(trie_tree, search_node_position, SEEK_SET);
                        trieBin.seekg(search_node_position, trieBin.beg);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
                        //fwrite(&search_node, sizeof(Trie_node), 1, trie_tree);
                        trieBin.write(reinterpret_cast<char*> (&search_node), sizeof(Trie_node));
////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        //fseek(trie_tree, 0, SEEK_END);
                        trieBin.seekg(0, trieBin.end);
                    }

                    flag = 1;
                }
            // Caso a letra buscada venha antes da letra avaliada no nodo
            }
            
            else if(name[i] < search_node.letter){
                // Se o nodo possuir algum nodo a esquerda, a busca continua
            
                if(search_node.left_pos != -1){
                    //fseek(trie_tree, search_node.left_pos, SEEK_SET);
                    trieBin.seekg(search_node.left_pos, trieBin.beg);

                // Caso contrario, o nodo e atualizado e passa-se a inserir o restante do nome na arvore
                }
                
                else {
                    if(name[i] != '\0'){
                        //fseek(trie_tree, 0, SEEK_END);
                        trieBin.seekg(0, trieBin.end);

                        //search_node.left_pos = ftell(trie_tree);
                        search_node.left_pos = trieBin.tellg();


                        //fseek(trie_tree, search_node_position, SEEK_SET);
                        trieBin.seekg(search_node_position, trieBin.beg);


                        //fwrite(&search_node, sizeof(Trie_node), 1, trie_tree);
                        trieBin.write(reinterpret_cast<char*> (&search_node), sizeof(Trie_node));







                        //fseek(trie_tree, 0, SEEK_END);
                        trieBin.seekg(0, trieBin.end);
                    }

                    flag = 1;
                }
            // Caso a letra buscada venha depois da letra avaliada no nodo
            }
            
            else {
                
                // Se o nodo possuir algum nodo a direita, a busca continua
                if(search_node.right_pos != -1){
                    //fseek(trie_tree, search_node.right_pos, SEEK_SET);
                    trieBin.seekg(search_node.right_pos, trieBin.beg);
                // Caso contrario, o nodo e atualizado e passa-se a inserir o restante do nome na arvore
                }
                
                else {
                    if(name[i] != '\0'){
                        //fseek(trie_tree, 0, SEEK_END);
                        trieBin.seekg(0, trieBin.end);

                        //search_node.right_pos = ftell(trie_tree);
                        search_node.right_pos = trieBin.tellg();

                        //fseek(trie_tree, search_node_position, SEEK_SET);
                        trieBin.seekg(search_node_position, trieBin.beg);





                        //fwrite(&search_node, sizeof(Trie_node), 1, trie_tree);
                        trieBin.write(reinterpret_cast<char*> (&search_node), sizeof(Trie_node));








                        //fseek(trie_tree, 0, SEEK_END);
                        trieBin.seekg(0, trieBin.end);
                    }

                    flag = 1;
                }
            }
        }

        //fseek(trie_tree, 0, SEEK_END);      // vai para o final do arquivo para que as proximas letras possam ser inseridas
        trieBin.seekg(0, trieBin.end);
    }

    // Insercao do nome ou do resto dele
    while(name[i] != '\0'){
        // Seta as informacoes para cada novo nodo
        son_node.letter = name[i];
        //son_position = ftell(trie_tree);
        son_position = trieBin.tellg();

        // Verifica se e um nodo terminal ou nao
        if(i == strlen(name) - 1){
            son_node.file_position = position;
            son_node.son_pos = -1;
        }
        
        else {
            son_node.file_position = -1;
            son_node.son_pos = son_position + sizeof(Trie_node);
        }

        son_node.left_pos = -1;
        son_node.right_pos = -1;










        // Escreve o nodo no arquivo
        //fwrite(&son_node, sizeof(Trie_node), 1, trie_tree);
        trieBin.write(reinterpret_cast<char*> (&son_node), sizeof(Trie_node));


        i++;
    }

    trieBin.close();

}



void searchByName(char nomeProcurado[NAME_MAX], fstream trieBin){

    // -> VARIAVEIS
    FILE *trie_tree;

    Trie_node search_node;

    int flag = 0;
    int i = 0;
    int erro;


    strdup(nomeProcurado);       // transforma todas as letras do nome para maiusculo

    /*trie_tree = fopen("dados/trie_tree_names.bin", "rb");

    if(trie_tree == NULL){
        printf("Erro ao abrir o arquivo 'trie_tree.bin'\n");

    }*/

    erro = iniciaTrie();

    if(!(trieBin.is_open())){
        printf("Erro ao abrir o arquivo 'trie_tree.bin'\n");
    }
    
    else {
        // O prefixo ou nome e buscado na trie tree
        while(nomeProcurado[i] != '\0' && flag == 0){
            
            
            
            
            
            
            //fread(&search_node, sizeof(Trie_node), 1, trie_tree);
            trieBin.read(reinterpret_cast<char*>(&search_node), sizeof(Trie_node));  







         // Caso a letra buscada no prefixo coincida com a letra avaliada no nodo
            if(nomeProcurado[i] == search_node.letter){
                
                // Verifica se o nodo possui filhos para que continue-se a busca
                if(search_node.son_pos != -1){
                    //fseek(trie_tree, search_node.son_pos, SEEK_SET);
                    trieBin.seekg(search_node.son_pos, trieBin.beg);
                    i++;
                }
                
                else {
                    flag = 1;
                }
            // Caso a letra buscada no prefixo venha antes da letra avaliada no nodo
            }
            
            else if(nomeProcurado[i] < search_node.letter){
                
                // Verifica se o nodo possui algum nodo a esquerda para que continue-se a busca
                if(search_node.left_pos != -1){
                    //fseek(trie_tree, search_node.left_pos, SEEK_SET);
                    trieBin.seekg(search_node.left_pos, trieBin.beg);
                }
                
                else {
                    flag = 1;
                }
            // Caso a letra buscada no prefixo venha depois da letra avaliada no nodo
            }
            
            else {
                
                // Verifica-se se o nodo possui algum nodo a direita para que continue-se a busca
                if(search_node.right_pos != -1){
                    //fseek(trie_tree, search_node.right_pos, SEEK_SET);
                    trieBin.seekg(search_node.right_pos, trieBin.beg);
                }
                
                else {
                    flag = 1;
                }
            }
        }

        // Caso o while pare porque o prefixo nao esta presente em nenhum filme ou o nome buscado nao
        // exista, uma mensagem de erro e mostrada
        if(flag == 1){
            printf("Nao foi encontrado nenhum nome\n");
        // Se nao, os proximos nodos sao percorridos em busca de todos os filmes que possuam tal prefixo ou nome
        }

        else{
            printf("aqui teriam os nomes");
        }
        
    }

    //fclose(trie_tree);
    trieBin.close();
}



//QUERY.C
