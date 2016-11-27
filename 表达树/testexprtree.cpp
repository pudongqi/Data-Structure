#include "exptree.h"
#include <iostream>
using namespace std;

void showStructure(ExprTreeNode *root) {
    if(root) {
        cout << root->dataltem << " ";
        ShowSub(root->left);
        ShowSub(root->right);
    }
    else {
        cout << "Empty Tree!" << endl;
    }
}

void showSub(struct ExprTreeNode *root) {
    if(root) {
        cout << root->dataltem << " ";
        ShowSub(root->left);
        ShowSub(root->right);
    }
}

