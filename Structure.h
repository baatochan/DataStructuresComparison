//
// Created by barto on 29.03.17.
//
#include <string>

#ifndef DATASTRUCTURESSDIZO_STRUCTURE_H
#define DATASTRUCTURESSDIZO_STRUCTURE_H

using namespace std;

class Structure {
public:

    virtual int loadFromFile(string FileName)= 0;

    virtual bool IsValueInList(int val)= 0;

    virtual void addValue(int index, int value)= 0;

    virtual void deleteValue(int index)= 0;

    virtual void display()= 0;

    virtual void generateList(int size)= 0;

};


#endif //DATASTRUCTURESSDIZO_STRUCTURE_H
