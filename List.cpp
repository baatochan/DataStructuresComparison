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
    /*int tempValue = rand();
    ListElement * tempElement;
    ListElement newElement(tempValue);
    if(firstElement==NULL) firstElement=&newElement;
    else {
        tempElement = firstElement;
        while (tempElement!=NULL) {
            tempElement = tempElement->getNextElement();
        }
        tempElement->setNextElement(&newElement);*/
    ListElement *tempElement;
    if(index<0) {
        cout<<"Błędny indeks"<<endl;
        return;
    }
    else if(index>=size) {
        ListElement newElement(value);
        if (firstElement == nullptr) firstElement = &newElement;
        else {
            tempElement = firstElement;
            while (tempElement != nullptr) {
                tempElement = tempElement->getNextElement();
            }
            tempElement->setNextElement(&newElement);
        }
    }
    else {
        ListElement newElement(value);
        ListElement *tempElementParent = firstElement;
        tempElement = firstElement;
        for (int i = 0; i < index; i++) {
            tempElementParent = tempElement;
            tempElement = tempElement->getNextElement();
        }
        tempElementParent->setNextElement(&newElement);
        newElement.setNextElement(tempElement);
    }
    size++;
}

void List::deleteValue(int index) {

}

void List::display() {
    ListElement * temp = firstElement;
    cout<<"Zawartość listy: "<<endl;
    /*while (temp->getNextElement()!=nullptr) {
        cout<<temp->getValue()<<" ";
        temp = temp->getNextElement();
    }*/
    for (int i = 0; i < size; i++) {
        cout<<temp->getValue()<<" ";
        temp = temp->getNextElement();
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
