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


void Console::menu() {
    cout << "a. Adaugarea unei cheltuieli in lista  "<<endl;
    cout << "b. Modificarea cheltuielilor din lista "<<endl;
    cout << "c. Stabilirea cheltuielilor cu anumite proprietati "<<endl;
    cout << "d. Obtinerea unor proprietati a diferitelor subliste "<<endl;
    cout << "e. Filtrarea listei de cheltuieli "<<endl;
    cout << "f. Afisare "<<endl;
    cout << "g. Afisare buget "<<endl;
    cout << "x. Iesire "<<endl;



}

int Console::console()
{


    while (true)
    {
        menu();
        cout << "Introduceti o optiune: ";
        char optiune;
        cin >> optiune;

        if (optiune == 'a')
        {

            cout << "1. Ex. Adauga 10 internet - adauga pentru ziua curenta o cheltuiala de 10 RON pentru internet "<<endl;
            cout << "2. Ex. Insereaza 25 100 mancare - insereaza pentru ziua 25 a lunii curente o cheltuiala de 100 RON pentru mancare "<<endl;


            cout << "Introduceti o optiune: ";
            char optiune2;
            cin >> optiune2;

            if (optiune2 == '1')
            {
                this -> add_current_day_cheltuiala();
            }
            else if (optiune2 == '2')
            {
                this -> add_cheltuiala_with_day();
            }
        }
        else if (optiune == 'b') {

            cout << "1. Ex. Elimina 15 - elimina toate cheltuielile din ziua 15 "<<endl;
            cout << "2. Ex. Elimină 2 la 9 - elimină toate cheltuielile pentru zilele 2,3, ..., 9"<<endl;
            cout << "3. Ex. Elimina mancare - elimina totate cheltuielile pentru mancare"<<endl;
            cout << "4. Moficare cheltuiala total \n";

            cout << "Introduceti o optiune: ";
            char optiune2;
            cin >> optiune2;

            if (optiune2 == '1')
            {
                this -> delete_cheltuiala_day();
            }
            else if (optiune2 == '2')
            {
                this -> delete_cheltuiala_from_int();          }
            else if (optiune2 == '3')
            {
                this -> delete_item_by_type();          }
            else if (optiune2 == '4')
            {
                this -> update_cheltuiala();
            }
        }
        else if (optiune == 'c')
        {

            cout << "1. Ex. Listeaza mancare - afisarea tuturor cheltuielilor pentru mancare ";
            cout << "2. Ex. Listeaza mancare > 5 - afisarea tuturor cheltuielilor pentru mancare mai mari de 5 RON \n";
            cout << "3. Ex. Listeaza internet = 44 - afisarea tuturor cheltuielilor pentru internet in valoare de 44 RON \n";

            cout << "Introduceti o optiune: ";
            char optiune2;
            cin >> optiune2;

            if (optiune2 == '1')
            {
                this->show_cheltuieli_by_type();
            }
            else if (optiune2 == '2')
            {
                this->show_cheltuiala_by_type_and_money1();
            }
            else if (optiune2 == '3')
            {
                this->show_cheltuiala_by_type_and_money2();
            }
        }
        else if (optiune == 'd')
        {

            cout << "1. Ex. Suma mancare - suma tuturor cheltuielilor din categoria mancare \n";
            cout << "2. Ex. Max zi - afisarea zilei cu cele mai mari cheltuieli \n";
            cout << "3. Ex. Sortare zi - afisarea sumelor cheltuite zilnic in ordine descrescatoare \n";
            cout << "4. Ex. Sorteaza mancare - afisarea sumelor cheltuite zilnic pentru mancare, ordonate crescator \n";


            cout << "Introduceti o optiune: ";
            char optiune2;
            cin >> optiune2;

            if (optiune2 == '1')
            {
                this -> sum_by_day();
            }
            else if (optiune2 == '2')
            {
                this -> max_day();
            }
            else if (optiune2 == '3')
            {
                this -> sort_sum_desc();
            }
            else if (optiune2 == '4')
            {
                this -> sort_sum_by_type();
            }
        }
        else if (optiune == 'e')
        {

            cout << "1. Ex. Filtrare mancare - pastreaza doar cheltuielile pentru mancare \n";
            cout << "2. Ex. Filtrare menaj < 100 - pastreaza doar cheltuielile pentru menaj mai mici decat 100 RON \n";
            cout << "3. Ex. Filtrare haine = 59 - pastreaza doar cheltuielile pentru haine egale cu 59 RON  \n";

            cout << "Introduceti o optiune: ";
            char optiune2;
            cin >> optiune2;

            if (optiune2 == '1')
            {
                this -> filter_by_type();
            }
            else if (optiune2 == '2')
            {
                this -> filter_by_type_and_money1();
            }


            else if (optiune2 == '3')
            {
                this -> filter_by_type_and_money2();
            }

        }
        else if (optiune == 'f') {
            this -> show_cheltuieli();
        }
        else if (optiune == 'x')
            return 0;
        else if (optiune == 'g')
        {
            cout << "Bugetul a inceput de la 100000 si s-a redus din cauza cheltuielilor lunare la : " << this -> service_cheltuieli.getBuget() << "\n";
        }


    }
}

void Console::add_current_day_cheltuiala()
{
    cout << "Introduceti suma de bani: ";
    int money;
    cin >> money;
    
    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type = new char[strlen(t) + 1];
    strcpy(type, t);

    this->service_cheltuieli.addCurrDay(money, type);
}


void Console::show_cheltuieli()
{
    int size = this -> service_cheltuieli.getSizeRepo();
    Cheltuiala* cheltuieli = this -> service_cheltuieli.getAll();
    for (int i = 0; i < size; i++) {
        cout << cheltuieli[i];

    }


}



void Console::add_cheltuiala_with_day()
{
    cout << "Introduceti ziua: ";
    int day;
    cin >> day;
    
    cout << "Introduceti suma de bani: ";
    int money;
    cin >> money;
    
    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type = new char[strlen(t) + 1];
    strcpy(type, t);

    this->service_cheltuieli.addCheltuiala(day, money, type);
}

void Console::delete_cheltuiala_day()
{
    cout << "Introduceti ziua: ";
    int day;
    cin >> day;

    this->service_cheltuieli.deleteItemByDay(day);
}


void Console::delete_cheltuiala_from_int()
{
    cout << "Introduceti ziua de la primul capat al intervalului: ";
    int day1;
    cin >> day1;
    cout << "Introduceti ziua de la celalalt capat: ";
    int day2;
    cin >> day2;
    
    this->service_cheltuieli.deleteItemFromInt(day1, day2);
}


void Console::delete_item_by_type()
{
    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type = new char[strlen(t) + 1];
    strcpy(type, t);
    this->service_cheltuieli.deleteItemByType(type);
    delete[] type;
}


void Console::show_cheltuieli_by_type()
{
    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type = new char[strlen(t) + 1];
    strcpy(type, t);

    Cheltuiala rez[100];
    int res = 0;
    
    this->service_cheltuieli.getItemByType(type, rez, res);
    this->show_items(res, rez);
    delete[] type;

}

void Console::show_cheltuiala_by_type_and_money1()
{
    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type = new char[strlen(t) + 1];
    strcpy(type, t);
    
    cout << "Introduceti suma de bani: ";
    int money;
    cin >> money;
    
    Cheltuiala rez[100];
    int res = 0;
    
    this->service_cheltuieli.getItemByTypeAndMoney1(money, type, rez, res);
    this->show_items(res, rez);
    delete[] type;

}

void Console::show_cheltuiala_by_type_and_money2()
{
    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type = new char[strlen(t) + 1];
    strcpy(type, t);
    
    cout << "Introduceti suma de bani: ";
    int money;
    cin >> money;
    
    Cheltuiala rez[100];
    int res = 0;
    this->service_cheltuieli.getItemByTypeAndMoney2(money, type, rez, res);
    this->show_items(res, rez);
    delete[] type;

}

void Console::sum_by_day()
{

    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type = new char[strlen(t) + 1];
    strcpy(type, t);
    
    int s = this->service_cheltuieli.sumByType(type);
    cout << " Suma tuturor cheltuielilor cu tipul "<<type<<" este "<<s <<endl;

    delete[] type;
}

void Console::max_day()
{

    int day = this->service_cheltuieli.maxDay();

    cout << " Ziua cu cele mai mari cheltueili este: "<<day <<endl;

}

void Console::sort_sum_desc()
{
    int res = 0;
    Cheltuiala rez[100];
    this->service_cheltuieli.sortSumDesc(rez, res);

    for (int i = 0; i < res; i++) {
        cout << rez[i].getMoney()<<" ";
    }

    cout<<endl;

}

void Console::sort_sum_by_type()
{
    Cheltuiala rez[100];
    
    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type = new char[strlen(t) + 1];
    strcpy(type, t);
    
    int res = 0;
    this->service_cheltuieli.sortSumByType(type, rez, res);

    for (int i = 0; i < res; i++) {
        cout <<rez[i].getMoney()<<" ";
    }

    cout<<endl;

    delete[] type;

}

void Console::filter_by_type()
{
    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type = new char[strlen(t) + 1];
    strcpy(type, t);
    

    this->service_cheltuieli.fillterByType(type);
    
    
    delete[] type;
}

void Console::filter_by_type_and_money1()
{
    cout << "Introduceti suma de bani: ";
    int money;
    cin >> money;
    
    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type = new char[strlen(t) + 1];
    strcpy(type, t);
    

    this->service_cheltuieli.fillterByTypeAndMoney(type, money);

    delete[] type;
}

void Console::filter_by_type_and_money2()
{
    cout << "Introduceti suma de bani: ";
    int money;
    cin >> money;
    
    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type = new char[strlen(t) + 1];
    strcpy(type, t);
    

    this->service_cheltuieli.fillterByTypeAndMoney2(type, money);
    delete[] type;
}

void Console::update_cheltuiala()
{
    cout << "Cheltuiala pe care vrei sa o modifici are urmatoarele caracteristici: ";
    
    cout << "Introduceti ziua: ";
    int day1;
    cin >> day1;
    
    cout << "Introduceti suma de bani: ";
    int money1;
    cin >> money1;
    
    cout << "Introduceti tipul: ";
    char t[100];
    cin >> t;
    char* type1 = new char[strlen(t) + 1];
    strcpy(type1, t);

    cout << "Noile caracteristici sunt: "<<endl;
    
    cout << "Introduceti ziua: ";
    int day2;
    cin >> day2;

    cout << "Introduceti suma de bani: ";
    int money2;
    cin >> money2;

    
    cout << "Introduceti tipul: ";
    char t2[100];
    cin >> t2;
    char* type2 = new char[strlen(t2) + 1];
    strcpy(type2, t2);

    this -> service_cheltuieli.update(day1, money1, type1, day2, money2, type2);

    delete[] type1;
    delete[] type2;

}

void Console::show_items(int n, Cheltuiala cheltuieli[])
{
    for (int i = 0; i < n; i++)
        cout << cheltuieli[i];
        cout << endl;
}

