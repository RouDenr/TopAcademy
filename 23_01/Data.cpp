#include <iostream>
#include <string>

class User {
    std::string name;
    int age;
    int *array_o; // массив оценок
    int size_arr; // фактический размер масива
    int cap; // вместимость массив (size * 2)

    public:
    User() {
        std::cout << "Input name: ";
        std::cin >> this->name;
        std::cout << "Input age: ";
        std::cin >> this->age;
    }
    User(const User &other) {
        // ...
    }
    User(std::string name, int age, int *arr, int size) {
        // ...
    }

    void print_data() {
        // высести все данные + print_avg_arr()
    }
    void print_avg_arr() {
        // вывести среднее значение arr
    }

    void add_to_arr(int val) {
        // добавить в конец arr
    }
    void del_to_arr(int index) {
        // добавить в конец arr
    }

    std::string getName() { return this->name; }
    int getAge() { return this->age; }

    void setName(std::string name) { this->name = name; }
    void setAge(int age) { this->age = age; }

    ~User() {
        // ...
    }
};


class Data{
    User *users;
    int size;

    public:
    Data() : Data(1) {}
    Data(const Data &other) {
        this->users = new User[other.size];
        this->size = other.size;
        for (int i = 0; i < this->size; ++i) {
            this->users[i].setName(other.users[i].getName());
            this->users[i].setAge(other.users[i].getAge());
        }
    }
    explicit Data(int count_users) {
        this->users = new User[count_users];
        this->size = count_users;
    }

    void print() {
        for (int i = 0; i < this->size; ++i) {
            this->users[i].print_data();
        }

    }

    ~Data() {
        delete [] this->users;
    }
};


int main(int argc, char const *argv[])
{
    Data test(3);
    test.print();
    return 0;
}
