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
    this -> buget = 100000;
}

Repo::~Repo()
{
    this -> noCheltuieli = 0;
    this -> buget = 0;
}

void Repo::addItem(Cheltuiala &c)
{
    this -> cheltuieli[this -> noCheltuieli++] = c;
    this -> buget -= c.getMoney();
}


Cheltuiala Repo::getItemFromPos(int pos)
{
    return this -> cheltuieli[pos];
}

int Repo::getSize()
{
    return this -> noCheltuieli;
}

Cheltuiala* Repo::getAll()
{
    return this -> cheltuieli;
}

int Repo::getBuget()
{
    return this -> buget;
}

void Repo::setSize(int a)
{
    this -> noCheltuieli = a;
}

int Repo::search(const Cheltuiala& c)
{
    for(int i = 0; i < this ->getSize(); i++)
    {if(this -> cheltuieli[i] == c)
    {return i;}}
    return -1;
}

void Repo::setBuget(int a)
{
    this -> buget = a;
}


void Repo::stergere(Cheltuiala c)
{
    int pozitie = this -> search(c);
    int lungime = this -> getSize();
    
    if(pozitie != -1)
    {
        for(int i = pozitie; i < lungime - 1; i ++)
        {this ->cheltuieli[i] = this -> cheltuieli[i + 1];}
    this -> setBuget(this -> buget + cheltuieli[pozitie].getMoney());
    this -> cheltuieli[lungime - 1] = Cheltuiala();
    this -> setSize(lungime - 1);
    }
}

Repo::Repo(Cheltuiala cheltuieli[], int n, int buget)
{
    this -> buget = buget;
    this -> noCheltuieli = n;
    
    for(int i = 0; i < n; i++)
        this -> cheltuieli[i] = cheltuieli[i];
}

Repo& Repo::operator=(Repo& r)
{
    this -> noCheltuieli = 0;
    
    for(int i = 0; i < this -> noCheltuieli; i++)
        this -> addItem(r.getAll()[i]);
    return *this;
}

void Repo::update(Cheltuiala c1, Cheltuiala c2)
{
    for(int i = 0; i < this -> getSize(); i++)
        if(this -> cheltuieli[i] == c1)
        {
            this -> setBuget(this ->buget + c1.getMoney() - c2.getMoney());
            this -> cheltuieli[i] = c2;
            break;
        }
    
    
    
};


