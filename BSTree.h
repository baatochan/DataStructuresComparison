//
// Created by barto on 15.04.17.
//

#ifndef DATASTRUCTURESSDIZO_BSTREE_H
#define DATASTRUCTURESSDIZO_BSTREE_H


#include "Structure.h"

class BSTree : public Structure {
private:

    class _node;

    _node * _root;

    int _height;

public:

    BSTree();

    ~BSTree();

    void loadDataFrom(string fileName) override ;

    bool lookFor(int value) override ;

    void add(int value, int index = 0) override ;

    void remove(int value) override ;

    void remove(int index, int value) override ;

    void removePosition(int index) override ;

    string print() override ;

    void generate(int size) override ;

    void test() override ;

private:

    void add(int value, _node *&node);

    void removeValue(int value);

    string print(_node * node);

    int getHeight(_node * node);

    void remove(_node * node);

    void DSW();

    void Listify();

    _node* rotateRight(_node* grandParent, _node* parent, _node* leftChild);

    void recreateBST();

    void makeRotations(int bound);

    void rotateLeft(_node* grandParent, _node* parent, _node* rightChild);
};


#endif //DATASTRUCTURESSDIZO_BSTREE_H
