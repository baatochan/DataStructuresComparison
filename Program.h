//
// Created by barto on 26.03.17.
//

#ifndef DATASTRUCTURESSDIZO_PROGRAM_H
#define DATASTRUCTURESSDIZO_PROGRAM_H


#include "Array.h"
#include "List.h"
#include "Heap.h"

class Program {
private:

    Structure* _structure;

public:

    void start();

private:

    void displayMenu(string info);

    void takeActionInMenu(string info);

};


#endif //DATASTRUCTURESSDIZO_PROGRAM_H
