//
// Created by barto on 29.03.17.
//
#include <string>

#ifndef DATASTRUCTURESSDIZO_STRUCTURE_H
#define DATASTRUCTURESSDIZO_STRUCTURE_H

class Structure {
public:

    virtual int loadFrom(std::string FileName)= 0;

    virtual bool lookFor(int val)= 0;

    virtual void add(int value, int index)= 0;

    virtual void remove(int value)= 0;

    virtual void remove(int index, int value)= 0;

    virtual void removePosition(int index)= 0;

    virtual std::string print()= 0;

    virtual void generate(int size)= 0;

};


#endif //DATASTRUCTURESSDIZO_STRUCTURE_H