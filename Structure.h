//
// Created by barto on 29.03.17.
//
#include <string>

#ifndef DATASTRUCTURESSDIZO_STRUCTURE_H
#define DATASTRUCTURESSDIZO_STRUCTURE_H

using namespace std;

class Structure {
public:

    virtual int loadFrom(string FileName)= 0;

    virtual bool lookFor(int val)= 0;

    virtual void add(int index, int value)= 0;

    virtual void remove(int index)= 0;

    virtual void display()= 0;

    virtual void generate(int size)= 0;

};


#endif //DATASTRUCTURESSDIZO_STRUCTURE_H
