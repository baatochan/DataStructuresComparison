//
// Created by barto on 24.03.18.
//

#include "Heap.h"

Heap::Heap() : Array() {}

void Heap::loadDataFrom(string fileName) {
	Array::loadDataFrom(fileName);
	heapify();
}

void Heap::add(int value, int index) {
	if (index != -1) return;
	Array::add(value, size - 1);
	heapifyUp(size - 1);
}

void Heap::removePosition(int index) {
	if (index != -1) return;
	_array[0] = _array[size - 1];
	Array::removePosition(size - 1);
	heapifyDown(0);
}

string Heap::print() {
	return Array::print();
}

void Heap::generate(int size, int range) {
	Array::generate(size, range);
	heapify();
}

void Heap::test() {
	Array::test();
}

void Heap::heapifyUp(int index) {

}

void Heap::heapifyDown(int index) {

}

void Heap::heapify() {

}

int Heap::getLastParent() {
	return getParent(size-1);
}

int Heap::getLeftChild(int index) {
	return (2*index) + 1;
}

int Heap::getRightChild(int index) {
	return (2*index) + 2;
}

bool Heap::leftChildExists(int index) {
	if (getLeftChild(index) >= size)
		return false;
	else
		return true;
}

bool Heap::rightChildExists(int index) {
	if (getRightChild(index) >= size)
		return false;
	else
		return true;
}

int Heap::getParent(int index) {
	return (index-1)/2;
}

bool Heap::parentExists(int index) {
	if (index <= 0 || index >= size)
		return false;
	else
		return true;
}
