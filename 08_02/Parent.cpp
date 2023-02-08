#include <string>
#include <iostream>


class Parent {
 protected: // Поля видны всем наследникам
    std::string name; //

 public:
    Parent() : Parent("Parent") {} // конструктор по умолчанию

    Parent(const Parent &other) : Parent(other.name) {} // конструктор копирования (от другого существуещего объекта)

    Parent(const std::string &name) { // конструктор с аргументом имени
        this->name = name;
        std::cout << "Hi! My name " << name << "\n";
    }

    virtual void sayName() {
        std::cout << "My name " << name << "\n";
    }

    virtual ~Parent() {
        std::cout << name << " is gone\n";
    }
};

class Child : public Parent {
 private:
    std::string last_name;

 public:

    Child() : Child("Child") {}
    Child(const Child &other) : Child(other.last_name) {}

    Child(const std::string &last_name) {
        this->last_name = last_name;
        std::cout << "Hi! My name " << this->name << " " << last_name << "\n";
    }

    Child(const std::string &name, const std::string &last_name) : Parent(name) {
        this->last_name = last_name;
        std::cout << "Hi! My name " << this->name << " " << last_name << "\n";
    }


    void sayName() {
        std::cout << "My name " << this->name << " " << last_name << "\n";
    }

    void sayLastName() {
        std::cout << "My lastname " << last_name << "!\n";
    }

    void sayHiByName(const std::string &name) {
        std::cout << "Hi " << name << "!\n";
    }
    ~Child() {
        std::cout << "Child " << this->last_name << " is gone\n";
    }
};

int main() {
    Parent staticParent;
    Parent *test = new Child("Ivan", "Ivanov");
    Parent *test_parent = new Parent("Ivanov");

    test->sayName();
    ((Child*)test)->sayHiByName("Mike");
    ((Child*)test_parent)->sayLastName();

    delete test;
    return 0;
}
