//
// Created by barto on 29.03.17.
//

#ifndef DATASTRUCTURESSDIZO_STRUCTURE_H
#define DATASTRUCTURESSDIZO_STRUCTURE_H


#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

class Structure {
protected:

    int size;

public:

    virtual void loadDataFrom(string fileName)= 0;

    virtual bool lookFor(int value)= 0;

    virtual void add(int value, int index)= 0;

    virtual void remove(int value)= 0;

    virtual void remove(int index, int value)= 0;

    virtual void removePosition(int index)= 0;

    virtual string print()= 0;

    virtual void generate(int size)= 0;

protected:

    vector<int> loadRawDataFrom(string path);

};


#endif //DATASTRUCTURESSDIZO_STRUCTURE_H
