

#ifndef LAB5VER2_DOUBLEARRAY_H
#define LAB5VER2_DOUBLEARRAY_H
#include "TArray.h"
#include "../header.h"
using namespace std;

class DoubleArray: public TArray {
private:
    int m_length;
    double* array;
public:
    DoubleArray(): m_length(0),array(nullptr) {}
    explicit DoubleArray(int length): m_length(length){
        if(length > 0){
            array = new double [m_length];
        }
        else{
            array = nullptr;
        }
    }
    void fill_array() override{
        for (int i = 0; i < m_length; ++i) {
            array[i] = (rand()%1000 - 10) / 10.0;
        }
    }
    void increase (int value) override{
        for (int i = 0; i < m_length; ++i) {
            array[i] = array[i] + value;
        }
    }
    double get_average() override{
        double sum = 0;
        for (int i = 0; i < m_length; ++i) {
            sum+= array[i];
        }
        return sum / m_length;
    }
    void decrease (int value) override {
        for (int i = 0; i < m_length; ++i) {
            array[i] = array[i] - value;
        }
    }
    void show_array() override{
        for (int i = 0; i < m_length; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    ~DoubleArray() override{delete[] array;}
};


#endif
