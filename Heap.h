//
// Created by barto on 24.03.18.
//

#ifndef DATASTRUCTURESSDIZO_HEAP_H
#define DATASTRUCTURESSDIZO_HEAP_H


#include "Array.h"

class Heap : public Array {
public:

	Heap();

	void loadDataFrom(string fileName) override;

	void add(int value, int index) override;

	void removePosition(int index) override;

	string print() override;

	void generate(int size, int range = RAND_MAX) override;

	void clear() override;

	void test(string nameOfStructure) override;

private:

	void heapifyUp(int index);

	void heapifyDown(int index);

	void heapify(); //Floyd's algorithm

	int getLastParent();

	int getLeftChild(int index);

	int getRightChild(int index);

	bool leftChildExists(int index);

	bool rightChildExists(int index);

	int getParent(int index);

	bool parentExists(int index);
};


#endif //DATASTRUCTURESSDIZO_HEAP_H
