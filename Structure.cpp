//
// Created by barto on 29.03.17.
//

#include "Structure.h"

// protected

vector<int> Structure::loadRawDataFrom(string path) {
	vector<int> returnIntVector = vector<int>();
	vector<string> values = vector<string>();

	fstream file(path, ios::in);

	if (!file.is_open())
		return returnIntVector;

	string amountOfNumbersS = "";
	getline(file, amountOfNumbersS);
	int amountOfNumbers = stoi(amountOfNumbersS);

	for (int i = 0; i < amountOfNumbers; i++) {
		string temp = "";
		getline(file, temp);
		values.push_back(temp);
	}

	if (values.empty())
		return returnIntVector;

	for (int i = 0; i < values.size(); i++) {
		returnIntVector.push_back(stoi(values[i]));
	}

	return returnIntVector;
}
