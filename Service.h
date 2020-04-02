//
//  Service.h
//  Laborator 4
//
//  Created by Isopescu Sebastian on 24/03/2020.
//  Copyright © 2020 Isopescu Sebastian. All rights reserved.
//

#ifndef Service_h
#define Service_h
#include "Repo.h"

class Service {
private:
    Repo repoCheltuiala;
public:
    int getCurrDay();
    void addCheltuiala(int day, int money, char* type);
    void addCurrDay(int money, char* type);
    Cheltuiala* getAll();
    void deleteItemByDay(int day);
    void deleteItemFromInt(int day1, int day2);
    void deleteItemByType(char* type);
    void getItemByType(char* type, Cheltuiala cheltuieli[], int& res);
    void getItemByTypeAndMoney1(int money, char* type, Cheltuiala cheltuieli[], int& res);
    void getItemByTypeAndMoney2(int money, char* type, Cheltuiala cheltuieli[], int& res);
    int sumByType(char* type);
    int maxDay();
    void sortSumDesc(Cheltuiala cheltuieli[], int& res);
    void sortSumByType(char* type, Cheltuiala cheltuieli[], int& res);
    void fillterByType(char* type);
    void fillterByTypeAndMoney(char* type, int nr);
    void fillterByTypeAndMoney2(char* type, int nr);
    int getBuget();
    int getSizeRepo();
    void update(int day1, int money1, char* type1, int day2, int money2, char* type2);
    
};

#endif /* Service_h */
