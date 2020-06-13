//
// Created by Giorgio on 08/06/2020.
//

#include "tabella.h"

void tabella::get_parameter(int a,string c) {
    stringstream h;
    string c1,c2=c;
    if (a == 0)
        table_name = c;
    else {
        h << c;
        getline(h, c1, ' ');
        if (c1 == "PRIMARY_KEY") {
            getline(h, c1);
            for (int j = 0; j < column.size(); j++) {
                if (column[j].get_param(0) == c1)
                    column[j].set_name_type(c1,1);
            }
        } else {
            column[i].set_name_type(c2);
            i++;
            column.resize(i + 1);
        }
    }
}

tabella::tabella() {
    i=0;
    column.resize(1);
}

void tabella::print() {
    cout << table_name << endl;
    for (int j = 0; j < column.size()-1; j++) {
        column[j].print();
        cout << endl;
    }
}

string tabella::return_name() {
    return table_name;
}

void tabella::add_param(const string c,const string c1) {
    stringstream h,h1;
    string c2;
    vector<string> c3,c4;//c3 contiene le colonne in cui inserire il dato, c4 i dati effettivi
    h << c;
    h1 << c1;
    while (getline(h,c2,',')){//Leggo e separe le colonne in cui mettere i dati
        c3.push_back(c2);
    }
    for (int j = 0; j < c3.size(); j++) {
        cout << c3[j] << endl;
    }
    getline(h1,c2,'(');
    while (c2[c2.size()-1] != ';'){//leggo e separo i dati da inserire
        getline(h1,c2,',');
        c4.push_back(c2);
    }
    c4[c4.size()-1].erase(c4[c4.size()-1].begin()+c4[c4.size()-1].size()-1);
    c4[c4.size()-1].erase(c4[c4.size()-1].begin()+c4[c4.size()-1].size()-1);
    for (int j = 0; j < c4.size(); j++) {
        cout << c4[j] << endl;
    }
    for (int l = 0; l < column.size(); l++) {
        column[l].add_param("/",0);
    }
    for (int j = 0; j < c3.size(); j++) {
        for (int k = 0; k < column.size(); k++) {
            if (c3[j] == column[k].get_param(0))
                column[k].add_param(c4[j],1);
        }
    }
}

void tabella::delete_row(const string c) {
    stringstream h;
    vector<int> search;
    string c1;
    h << c;
    getline(h,c1,' ');
    if (c1 == "WHERE"){
        getline(h,c1,' ');
        for (int j = 0; j < column.size(); j++) {
            if (c1 == column[j].get_param(0)){
                getline(h,c1,' ');
                getline(h,c1,';');
                cout << c1;
                search = column[j].search(c1);
            }
        }
    }
    cout << endl;
    for (int l = 0; l < search.size(); l++) {
        cout << search[l] << "   ";
    }
    cout << endl;
    for (int k = 0; k < column.size(); k++) {
        column[k].delete_param(search);
    }
}

void tabella::delete_row() {
    for (int j = 0; j < column.size(); j++) {
        column[j].delete_param();
    }
}

void tabella::print(string c) {
    stringstream h;
    string f;
    h<<c;
    while (getline(h,f,',')){
        for (int j = 0; j < column.size(); j++) {
            if (column[j].get_param(0) == f){
                column[j].print();
                cout << endl;
            }
        }
    }
}

void tabella::print(string c, string c1) {
    stringstream h,h1;
    vector<int> search;
    string c2,f;
    //cout << c1 << endl;
    h << c1;
    getline(h,c2,' ');
    //cout << c2 << endl;
    if (c2 == "WHERE"){
        getline(h,c2,' ');
        //cout << c2 << endl;
        for (int j = 0; j < column.size(); j++) {
            if (c2 == column[j].get_param(0)){
                getline(h,c2,' ');
                //cout << c2 << endl;
                getline(h,c2,';');
                cout << c2 << endl;
                search = column[j].search(c2);
            }
        }
    }
    cout << endl;
    for (int l = 0; l < search.size(); l++) {
        cout << search[l] << "   ";
    }
    cout << endl;
    //cout << c << endl;
    h1 << c;
    while (getline(h1,f,',')){
        //cout << f << endl;
        for (int j = 0; j < column.size(); j++) {
            if (column[j].get_param(0) == f){
                column[j].print(search);
                cout << endl;
            }
        }
    }
}

void tabella::update(string c, string c1) {
    stringstream h,h1;
    vector<stringstream> h2(100);
    int k=0;
    vector<int> search;
    string c2,f,f1;
    //cout << c1 << endl;
    h << c1;
    getline(h,c2,' ');
    //cout << c2 << endl;
    if (c2 == "WHERE"){
        getline(h,c2,' ');
        //cout << c2 << endl;
        for (int j = 0; j < column.size(); j++) {
            if (c2 == column[j].get_param(0)){
                getline(h,c2,' ');
                //cout << c2 << endl;
                getline(h,c2,';');
                cout << c2 << endl;
                search = column[j].search(c2);
            }
        }
    }
    h1 << c;
    //cout << c << endl;
    getline(h1,f,' ');
    //cout << f << endl;
    while (getline(h1,f,',')){
        cout << f << endl;
        h2[k] << f;
        getline(h2[k],f,' ');
        cout << f << endl;
        for (int j = 0; j < column.size(); j++) {
            if (column[j].get_param(0) == f){
                getline(h2[k],f,' ');
                //cout << f << endl;
                getline(h2[k],f,',');
                //cout << f << endl;
                column[j].update(search,f);
            }
        }
        k++;
        cout << endl << endl << endl;
    }
}

void tabella::print_order(string c, string c1) {
    stringstream h,h1;
    string f;
    vector<int> location;
    //cout << c << endl << c1 << endl;
    h << c1;
    getline(h,f,' ');
    getline(h,f,' ');
    //cout << f;
    for (int j = 0; j < column.size(); j++) {
        if (column[j].get_param(0) == f){
            getline(h,f,';');
            location = column[j].order(f);
        }
    }
    //cout << endl;
    h1 << c;
    while (getline(h1,f,',')){
        //cout << f << endl;
        for (int j = 0; j < column.size(); j++) {
            if (column[j].get_param(0) == f){
                //STAMPA ORDINATA
                column[j].order_print(location);
                //cout << endl;
            }
        }
    }
}
