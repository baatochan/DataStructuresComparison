//
// Created by barto on 26.03.17.
//
#include <iostream>
#include "ListElement.h"

ListElement::ListElement(int value) {
    nextElement=NULL;
    this->value=value;
}

int ListElement::getValue() {
    return value;
}

ListElement * ListElement::getNextElement() {
    return nextElement;
}

void ListElement::setValue(int value) {
    this->value = value;
}

void ListElement::setNextElement(ListElement *nextElement) {
    this->nextElement = nextElement;
}
