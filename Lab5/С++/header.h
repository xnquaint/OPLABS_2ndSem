

#ifndef LAB5VER2_HEADER_H
#define LAB5VER2_HEADER_H

#include "iostream"
#include "string"
#include "cstdlib"
#include "ctime"
#include <vector>
#include "classes/TArray.h"
#include "classes/IntArray.h"
#include "classes/DoubleArray.h"
using namespace std;

void init_arrays(int, vector<IntArray>&, vector<DoubleArray>&);
void show_arrays(vector<DoubleArray>, int);
void show_arrays(vector<IntArray>, int);
void increase_int_arrays(vector<IntArray>&, int, int);
void decrease_double_arrays(vector<DoubleArray>&, int, int);
double find_average(vector<IntArray>, vector<DoubleArray>, int, int&, string&);
void show_average_array(vector<IntArray>, vector<DoubleArray>, int, string);
#endif
