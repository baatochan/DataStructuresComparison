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
    _firstElement = nullptr;
    _lastElement = nullptr;

    size = 0;
}

List::~List() {
    if (_firstElement != nullptr) {
        _listElement *tempCurrentElement = _firstElement;
        _listElement *tempNextElement = _firstElement->NextElement;

        while (tempCurrentElement != nullptr) {
            delete tempCurrentElement;
            tempCurrentElement = tempNextElement;
            tempNextElement = tempNextElement->NextElement;
        }
    }
}

void List::loadDataFrom(std::string fileName) {
    std::vector<int> data = loadRawDataFrom(fileName);

    for (int i = 0; i < data.size(); i++) {
        add(data[i],size);
    }
}

bool List::lookFor(int value) {
    bool valueExists = false;
    _listElement * currentElement = _firstElement;

    for (int i = 0; i < size; i++) {
        if(currentElement->Value == value) {
            valueExists = true;
            cout<<"Wartość znajduje się pod indeksem " + to_string(i)<<endl;
        }
        currentElement = currentElement->NextElement;
    }

    return valueExists;
}

void List::add(int value, int index) {
    int halfOfSize = size/2;
    if (index < 0) {
        cout<<"Index nie może być ujemny."<<endl;
        return;
    }
    else if (index == 0) {
        addAtTheBeggining(value);
        return;
    }
    else if (index > 0 && index < halfOfSize) {
        _listElement * newElement = new _listElement(value);
        _listElement * currentElement = _firstElement;
        for (int i = 0; i < index; i++) {
            currentElement = currentElement->NextElement;
        }
        newElement->NextElement = currentElement->NextElement;
        newElement->PreviousElement = currentElement;
        (currentElement->NextElement)->PreviousElement = newElement;
        currentElement->NextElement = newElement;
        size++;
        return;
    }
    else if (index >= halfOfSize && index < (size - 1)) {
        _listElement * newElement = new _listElement(value);
        _listElement * currentElement = _lastElement;
        for (int i = (size - 1); i > index ; i--) {
            currentElement = currentElement->PreviousElement;
        }
        newElement->PreviousElement = currentElement->PreviousElement;
        newElement->NextElement = currentElement;
        (currentElement->PreviousElement)->NextElement = newElement;
        currentElement->PreviousElement = newElement;
        size++;
        return;
    }
    else if (index > (size - 1)) {
        addAtTheEnd(value);
        return;
    }
    else {
        cout<<"Coś jest nie tak."<<endl;
        return;
    }
}

void List::remove(int value) {
    
}

void List::remove(int index, int value) {

}

void List::removePosition(int index) {

}

std::string List::print() {
    string temp = "";
    _listElement * currentElement = _firstElement;
    while (currentElement != nullptr) {
        temp += to_string(currentElement->Value) + ", ";
        currentElement = currentElement->NextElement;
    }
    temp.pop_back();
    temp.pop_back();
    temp = "{ " + temp + " }";
    return temp;
}

void List::generate(int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        add((rand()-(RAND_MAX/2)),this->size);
    }
}

// private

void List::addAtTheBeggining(int value) {
    _listElement * newElement = new _listElement(value);
    if(size == 0) {
        _firstElement = newElement;
        _lastElement = newElement;
    }
    else {
        _firstElement->PreviousElement = newElement;
        newElement->NextElement = _firstElement;
        _firstElement = newElement;
    }
    size++;
}

void List::addAtTheEnd(int value) {
    _listElement * newElement = new _listElement(value);
    _lastElement->NextElement = newElement;
    newElement->PreviousElement = _lastElement;
    _lastElement = newElement;
    size++;
}
