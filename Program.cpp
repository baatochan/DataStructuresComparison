//
// Created by barto on 26.03.17.
//
#include <iostream>
#include "Program.h"

using namespace std;

void Program::Start() {
    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1.Tablica" << endl;
        cout << "2.Lista" << endl;
        cout << "3.Kopiec" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        cout << endl;

        switch (option){
            case '1':
                //myStructure = new Table();
                //displayMenu("--- TABLICA ---");
                //takeActionInMenu();
                break;

            case '2':
                myStructure = new List();
                displayMenu("--- LISTA ---");
                takeActionInMenu();
                break;

            case '3':
                //myStructure = new Heap();
                //displayMenu("--- KOPIEC ---");
                //takeActionInMenu();
                break;
        }

    } while (option != '0');
}

void Program::displayMenu(string info) {
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku" << endl;
    cout << "2.Usun" << endl;
    cout << "3.Dodaj" << endl;
    cout << "4.Znajdz" << endl;
    cout << "5.Utworz losowo" << endl;
    cout << "6.Wyswietl" << endl;
    cout << "7.Test (pomiary)" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}


void Program::takeActionInMenu() {
    char opt;
    string fileName;
    int index, value;


    do{
        cin >> opt;
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << " Podaj nazwę zbioru:";
                cin >> fileName;
                myStructure->loadFrom(fileName);
                myStructure->display();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj index:";
                cin >> index;
                myStructure->remove(index);
                myStructure->display();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj waertość:";
                cin >> value;

                myStructure->add(index,value);
                myStructure->display();
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj waertość:";
                cin >> value;
                if (myStructure->lookFor(value))
                    cout << "poadana wartośc jest w tablicy";
                else
                    cout << "poadanej wartości NIE ma w tablicy";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilość elementów tablicy:";
                cin >> value;
                myStructure->generate(value);
                myStructure->display();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                myStructure->display();
                break;

            case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                // można sobie tu dodać własne case'y
                break;
        }

    } while (opt != '0');
}

