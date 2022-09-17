#include "../Include/Registro.h"
#include "../Include/trie.h"

#define BUFFER_MAX 400
#define NAME_MAX 256

using namespace std;

void Trie::saveTrie(string Issue, long position, fstream& trieBin){
    Trie_node search_node;
    Trie_node son_node;
    int file_size;
    int i = 0, j;
    int flag = 0;
    long son_position;
    long search_node_position;
    char name[NAME_MAX];

    for(j=0;j<Issue.size();j++)
        name[j] = Issue.at(j);
    name[j] = '\0';

    trieBin.seekg(0, trieBin.end);
    file_size = trieBin.tellg();

    // Se o arquivo ja tiver nodos, e preciso buscar a posicao correta de insercao.
    // Caso contrario, a insercao e feita diretamente
    if(file_size != 0){
        trieBin.seekg(0, trieBin.beg);
        while(flag == 0 && name[i] != '\0'){
            search_node_position = trieBin.tellg();
////////////////////////////////////////////////////////////////////////////////////////////////////////////
            trieBin.read((char*)&search_node, sizeof(Trie_node));
////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // Caso a letra buscada coincida com a letra avaliada no nodo
            if(name[i] == search_node.letter){
                i++;
                // Se o nodo possuir filhos, a busca continua
                if(search_node.son_pos != -1){
                    trieBin.seekp(search_node.son_pos, trieBin.beg);
                // Caso contrario, o filho e atualizado e passa-se a inserir o restante do nome na arvore
                }
                else {
                    if(name[i] != '\0'){
                        trieBin.seekp(0, trieBin.end);
                        search_node.son_pos = trieBin.tellp();
                        trieBin.seekp(search_node_position, trieBin.beg);
                        trieBin.write((char*)&search_node, sizeof(Trie_node));
                        trieBin.seekp(0,trieBin.end);
                    }
                    flag = 1;
                }
            // Caso a letra buscada venha antes da letra avaliada no nodo
            }
            else if(name[i] < search_node.letter){
                // Se o nodo possuir algum nodo a esquerda, a busca continua
                if(search_node.left_pos != -1){
                    trieBin.seekp(search_node.left_pos, trieBin.beg);
                // Caso contrario, o nodo e atualizado e passa-se a inserir o restante do nome na arvore
                }
                else {
                    if(name[i] != '\0'){
                        trieBin.seekp(0, trieBin.end);
                        search_node.left_pos = trieBin.tellp();
                        trieBin.seekp(search_node_position, trieBin.beg);
                        trieBin.write((char*)&search_node, sizeof(Trie_node));
                        trieBin.seekp(0, trieBin.end);
                    }
                    flag = 1;
                }
            // Caso a letra buscada venha depois da letra avaliada no nodo
            }
            else {
                // Se o nodo possuir algum nodo a direita, a busca continua
                if(search_node.right_pos != -1){
                    trieBin.seekp(search_node.right_pos, trieBin.beg);
                // Caso contrario, o nodo e atualizado e passa-se a inserir o restante do nome na arvore
                }
                else {
                    if(name[i] != '\0'){
                        trieBin.seekp(0, trieBin.end);
                        search_node.right_pos = trieBin.tellp();
                        trieBin.seekp(search_node_position, trieBin.beg);
                        trieBin.write((char*)&search_node, sizeof(Trie_node));
                        trieBin.seekp(0, trieBin.end);
                    }
                    flag = 1;
                }
            }
        }
        // vai para o final do arquivo para que as proximas letras possam ser inseridas
        trieBin.seekp(0, trieBin.end);
    }
    // Insercao do nome ou do resto dele
    while(name[i] != '\0'){
        // Seta as informacoes para cada novo nodo
        son_node.letter = name[i];
        son_position = trieBin.tellp();
        if(i == strlen(name) - 1){// Verifica se e um nodo terminal ou nao
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
        trieBin.write((char*)&son_node, sizeof(Trie_node));
        i++;
    }
}
///---------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------
long Trie::searchByName(string Issue, fstream& trieBin){
    char nomeProcurado[NAME_MAX];
    Trie_node search_node;
    int flag = 0;
    int i = 0, j;

    for(j=0;j<Issue.size();j++)
        nomeProcurado[j] = Issue.at(j);
    nomeProcurado[j] = '\0';

    trieBin.seekg(0, trieBin.beg);
    // O prefixo ou nome e buscado na trie tree
    while(nomeProcurado[i] != '\0' && flag == 0){
        trieBin.read((char*)&search_node, sizeof(Trie_node));
        // Caso a letra buscada no prefixo coincida com a letra avaliada no nodo
        if(nomeProcurado[i] == search_node.letter){
            // Verifica se o nodo possui filhos para que continue-se a busca
            if(search_node.son_pos != -1){
                trieBin.seekg(search_node.son_pos, trieBin.beg);
                i++;
            }
            else
                flag = 1;
            // Caso a letra buscada no prefixo venha antes da letra avaliada no nodo
        }
        else if(nomeProcurado[i] < search_node.letter)
            if(search_node.left_pos != -1)// Verifica se o nodo possui algum nodo a esquerda para que continue-se a busca
                trieBin.seekg(search_node.left_pos, trieBin.beg);
            else
                flag = 1;
            // Caso a letra buscada no prefixo venha depois da letra avaliada no nodo
        else
            if(search_node.right_pos != -1)// Verifica-se se o nodo possui algum nodo a direita para que continue-se a busca
                trieBin.seekg(search_node.right_pos, trieBin.beg);//fseek(trie_tree, search_node.right_pos, SEEK_SET);
            else
                flag = 1;
    }
    // Caso o while pare porque o prefixo nao esta presente em nenhum filme ou o nome buscado nao
    // exista, uma mensagem de erro e mostrada
    if(flag == 1)
        return -1;
    // Se nao, os proximos nodos sao percorridos em busca de todos os filmes que possuam tal prefixo ou nome
    else
        return search_node.file_position;
}
