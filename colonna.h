//
// Created by Giorgio on 08/06/2020.
//

#ifndef NONSO_COLONNA_H
#define NONSO_COLONNA_H
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "commands.h"
#include "dati.h"

class colonna {
public:
    colonna();
    void set_name_type(string c,int a =0);
    string get_param(int a);
    void add_param(const string c,int a);
    vector<int> search(string c);
    vector<int> order(string c);
    void delete_param(vector<int> location);
    void delete_param();
    void print();
    void print(vector<int> location);
    void update(vector<int> location,string c);
    void order_print(vector<int> location);
private:
    string _name;
    string _type;
    int not_null;
    int p_key;
    int auto_i;
    dati info;//contiene il vettore con i dati della colonna
};


#endif //NONSO_COLONNA_H
