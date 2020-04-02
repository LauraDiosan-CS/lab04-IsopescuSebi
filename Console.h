//
//  Console.h
//  Laborator 4
//
//  Created by Isopescu Sebastian on 24/03/2020.
//  Copyright © 2020 Isopescu Sebastian. All rights reserved.
//

#ifndef Console_h
#define Console_h
#include "Service.h"

class Console
{
private:
    Service service_cheltuieli;
public:
    void menu();
    int console();
    void add_current_day_cheltuiala();
    void show_cheltuieli();
    void add_cheltuiala_with_day();
    void delete_cheltuiala_day();
    void delete_cheltuiala_from_int();
    void delete_item_by_type();
    void show_cheltuieli_by_type();
    void show_cheltuiala_by_type_and_money1();
    void show_cheltuiala_by_type_and_money2();
    void sum_by_day();
    void max_day();
    void sort_sum_desc();
    void sort_sum_by_type();
    void filter_by_type();
    void filter_by_type_and_money1();
    void filter_by_type_and_money2();
    void update_cheltuiala();
    void show_items(int n, Cheltuiala cheltuieli[]);

};

#endif /* Console_h */
