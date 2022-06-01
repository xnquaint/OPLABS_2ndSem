#include "header.h"

int main() {
    double x1, y1, x2, y2;
    string point1;
    string point2;
    cout << "Enter first line. " << endl;
    cout << "First point: " << endl;
    cout << "X: "; cin >> x1;
    cout << "Y: "; cin >> y1; cout << endl;
    cout << "Second point: " << endl;
    cout << "X: "; cin >> x2;
    cout << "Y: "; cin >> y2; cout << endl;
    cout << "Enter second line. " << endl;
    cin.ignore();
    cout << "Enter first point in format[x y]: ";
    getline(cin, point1);
    cout << "Enter second point in format[x y]: ";
    getline(cin, point2); cout << endl;

    Line V1(x1, y1, x2, y2);
    Line V2(point1, point2);
    Line V3(V1);
    V3 = V1 + V2;
    cout <<"First line: ";  V1.show_line();
    cout << "Second line:"; V2.show_line();
    cout << "Third line: "; V3.show_line();
    V3++;
    cout << "Third line after increment: " ; V3.show_line(); cout << endl;

    cout << "Enter point to check: " << endl;
    cout << "X: "; cin >> x1;
    cout << "Y: "; cin >> y1;
    V3.doesBelong(x1, y1) ? cout << "Point belongs to the line." : cout << "Point doesnt belong to the line.";
    return 0;
}
