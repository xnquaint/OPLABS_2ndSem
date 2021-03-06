
#ifndef LAB5VER2_TARRAY_H
#define LAB5VER2_TARRAY_H


class TArray {
protected:
    int m_length;
    TArray(int length) : m_length(length){};
public:
    virtual void fill_array() = 0;
    virtual void increase(int) = 0;
    virtual void decrease(int) = 0;
    virtual double get_average() = 0;
    virtual void show_array() = 0;
    virtual ~TArray()= default;
};


#endif
