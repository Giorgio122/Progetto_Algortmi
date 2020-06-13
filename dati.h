//
// Created by Giorgio on 09/06/2020.
//

#ifndef NONSO_DATI_H
#define NONSO_DATI_H
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "commands.h"

class dati {
public:
    dati();
    void add_param(string type,string c,int a);
    void print_param(string type);
    void print_param(string type,vector<int> location);
    vector<int> search(string type,string dato);
    void delete_data(string type,vector<int> location);
    void delete_data(string type);
    void update(string type,vector<int> location,string param);
    vector<int> order(string type, string order_type);
    void order_print(string type, vector<int> location);
private:
    vector<int> row_int;
    vector<float> row_float;
    vector<string> row_string;
    int y;//indica il numero di righe
};


#endif //NONSO_DATI_H
