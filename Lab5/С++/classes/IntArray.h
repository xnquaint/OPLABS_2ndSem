

#ifndef LAB5VER2_INTARRAY_H
#define LAB5VER2_INTARRAY_H
#include "TArray.h"
#include "../header.h"
using namespace std;

class IntArray: public TArray {
private:

    int* array;
public:
    IntArray(): TArray(0), array(nullptr) {}
    explicit IntArray(int length): TArray(length){
        if(length > 0){
            array = new int [m_length];
        }
        else{
            array = nullptr;
        }
    }

    void fill_array() override{
        for (int i = 0; i < m_length; ++i) {
            array[i] = rand()%100 - 1;
        }
    }
     void increase(int value) override{
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

     void decrease(int value) override {
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
    ~IntArray() override{delete[] array;}
};


#endif
