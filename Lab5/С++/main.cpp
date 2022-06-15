
#include "header.h"
int main() {
    srand(time(nullptr));
    int m;
    double average;
    int value;
    int index;
    string type;
    do {
        cout << "Enter the number of arrays to be created: ";
        cin >> m;
    }while(m <= 0);
    vector<IntArray> int_arrays;
    vector<DoubleArray> double_arrays;
    init_arrays(m, int_arrays, double_arrays);
    cout << endl;
    show_arrays(int_arrays, m);
    show_arrays(double_arrays, m);
    cout << "Enter the value: "; cin >> value;
    increase_int_arrays(int_arrays, m, value);
    decrease_double_arrays(double_arrays, m, value);
    cout << endl << "Arrays after operations: " << endl;
    show_arrays(int_arrays, m);
    show_arrays(double_arrays, m);
    average = find_average(int_arrays, double_arrays, m, index, type);
    cout << endl << "The largest average: " << average;
    show_average_array(int_arrays, double_arrays, index, type);
    return 0;
}
