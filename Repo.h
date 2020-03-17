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
public:
    Repo();
    ~Repo();
    void addItem(Cheltuiala &c);
    Cheltuiala getItemFromPos(int pos);
    int getSize();
    

};


#endif /* Repo_h */
