const double growthFactor = 1.5;
const int initialSize = 6;

template <typename T>
class ArrayList {
    private:
       int size_;
       T *data_ = nullptr;
       int capacity_ = initialSize;

    public:
        ArrayList(T arr[], int startSize) {
            capacity_ = startSize;
            data_ = new int[capacity_];
        }

        T operator[] (int index) const234 {
            return data_[index];
        }

};

template <typename T>
ArrayList<T>::ArrayList(T arr[], int arrSize) {
    size_ = startSize;
    data_ = new T[startSize];
    for(int i = 0; i < arrSize; i++) {
        data_[i] = arr[i];
    }
}