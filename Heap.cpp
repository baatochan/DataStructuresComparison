//
// Created by barto on 15.04.17.
//

#include "Heap.h"

// public

Heap::Heap() {

}

Heap::~Heap() {

}

void Heap::loadDataFrom(string fileName) {
    Array::loadDataFrom(fileName);
}

bool Heap::lookFor(int value) {
    return Array::lookFor(value);
}

void Heap::add(int value, int index) {
    Array::add(value, index);
}

void Heap::remove(int value) {
    Array::remove(value);
}

void Heap::remove(int index, int value) {
    Array::remove(index, value);
}

void Heap::removePosition(int index) {
    Array::removePosition(index);
}

string Heap::print() {
    return Array::print();
}

void Heap::generate(int size) {
    Array::generate(size);
}
