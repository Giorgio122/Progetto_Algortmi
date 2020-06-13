#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "tabella.h"
#include "commands.h"

int main() {
    vector<string> stringa_comandi, elem_stringa;
    vector<tabella> table(1);
    string comando,comando1;
    int i = 0,k=0;
    vector<stringstream> h(100),h1(100);
    bool end_line = false;
    while (comando1 != "QUIT()") {
        while (end_line == false) {
            getline(cin, comando, '\n');
            transform(comando.begin(), comando.end(), comando.begin(), ::toupper);
            stringa_comandi.push_back(comando);
            if (comando[comando.size() - 1] == ';') {
                end_line = true;
            }
        }
        h[k] << stringa_comandi[0];
        //cout << stringa_comandi[0] << endl;
        getline(h[k], comando, ' ');
        elem_stringa.push_back(comando);
        //cout << elem_stringa[0] << endl;
        if (elem_stringa[0] == "CREATE_TABLE") {
            getline(h[k], comando, ' ');
            elem_stringa.push_back(comando);
            getline(h[k], comando, ' ');
            table[i].get_parameter(0, elem_stringa[1]);
            for (int j = 1; j < stringa_comandi.size() - 1; j++) {
                table[i].get_parameter(1, stringa_comandi[j]);
            }
            i++;
            table.resize(i + 1);
        }
        if (elem_stringa[0] == "DROP_TABLE") {
            getline(h[k], comando, ';');
            //cout << comando;
            for (int j = 0; j < table.size(); j++) {
                if (table[j].return_name() == comando)
                    table.erase(table.begin() + j);
            }
        }
        if (elem_stringa[0] == "INSERT_INTO") {
            getline(h[k], comando, '(');
            for (int j = 0; j < table.size(); j++) {
                if (table[j].return_name() == comando) {
                    getline(h[k], comando, ')');
                    //cout << comando << "   " << stringa_comandi[1];
                    table[j].add_param(comando, stringa_comandi[1]);
                }
            }
        }
        if (elem_stringa[0] == "DELETE_FROM"){
            getline(h[k], comando, '\n');
            //cout << comando << endl;
            stringa_comandi[1].erase(stringa_comandi[1].begin()+stringa_comandi[1].size()-1);
            //cout << stringa_comandi[1]<< endl;
            for (int j = 0; j < table.size(); j++) {
                if (table[j].return_name() == comando)
                    table[j].delete_row(stringa_comandi[1]);
            }
        }
        if (elem_stringa[0] == "TRUNCATE_TABLE"){
            getline(h[k], comando, ';');
            for (int j = 0; j < table.size(); j++) {
                if (table[j].return_name() == comando){
                    table[j].delete_row();
                }
            }
        }
        if (elem_stringa[0] == "UPDATE"){
            getline(h[k], comando, '\n');
            for (int j = 0; j < table.size(); j++) {
                if (table[j].return_name() == comando){
                    table[j].update(stringa_comandi[1],stringa_comandi[2]);
                }
            }
        }
        if (elem_stringa[0] == "SELECT"){
            std::size_t found;
            switch (stringa_comandi.size()) {
                case 1:
                    //cout << "BBBBBBBBBBBBBBBBBBBBBBB" << endl;
                    getline(h[k], comando, ' ');
                    getline(h[k], comando, ' ');
                    getline(h[k], comando, ';');
                    for (int j = 0; j < table.size(); j++) {
                        if (table[j].return_name() == comando) {
                            table[j].print();
                        }
                    }
                    break;
                case 2:
                    //cout << "AAAAAAAAAAAAAAAAAAAAAAA" << endl;
                    h1[k] << stringa_comandi[1];
                    getline(h1[k],comando,' ');
                    getline(h1[k],comando,';');
                    for (int j = 0; j < table.size(); j++) {
                        if (table[j].return_name() == comando) {
                            getline(h[k], comando, ' ');
                            table[j].print(comando);
                        }
                    }
                    break;
                case 3:
                    h1[k] << stringa_comandi[1];
                    getline(h1[k],comando,' ');
                    getline(h1[k],comando,' ');
                    getline(h[k],comando1,' ');
                    found = stringa_comandi[2].find("WHERE");
                    if (found == 0){
                        for (int j = 0; j < table.size(); j++) {
                            if (table[j].return_name() == comando)
                                table[j].print(comando1,stringa_comandi[2]);
                        }
                    } else{
                        found = stringa_comandi[2].find("ORDER_BY");
                        if (found == 0){
                            for (int j = 0; j < table.size(); j++) {
                                if (table[j].return_name() == comando)
                                    table[j].print_order(comando1,stringa_comandi[2]);
                            }
                        }
                    }
                    break;
                case 4:
                    break;
                default:
                    cout << "Selezione errata" << endl;
                    break;
            }
        }
        end_line = false;
        stringa_comandi.clear();
        elem_stringa.clear();
        k++;
        cout << endl << "Cosa vuoi fare" << endl;
        cin >> comando1;
        getline(cin, comando, '\n');
    }
    //table[0].print();
    /*cout << endl;
    table[1].print();*/
    return 0;
}
