//
//  Service.cpp
//  Laborator 4
//
//  Created by Isopescu Sebastian on 24/03/2020.
//  Copyright © 2020 Isopescu Sebastian. All rights reserved.
//




#include "Service.h"
#include <ctime>

int Service::getCurrDay()
{
    time_t now = time(0);
    tm* localT = localtime(&now);
    
    return localT -> tm_mday;
}

void Service::addCheltuiala(int day, int money, char* type)
{
    Cheltuiala newC(day, money, type);
    this -> repoCheltuiala.addItem(newC);
}

void Service::addCurrDay(int money, char* type)
{
    int day = getCurrDay();
    Cheltuiala cheltuiala(day, money, type);
    this -> repoCheltuiala.addItem(cheltuiala);
}

Cheltuiala* Service::getAll()
{

    return this -> repoCheltuiala.getAll();
}

void Service::deleteItemByDay(int day)
{


    for (int i = 0; i < this->repoCheltuiala.getSize(); i++) {

        if (this -> getAll()[i].getDay() == day) {
            this -> repoCheltuiala.stergere(this -> getAll()[i]);
            i--;
        }
    }
}

void Service::deleteItemFromInt(int day1, int day2)
{
    for(int i = 0; i < this -> repoCheltuiala.getSize(); i ++)
    {if(this -> getAll()[i].getDay() >= day1 && this ->getAll()[i].getDay() <= day2)
    {this -> repoCheltuiala.stergere(this -> getAll()[i]);
        i--;}}
}

void Service::deleteItemByType(char* type)
{
    int i = 0;
    while (i < this -> repoCheltuiala.getSize())
    {
        if (strcmp(this -> getAll()[i].getType(), type) == 0)
            this -> repoCheltuiala.stergere(this -> getAll()[i]);
        else
            i++;
    }
}

void Service::getItemByType(char* type, Cheltuiala cheltuieli[], int& res)
{
    res = 0;
    for(int i = 0; i < this -> repoCheltuiala.getSize(); i++)
        if(strcmp(this ->getAll()[i].getType(), type) == 0)
            cheltuieli[res ++] = this -> getAll()[i];
}

void Service::getItemByTypeAndMoney1(int money, char* type, Cheltuiala cheltuieli[], int& res)
{
    res = 0;
    for(int i = 0; i < this ->repoCheltuiala.getSize(); i++)
        if(strcmp(this -> getAll()[i].getType(), type) == 0 && this -> getAll()[i].getMoney() > money)
            cheltuieli[res ++] = this -> getAll()[i];
}

void Service::getItemByTypeAndMoney2(int money, char* type, Cheltuiala cheltuieli[], int& res)
{
    res = 0;
    for(int i = 0; i < this ->repoCheltuiala.getSize(); i++)
        if(strcmp(this -> getAll()[i].getType(), type) == 0 && this -> getAll()[i].getMoney() == money)
            cheltuieli[res ++] = this -> getAll()[i];
}
int Service::sumByType(char* type)
{
    int s = 0;
    for(int i = 0; i < this -> repoCheltuiala.getSize(); i++)
        if(strcmp(this -> getAll()[i].getType(), type) == 0)
            s += this -> getAll()[i].getMoney();
    return s;
}

int Service::maxDay()
{
    int v[32] = {0};
    int max = -1;
    int max1 = -1;
    for(int i = 0; i < this -> repoCheltuiala.getSize(); i ++)
    {v[this -> getAll()[i].getDay()] += this -> getAll()[i].getMoney();
    if(v[this -> getAll()[i].getDay()] > max)
    {max = v[this -> getAll()[i].getDay()];
        max1 = this -> getAll()[i].getDay();}}
    return max1;
}

void Service::sortSumDesc(Cheltuiala cheltuieli[], int& res)
{
    res = 0;
    int ok = 1;
    Cheltuiala aux;
    
    for(int i = 0; i < this -> repoCheltuiala.getSize(); i++)
        cheltuieli[res ++] = this -> getAll()[i];
    
    while (ok == 1)
    {ok = 0;
    for(int i = 0; i < res - 1; i++)
        if(cheltuieli[i].getMoney() < cheltuieli[i + 1].getMoney())
        {
            aux = cheltuieli[i];
            cheltuieli[i] = cheltuieli[i + 1];
            cheltuieli[i + 1] = aux;
            ok = 1;
        }
    }
}

void Service::sortSumByType(char* type, Cheltuiala cheltuieli[], int& res)
{
    res = 0;
    int ok = 1;
    Cheltuiala aux;
    for(int i = 0; i < this -> repoCheltuiala.getSize(); i++)
        if(strcmp(this -> getAll()[i].getType(), type) == 0)
            cheltuieli[res ++] = this -> getAll()[i];
    
        while (ok == 1)
           {ok = 0;
           for(int i = 0; i < res - 1; i++)
               if(cheltuieli[i].getMoney() > cheltuieli[i + 1].getMoney())
               {
                   aux = cheltuieli[i];
                   cheltuieli[i] = cheltuieli[i + 1];
                   cheltuieli[i + 1] = aux;
                   ok = 1;
               }
           }
        
}
void Service::fillterByType(char* type)
{
    int i = 0;
    while (i < this -> repoCheltuiala.getSize())
    {if (strcmp(this -> getAll()[i].getType(), type) !=0)
        this -> repoCheltuiala.stergere(this -> getAll()[i]);
        else
            i++;
    }
}
void Service::fillterByTypeAndMoney(char* type, int nr)
{
    int i = 0;
    while(i < this -> repoCheltuiala.getSize())
    {
        if(strcmp(this -> getAll()[i].getType(), type) == 0 && this -> getAll()[i].getMoney() >= nr)
            this -> repoCheltuiala.stergere(this -> getAll()[i]);
        else if (strcmp(this -> getAll()[i].getType(), type) !=0)
            this -> repoCheltuiala.stergere(this -> getAll()[i]);
        else
            i ++;
        
    }
}

void Service::fillterByTypeAndMoney2(char* type, int nr)
{
    int i = 0;
    while(i < this -> repoCheltuiala.getSize())
    {
        if(strcmp(this -> getAll()[i].getType(), type) == 0 && this -> getAll()[i].getMoney() != nr)
            this -> repoCheltuiala.stergere(this -> getAll()[i]);
        else if (strcmp(this -> getAll()[i].getType(), type) !=0)
            this -> repoCheltuiala.stergere(this -> getAll()[i]);
        else
            i ++;
        
    }
}

int Service::getBuget()
{

    return this -> repoCheltuiala.getBuget();
}

int Service::getSizeRepo()
{
    return this -> repoCheltuiala.getSize();
}


void Service::update(int day1, int money1, char* type1, int day2, int money2, char* type2) {
    Cheltuiala c1(day1, money1, type1);
    Cheltuiala c2(day2, money2, type2);

    this -> repoCheltuiala.update(c1, c2);
}
