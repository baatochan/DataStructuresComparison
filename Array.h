//
// Created by barto on 11.04.17.
//

#ifndef DATASTRUCTURESSDIZO_ARRAY_H
#define DATASTRUCTURESSDIZO_ARRAY_H

#include "Structure.h"

class Array : public Structure {
private:

    int* _array;

public:
    Array();

    ~Array();

    void loadDataFrom(std::string fileName) override ;

    bool lookFor(int value) override ;

    void add(int value, int index) override ;

    void remove(int value) override ;

    void remove(int index, int value) override ;

    void removePosition(int index) override ;

    std::string print() override ;

    void generate(int size) override ;

};


#endif //DATASTRUCTURESSDIZO_ARRAY_H