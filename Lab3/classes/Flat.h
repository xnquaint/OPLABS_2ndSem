
#ifndef LAB3_FLAT_H
#define LAB3_FLAT_H

class Flat{
private:
    double a_coefficient;
    double b_coefficient;
    double c_coefficient;
    double d_coefficient;
public:
    Flat(double a, double b, double c, double d): a_coefficient(a), b_coefficient(b), c_coefficient(c),d_coefficient(d) {};
    double get_a() const;
    double get_b() const;
    double get_c() const;
    double get_d() const;
};
#endif
