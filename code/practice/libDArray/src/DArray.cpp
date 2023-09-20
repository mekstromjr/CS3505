#include "DArray.h"

DArray::DArray(int size): size_(size) {
    data_ = new int[size_] { };
}

DArray::DArray(const DArray& other) {
    size_ = other.size_;
    data_ = new int[size_];
    for(int i = 0; i < size_; i++)
        data_[i] = other.data_[i];
}

DArray::~DArray() {
    delete [] data_;
}

int DArray::size() {
    return size_;
}

int DArray::operator[](int index) const {
    return data_[index];
}

int& DArray::operator[](int index) {
    while(index >= size_) 
        resize(size_ * 1.2);
    
    return data_[index];
}

void DArray::resize(int newSize) {
    int* newData = new int[newSize] { };
    for(int i = 0; i < size_; i++) 
        newData[i] = data_[i];
    
    delete [] data_;
    data_ = newData;
    size_ = newSize;
}

DArray& DArray::operator=(DArray other/*Auto-Calls copy constructor before this*/) {
    // swap(data_, other.data_);
    int* tmpData = data_;
    data_ = other.data_;
    other.data_ = tmpData;
    // swap(size_, other.size_);
    int tmpSize = size_;
    size_ = other.size_;
    other.size_ = tmpSize;
    
    return *this;
}

std::ostream& operator<<(std::ostream& output, DArray arr) {
    output << "[";
    for(int i = 0; i < arr.size() - 1; i++) 
        output << arr[i] << ", ";
    
    output << arr[arr.size() - 1] << "]";

    return output;
}
