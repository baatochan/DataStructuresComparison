//
// Created by barto on 26.03.17.
//


#include "Program.h"

// public

void Program::start() {
	char option;
	do {
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		cin >> option;
		cout << endl;

		switch (option) {
			case '1':
				_structure = new Array();
				_isHeap = false;
				useMenu("--- TABLICA ---");
				break;

			case '2':
				_structure = new List();
				_isHeap = false;
				useMenu("--- LISTA ---");
				break;

			case '3':
				_structure = new Heap();
				_isHeap = true;
				useMenu("--- KOPIEC ---");
				break;

			case '0':
				break;

			default:
				cout << "Nie ma takiej opcji, wybierz jeszcze raz." << endl;
				break;
		}

	} while (option != '0');
}

// private

void Program::printMenu(string info) {
	cout << endl;
	cout << info << endl;
	cout << "1.Dodaj" << endl;
	cout << "2.Wczytaj z pliku" << endl;
	cout << "3.Utworz losowo" << endl;
	if (_isHeap) {
		cout << "5.Usun korzen" << endl;
	} else {
		cout << "4.Usun wartosc" << endl;
		cout << "5.Usun pozycje" << endl;
		cout << "6.Usun pozycje, gdy zgadza sie wartosc" << endl;
	}
	cout << "7.Znajdz" << endl;
	cout << "8.Wyswietl" << endl;
	cout << "9.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void Program::useMenu(string info) {
	char opt = 0;
	string fileName = "";
	int index = 0;
	int value = 0;

	do {
		printMenu(info);
		cin >> opt;
		cout << endl;

		switch (opt) {
			case '1': //cout << "1.Dodaj" << endl;
				if (!_isHeap) {
					cout << "Podaj index:";
					cin >> index;
				} else {
					index = -1;
				}
				cout << "Podaj wartosc:";
				cin >> value;

				_structure->add(value, index);
				cout << _structure->print() << endl;
				break;

			case '2': //cout << "2.Wczytaj z pliku" << endl;
				cout << "Podaj nazwe pliku:";
				cin >> fileName;
				_structure->loadDataFrom(fileName);
				cout << _structure->print() << endl;
				break;

			case '3':  //cout << "3.Utworz losowo" << endl;
				cout << "Podaj ilosc elementow:";
				cin >> value;
				_structure->generate(value);
				cout << _structure->print() << endl;
				break;

			case '4': //cout << "4.Usun wartosc" << endl;
				if (!_isHeap) {
					cout << "Podaj wartosc:";
					cin >> value;
					_structure->remove(value);
					cout << _structure->print() << endl;
				} else {
					cout << "Nie ma takiej opcji, wybierz jeszcze raz." << endl;
				}
				break;

			case '5': //cout << "5.Usun pozycje" << endl;
				if (!_isHeap) {
					cout << "Podaj index:";
					cin >> index;
				} else {
					index = -1;
				}
				_structure->removePosition(index);
				cout << _structure->print() << endl;
				break;

			case '6': //cout << "6.Usun pozycje, gdy zgadza sie wartosc" << endl;
				if (!_isHeap) {
					cout << "Podaj index:";
					cin >> index;
					cout << "Podaj wartosc:";
					cin >> value;
					_structure->remove(index, value);
					cout << _structure->print() << endl;
				} else {
					cout << "Nie ma takiej opcji, wybierz jeszcze raz." << endl;
				}
				break;

			case '7': //cout << "7.Znajdz" << endl;
				cout << "Podaj waertosc:";
				cin >> value;
				if (_structure->lookFor(value))
					cout << "Podana wartosc jest w strukturze";
				else
					cout << "Podanej wartosci NIE ma w strukturze";
				break;

			case '8':  //cout << "8.Wyswietl" << endl;
				cout << _structure->print() << endl;
				break;

			case '9': //cout << "9.Test (pomiary)" << endl;
				// mozna sobie tu dodac wlasne case'y
				_structure->test(info);
				break;

			case '0':
				break;

			default:
				cout << "Nie ma takiej opcji, wybierz jeszcze raz." << endl;
				break;
		}

	} while (opt != '0');

	delete _structure;
}
