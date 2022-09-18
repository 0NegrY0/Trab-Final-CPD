#include "./include/Registro.h"
#include "./include/ArqInv.h"
#include "./include/trie.h"
#include "./include/Registro.h"
#include "./include/ordenar.h"
#include <ostream>

using namespace std;

int main()
{

    int escolha;

    std::cout << "Trabalho Final CPD" << std::endl;
    
    do{
        cout << "Ler Arquivo - 1\nOrdenar Arquivo Lido - 2\nPesquisar por Nome - 3\n" << endl;
        cin >> escolha;

        switch (escolha) {
            case 1:
                HandleInputFiles();
                break;
            case 2:
                imprimirOrdenado();

        }


    }while(escolha != 0);
    
    
    
    
    
    
    return 0;
}
