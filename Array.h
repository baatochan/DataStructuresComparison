//
// Created by barto on 11.04.17.
//

#ifndef DATASTRUCTURESSDIZO_ARRAY_H
#define DATASTRUCTURESSDIZO_ARRAY_H


#include "Structure.h"

class Array : public Structure {
protected:

	int *_array;

public:
	Array();

	~Array();

	void loadDataFrom(string fileName) override;

	int lookFor(int value, bool doPrint) override;

	void add(int value, int index) override;

	void remove(int value) override;

	void remove(int index, int value) override;

	void removePosition(int index) override;

	string print() override;

	void generate(int size, int range = RAND_MAX) override;

	void clear() override;

};


#endif //DATASTRUCTURESSDIZO_ARRAY_H
