#ifndef MANGDONG_H
#define MANGDONG_H

template <typename T>
class MangDong {
private:
    T* data;
    int capacity;
    int size;

    void thayDoiKichThuoc(int newCapacity) {
        T* temp = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity = newCapacity;
    }

public:
    MangDong() {
        capacity = 4;
        size = 0;
        data = new T[capacity];
    }

    ~MangDong() {
        delete[] data;
    }

    int getSize() const { return size; }

    void push_back(const T& element) {
        if (size == capacity) {
            thayDoiKichThuoc(capacity * 2);
        }
        data[size++] = element;
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }
};

#endif