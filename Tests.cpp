//
//  Tests.cpp
//  Laborator 4
//
//  Created by Isopescu Sebastian on 17/03/2020.
//  Copyright © 2020 Isopescu Sebastian. All rights reserved.
//

#include "Tests.h"
#include "assert.h"
#include "Cheltuiala.h"
#include "Repo.h"
#include "Service.h"
#include <string.h>

void testEntity()
{
    Cheltuiala c1(3, 5, "Internet");
    assert(c1.getDay() == 3);
    assert(c1.getMoney() == 5);
    assert(strcmp(c1.getType(), "Internet") == 0);
    Cheltuiala c2(54, 23, "Haine");
    assert(c2.getDay() == 54);
    assert(c2.getMoney() == 23);
    assert(strcmp(c2.getType(), "Haine") == 0);
    c2.setDay(1);
    assert(c2.getDay() == 1);
//    c2.setDay("asd");
//    assert(strcmp(c2.getType()))
    
}

void testRepo()
{
       Repo rep;
    Cheltuiala c3(1, 2, "Menaj");
    Cheltuiala c4(3, 5, "Mancare");


    rep.addItem(c3);
    rep.addItem(c4);
    Cheltuiala cheltuiala3 = rep.getItemFromPos(0);
    int ziua1 = cheltuiala3.getDay();
    int bani1 = cheltuiala3.getMoney();
    assert(ziua1 == 1);
    assert(bani1 == 2);
    Cheltuiala cheltuiala4 = rep.getItemFromPos(1);
    int ziua2 = cheltuiala4.getDay();
    int bani2 = cheltuiala4.getMoney();
    assert(ziua2 == 3);
    assert(bani2 == 5);
    rep.stergere(c3);
    Cheltuiala cheltuiala5 = rep.getAll()[0];
    assert(cheltuiala5.getDay() == 3);


}

void testService()
{
    
    char* t1 = new char[10];
    char* t2 = new char[10];

    strcpy(t1, "Internet");
    strcpy(t2, "Mancare");
    Service service_cheltuieli;
    
    service_cheltuieli.addCurrDay(10, t1);
    service_cheltuieli.addCheltuiala(1, 123, t2);
    
    int currDay = service_cheltuieli.getCurrDay();
    
    
    assert(service_cheltuieli.getAll()[0].getDay() == currDay);
    assert(service_cheltuieli.getAll()[1].getDay() == 1);
    assert(service_cheltuieli.getAll()[0].getMoney() == 10);
    assert(service_cheltuieli.getAll()[1].getMoney() == 123);
    assert(strcmp(service_cheltuieli.getAll()[0].getType(), "Internet") == 0);
    assert(strcmp(service_cheltuieli.getAll()[1].getType(), "Mancare") == 0);
    
    service_cheltuieli.deleteItemByType(t1);
    assert(service_cheltuieli.getAll()[0].getDay() == 1);
    
    service_cheltuieli.deleteItemByDay(1);
    assert(service_cheltuieli.getSizeRepo() == 0);
    
    delete[] t1;
    delete[] t2;
    
    
    testEliminateFromInterval();
    testGetItemByType();
    testSublist();
    testSorts();
    testFillter();
}

void testEliminateFromInterval()
{
    char* t1 = new char[10];
    char* t2 = new char[10];
    strcpy(t1, "Internet");
    strcpy(t2, "Mancare");
    Service service_cheltuieli;
    
    service_cheltuieli.addCheltuiala(5, 345, t1);
    service_cheltuieli.addCheltuiala(6, 645, t2);
    service_cheltuieli.addCheltuiala(7, 15, t2);
    service_cheltuieli.addCheltuiala(8, 465, t2);
    service_cheltuieli.addCheltuiala(9, 235, t1);
    service_cheltuieli.addCheltuiala(10, 45, t2);
    
    service_cheltuieli.deleteItemFromInt(7, 9);
    
    assert(service_cheltuieli.getAll()[0].getDay() == 5);
    assert(service_cheltuieli.getAll()[1].getDay() == 6);
    assert(service_cheltuieli.getAll()[2].getDay() == 10);
    
    delete[] t1;
    delete[] t2;
    
    
    
}

void testGetItemByType()
{
    char* t1 = new char[10];
    char* t2 = new char[10];
    strcpy(t1, "Internet");
    strcpy(t2, "Mancare");
    Service service_cheltuieli;
    
    service_cheltuieli.addCheltuiala(5, 345, t1);
    service_cheltuieli.addCheltuiala(6, 645, t1);
    service_cheltuieli.addCheltuiala(7, 15, t2);
    service_cheltuieli.addCheltuiala(8, 465, t2);
    service_cheltuieli.addCheltuiala(9, 235, t1);
    service_cheltuieli.addCheltuiala(10, 45, t2);
    
    Cheltuiala rez[1000];
    int res = 0;
    service_cheltuieli.getItemByType(t1, rez, res);
    
    assert(res == 3);
    assert(rez[0].getDay() == 5);
    assert(rez[1].getDay() == 6);
    assert(rez[2].getDay() == 9);
    
    service_cheltuieli.getItemByTypeAndMoney1(300, t1, rez, res);
    
    assert(res == 2);
    assert(rez[0].getDay() == 5);
    assert(rez[1].getDay() == 6);
    
    service_cheltuieli.getItemByTypeAndMoney2(465, t2, rez, res);
    
    assert(res == 1);
    assert(rez[0].getDay() == 8);
    
    delete[] t1;
    delete[] t2;
    
}

void testSublist()
{
    char* t1 = new char[10];
    char* t2 = new char[10];
    strcpy(t1, "Internet");
    strcpy(t2, "Mancare");
    Service service_cheltuieli;
    
    service_cheltuieli.addCheltuiala(5, 345, t1);
    service_cheltuieli.addCheltuiala(6, 645, t1);
    service_cheltuieli.addCheltuiala(7, 15, t2);
    service_cheltuieli.addCheltuiala(8, 465, t2);
    service_cheltuieli.addCheltuiala(9, 235, t1);
    service_cheltuieli.addCheltuiala(10, 45, t2);
    
    int s = service_cheltuieli.sumByType(t1);
    assert(s = 1225);
    
    int maxDay = service_cheltuieli.maxDay();
    assert(maxDay == 6);
    
    delete[] t1;
    delete[] t2;
}


void testSorts()
{
    char* t1 = new char[10];
    char* t2 = new char[10];
    strcpy(t1, "Internet");
    strcpy(t2, "Mancare");
    Service service_cheltuieli;
    
    service_cheltuieli.addCheltuiala(5, 345, t1);
    service_cheltuieli.addCheltuiala(6, 645, t1);
    service_cheltuieli.addCheltuiala(7, 15, t2);
    service_cheltuieli.addCheltuiala(8, 465, t2);
    
    Cheltuiala rez[1000];
       int res = 0;
    
    service_cheltuieli.sortSumDesc(rez, res);
    
    assert(res == 4);
    assert(rez[0].getDay() == 6);
    assert(rez[1].getDay() == 8);
    assert(rez[2].getDay() == 5);
    assert(rez[3].getDay() == 7);
    
    service_cheltuieli.sortSumByType(t2, rez, res);
    assert(res == 2);
    assert(rez[0].getDay() == 7);
    assert(rez[1].getDay() == 8);
    
    delete[] t1;
    delete[] t2;
    
}

void testFillter()
{
    char* t1 = new char[10];
    char* t2 = new char[10];
    strcpy(t1, "Internet");
    strcpy(t2, "Mancare");
    Service service_cheltuieli;
    
    service_cheltuieli.addCheltuiala(5, 345, t1);
    service_cheltuieli.addCheltuiala(6, 645, t1);
    service_cheltuieli.addCheltuiala(7, 15, t2);
    service_cheltuieli.addCheltuiala(8, 465, t2);
    service_cheltuieli.addCheltuiala(9, 235, t1);
    service_cheltuieli.addCheltuiala(10, 45, t2);
    
    Cheltuiala rez[1000];

    
    service_cheltuieli.fillterByType(t1);
    assert(service_cheltuieli.getAll()[0].getDay() == 5);
    assert(service_cheltuieli.getAll()[1].getDay() == 6);
    assert(service_cheltuieli.getAll()[2].getDay() == 9);
    
    service_cheltuieli.fillterByTypeAndMoney(t1, 300);
    assert(service_cheltuieli.getAll()[0].getDay() == 9);
    
    service_cheltuieli.addCheltuiala(5, 345, t1);
    service_cheltuieli.addCheltuiala(6, 645, t1);
    service_cheltuieli.addCheltuiala(7, 15, t2);
    service_cheltuieli.addCheltuiala(8, 465, t2);
    service_cheltuieli.addCheltuiala(10, 45, t2);
    
    service_cheltuieli.fillterByTypeAndMoney2(t1, 345);
    assert(service_cheltuieli.getAll()[0].getDay() == 5);
}

