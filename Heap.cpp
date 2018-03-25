//
// Created by barto on 24.03.18.
//

#include "Heap.h"

// public

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

void Heap::clear() {
	Array::clear();
}

void Heap::test(string nameOfStructure) {
	nameOfStructure = nameOfStructure.substr(4, nameOfStructure.size() - 8);
	char opt = 0;
	Counter counter;
	int nOE[3] = {50, 10000, 20000};
	int r[3] = {100, RAND_MAX / 2, RAND_MAX};
	int numberOfTests;
	double sumOfResults;
	int index;

	do {
		cout << "- TESTY -" << endl;
		cout << "1. Dodawanie" << endl;
		cout << "2. Usuwanie" << endl;
		cout << "0. Powrot" << endl;
		cout << "Podaj opcje:";
		cin >> opt;
		cout << endl;
		switch (opt) {
			case '1':
				cout << endl << "Podaj ilosc testow: ";
				cin >> numberOfTests;
				for (int i = 0; i < sizeof(nOE) / sizeof(int); i++) {
					for (int j = 0; j < sizeof(r) / sizeof(int); j++) {
						int numberOfElements = nOE[i];
						int range = r[j];

						string path = "..\\wyniki\\";
						path += to_string(time(0));
						path += "-" + nameOfStructure + "-dodawanie-n" + to_string(numberOfElements) + "-r" +
								to_string(range) + ".txt";

						fstream file(path, fstream::out);
						srand(time(NULL));

						if (!file.is_open()) {
							cout << "Wyniki sie nie zapisza!!!" << endl;
						}

						file.setf(ios::fixed);

						sumOfResults = 0;

						for (int k = 0; k < numberOfTests; k++) {
							generate(numberOfElements, range);

							int value = rand() % range;
							counter.startCounter();
							add(value, -1);
							double result = counter.getCounter();
							sumOfResults += result;
							cout << result << endl;
							file << result << endl;
							removePosition(-1);

							clear();
						}

						sumOfResults /= numberOfTests;

						cout << "Srednia: " << sumOfResults << endl;
						file << "Srednia: " << sumOfResults << endl;

						file.close();
					}
				}
				break;
			case '2':
				cout << endl << "Podaj ilosc testow: ";
				cin >> numberOfTests;
				for (int i = 0; i < sizeof(nOE) / sizeof(int); i++) {
					for (int j = 0; j < sizeof(r) / sizeof(int); j++) {
						int numberOfElements = nOE[i];
						int range = r[j];

						string path = "..\\wyniki\\";

						path += to_string(time(0));
						path += "-" + nameOfStructure + "-usuwanie-n" + to_string(numberOfElements) + "-r" +
								to_string(range) + ".txt";

						fstream file(path, fstream::out);
						srand(time(NULL));

						if (!file.is_open()) {
							cout << "Wyniki sie nie zapisza!!!" << endl;
						}

						file.setf(ios::fixed);

						sumOfResults = 0;

						for (int k = 0; k < numberOfTests; k++) {
							generate(numberOfElements, range);

							int value = rand() % range;
							add(value, -1);
							counter.startCounter();
							removePosition(-1);
							double result = counter.getCounter();
							sumOfResults += result;
							cout << result << endl;
							file << result << endl;

							clear();
						}

						sumOfResults /= numberOfTests;

						cout << "Srednia: " << sumOfResults << endl;
						file << "Srednia: " << sumOfResults << endl;

						file.close();
					}
				}
				break;
			case '0':
				break;
			default:
				cout << "Nie ma takiej opcji, wybierz jeszcze raz." << endl;
				break;
		}
	} while (opt != '0');
}

// private

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
	for (int i = getLastParent(); i >= 0; i--) {
		heapifyDown(i);
	}
}

int Heap::getLastParent() {
	return getParent(size - 1);
}

int Heap::getLeftChild(int index) {
	return (2 * index) + 1;
}

int Heap::getRightChild(int index) {
	return (2 * index) + 2;
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
	return (index - 1) / 2;
}

bool Heap::parentExists(int index) {
	if (index <= 0 || index >= size)
		return false;
	else
		return true;
}
