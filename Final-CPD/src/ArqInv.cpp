/*#include "../Include/ArqInv.h"

Código:
0->writer
1->issue

T->removido
F->ñ removido

0-nameWriter-PosProxWriter-PosIssue

1-flag-issue-PosProxIssue


ArqInv::InsertionInvArq(Registro reg, std::string NameFile){

    std::fstream arq_inv("../"+NameFile+"/arq_inv.bin", std::ofstream::binary);

    while(arq_inv.eof()){
        while(getline(arq_inv, aux, '-')){
            if(aux=="0"){
                getline(arq_inv, aux, '-');
                getline(arq_inv, aux, '-');
                if(aux==reg.writer){
                    while(aux != "1" && getline(arq_inv, aux, '-')){}
                    getline(arq_inv, aux, '-');
                    getline(arq_inv, aux, '-');
                    if(aux!=reg.issue)

                }
                else{

                }

            }
            else{

            }
        }
        arq_inv.write('0');
    }
}*/
