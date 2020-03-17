//
//  Repo.cpp
//  Laborator 4
//
//  Created by Isopescu Sebastian on 17/03/2020.
//  Copyright © 2020 Isopescu Sebastian. All rights reserved.
//
#include <iostream>
#include "Repo.h"
#include "Cheltuiala.h"
using namespace std;

Repo::Repo()
{
    this -> noCheltuieli = 0 ;
}

Repo::~Repo(){}

void Repo::addItem(Cheltuiala &c)
{
    this -> cheltuieli[this -> noCheltuieli++] = c;
}

Cheltuiala Repo::getItemFromPos(int pos)
{
    return this -> cheltuieli[pos];
}

int Repo::getSize()
{
    return this -> noCheltuieli;
}

