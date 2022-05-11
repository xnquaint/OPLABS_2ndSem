#include "header.h"

int main() {
    vector<double> point = create_point();
    vector<Flat> flats = fill_flats();
    vector<Flat> appropriate_flats = define_flats(flats, point);
    show_right_flats(appropriate_flats);
    return 0;
}
