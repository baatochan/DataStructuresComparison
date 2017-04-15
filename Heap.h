//
// Created by barto on 15.04.17.
//

#ifndef DATASTRUCTURESSDIZO_HEAP_H
#define DATASTRUCTURESSDIZO_HEAP_H


#include "Array.h"

class Heap : public Array {
private:



public:
    Heap();

    ~Heap();

    void loadDataFrom(string fileName) override ;

    bool lookFor(int value) override ;

    void add(int value, int index) override ;

    void remove(int value) override ;

    void remove(int index, int value) override ;

    void removePosition(int index) override ;

    string print() override ;

    void generate(int size) override ;
};


#endif //DATASTRUCTURESSDIZO_HEAP_H
