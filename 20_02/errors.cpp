
#include <iostream>
// #include <exception>


int input_n() {
    int n;
    std::cout << " : ";
    std::cin >> n;
    return n;
}

// Выбрсывает исключение
int print_n() {

    int n = input_n();

    if (n >= 10 && n <= 15) {
        std::cout << n << "\n";
    } else {
        throw "Число должно быть от 10 до 15!";
    }

    return n;
}

void print_all_del(int n) {

    for (int i = 1; i < n; ++i) {

        if (n % i == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
}

void print_div(int n) {
    int m = input_n();

    if (m == 0) throw "На ноль делить нельзя!!!";

    std::cout << "Остаток от деления " << n % m << "\n";
}

void chose_com(int n) {

    int v;

    std::cout << "Выберите команду \n";
    std::cout << "1. Все делители \n";
    std::cout << "2. Остаток от деления \n";
    std::cout << " : ";

    std::cin >> v;

    switch (v)
    {
    case 1:
        print_all_del(n);
        break;
    case 2:
        print_div(n);
        break;
    default:
        break;
    }
}

int main () {

    while (true) {
        try {
                std::cout << "Введите число от 10 до 15";
                int n = print_n();
                chose_com(n);


        } catch (const char* error) {
            std::cout << "Ошибка!!!\n";

            std::cout << error << "\n";
        }

    }
    std::cout << "End!!\n";

}
