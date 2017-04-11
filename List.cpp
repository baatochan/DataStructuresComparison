//
// Created by barto on 11.04.17.
//

#include "List.h"

// private

class List::_listElement {
public:

    _listElement * PreviousElement;
    _listElement * NextElement;

    int Value;

public:

    _listElement(int value) {
        PreviousElement = nullptr;
        NextElement = nullptr;

        Value = value;
    }

};

// public

List::List() {

}

List::~List() {

}

void List::loadDataFrom(std::string fileName) {

}

bool List::lookFor(int value) {
    return false;
}

void List::add(int value, int index) {

}

void List::remove(int value) {

}

void List::remove(int index, int value) {

}

void List::removePosition(int index) {

}

std::string List::print() {
    return std::__cxx11::string();
}

void List::generate(int size) {

}
