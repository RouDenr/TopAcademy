#include <iostream>

class Drob {
    int a, b; // (a / b)

    public:
    Drob() : Drob(0,0) {}

    Drob(const Drob &other) : Drob(other.a, other.b) {}

    Drob(int a, int b) {
        this->a = a;
        this->b = b;
    }

    void print() {
        std::cout << this->a << "/" << this->b << "\n";
    }

    void input() {
        std::cout << "Input a: ";
        std::cin >> this->a;
        std::cout << "Input b: ";
        std::cin >> this->b;
    }

    void plus(int val){
        val = val * this->b;

        this->a = this->a + val;
    }

    void minus(int val){
        plus(-val);
    }

    ~Drob() {}
};

int main(int argc, char const *argv[])
{
    Drob test;

    test.input();
    Drob copy = test;

    test.print();
    test.plus(4);
    test.print();
    return 0;
}
