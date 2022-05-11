#include "iostream"
#include "vector"
#include "classes/Flat.h"
using namespace std;

vector<double> create_point();
int get_amount();
vector <Flat> fill_flats();
vector<Flat> define_flats(const vector<Flat>&, vector<double>);
bool isBelong(Flat, vector<double>);
void show_right_flats(vector<Flat>);



