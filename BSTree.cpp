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

}

void BSTree::loadDataFrom(std::string fileName) {
    std::vector<int> data = loadRawDataFrom(fileName);

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

}

void BSTree::remove(int value) {

}

void BSTree::remove(int index, int value) {

}

void BSTree::removePosition(int index) {

}

std::string BSTree::print() {
    return std::__cxx11::string();
}

void BSTree::generate(int size) {

}
