#include <iostream>

class Point {
 private:
    int x, y;

 public:
    Point() : Point(0, 0) {}

    Point(const Point &other) : Point(other.x, other.y) {}

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point &operator=(const Point &other) {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

    Point operator+(int val) const {
        return Point(this->x + val, this->y + val);
    }
    Point operator+(const Point &other) const {
        return Point(this->x + other.x, this->y + other.y);
    }

    void print() {
        std::cout << "[" << this->x << ", " << this->y << "]\n";
    }

    int getX() const {
        return this->x;
    }
    int getY() const {
        return this->y;
    }

};

    std::ostream &operator<<(std::ostream &out, const Point& point) {
        out << "[" << point.getX() << ", " << point.getY() << "]";
        return out;
    }


template <typename T>
class Array {
 private:
    T* arr;
    int size;
    int cap;
 public:
    Array() {
        this->arr = nullptr;
        size = 0;
        cap = 0;
    }

    int getSize() {return this->size; }

    Array(const Array &other) : Array(other.arr, other.size) {}

    Array(const T* arr, int size) {
        this->cap = size * 2;
        this->arr = new T[this->cap];
        this->size = size;
        for (int i = 0; i < size; ++i) {
            this->arr[i] = arr[i];
        }
    }

    T &operator[](int index) {
        return this->arr[index];
    }

    void add_back(T val) {
        // добвление элемента в конец
    }

    void delete_index(int index) {
        // удаление элемента по индексу
    }

    void add_index(T val, int index) {
        // добавление элемента по индексу
    }

    void plus_all(T val) {
        // прибавить ко всем элементам val
        // {1, 2, 3, 4} plus_all(3) {4, 5, 6, 7}
    }

    void minus_all(T val) {
        // вычесть из всех элементов val
        // {1, 2, 3, 4} minus_all(3) {-2, -1, 0, 1}
    }

    void print() {
        std::cout << "[ ";
        for (int i = 0; i < this->size; ++i) {
            std::cout << this->arr[i];
            if (i != size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << " ]\n";
    }

    ~Array() {
        delete [] this->arr;
    }
};

    template <typename T>
    std::ostream &operator<<(std::ostream &out, Array<T> array) {
        out << "[ ";
        for (int i = 0; i < array.getSize(); ++i) {
            out << array[i];
            if (i != array.getSize() - 1) {
                out << ", ";
            }
        }
        out << " ]";
        return out;
    }


template <typename T>
void print_any(const T &val) {
    std::cout << val + val << "\n";
}

int main()
{
    Point points[3] {Point(1,2), Point(3, 6), Point(8, 56)};
    int arr[5] { 1, 2, 3, 4, 5};

    Array<Point> array_points(points, 3);
    Array<int> array_int(arr, 5);
    std::cout << "init points" << array_points << "\n";
    std::cout << "init int"<< array_int << "\n";

    array_int.add_back(7);
    array_points.add_back(Point(7, 1));
    std::cout << array_points << "\n";
    std::cout << array_int << "\n";

    array_int.delete_index(2);
    array_points.delete_index(2);
    std::cout << array_points << "\n";
    std::cout << array_int << "\n";

    array_points.plus_all(Point(1, 1));
    array_int.plus_all(1);
    std::cout << array_points << "\n";
    std::cout << array_int << "\n";

    array_points.minus_all(Point(2, 0));
    array_int.minus_all(2);
    std::cout << array_points << "\n";
    std::cout << array_int << "\n";
}
