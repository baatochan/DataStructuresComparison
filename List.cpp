//
// Created by barto on 26.03.17.
//

#include <iostream>
#include "List.h"
#include "ListElement.h"

using namespace std;

List::List() {
    firstElement = nullptr;
    size = 0;
}

int List::loadFromFile(string FileName) {
    return 0;
}

bool List::IsValueInList(int val) {
    return false;
}

void List::addValue(int index, int value) {
    ListElement newElement(value);
    if(index<0) {
        cout<<"Błędny indeks"<<endl;
        return;
    }
    else if(index>=size) {
        if (firstElement == nullptr) firstElement = &newElement;
        else {
            ListElement *lastElement;
            lastElement = firstElement;
            while (lastElement != nullptr) {
                lastElement = lastElement->getNextElement();
            }
            lastElement->setNextElement(&newElement);
        }
    }
    else {
        ListElement *elementAfterNew = firstElement;
        ListElement *elementBeforeNew = firstElement;
        for (int i = 0; i < index; i++) {
            elementBeforeNew = elementAfterNew;
            elementAfterNew = elementAfterNew->getNextElement();
        }
        elementBeforeNew->setNextElement(&newElement);
        newElement.setNextElement(elementAfterNew);
    }
    size++;
}

void List::deleteValue(int index) {

}

void List::display() {
    ListElement *temp = firstElement;
    cout << "Zawartość listy: " << endl;
    /*while (temp->getNextElement()!=nullptr) {
        cout<<temp->getValue()<<" ";
        temp = temp->getNextElement();
    }*/
    for (int i = 0; i < size; i++) {
        cout << temp->getValue() << " ";
        temp = temp->getNextElement();
    }
}

void List::generateList(int size) {
    if(firstElement!=nullptr) {
        cout<<"Lista nie jest pusta! Usuń listę i spróbuj ponownie.";
        return;
    }
    this->size = size;
    for (int i = 0; i < size; i++) {
        int tempValue = rand();
        addValue(i,tempValue);
    }
}
