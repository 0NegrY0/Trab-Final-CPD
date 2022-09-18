#include <iostream>
#include <string>

#define MAX_NAME 200

using namespace std;
 
#define MAX 4
#define MIN 2
 
struct btreeNode {
    string val[MAX + 1];
    int count;
    long position[MAX + 1];
    btreeNode *link[MAX + 1];
};

btreeNode * createNode(string val, btreeNode *child, long position);

string char_to_string(char value[MAX_NAME]);

void addValToNode(string val, int pos, btreeNode *node, btreeNode *child, long position);

void splitNode(string val, string *pval, int pos, btreeNode *node,btreeNode *child, btreeNode **newNode, long position, long *Pposition);

int setValueInNode(string val, string *pval,btreeNode *node, btreeNode **child, long position, long *Pposition);
void insertion(string val, long position, int first);

void doRightShift(btreeNode *myNode, int pos);

void doLeftShift(btreeNode *myNode, int pos);

void traversal(btreeNode *myNode);

void imprimirOrdenado();