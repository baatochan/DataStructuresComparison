//
// Created by barto on 15.04.17.
//

#include "Heap.h"

// public

Heap::Heap() : Array() {}

void Heap::loadDataFrom(string fileName) {
    Array::loadDataFrom(fileName);
    heapifyEverything();
}

void Heap::add(int value, int index) {
    if(index >= size){
        index = size;
        Array::add(value, index);
        heapifyWayUp(index);
    }
    else {
        Array::add(value, index);
        heapifyEverything();
    }

}

void Heap::remove(int value) {
    Array::remove(value);
    heapifyEverything();
}

void Heap::remove(int index, int value) {
    Array::remove(index, value);
    heapifyEverything();
}

void Heap::removePosition(int index) {
    Array::removePosition(index);
    if (index < (size - 1))
        heapifyEverything();
}

string Heap::print() {
    return Array::print();
}

void Heap::generate(int size, int range) {
    Array::generate(size, range);
    heapifyEverything();
}

// private

void Heap::heapifyEverything() {
    for (int i = size; i >= 0; --i) {
        heapify(i);
    }
}

void Heap::heapifyWayUp(int index) {
    int level = getLevel(index);
    for (int i = 0; i < level; i++) {
        heapify(index);
        index = getParent(index);
    }
}

void Heap::heapify(int index) {
    int parent = getParent(index);
    if (_array[index]>_array[parent]) {
        int tmp = _array[index];
        _array[index] = _array[parent];
        _array[parent] = tmp;
    }
}

int Heap::getParent(int index) {
    return (index-1)/2;
}

int Heap::getLevel(int index) {
    int level = 0;
    int tmp = 0;
    while (tmp < index) {
        level++;
        tmp = (int)pow(2,level+1);
        tmp -= 2;
    }
    return level;
}

void Heap::test() {
    Counter counter;
    int nOE[3] = {50, 10000, 20000};
    int r[3] = {100, RAND_MAX/2, RAND_MAX};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int numberOfElements = nOE[i];
            int range = r[j];

            string path = "C:\\cpp\\DataStructuresSDiZO\\wyniki\\";
            path += "kopiec-";
            path += "dodawanie-";
            path += to_string(numberOfElements) + "-";
            path += to_string(range) + ".txt";

            fstream file(path, fstream::out);
            srand(time(NULL));

            if(!file.is_open()) {
                cout<<"Wyniki się nie zapiszą!!!"<<endl;
                return;
            }

            generate(numberOfElements,range);

            file.setf(ios::fixed);

            for (int i = 0; i < 10; i++) {
                int value = rand() % range;
                counter.startCounter();
                add(value, size);
                double result = counter.getCounter();
                cout<<result<<endl;
                file<<result<<endl;
                removePosition(size - 1);
            }

            file.close();
        }
    }
}
