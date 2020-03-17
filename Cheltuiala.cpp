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
    this -> type = new char[strlen(n) + 1];
    strcpy(this -> type, n);
    
}

Cheltuiala::Cheltuiala(const Cheltuiala &c)
{
    this -> day = c.day;
    this -> money = c.money;
    this -> type = new char[strlen(c.type) + 1];
    strcpy(this -> type, c.type);
    
}

Cheltuiala::~Cheltuiala()
{
    if(this -> type)
    {
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
