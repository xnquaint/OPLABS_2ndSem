
#include "Tree.h"
using namespace std;

Tree::Tree() {
    root = nullptr;
}
Tree::~Tree() {
    delete root;
}

void Tree::addElement(char str) {
    insertElementRecursion(root, str, nullptr);
}

void Tree::printTreeRecursion(Branch *& branch, int level) {
    char space = ' ';
    char under = '_';
    for (int i = 0; i < level; i++)
        cout << string(3, space) << "|";
    cout << string(2, under);
    if (branch != nullptr)
    {
        cout << branch->Data << "\n";
        printTreeRecursion(branch->RightBranch, level + 1);
        printTreeRecursion(branch->LeftBranch, level + 1);
    }
    else
        cout << "\n";
}

void Tree::printTree() {
    this->printTreeRecursion(root, 0);
}
void Tree::insertElementRecursion(Branch *& branch, char str, Branch* parent) {
    if(branch == nullptr){
        branch = new Branch;
        branch->Data = str;
        branch->Parent = parent;
        branch->LeftBranch = nullptr;
        branch->RightBranch = nullptr;
    }
    else{
        if(str < branch->Data){
            insertElementRecursion(branch->LeftBranch, str, branch);
        }
        else if (str == branch->Data) {
            duplicates.push_back(str);
            return;
        }
        else{
            insertElementRecursion(branch->RightBranch, str, branch);
        }
    }
}
int Tree::deleteElementsPrivate(char key){

    Branch** current = findBranch(root, key);
    if (current == nullptr)
        return -1;

    if ((*current)->LeftBranch == nullptr && (*current)->RightBranch == nullptr) {
        Branch* tmp = *current;
        if ((*current)->Data < (*current)->Parent->Data)
            (*current)->Parent->LeftBranch = nullptr;
        else
            (*current)->Parent->RightBranch = nullptr;
        delete tmp;
        return 0;
    }

    if ((*current)->LeftBranch != nullptr && (*current)->RightBranch != nullptr) {
        auto leftmost = (*current)->RightBranch;

        while (leftmost && leftmost->LeftBranch != nullptr)
            leftmost = leftmost->LeftBranch;

        (*current)->Data = leftmost->Data;

        if (leftmost->RightBranch != nullptr) {
            leftmost->RightBranch->Parent = leftmost->Parent;
            auto tmp = leftmost->RightBranch;
            *leftmost = *leftmost->RightBranch;
            leftmost->Parent->LeftBranch = leftmost;
            delete tmp;
        } else {
            leftmost->Parent->RightBranch = nullptr;
            delete leftmost;
        }
        return 0;
    } else {
        if ((*current)->LeftBranch != nullptr) {
            Branch* tmp = *current;
            *current = (*current)->LeftBranch;
            (*current)->Parent = tmp->Parent;
            delete tmp;
        } else {
            auto tmp = *current;
            *current = (*current)->RightBranch;
            (*current)->Parent = tmp->Parent;
            delete tmp;
        }
        return 0;
    }
}

void Tree::postOrderRecursion(Branch*& branch) {
    if(branch == nullptr)
        return;
    postOrderRecursion(branch->LeftBranch);
    postOrderRecursion(branch->RightBranch);
    cout << branch->Data << " ";
}

void Tree::printPostOrder() {
    postOrderRecursion(root);
}

void Tree::deleteElements() {
    if (duplicates.empty()) return;
    for (char duplicate : duplicates) {
        deleteElementsPrivate(duplicate);
    }
}

Branch **Tree::findBranch(Branch *& branch, char key) {
    if (branch == nullptr)
        return nullptr;

    if (key == branch->Data)
        return &branch;

    if (key < branch->Data)
        return findBranch(branch->LeftBranch, key);
    else
        return findBranch(branch->RightBranch, key);
}







