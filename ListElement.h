//
// Created by barto on 26.03.17.
//

#ifndef DATASTRUCTURESSDIZO_LISTELEMENT_H
#define DATASTRUCTURESSDIZO_LISTELEMENT_H


class ListElement {
private:
    ListElement *nextElement;
    int value;
public:
    ListElement(int value);
    int getValue();
    ListElement * getNextElement();
    void setValue(int value);
    void setNextElement(ListElement* nextElement);
};


#endif //DATASTRUCTURESSDIZO_LISTELEMENT_H
