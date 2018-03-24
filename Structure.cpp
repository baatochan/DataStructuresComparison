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

void Structure::test(string nameOfStructure) {
	char opt = 0;
	Counter counter;
	int nOE[3] = {50, 10000, 20000};
	int r[3] = {100, RAND_MAX/2, RAND_MAX};
	int numberOfTests;
	double sumOfResults;

	do {
		cout<<"- TESTY -"<<endl;
		cout<<"1. Dodawanie na poczatku"<<endl;
		cout<<"2. Dodawanie na koncu"<<endl;
		cout<<"3. Dodawanie w srodku"<<endl;
		cout<<"4. Usuwanie na poczatku"<<endl;
		cout<<"5. Usuwanie na koncu"<<endl;
		cout<<"6. Usuwanie w srodku"<<endl;
		cout<<"0. Powrot"<<endl;
		cout << "Podaj opcje:";
		cin >> opt;
		cout << endl;
		switch (opt) {
			case '1':
				cout<<endl<<"Podaj ilosc testow: ";
				cin>>numberOfTests;
				for (int i = 0; i < sizeof(nOE) ; i++) {
					for (int j = 0; j < sizeof(r); j++) {
						int numberOfElements = nOE[i];
						int range = r[j];

						string path = "..\\wyniki\\";
						nameOfStructure = nameOfStructure.substr(4, nameOfStructure.size()-8);
						path += to_string(time(0));
						path += "-" + nameOfStructure + "-dodawanie-n" + to_string(numberOfElements) + "-r" + to_string(range) + ".txt";

						fstream file(path, fstream::out);
						srand(time(NULL));

						if(!file.is_open()) {
							cout<<"Wyniki się nie zapiszą!!!"<<endl;
						}

						generate(numberOfElements,range);

						file.setf(ios::fixed);

						sumOfResults = 0;

						for (int i = 0; i < numberOfTests; i++) {
							int value = rand() % range;
							counter.startCounter();
							add(value, 0);
							double result = counter.getCounter();
							sumOfResults += result;
							cout<<result<<endl;
							file<<result<<endl;
							removePosition(0);
						}

						sumOfResults /= numberOfTests;

						cout<<"Srednia: "<<sumOfResults<<endl;
						file<<"Srednia: "<<sumOfResults<<endl;

						file.close();

						clear();
					}
				}
				break;
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '0':
			default:
				cout << "Nie ma takiej opcji, wybierz jeszcze raz." << endl;
				break;
		}
	} while (opt != '0');
}
