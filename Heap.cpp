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
	Array::add(value, size);
	heapifyUp(size - 1);
}

void Heap::removePosition(int index) {
	if (index != -1) return;
	_array[0] = _array[size - 1];
	Array::removePosition(size - 1);
	heapifyDown(0);
}

string Heap::print() {
	string temp = "";
	int breakPoint = 0;
	int numOfBP = 0;

	for (int i = 0; i < size; i++) {
		temp += to_string(_array[i]);
		if (size - i > 1) {
			temp += ", ";
			if (i == breakPoint) {
				temp += "\n";
				numOfBP++;
				breakPoint = breakPoint + pow(2, numOfBP);
			}
		}

	}

	temp = "{ " + temp + " }";

	return temp;
}

void Heap::generate(int size, int range) {
	Array::generate(size, range);
	heapify();
}

void Heap::heapifyUp(int index) {
	if (parentExists(index))
		if (_array[getParent(index)] < _array[index]) {
			std::swap(_array[getParent(index)], _array[index]);
			heapifyUp(getParent(index));
		}
}

void Heap::heapifyDown(int index) {
	int largest = index;

	if (leftChildExists(index))
		if (_array[getLeftChild(index)] > _array[index])
			largest = getLeftChild(index);
	if (rightChildExists(index))
		if (_array[getRightChild(index)] > _array[largest])
			largest = getRightChild(index);

	if (largest != index) {
		std::swap(_array[largest], _array[index]);
		heapifyDown(largest);
	}
}

void Heap::heapify() {
	for (int i = getLastParent(); i >= 0 ; i--) {
		heapifyDown(i);
	}
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

void Heap::clear() {
	Array::clear();
}
