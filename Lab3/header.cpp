
#include "header.h"
vector<double> create_point(){
    double x;
    double y;
    double z;
    vector<double> point;
    cout << "Enter the point: " << endl;
    cout << " X: "; cin >> x; point.push_back(x);
    cout << "Y: "; cin >> y; point.push_back(y);
    cout << "Z: "; cin >> z; point.push_back(z);
    return point;
}
int get_amount(){
    int amount;
    do {
        cout << "Enter amount of flats: ";
        cin >> amount;
    }while(amount <= 0);
    return amount;
}
vector <Flat> fill_flats() {
    vector<Flat> flats;
    int amount = get_amount();
    double a;
    double b;
    double c;
    double d;
    for (int i = 0; i < amount; ++i) {
        cout << "\n";
        cout << "Flat number " << i + 1 << "." << endl;
        cout << "Enter coefficient a: ";
        cin >> a;
        cout << "Enter coefficient b: ";
        cin >> b;
        cout << "Enter coefficient c: ";
        cin >> c;
        cout << "Enter coefficient d: ";
        cin >> d;
        cout << "\n";
        cout << "Flat: " << a << "x + " << b << "y + " << c << "z + " << d << " = 0" << endl;
        Flat some_flat(a, b, c, d);
        flats.push_back(some_flat);
    }
    return flats;
}
void define_flats(const vector<Flat>& flats, vector<double> point){
    double a;
    double b;
    double c;
    double d;
    cout << "\n" << "Point: " << "(" << point[0] << ", " << point[1] << ", " << point[2] << ")" << endl;
    vector<Flat> assigned_flats;
    for (int i = 0; i < flats.size(); ++i) {
        if(isBelong(flats[i], point)) {
            assigned_flats.push_back(flats[i]);
        }
    }
    if(assigned_flats.empty()){
        cout << "Point doesnt belong to any of the flats.";
    }
    else{
        cout << "Flats the point belongs to: " << endl;
        for (int i = 0; i < assigned_flats.size(); ++i) {
            a = assigned_flats[i].get_a();
            b = assigned_flats[i].get_b();
            c = assigned_flats[i].get_c();
            d = assigned_flats[i].get_d();
            cout << a << "x + " << b << "y + " << c << "z + " << d << " = 0" << endl;
        }
    }
}

bool isBelong(Flat flats, vector<double> point){
    double a = flats.get_a();
    double b = flats.get_b();
    double c = flats.get_c();
    double d = flats.get_d();
    double x = point[0];
    double y = point[1];
    double z = point[2];
    return a*x + b*y + c*z + d == 0;
}


