//
// Created by barto on 15.04.17.
//

#include "BSTree.h"


// private

class BSTree::_node {
public:

    int Value;

    _node* Left;
    _node* Right;

    _node(int value) {
        Value = value;
        Left = nullptr;
        Right = nullptr;
    }

};

// public

BSTree::BSTree() {
    _root = nullptr;
}

BSTree::~BSTree() {
    remove(_root);
}

void BSTree::loadDataFrom(string fileName) {
    vector<int> data = loadRawDataFrom(fileName);

    for (int i = 0; i < data.size(); i++) {
        add(data[i]);
    }
}

bool BSTree::lookFor(int value) {
    _node *current = _root;

    while (current) {
        if (current->Value == value) {
            break;
        } else {
            if (value < current->Value) {
                current = current->Left;
            } else {
                current = current->Right;
            }
        }
    }

    if (current == nullptr) {
        return false;
    }
    else {
        return true;
    }
}

void BSTree::add(int value, int index) {
    add(value, _root);
}

void BSTree::remove(int value) {
    _node * parent;
    _node * current = _root;

    while(current) {
        if(current->Value == value){
            break;
        }
        else {
            parent = current;
            if (value<current->Value){
                current = current->Left;
            }
            else {
                current = current->Right;
            }
        }
    }

    if(current == nullptr) {
        cout << "Value not found! " << endl;
        return;
    }

    // removing node with no child

    if(current->Left == nullptr && current->Right == nullptr) {
        if(current == _root){
            _root = nullptr;
            delete current;
            return;
        }
        else {
            if(parent->Left == current)
                parent->Left = nullptr;
            else
                parent->Right = nullptr;

            delete current;
            return;
        }
    }

    // removing node with one child - left

    if(current->Left == nullptr && current->Right != nullptr) {
        if (current == _root) {
            _root = current->Left;
            delete current;
            return;
        }
        else {
            if (parent->Left == current) {
                parent->Left = current->Right;
            } else {
                parent->Right = current->Right;
            }
            delete current;
            return;
        }
    }

    // removing node with one child - right

    if(current->Left != nullptr && current->Right == nullptr) {
        if (current == _root) {
            _root = current->Right;
            delete current;
        }
        else {
            if (parent->Left == current) {
                parent->Left = current->Left;
            } else {
                parent->Right = current->Left;
            }
            delete current;
            return;
        }
    }

    // removing node with two children
    // replace removing node with smallest element of the right subtree

    if (current->Left != nullptr && current->Right != nullptr) {
        _node * currentR = current->Right;
        if(currentR->Left == nullptr && currentR->Right == nullptr) {//right child has no child
            current->Value = currentR->Value;
            delete currentR;
            current->Right = nullptr;
        } else { // right child has children

            if(currentR->Left != nullptr) {//there is left subtree of right child
                _node * currentRL;
                _node * parrentRL;
                parrentRL = currentR;
                currentRL = currentR->Left;
                while(currentRL->Left != nullptr) {
                    parrentRL = currentRL;
                    currentRL = currentRL->Left;
                }
                current->Value = currentRL->Value;
                delete currentRL;
                parrentRL->Left = nullptr;
            } else { // there is no left subtree
                if(parent->Left == current) {
                    parent->Left = currentR;
                } else {
                    parent->Right = currentR;
                }

                currentR->Left = current->Left;
                delete current;
            }
        }
    }
}

void BSTree::remove(int index, int value) {} //nie dotyczy BST

void BSTree::removePosition(int index) {} //nie dotyczy BST

string BSTree::print() {
    string s = "BST: \n";
    _height = getHeight(_root);
    s += print(_root);
    return s;
}

void BSTree::generate(int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        add((rand()-(RAND_MAX/2)));
    }
}

// private

void BSTree::add(int value, BSTree::_node *&node) {
    if (node == nullptr) {
        node = new _node(value);
    }
    else {
        if (value < node->Value) {
            add(value, node->Left);
        }
        else {
            add(value, node->Right);
        }
    }
}

string BSTree::print(BSTree::_node *node) {
    if (node != nullptr) {
        string tmp = "";
        int height = getHeight(node);
        int reverseHeight = _height - height;
        string order = "";
        for (int i = 0; i < reverseHeight; ++i) {
            order += "    ";
        }

        tmp += print(node->Left);

        tmp += order;
        tmp += to_string(node->Value);
        tmp += "\n";

        tmp += print(node->Right);

        return tmp;
    }
    return "";
}

int BSTree::getHeight(BSTree::_node *node) {
    if (node == nullptr) return 0;
    int leftHeight = getHeight(node->Left);
    int rightHeight = getHeight(node->Right);
    return max(leftHeight, rightHeight) + 1;
}

void BSTree::remove(BSTree::_node *node) {
    if(node != nullptr) {
        remove(node->Left);
        remove(node->Right);
        delete node;
        return;
    }
    else
        return;
}
