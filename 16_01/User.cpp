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
    static int count_user;
    static int sumForAllUsers;
    int id;
    std::string name;
    data user_data;
    int sum;

 public:
    User() : User("Ivan", data()){}

    User(const User &other)
        : User(other.name, other.user_data) {
            this->id = other.id;
            this->sum = other.sum;
    }

    User(std::string name, data new_data) {
        this->id = count_user + 1;
        this->sum = 0;
        this->name = name;
        this->user_data.day = new_data.day;
        this->user_data.month = new_data.month;
        this->user_data.year = new_data.year;

        count_user += 1;
    }

    void printUserData() const {
        std::cout << "Id : " << this->id << "\n";
        std::cout << "Name : " << this->name << "\n";
        std::cout << "Data : " << this->user_data.day
                << "." << this->user_data.month
                << "." << this->user_data.year << "\n";
        std::cout << "Sum : " << this->sum << "\n";
    }

    void addSum(int sum) {
        this->sum = this->sum + sum;
        sumForAllUsers = sumForAllUsers + sum;
    }


    static void printSumForAllUsers() {
        std::cout << sumForAllUsers << "\n";
    }
    static void printCountUser() {
        std::cout << count_user << "\n";
    }


};

int User::count_user { 0 };
int User::sumForAllUsers { 0 };


int main() {
    User Steve("Steve", data(1997, 04, 21));
    User Defoult;
    User CopySteve(Steve);

    Steve.addSum(300);
    Defoult.addSum(450);

    Steve.printUserData();
    std::cout << "\n";
    CopySteve.printUserData();
    std::cout << "\n";
    Defoult.printUserData();

    std::cout << "\n";
    User::printCountUser();
    User::printSumForAllUsers();
    return 0;
}
