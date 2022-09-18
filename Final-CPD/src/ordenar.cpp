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
 
btreeNode *root;
 
/* creating new node */
btreeNode * createNode(string val, btreeNode *child, long position) {
    btreeNode *newNode = new btreeNode;
    newNode->val[1] = val;
    newNode->position[1] = position;
    newNode->count = 1;
    newNode->link[0] = root;
    newNode->link[1] = child;
    return newNode;
}

string char_to_string(char value[MAX_NAME]){
    string s(value);
    return s;
}

 
/* Places the value in appropriate position */
void addValToNode(string val, int pos, btreeNode *node, btreeNode *child, long position) {
    int j = node->count;
    while (j > pos) {
        node->val[j + 1] = node->val[j];
        node->position[j + 1] = node->position[j];
        node->link[j + 1] = node->link[j];
        j--;
    }
    node->position[j + 1] = position;
    node->val[j + 1] = val;
    node->link[j + 1] = child;
    node->count++;
}
 
/* split the node */
void splitNode(string val, string *pval, int pos, btreeNode *node,btreeNode *child, btreeNode **newNode, long position, long *Pposition) {
    int median, j;
 
    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;
 
    *newNode = new btreeNode;
    j = median + 1;
    while (j <= MAX) {
        (*newNode)->val[j - median] = node->val[j];
        (*newNode)->position[j - median] = node->position[j];
        (*newNode)->link[j - median] = node->link[j];
        j++;
    }
    node->count = median;
    (*newNode)->count = MAX - median;
 
    if (pos <= MIN) {
        addValToNode(val, pos, node, child, position);
    }
    else {
        addValToNode(val, pos - median, *newNode, child, position);
    }
    *pval = node->val[node->count];
    *Pposition = node->position[node->count];
    (*newNode)->link[0] = node->link[node->count];
    node->count--;
}
 
/* sets the value val in the node */
int setValueInNode(string val, string *pval,btreeNode *node, btreeNode **child, long position, long *Pposition) {
 
    int pos;
    if (!node) {
        *pval = val;
        *Pposition = position;
        *child = NULL;
        return 1;
    }
 
    if (val < node->val[1]) {
        pos = 0;
    }
    else {
        for (pos = node->count;
            (val < node->val[pos] && pos > 1); pos--);
        if (val == node->val[pos]) {
            cout<<"Duplicates not allowed\n";
            return 0;
        }
    }
    if (setValueInNode(val, pval, node->link[pos], child, position, Pposition)) {
        if (node->count < MAX) {
            addValToNode(*pval, pos, node, *child, *Pposition);
        }
        else {
            splitNode(*pval, pval, pos, node, *child, child, *Pposition, Pposition);
            return 1;
        }
    }
    return 0;
}
 
/* insert val in B-Tree */
void insertion(string val, long position) {
    int flag;
    string i;
    long Pposition;
    btreeNode *child;
 
    flag = setValueInNode(val, &i, root, &child, position, &Pposition);
    if (flag)
        root = createNode(i, child, position);
}
 

 
 
/* shifts value from parent to right child */
void doRightShift(btreeNode *myNode, int pos) {
    btreeNode *x = myNode->link[pos];
    int j = x->count;
 
    while (j > 0) {
        x->val[j + 1] = x->val[j];
        x->position[j + 1] = x->position[j];
        x->link[j + 1] = x->link[j];
    }
    x->val[1] = myNode->val[pos];
    x->position[1] = myNode->position[pos];
    x->link[1] = x->link[0];
    x->count++;
 
    x = myNode->link[pos - 1];
    myNode->val[pos] = x->val[x->count];
    myNode->position[pos] = x->position[x->count];
    myNode->link[pos] = x->link[x->count];
    x->count--;
    return;
}
 
/* shifts value from parent to left child */
void doLeftShift(btreeNode *myNode, int pos) {
    int j = 1;
    btreeNode *x = myNode->link[pos - 1];
 
    x->count++;
    x->val[x->count] = myNode->val[pos];
    x->position[x->count] = myNode->position[pos];
    x->link[x->count] = myNode->link[pos]->link[0];
 
    x = myNode->link[pos];
    myNode->val[pos] = x->val[1];
    myNode->position[pos] = x->position[1];
    x->link[0] = x->link[1];
    x->count--;
 
    while (j <= x->count) {
        x->val[j] = x->val[j + 1];
        x->position[j] = x->position[j + 1];
        x->link[j] = x->link[j + 1];
        j++;
    }
    return;
}
 
 


/* B-Tree Traversal */
void traversal(btreeNode *myNode) {
    int i;
    if (myNode) {
        for (i = 0; i < myNode->count; i++) {
            traversal(myNode->link[i]);
            cout<< myNode->val[i + 1]<<' ' << myNode->position[i + 1] << ' ';                      //saida
        }
        traversal(myNode->link[i]);
    }
}

int main() {
    int opt;
    string val;
    long position;
    while (true) {
        cout<<"1. Insertion\t";
        cout<<"4. Traversal\n";
        cout<<"5. Exit\nEnter your choice: ";
        cin >> opt;
        cout << endl;
        switch (opt) {
        case 1:
            cout<<"Enter your input:";
            cin >> val;
            cin >> position;
            insertion(val, position);
            break;
        
        case 4:
            traversal(root);
            break;
        case 5:
            exit(0);
        }
        cout << endl;
    }
 
    system("pause");
}

