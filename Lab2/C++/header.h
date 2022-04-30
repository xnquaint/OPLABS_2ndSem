
#ifndef LAB2SUPFINAL_HEADER_H
#define LAB2SUPFINAL_HEADER_H
#include <iostream>
#include <string>
#include <fstream>
#include "vector"
#include "cstring"
using namespace std;
struct catalog{
    char name[70];
    char type[40];
    char color[30];
    int price;
    int amount;
};

void input_file(const char*);
void output_file(const char*);
void create_second_file(const char*, const char*);
void edit_file(const char*);
#endif //LAB2SUPFINAL_HEADER_H
