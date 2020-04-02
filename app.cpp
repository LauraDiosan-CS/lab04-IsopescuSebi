//
//  app.cpp
//  Laborator 4
//
//  Created by Isopescu Sebastian on 30/03/2020.
//  Copyright © 2020 Isopescu Sebastian. All rights reserved.
//

#include "Cheltuiala.h"
#include "Repo.h"
#include "Service.h"
#include "Console.h"
#include "Tests.h"
#include <iostream>

using namespace std;

int main()
{
    testEntity();
    cout<<"Testul entitate a trecut"<<endl;
    testRepo();
    cout<<"Testul repo a trecut"<<endl;
    testService();
    cout<<"Testul service a trecut"<<endl;
    Console c;
    c.console();
    return 0;
}
