#include "Registro.h"
#include <iostream>
#include <fstream>

class ArqInv{
    typedef struct inv_issue{
        std::string issue;
        struct inv_issue *prox_issue;
    }InvIssue;

    typedef struct inv_writer{
        char removed;
        std::string writer;
        InvIssue *issuePtr;
        struct inv_writer *prox_writer;
    }invWriter;

    ArqInv(invWriter *node){
        node->removed='F';
        node->issuePtr = nullptr;
        node->prox_writer = nullptr;
    }

    //void InsertionInvArq(Registro::Registro reg, std::string NameFile);
};
