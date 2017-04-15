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

void List::loadDataFrom(string fileName) {
    vector<int> data = loadRawDataFrom(fileName);

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
    _listElement * currentElement = _firstElement;
    while (currentElement != nullptr) {
        if (currentElement->Value == value) {
            if (currentElement == _firstElement) {
                currentElement = currentElement->NextElement;
                removeFirst();
            }
            else if (currentElement == _lastElement) {
                removeLast();
                return;
            }
            else {
                (currentElement->PreviousElement)->NextElement = currentElement->NextElement;
                (currentElement->NextElement)->PreviousElement = currentElement->PreviousElement;
                _listElement * tmp = currentElement->NextElement;
                delete currentElement;
                currentElement = tmp;
                size--;
            }
        }
        else
            currentElement = currentElement->NextElement;
    }
}

void List::remove(int index, int value) {
    int halfOfSize = size/2;
    if (index < 0) {
        cout<<"Index nie może być mniejszy od zera!"<<endl;
        return;
    }
    else if (index == 0) {
        if (_firstElement->Value == value)
            removeFirst();
        return;
    }
    else if (index > 0 && index < halfOfSize) {
        _listElement * currentElement = _firstElement;
        for (int i = 0; i < index; i++) {
            currentElement = currentElement->NextElement;
        }
        if (currentElement->Value == value) {
            (currentElement->PreviousElement)->NextElement = currentElement->NextElement;
            (currentElement->NextElement)->PreviousElement = currentElement->PreviousElement;
            delete currentElement;
            size--;
            return;
        }
        else
            return;
    }
    else if (index >= halfOfSize && index < (size - 1)) {
        _listElement * currentElement = _lastElement;
        for (int i = (size - 1); i > index ; i--) {
            currentElement = currentElement->PreviousElement;
        }
        if (currentElement->Value == value) {
            (currentElement->PreviousElement)->NextElement = currentElement->NextElement;
            (currentElement->NextElement)->PreviousElement = currentElement->PreviousElement;
            delete currentElement;
            size--;
            return;
        }
        else
            return;

    }
    else if (index == (size - 1)) {
        if (_lastElement->Value == value)
            removeLast();
        return;
    }
    else if (index > (size - 1)) {
        cout<<"Podany indeks nie znajduje się w liście. Lista jest krótsza!"<<endl;
        return;
    }
    else {
        cout<<"WUT WUT?!"<<endl;
        return;
    }
}

void List::removePosition(int index) {
    int halfOfSize = size/2;
    if (index < 0) {
        cout<<"Index nie może być mniejszy od zera!"<<endl;
        return;
    }
    else if (index == 0) {
        removeFirst();
        return;
    }
    else if (index > 0 && index < halfOfSize) {
        _listElement * currentElement = _firstElement;
        for (int i = 0; i < index; i++) {
            currentElement = currentElement->NextElement;
        }
        (currentElement->PreviousElement)->NextElement = currentElement->NextElement;
        (currentElement->NextElement)->PreviousElement = currentElement->PreviousElement;
        delete currentElement;
        size--;
        return;
    }
    else if (index >= halfOfSize && index < (size - 1)) {
        _listElement * currentElement = _lastElement;
        for (int i = (size - 1); i > index ; i--) {
            currentElement = currentElement->PreviousElement;
        }
        (currentElement->PreviousElement)->NextElement = currentElement->NextElement;
        (currentElement->NextElement)->PreviousElement = currentElement->PreviousElement;
        delete currentElement;
        size--;
        return;
    }
    else if (index == (size - 1)) {
        removeLast();
        return;
    }
    else if (index > (size - 1)) {
        cout<<"Podany indeks nie znajduje się w liście. Lista jest krótsza!"<<endl;
        return;
    }
    else {
        cout<<"WUT WUT?!"<<endl;
        return;
    }
}

string List::print() {
    string temp = "";
    _listElement * currentElement = _firstElement;
    bool isEmpty = true;
    while (currentElement != nullptr) {
        temp += to_string(currentElement->Value) + ", ";
        currentElement = currentElement->NextElement;
        isEmpty = false;
    }
    if (!isEmpty) {
        temp.pop_back();
        temp.pop_back();
    }
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
    if (size > 0) {
        _listElement * newElement = new _listElement(value);
        _lastElement->NextElement = newElement;
        newElement->PreviousElement = _lastElement;
        _lastElement = newElement;
        size++;
    }
    else if (size == 0) {
        _listElement * newElement = new _listElement(value);
        _lastElement = newElement;
        _firstElement = newElement;
        size++;
    }
    else {
        cout<<"WUT WUT?!"<<endl;
    }
}

void List::removeFirst() {
    if (size > 1) {
        _listElement *tmp = _firstElement;
        _firstElement = tmp->NextElement;
        _firstElement->PreviousElement = nullptr;
        delete tmp;
        size--;
    }
    else if (size == 1){
        delete _firstElement;
        _firstElement = nullptr;
        _lastElement = nullptr;
        size--;
    }
    else {
        cout<<"WUT WUT?!"<<endl;
    }
}

void List::removeLast() {
    if (size > 1) {
    _listElement * tmp = _lastElement;
    _lastElement = tmp->PreviousElement;
    _lastElement->NextElement = nullptr;
    delete tmp;
    size--;
    }
    else if (size == 1){
        delete _lastElement;
        _firstElement = nullptr;
        _lastElement = nullptr;
        size--;
    }
    else {
        cout<<"WUT WUT?!"<<endl;
    }
}
