//
//  Cheltuiala.h
//  Laborator 4
//
//  Created by Isopescu Sebastian on 17/03/2020.
//  Copyright © 2020 Isopescu Sebastian. All rights reserved.
//

#ifndef Cheltuiala_h
#define Cheltuiala_h

#include <iostream>
#include <string.h>
#include <ostream>
using namespace std;

class Cheltuiala{
private:
    int day;
    int money;
    char* type;
public:
    Cheltuiala();
    Cheltuiala(int a, int b, char* n);
    Cheltuiala(const Cheltuiala &c);
    ~Cheltuiala();
    int getDay();
    int getMoney();
    char* getType();
    void setDay(int a);
    void setMoney(int a);
    void setType(char* a);
    Cheltuiala& operator=(const Cheltuiala& c);
    bool operator==(const Cheltuiala& c);
    
    friend ostream& operator<<(ostream& os, const Cheltuiala& c);
    
    

};

#endif /* Cheltuiala_h */
