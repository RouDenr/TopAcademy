#include <iostream>

class Point {
    public:
    int x, y;
};

class Array {
    int *arr;
    int size;
    int cap;

 public:
 explicit Array(int cap) {
    this->arr = new int[cap];
    this->cap = cap;
    size = 0;
 }

 void add_back(int val) {
    if (this->size + 1 > this->cap) {
        std::cout << "No: cap = " << this->cap << '\n';
    } else {
        this->arr[size] = val;
        size += 1;
    }
 }

 void insert(int i, int val) {
    if (i < 0 || i >= this->size) {
        std::cout << "size = " << this->size << "\n";
    } else {
        this->arr[i] = val;
    }
 }

 void erase(int index) {
    if (index < 0 || index >= this->size) {
        std::cout << "size = " << this->size << "\n";
    } else {
        for (int i = index + 1; i < this->size; ++i) {
            this->arr[i - 1] = this->arr[i];
        }
        this->size -= 1;
    }
 }

    void print() const {
        std::cout << "[ ";
        for (int i = 0; i < this->size; ++i) {
            std::cout << this->arr[i] << ", ";
        }
        std::cout << "]\n";
    }

    Array &operator+(int val) {
        add_back(val);
        return *this;
    }

    bool operator<(const Array &other) {
        return this->size < other.size;
    }
    bool operator>(const Array &other) {
        return this->size > other.size;
    }

    Array &operator-(const Array &other) {
       for (int i = 0; i < this->size && i < other.size; ++i) {
            this->arr[i] -= other.arr[i];
        }
        return *this;
    }

    int &operator[](int index) {
        return this->arr[index];
    }
    ~Array() {
        delete [] this->arr;
    }
};

int main() {
    Array arr(15);
    Array arr2(15);

    arr.add_back(1);
    arr.add_back(2);
    arr.add_back(3);
    arr.add_back(4);
    arr.print();

    arr.add_back(5);
    arr.add_back(6);
    arr.print();


    arr.insert(1, 22);
    arr.print();
    arr.erase(1);
    arr.print();

    arr + 7 + 8;
    arr.print();

    arr2 + 2 + 5;

    if (arr > arr2) {
        std::cout << "arr > arr2\n";
    } else {
        std::cout << "arr < arr2\n";
    }

    arr2.print();
    arr.print();
    arr2 - arr;
    arr2.print();
    std::cout << arr[0] << "\n";
    return 0;
}

