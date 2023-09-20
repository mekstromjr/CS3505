
#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>

class DArray {
    private:
        int* data_;
        int size_;

    public:
        DArray(int size = 5);
        DArray(const DArray& other);
        ~DArray();
        int size();
        int operator[](int index) const;
        int& operator[](int index);
        void resize(int newSize);
        DArray& operator=(DArray other);
        friend std::ostream& operator<<(std::ostream& output, DArray arr);
};

#endif