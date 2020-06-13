//
// Created by Giorgio on 09/06/2020.
//

#include "dati.h"

dati::dati() {
    y=0;
}

void dati::add_param(string type, string c, int a) {
    if (type == "INT"){
        if (a == 0){
            row_int.push_back(-100);
            y++;
            //cout << y << endl;
        } if (a == 1){
            //cout << "SIIIIIIIIIIIIIIIIIIIIII"  << " " << y << endl;
            int f = stoi(c);
            row_int[y-1] = f;
        }
    }
    if (type == "FLOAT"){
        if (a == 0){
            row_float.push_back(-100);
            y++;
        } else{
            float f = stof(c);
            row_float[y-1] = f;
            //cout << row_float[y-1] << endl;
        }
    }
    if ((type != "INT") && (type != "FLOAT")){
        if (a == 0){
            row_string.push_back("/");
            y++;
        } else{
            //cout << "SIIIIIIIIIIIIIIIIIIIIII"  << " " << y << endl;
            row_string[y-1] = c;
            //cout << row_string[y-1] << endl;
        }
    }
}
void dati::print_param(string type) {
    //cout << y << endl;
    if (type == "INT"){
        for (int i = 0; i < row_int.size(); i++) {
            cout << row_int[i] << " ";
        }
    }
    if (type == "FLOAT"){
        for (int i = 0; i < row_float.size(); i++) {
            cout << row_float[i] << " ";
        }
    } else{
        for (int i = 0; i < row_string.size(); i++) {
            cout << row_string[i] << " ";
        }
    }
}

vector<int> dati::search(string type, string dato) {
    vector<int> c;
    if (type == "INT"){
        int f = stoi(dato);
        for (int i = 0; i < row_int.size(); i++) {
            if (row_int[i] == f){
                c.push_back(i);
            }
        }
        return c;
    }
    if (type == "FLOAT"){
        int f = stof(dato);
        for (int i = 0; i < row_float.size(); i++) {
            if (row_float[i] == f){
                c.push_back(i);
            }
        }
        return c;
    }
    if ((type != "INT") && (type != "FLOAT")){
        for (int i = 0; i < row_string.size(); i++) {
            if (row_string[i] == dato){
                c.push_back(i);
            }
        }
        return c;
    }
    return c;
}

void dati::delete_data(string type,vector<int> location) {
    int k=0;
    if (type == "INT"){
        for (int i = 0; i < location.size(); i++) {
            row_int.erase(row_int.begin()+location[i]-k);
            //location[i+1]--;
            y--;
            k++;
        }
    }
    if (type == "FLOAT"){
        for (int i = 0; i < location.size(); i++) {
            row_float.erase(row_float.begin()+location[i]-k);
            //location[i+1]--;
            y--;
            k++;
        }
    }
    if ((type != "INT") && (type != "FLOAT")){
        for (int i = 0; i < location.size(); i++) {
            row_string.erase(row_string.begin()+location[i]-k);
            //location[i+1]--;
            y--;
            k++;
        }
    }
}

void dati::delete_data(string type) {
    if (type == "INT"){
        y=0;
        row_int.clear();
    }
    if (type == "FLOAT"){
        y=0;
        row_float.clear();
    }
    if ((type != "INT") && (type != "FLOAT")){
        y=0;
        row_string.clear();
    }
}

void dati::print_param(string type, vector<int> location) {
    if (type == "INT"){
        for (int i = 0; i < location.size(); i++) {
            cout << row_int[location[i]] << " ";
        }
    }
    if (type == "FLOAT"){
        for (int i = 0; i < location.size(); i++) {
            cout << row_float[location[i]] << " ";
        }
    }
    if ((type != "INT") && (type != "FLOAT")){
        for (int i = 0; i < location.size(); i++) {
            cout << row_string[location[i]] << " ";
        }
    }
}

void dati::update(string type,vector<int> location,string param) {
    if (type == "INT"){
        int f = stoi(param);
        for (int i = 0; i < location.size(); i++) {
            row_int[location[i]] = f;
        }
    }
    if (type == "FLOAT"){
        float f = stof(param);
        for (int i = 0; i < location.size(); i++) {
            row_float[location[i]] = f;
        }
    }
    if ((type != "INT") && (type != "FLOAT")){
        for (int i = 0; i < location.size(); i++) {
            row_string[location[i]] = param[0];
        }
    }
}

vector<int> dati::order(string type, string order_type) {
    vector<int> order;
    if (type == "INT") {
        order.resize(row_int.size());
        for (int i = 0; i < order.size(); i++) {
            order[i] = i;
        }
        if (order_type == "ASC"){
            vector<int> row = row_int;
            int min,n=row_int.size(),temp;
            for (int i = 0; i < n-1; i++) {
                min = i;
                for (int j = i+1; j < n; j++) {
                    if (row[j] < row[min])
                        min = j;
                }
                temp = row[min];
                row[min] = row[i];
                row[i] = temp;
                temp = order[min];
                order[min] = order[i];
                order[i] = temp;
            }
            return order;
        } else{
            vector<int> row = row_int;
            int min,n=row_int.size(),temp;
            for (int i = 0; i < n-1; i++) {
                min = i;
                for (int j = i+1; j < n; j++) {
                    if (row[j] > row[min])
                        min = j;
                }
                temp = row[min];
                row[min] = row[i];
                row[i] = temp;
                temp = order[min];
                order[min] = order[i];
                order[i] = temp;
            }
            return order;
        }
    }
    if (type == "FLOAT"){
        order.resize(row_float.size());
        for (int i = 0; i < order.size(); i++) {
            order[i] = i;
        }
        if (order_type == "ASC"){
            vector<float> row = row_float;
            int min,n=row_float.size(),temp1;
            float temp;
            for (int i = 0; i < n-1; i++) {
                min = i;
                for (int j = i+1; j < n; j++) {
                    if (row[j] < row[min])
                        min = j;
                }
                temp = row[min];
                row[min] = row[i];
                row[i] = temp;
                temp1 = order[min];
                order[min] = order[i];
                order[i] = temp1;
            }
            return order;
        } else{
            vector<float> row = row_float;
            int min,n=row_float.size(),temp1;
            float temp;
            for (int i = 0; i < n-1; i++) {
                min = i;
                for (int j = i+1; j < n; j++) {
                    if (row[j] > row[min])
                        min = j;
                }
                temp = row[min];
                row[min] = row[i];
                row[i] = temp;
                temp1 = order[min];
                order[min] = order[i];
                order[i] = temp1;
            }
            return order;
        }
    }
    if ((type != "INT") && (type != "FLOAT")){
        order.resize(row_string.size());
        for (int i = 0; i < order.size(); i++) {
            order[i] = i;
        }
        if (order_type == "ASC"){
            vector<string> row = row_string;
            int min,n=row_string.size(),temp1;
            string temp;
            for (int i = 0; i < n-1; i++) {
                min = i;
                for (int j = i+1; j < n; j++) {
                    if (row[j] < row[min])
                        min = j;
                }
                temp = row[min];
                row[min] = row[i];
                row[i] = temp;
                temp1 = order[min];
                order[min] = order[i];
                order[i] = temp1;
            }
            return order;
        } else{
            vector<string> row = row_string;
            int min,n=row_string.size(),temp1;
            string temp;
            for (int i = 0; i < n-1; i++) {
                min = i;
                for (int j = i+1; j < n; j++) {
                    if (row[j] > row[min])
                        min = j;
                }
                temp = row[min];
                row[min] = row[i];
                row[i] = temp;
                temp1 = order[min];
                order[min] = order[i];
                order[i] = temp1;
            }
            return order;
        }
    }
    return vector<int>(0);
}

void dati::order_print(string type,vector<int> location) {
    if (type == "INT"){
        for (int i = 0; i < location.size(); i++) {
            cout << row_int[location[i]] << " ";
        }
    }
    if (type == "FLOAT"){
        for (int i = 0; i < location.size(); i++) {
            cout << row_float[location[i]] << " ";
        }
    }
    if ((type != "INT") && (type != "FLOAT")){
        for (int i = 0; i < location.size(); i++) {
            cout << row_string[location[i]] << " ";
        }
    }
}
