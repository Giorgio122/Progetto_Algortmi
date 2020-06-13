//
// Created by Giorgio on 08/06/2020.
//

#include "colonna.h"

void colonna::set_name_type(string c,int a) {
    stringstream h;
    vector<string> l;
    string l1;
    if (a == 1)
        p_key = 1;
    else {
        h << c;
        while (getline(h, l1, ' ')) {
            l.push_back(l1);
        }
        _name = l[0];//Controllo il nome
        _type = l[1];//controllo il tipo di dato
        if (l.size() > 2) {
            if (l[2] == "NOT_NULL")
                not_null = 1;
            if (l[2] == "AUTO_INCR" && _type == "INT")
                auto_i = 1;
        }
        if (l.size() > 3) {
            if (l[3] == "NOT_NULL")
                not_null = 1;
            if (l[3] == "AUTO_INCR" && _type == "INT")
                auto_i = 1;
        }
    }
}

void colonna::print() {
    cout << _name << " " << _type << " "<< not_null << " "<< auto_i << " "<< p_key << endl;
    info.print_param(_type);
}

colonna::colonna() {
    not_null = 0;
    auto_i = 0;
    p_key = 0;
}

string colonna::get_param(int a) {
    if (a == 0)
        return _name;
    return _type;
}

void colonna::add_param(const string c,int a) {
    if (a == 0)
        info.add_param(_type,"/",0);
    else{
        //cout << c << " "<< _type << endl;
        info.add_param(_type,c,1);
    }
}

vector<int> colonna::search(string c) {
    return info.search(_type,c);;
}

void colonna::delete_param(vector<int> location) {
    info.delete_data(_type,location);
}

void colonna::delete_param() {
    info.delete_data(_type);
}

void colonna::print(vector<int> location) {
    cout << _name << endl;
    info.print_param(_type,location);
}

void colonna::update(vector<int> location,string c) {
    info.update(_type,location,c);
}

vector<int> colonna::order(string c) {
    return info.order(_type,c);
}

void colonna::order_print(vector<int> location) {
    info.order_print(_type,location);
}

