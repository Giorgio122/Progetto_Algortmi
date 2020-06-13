//
// Created by Giorgio on 08/06/2020.
//

#ifndef NONSO_TABELLA_H
#define NONSO_TABELLA_H

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "colonna.h"
#include "commands.h"

class tabella {
public:
    tabella();
    void get_parameter(int a,string c);//c contiene i parametri da inserire
    void print();
    void print(string c);//c contiene le colonne da stampare
    void print(string c,string c1);//c contiene le colonne da stampare, c1 contiene il condizionamento(ES WHERE AGE = 20)
    void print_order(string c,string c1);//c contiene le colonne da stampare, c1 la colonna secondo cui ordinare
    void add_param(const string c,const string c1);// c contiene i campi da settare, c1 i corrispondenti valori
    string return_name();
    void delete_row(const string c);
    void delete_row();
    void update(string c,string c1);//c contiene le colonne da stampare, c1 contiene il condizionamento(ES WHERE AGE = 20)
private:
    string table_name;
    vector<colonna> column;
    int i;
};


#endif //NONSO_TABELLA_H
