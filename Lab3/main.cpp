#include "header.h"

int main() {
    vector<double> point = create_point();
    vector<Flat> flats = fill_flats();
    define_flats(flats, point);
    return 0;
}
