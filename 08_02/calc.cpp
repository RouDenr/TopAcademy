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

}
