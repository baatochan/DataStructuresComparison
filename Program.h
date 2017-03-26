//
// Created by barto on 26.03.17.
//
#include <string>
#include "List.h"

#ifndef DATASTRUCTURESSDIZO_PROGRAM_H
#define DATASTRUCTURESSDIZO_PROGRAM_H

using namespace std;

class Program {
private:
    List myList;
public:
    void Start();
private:
    void displayMenu(string info);
    void menu_table();
    void menu_list();
    void menu_heap();
};


#endif //DATASTRUCTURESSDIZO_PROGRAM_H
