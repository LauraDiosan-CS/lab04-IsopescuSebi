//
//  Cheltuiala.cpp
//  Laborator 4
//
//  Created by Isopescu Sebastian on 17/03/2020.
//  Copyright © 2020 Isopescu Sebastian. All rights reserved.
//

#include "Cheltuiala.h"
#include <iostream>
#include <string.h>
#include <ostream>
#include <cstddef>

using namespace std;

Cheltuiala::Cheltuiala()
{
    this -> day = 0;
    this -> money = 0;
    this -> type = NULL;
}

Cheltuiala::Cheltuiala(int a, int b, char* n)
{
    this -> day = a;
    this -> money = b;
    this -> type = new char[1 + strlen(n)];
    strcpy(this -> type, n);
    
}

Cheltuiala::Cheltuiala(const Cheltuiala& c)
{
    this -> day = c.day;
    this -> money = c.money;
    this -> type = new char[1 + strlen(c.type)];
    strcpy(this -> type, c.type);

}

Cheltuiala::~Cheltuiala()
{
    this -> day = 0;
    this -> money = 0;
    if(this -> type != NULL)
    {
        delete[] this -> type;
        this -> type = NULL;
    }
}

int Cheltuiala::getDay()
{
    return this -> day;
}

int Cheltuiala::getMoney()
{
    return this -> money;
}

char* Cheltuiala::getType()
{
    return this -> type;
}

void Cheltuiala::setDay(int a)
{
    this -> day = a;
}

void Cheltuiala::setMoney(int a)
{
    this -> money = a;
}

void Cheltuiala::setType(char* type)
{
    if(this -> type != NULL)
        delete[] this -> type;
    if(type != NULL)
    {this -> type = new char [1 + strlen(type)];
        strcpy(this -> type, type);}
    else
        this -> type = NULL;
}
Cheltuiala& Cheltuiala::operator=(const Cheltuiala &c)
{
    this -> setDay(c.day);
    this -> setMoney(c.money);
    this -> setType(c.type);
    
    return *this;
}

bool Cheltuiala::operator==(const Cheltuiala &c)
{
    return (this -> day == c.day) && (this -> money == c.money) && (strcmp(this -> type, c.type) == 0);
}

ostream& operator<<(ostream& os, const Cheltuiala& c)
{
    os << "Cheltuiala din ziua: "<<c.day<<" cu suma: "<<c.money<<" si tipul: "<<c.type<<endl;
    return os;
}
