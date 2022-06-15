

#include "header.h"
void init_arrays(int m, vector<IntArray>& int_arrays, vector<DoubleArray>& double_arrays){
    const int SIZE = 5;
    for (int i = 0; i < m; ++i) {
        int_arrays.push_back(IntArray(SIZE));
        int_arrays[i].fill_array();
        double_arrays.push_back(DoubleArray(SIZE));
        double_arrays[i].fill_array();
    }
}
void show_arrays(vector<DoubleArray> double_arrays, int m){
    for (int i = 0; i < m; ++i) {
        double_arrays[i].show_array();
    }
    cout << endl;
}
void show_arrays(vector<IntArray> int_arrays, int m){
    for (int i = 0; i < m; ++i) {
        int_arrays[i].show_array();
    }
    cout << endl;
}
void increase_int_arrays(vector<IntArray>& int_arrays, int m, int value){
    for (int i = 0; i < m; ++i) {
        int_arrays[i].increase(value);
    }
}
void decrease_double_arrays(vector<DoubleArray>& double_arrays, int m, int value){
    for (int i = 0; i < m; ++i) {
        double_arrays[i].decrease(value);
    }
}
double find_average(vector<IntArray> int_arrays, vector<DoubleArray> double_arrays, int m, int &index, string &type){
    double temp;
    double average;
    type = "int";
    for (int i = 0; i < m; ++i) {
        temp = int_arrays[i].get_average();
        if (temp >= average) {
            average = temp;
            index = i;
        }
    }
    for (int i = 0; i < m; ++i) {
        temp = double_arrays[i].get_average();
        if(temp >= average) {
            average = temp;
            index = i;
            type = "double";
        }
    }
    return average;
}
void show_average_array(vector<IntArray> int_arrays, vector<DoubleArray> double_arrays, int index, string type){
    cout << endl;
    cout << "Type: " << type << ". Index: " << index + 1 << endl;
    return type == "int" ? int_arrays[index].show_array() : double_arrays[index].show_array();
}
