
#ifndef LAB6_TREE_H
#define LAB6_TREE_H
#include <iostream>
#include "string"
#include "cstdlib"
#include "vector"
using namespace std;

struct Branch{
    char Data;
    Branch* LeftBranch;
    Branch* RightBranch;
    Branch* Parent;
};

class Tree {
private:
    Branch *root;
    vector<char> duplicates;

    void insertElementRecursion(Branch*&, char, Branch*);
    void printTreeRecursion(Branch *&, int);
    int deleteElementsPrivate(char key);
    void postOrderRecursion(Branch*&);
    Branch** findBranch(Branch*&, char);
public:
    Tree();
    ~Tree();
    void addElement(char);
    void printTree();
    void deleteElements();
    void printPostOrder();

};



#endif //LAB6_TREE_H
