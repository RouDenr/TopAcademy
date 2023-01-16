#include <iostream>
#include <string>

struct data {
    int year, month, day;
    data() : data(1999, 01, 01) {}

    data(int y, int m, int d) {
        this->year = y;
        this->month = m;
        this->day = d;
    }
};


class User {
 private:
    int id;
    std::string name;
    data user_data;
    int sum;

 public:
    User() : User("Ivan", data()){}

    User(const User &other) {}

    User(std::string name, data new_data) {
        this->id = 0;
        this->sum = 0;
        this->name = name;
        this->user_data.day = new_data.day;
        this->user_data.month = new_data.month;
        this->user_data.year = new_data.year;
    }

    void printUserData() {
        std::cout << "Id : " << this->id << "\n";
        std::cout << "Name : " << this->name << "\n";
        std::cout << "Data : " << this->user_data.day
                << "." << this->user_data.month
                << "." << this->user_data.year << "\n";
        std::cout << "Sum : " << this->sum << "\n";
    }
};




int main(int argc, char const *argv[]) {

    return 0;
}
