//
// Created by barto on 26.03.17.
//


#include "Program.h"

void Program::start() {
    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1.Tablica" << endl;
        cout << "2.Lista" << endl;
        cout << "3.Kopiec" << endl;
        cout << "4.BST" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        cout << endl;

        switch (option){
            case '1':
                _structure = new Array();
                _isBST = false;
                takeActionInMenu("--- TABLICA ---");
                break;

            case '2':
                _structure = new List();
                _isBST = false;
                takeActionInMenu("--- LISTA ---");
                break;

            case '3':
                _structure = new Heap();
                _isBST = false;
                takeActionInMenu("--- KOPIEC ---");
                break;

            case '4':
                _structure = new BSTree();
                _isBST = true;
                takeActionInMenu("--- BINARY SEARCH TREE ---");
                break;

            case '0':
                break;

            default:
                cout<<"Nie ma takiej opcji, wybierz jeszcze raz."<<endl;
                break;
        }

    } while (option != '0');
}

void Program::displayMenu(string info) {
    cout << endl;
    cout << info << endl;
    cout << "1.Dodaj" << endl;
    cout << "2.Wczytaj z pliku" << endl;
    cout << "3.Utworz losowo" << endl;
    cout << "4.Usun wartosc" << endl;
    cout << "5.Usun pozycje" << endl;
    cout << "6.Usun pozycje, gdy zgadza sie wartosc" << endl;
    cout << "7.Znajdz" << endl;
    cout << "8.Wyswietl" << endl;
    cout << "9.Test (pomiary)" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void Program::takeActionInMenu(string info) {
    char opt = 0;
    string fileName = "";
    int index = 0;
    int value = 0;


    do{
        displayMenu(info);
        cin >> opt;
        cout << endl;
        switch (opt){
            case '1': //cout << "1.Dodaj" << endl;
                if(!_isBST){
                    cout << "podaj index:";
                    cin >> index;
                }
                else _isBST = 0;
                cout << "podaj wartość:";
                cin >> value;

                _structure->add(value,index);
                cout<<_structure->print()<<endl;
                break;

            case '2': //cout << "2.Wczytaj z pliku" << endl;
                cout << " Podaj nazwę pliku:";
                cin >> fileName;
                _structure->loadDataFrom(fileName);
                cout<<_structure->print()<<endl;
                break;

            case '3':  //cout << "3.Utworz losowo" << endl;
                cout << "Podaj ilość elementów:";
                cin >> value;
                _structure->generate(value);
                cout<<_structure->print()<<endl;
                break;

            case '4': //cout << "4.Usun wartosc" << endl;
                cout << "podaj wartosc:";
                cin >> value;
                _structure->remove(value);
                cout<<_structure->print()<<endl;
                break;

            case '5': //cout << "5.Usun pozycje" << endl;
                if(!_isBST){
                    cout << "podaj index:";
                    cin >> index;
                    _structure->removePosition(index);
                    cout<<_structure->print()<<endl;
                }
                else cout<<"Nie dotyczy drzew BST."<<endl;
                break;

            case '6': //cout << "6.Usun pozycje, gdy zgadza sie wartosc" << endl;
                if(!_isBST){
                    cout << "podaj index:";
                    cin >> index;
                    cout << "podaj wartosc:";
                    cin >> value;
                    _structure->remove(index,value);
                    cout<<_structure->print()<<endl;
                }
                else cout<<"Nie dotyczy drzew BST."<<endl;
                break;

            case '7': //cout << "7.Znajdz" << endl;
                cout << " podaj waertość:";
                cin >> value;
                if (_structure->lookFor(value))
                    cout << "poadana wartośc jest w strukturze";
                else
                    cout << "poadanej wartości NIE ma w strukturze";
                break;

            case '8':  //cout << "8.Wyswietl" << endl;
                cout<<_structure->print()<<endl;
                break;

            case '9': //cout << "9.Test (pomiary)" << endl;
                // można sobie tu dodać własne case'y
                //((Heap*)_structure)->test();
                break;

            case '0':
                break;

            default:
                cout<<"Nie ma takiej opcji, wybierz jeszcze raz."<<endl;
                break;
        }

    } while (opt != '0');

    delete _structure;
}
