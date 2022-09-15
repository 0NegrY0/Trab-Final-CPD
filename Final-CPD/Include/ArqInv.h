#include "Registro.h"
#include <iostream>
#include <fstream>
//#include <ofstream>

/** code:
 *
 * 0 -> writer
 * 1 -> issue
 *
 * Is it Removed?
 * T -> True
 * F -> False
 *
 * -- -> addres does not exist.
 *
 * 0-writer-issuePtr-prox_writer-
 * 1-removed-issue-prox_issue-
 *
 **/

class ArqInv{
    typedef struct inv_writer{
        int code;
        std::string writer;
        int issuePtr;
        int prox_writer;
    }invWriter;

    typedef struct inv_issue{
        std::string issue;
        bool removed;
        int prox_issue;
    }InvIssue;

    ArqInv(invWriter *node){
        node->code = -1;
        node->removed = false;
        node->issuePtr = -1;
        node->prox_writer = -1;
    }
};
