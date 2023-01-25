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
void print_any(const T &val) {
    std::cout << val + val << "\n";
}

int main()
{
    Point a(3, 5);
    Point b(2, 1);

    a = a + b;

    print_any(7);
    print_any(25.6);
    print_any(a);
    return 0;
}
