//
// Created by barto on 26.03.17.
//

#include <iostream>
#include "List.h"
#include "ListElement.h"

using namespace std;

List::List() {
    firstElement = NULL;
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
    if(index<0) {
        cout<<"Błędny indeks"<<endl;
        return;
    }

}

void List::deleteValue(int index) {

}

void List::display() {
    ListElement * temp = firstElement;
    cout<<"Zawartość listy: "<<endl;
    while (temp->getNextElement()!=NULL) {
        cout<<temp->getValue()<<" ";
        temp = temp->getNextElement();
    }
}

void List::generateList(int size) {
    if(firstElement!=NULL) {
        cout<<"Lista nie jest pusta! Usuń listę i spróbuj ponownie.";
        return;
    }
    this->size = size;
    for (int i = 0; i < size; i++) {
        int tempValue = rand();
        addValue(i,tempValue);
    }
}
