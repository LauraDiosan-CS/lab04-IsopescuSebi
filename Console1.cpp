
//
//  Console.cpp
//  Laborator 4
//
//  Created by Isopescu Sebastian on 24/03/2020.
//  Copyright © 2020 Isopescu Sebastian. All rights reserved.
//

#include "Console.h"
#include <iostream>
using namespace std;


void Console::meniu()
{
    cout << "a. Adaugarea unei cheltuieli in lista  \n";
    cout << "b. Stergerea cheltuielilor din lista \n";
    cout << "c. Modificarea cheltuielilor \n";
    cout << "d. Afisare \n";
    cout << "x. Iesire \n";
}
    
int Console::console()
{

while (true)
{
    meniu();
    char op;
    cin >> op;

    if (op == 'a')
        this -> add_cheltuiala();
//    else if (op == 'b')
//        this -> delete_cheltuiala();
//    else if (op == 'c')
//        this -> modify_cheltuiala();
    else if (op == 'd')
        this -> show_cheltuieli();
    else if (op == 'x')
        return 0;
}
}

void Console::show_cheltuieli()
    {
        int size = this -> service_cheltuieli.getSizeRepo();
        Cheltuiala* cheltuiala = this -> service_cheltuieli.getAll();
        for(int i = 0; i < size; i++)
            cout << cheltuiala[i];
    }

void Console::add_cheltuiala()
    {
        int day;
        cout <<"Introdu ziua: "<<endl;
        cin >> day;
        
        int money;
        cout << "Introdu suma de bani: ";
        cin >> money;
        
        
        char c[100];
        cout << "Introdu tipul: ";
        cin >> c;
        char* type = new char[strlen(c) + 1];
        strcpy(type, c);
    
        this -> service_cheltuieli.addCheltuiala(day, money, type);
        
    }
    
    


