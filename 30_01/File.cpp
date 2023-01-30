#include <iostream>
#include <fstream>
#include <string>

void write_in_file(std::string name_file) {
    std::ofstream fout;

    int ch = 0;
    while (ch != 1 && ch != 2)
    {
        std::cout << "1.Reinput\n2.App in end file\n :";
        std::cin >> ch;

        if (ch == 1)
            fout.open(name_file); // перезпись в файл
        else if (ch == 2)
            fout.open(name_file, std::ios::app); // запись в конец файла
    }

    if (fout.is_open()) {
        std::string line = "";
        std::cin.ignore();
        while (fout.good() && line != "end") {
            std::getline(std::cin, line);
            if ( line != "end") {
                fout << line << "\n";
            }
        }
    } else {
        std::cout << "File not open!!!!\n";
    }

}















void read_all_file(std::string name_file) {
    std::ifstream fin;

    fin.open(name_file);
    if (fin.is_open()) {

        while (fin.good()) {
            std::string line;

            std::getline(fin, line);
            std::cout << line << "\n";
        }
    } else {
        std::cout << "File not open!!!!\n";
    }
    fin.close();
}

void file_hello() {
    std::ifstream fin;
    std::string file_name;

    std::cout << "Input file name: ";
    std::cin >> file_name;

    fin.open(file_name);

    std::string name;
    //std::cout << "Input name: ";
    //std::cin >> name;
    fin >> name;
    //std::getline(std::cin, name);
    //std::getline(fin, name);

    std::cout << "Hello " << name << "!\n";
    fin.close();
}

int main() {
    std::string file_name;

    std::cout << "Input file name: ";
    std::cin >> file_name;
    //read_all_file(file_name);
    write_in_file(file_name);
    return 0;
}

