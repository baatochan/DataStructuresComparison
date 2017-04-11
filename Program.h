//
// Created by barto on 26.03.17.
//
#include <string>
#include "Structure.h"

#ifndef DATASTRUCTURESSDIZO_PROGRAM_H
#define DATASTRUCTURESSDIZO_PROGRAM_H

using namespace std;

class Program {
private:
    Structure* _structure;
    bool _isBST = false;
public:
    void Start();
private:
    void displayMenu(std::string info);
    void takeActionInMenu(std::string info);
};


#endif //DATASTRUCTURESSDIZO_PROGRAM_H
