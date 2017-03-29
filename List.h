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

    int loadFromFile(string FileName);

    bool IsValueInList(int val);

    void addValue(int index, int value);

    void deleteValue(int index);

    void display();

    void generateList(int size);
};


#endif //DATASTRUCTURESSDIZO_LIST_H
