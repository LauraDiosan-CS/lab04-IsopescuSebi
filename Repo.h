//
//  Repo.h
//  Laborator 4
//
//  Created by Isopescu Sebastian on 17/03/2020.
//  Copyright © 2020 Isopescu Sebastian. All rights reserved.
//

#ifndef Repo_h
#define Repo_h
#include "Cheltuiala.h"

using namespace std;

class Repo
{
private:
    Cheltuiala cheltuieli[10];
    int noCheltuieli;
    int buget;
public:
    Repo();
    ~Repo();
    void addItem(Cheltuiala &c);
    Cheltuiala getItemFromPos(int pos);
    int getSize();
    Cheltuiala* getAll();
    int getBuget();
    void setSize(int a);
    int search(const Cheltuiala& c);
    void setBuget(int a);
    void stergere(Cheltuiala c);
    Repo(Cheltuiala cheltuieli[], int n, int buget);
    Repo& operator=(Repo& r);
    void update(Cheltuiala c1, Cheltuiala c2);

};


#endif /* Repo_h */
