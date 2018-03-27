//
// Created by barto on 11.04.17.
//

#include "Array.h"

// public

Array::Array() {
	size = 0;
	_array = new int[0];
}

Array::~Array() {
	delete[] _array;
}

void Array::loadDataFrom(string fileName) {
	vector<int> data = loadRawDataFrom(fileName);

	for (int i = 0; i < data.size(); i++) {
		Array::add(data[i], size);
	}
}

int Array::lookFor(int value, bool doPrint) {
	int valueExistsTimes = 0;

	for (int i = 0; i < size; i++) {
		if (_array[i] == value) {
			valueExistsTimes++;
			if (doPrint)
				cout << "Wartosc znajduje sie pod indeksem " + to_string(i) << endl;
		}
	}

	return valueExistsTimes;
}

void Array::add(int value, int index) {
	if (index < 0) {
		cout << "Indeks nie moze byc ujemny!" << endl;
		return;
	} else if (index < size) {
		if (_array[index] != 0) {
			int *tempArr = new int[++size];
			int i;
			for (i = 0; i < index; i++) {
				tempArr[i] = _array[i];
			}
			tempArr[i++] = value;
			for (i; i < size; i++) {
				tempArr[i] = _array[i - 1];
			}

			delete[] _array;
			_array = tempArr;
		} else {
			_array[index] = value;
		}
	} else if (index == size) {
		int *tempArr = new int[++size];
		for (int i = 0; i < size - 1; i++) {
			tempArr[i] = _array[i];
		}
		tempArr[index] = value;

		delete[] _array;
		_array = tempArr;
	} else if (index > size) {
		int *tempArr = new int[index + 1];
		int oldSize = size;
		size = index + 1;
		int i;
		for (i = 0; i < oldSize; i++) {
			tempArr[i] = _array[i];
		}
		for (i; i < index; i++) {
			tempArr[i] = 0;
		}
		tempArr[i] = value;

		delete[] _array;
		_array = tempArr;
	}
}

void Array::remove(int value) {
	for (int i = 0; i < size; i++) {
		if (_array[i] == value) {
			removePosition(i);
			i--;
		}
	}
}

void Array::remove(int index, int value) {
	if (_array[index] == value)
		removePosition(index);
}

void Array::removePosition(int index) {
	if (index < 0) {
		cout << "Indeks nie moze byc ujemny!" << endl;
		return;
	} else if (index >= size) {
		cout << "Tablica nie posida tego indeksu, tablica jest krotsza" << endl;
	} else {
		int *tempArr = new int[size - 1];
		int i = 0;
		for (i; i < index; i++) {
			tempArr[i] = _array[i];
		}
		for (i; i < size - 1; i++) {
			tempArr[i] = _array[i + 1];
		}
		size--;
		delete[] _array;
		_array = tempArr;
	}

}

string Array::print() {
	string temp = "";

	for (int i = 0; i < size; i++) {
		temp += to_string(_array[i]);
		if (size - i > 1) temp += ", ";
	}

	temp = "{ " + temp + " }";

	return temp;
}

void Array::generate(int size, int range) {
	srand(time(NULL));

	for (int i = 0; i < size; ++i) {
		Array::add((rand() % (range + 1)), this->size);
	}
}

void Array::clear() {
	delete[] _array;
	size = 0;
	_array = new int[0];
}
