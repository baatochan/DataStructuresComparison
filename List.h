//
// Created by barto on 26.03.17.
//
#include <string>
#include "ListElement.h"

#ifndef DATASTRUCTURESSDIZO_LIST_H
#define DATASTRUCTURESSDIZO_LIST_H

using namespace std;

class List {
private:
    ListElement *firstElement;
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
