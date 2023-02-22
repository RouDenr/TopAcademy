#include <iostream>
#include <memory>


template <typename T>
class Array {
    std::unique_ptr<T *> array;
    int size;
    int cap;

    public:
    Array() {}
    Array(const Array &other) {}
    Array(int size, T val) {} // как пример конструктор от размера и знчения (необязтельно)


    void add_begin(T val) {} // добавить в начало
    void add_end(T val) {} // добавить в конец

    void del_begin() {} // удалить из начала
    void del_end() {} // удалить из конца

    void print() {} // вывести массив

    ~Array() {}
};
