#include <string>
#include <iostream>

class Calc {

public:
    //
    // Cal() ....
    //

    virtual void plus(int a, int b) {
        //...
    }

    virtual void minus(int a, int b) {
        //...
    }

    // ~Calc() {}

};

class SuperCalc : public Calc {

 public:
    void mult(int a, int b) { // умножение
        //...
    }

    void div(int a, int b) { // деление
        //...
    }

};

class SaveCalc : public Calc { // сохраняет последнюю операцуию

    //
    // SaveCal() ....
    //

    private:
    std::string last_operation; // последняя выполненая операция

    public:
    std::string getLastOperation() {
        return this->last_operation;
    }

    // void plus() {...}
    // void minus() {...}

    // ~SaveCalc() {}

};

int main() {
    Calc def_calc;
    SuperCalc super_calc;
    SaveCalc save_calc;

    def_calc.minus(100, 50);
    def_calc.plus(5, 7);

    super_calc.minus(10, 8);
    super_calc.minus(50, 10);
    super_calc.mult(7, 11);
    super_calc.div(512, 16);

    save_calc.minus(77, 8);
    save_calc.plus(8, 60);
    std::cout << save_calc.getLastOperation() << "\n";

}
