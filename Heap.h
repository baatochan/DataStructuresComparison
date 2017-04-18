//
// Created by barto on 15.04.17.
//

#ifndef DATASTRUCTURESSDIZO_HEAP_H
#define DATASTRUCTURESSDIZO_HEAP_H


#include "Array.h"

class Heap : public Array {
public:

    Heap();

    void loadDataFrom(string fileName) override ;

    void add(int value, int index) override ;

    void remove(int value) override ;

    void remove(int index, int value) override ;

    void removePosition(int index) override ;

    string print() override ;

    void generate(int size) override ;

    void test() override ;

private:

    void heapifyEverything(); //restore heap rule in whole structure

    void heapifyWayUp(int index); //restore heap rule for element and every parent to the root

    void heapify(int index); //restore heap rule for this child (checks if the value under the provided index is smaller than parent)

    int getParent(int index);

    int getLevel(int index);

};


#endif //DATASTRUCTURESSDIZO_HEAP_H
