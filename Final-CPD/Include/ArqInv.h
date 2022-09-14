#include "Registro.h"
#include <iostream>
#include <fstream>
#include <ofstream>

typedef inv_writer invWriter;
typedef inv_issue InvIssue;

class ArqInv{
    struct inv_writer{
        char removed;
        std::string writer;
        invIssue *issuePtr;
        invWriter *prox_writer;
    };

    struct inv_issue{
        std::string issue;
        InvIssue *prox_issue;
    };

    ArqInv(invWriter *node){
        node->removed='F';
        node->issuePtr = nullptr;
        node->prox_writer = nullptr;
    }
};
