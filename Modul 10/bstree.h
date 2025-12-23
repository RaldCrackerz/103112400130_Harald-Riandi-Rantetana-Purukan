#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <algorithm> 

using namespace std;

typedef int infotype;
typedef struct Node* address;
const address Nil = NULL;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);

void insertNode(address &root, infotype x);
address findNode(infotype x, address root);

void printInorder(address root);

int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int start); 

#endif