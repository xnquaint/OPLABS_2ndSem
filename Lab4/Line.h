
#ifndef LAB4_LINE_H
#define LAB4_LINE_H
#include "header.h"
#include "string"
using namespace std;

class Line{
private:
    double start_x;
    double start_y;
    double end_x;
    double end_y;
public:
    Line();
    Line(const string&, const string&);
    Line(Line&);
    Line(double, double, double, double);
    double get_start_x() const;
    double get_start_y() const;
    double get_end_x() const;
    double get_end_y() const;
    void show_line();
    friend Line operator+(Line& line1, Line& line2);
    Line operator++(int);
    bool doesBelong(double x, double y);
};
#endif //LAB4_LINE_H
