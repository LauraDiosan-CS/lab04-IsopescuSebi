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
    
}

void testRepo()
{
       Repo rep;
    Cheltuiala c3(1, 2, "Menaj");
    Cheltuiala c4(3, 5, "Mancare");


    rep.addItem(c3);
    rep.addItem(c4);
    Cheltuiala cheltuiala1 = rep.getItemFromPos(0);
    int ziua1 = cheltuiala1.getDay();
    int bani1 = cheltuiala1.getMoney();
    assert(ziua1 == 1);
    assert(bani1 == 2);
    Cheltuiala cheltuiala2 = rep.getItemFromPos(1);
    int ziua2 = cheltuiala2.getDay();
    int bani2 = cheltuiala2.getMoney();
    assert(ziua2 == 3);
    assert(bani2 == 5);


}

