
#include "Line.h"
Line::Line(){
    start_x = 0.0;
    start_y = 0.0;
    end_x = 0.0;
    end_y = 0.0;
}
Line::Line(const string& line1, const string& line2) {
    start_x = stod(split(line1, ' ')[0]);
    start_y = stod(split(line1, ' ')[1]);
    end_x = stod(split(line2, ' ')[0]);
    end_y = stod(split(line2, ' ')[1]);
}
Line::Line(Line &line) {
    this->start_x = line.start_x;
    this->start_y = line.start_y;
    this->end_x = line.end_x;
    this->end_y = line.end_y;
}

Line::Line(double x1, double y1, double x2, double y2) {
    start_x = x1;
    start_y = y1;
    end_x = x2;
    end_y = y2;
}

double Line::get_start_x() const {
    return start_x;
}

double Line::get_start_y() const {
    return start_y;
}

double Line::get_end_x() const {
    return end_x;
}

double Line::get_end_y() const {
    return end_y;
}

Line operator+(Line &line1, Line &line2) {
    Line line(line1.start_x + line2.start_x, line1.start_y + line2.start_y,line1.end_x + line2.end_x,line1.end_y + line2.end_y);
   return line;
}

Line Line::operator++(int) {
    Line line(*this);
    end_x += 1;
    end_y += 1;
    return line;
}
void Line::show_line() {
    cout << "start(" << start_x << ", " << start_y << ")" << " end(" << end_x << ", " << end_y << ")" << endl;
}

bool Line::doesBelong(double x, double y) {
    return ((((x - start_x) * (end_y - start_y)) - ((y - start_y) * (end_x - start_x)) == 0) && ((x >= start_x && x <= end_x) || (x>= end_x && x <= start_x)));
}








