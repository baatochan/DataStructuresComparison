//
// Created by barto on 26.03.17.
//
#include "ListElement.h"
#include "Structure.h"

#ifndef DATASTRUCTURESSDIZO_LIST_H
#define DATASTRUCTURESSDIZO_LIST_H

class List : public Structure {
public:
    ListElement *firstElement;
private:
    int size;
public:
    List();

    int loadFrom(string FileName);

    bool lookFor(int val);

    void add(int index, int value);

    void remove(int index);

    void display();

    void generate(int size);
};


#endif //DATASTRUCTURESSDIZO_LIST_H
