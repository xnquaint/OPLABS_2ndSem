
#include "Tree.h"

int main() {
    Tree tree;
    string str;


    vector<char> array;
    cout << "Enter string: ";
    getline(cin, str);
    for (char & i : str) {
        if(i != ' ' && i != ',' && i != '.') {
            array.push_back(i);
        }
    }
    for (char i : array) {
        tree.addElement(i);
    }
    cout << "Tree: " << endl;
    tree.printTree();
    tree.deleteElements();
    cout << "Postorder (after deleting duplicates): " << endl;
    tree.printPostOrder();
    return 0;
}
