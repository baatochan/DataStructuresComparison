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
    Array::test();
}