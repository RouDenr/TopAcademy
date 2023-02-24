#include <iostream>
#include "main.hpp"

class Point {
 private:
    int x = 0, y = 0;
 public:
    Point() : Point(0, 0) {}

    Point(const Point &other) : Point(other.x, other.y) {}

    Point(int x, int y) {
        this->setX(x);
        this->setY(y);
    }

    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }
    void setX(const int &x) {
        if (x >= -50 && x <= 50) {
            this->x = x;
        } else {
            std::cout << "-50 <= x <= 50\n";
        }
    }
    void setY(const int &y) {
        if (y >= -50 && y <= 50) {
            this->y = y;
        } else {
            std::cout << "-50 <= y <= 50\n";
        }
    }
};


int main(int argc, char const *argv[]) {
    Point test_point(0, 5);
    Point copy_pint(test_point);

    std::cout << "Point x = " << test_point.getX() <<" \n";
    std::cout << "Point y = " << test_point.getY() <<" \n";
    return 0;
}
