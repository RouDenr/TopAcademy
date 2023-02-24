#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>

template <typename T>
class Array {
 private:
    T *array;
    int size;
    int cap;

 public:
    Array() : Array(0, 0) {}

    Array(const Array &other) {}

    Array(const T* begin, const T* end) {
        this->size = 0;
        for (const T* i = begin; i != end; ++i) {
            this->size += 1;
        }
        this->array = new T[this->size];

        int i_arr = 0;
        for (const T* i = begin; i != end; ++i) {
            array[i_arr] = *i;
            ++i_arr;
        }
        this->cap = this->size;
    }

    Array(int size, T val) {
        this->array = new T[size];
        this->size = size;
        this->cap = size;

        for (int i = 0; i < size; ++i) {
            this->array[i] = val;
        }
    }

    ~Array() {
        delete [] this->array;
    }

    T &operator[](int i) {
        return this->array[i];
    }

    void recap(int new_cap) {
        if (new_cap <= this->cap) {
            std::cout << "Capasity > new capasity\n";
        } else {
            T* tmp_arr = this->array;
            this->array = new T[new_cap];
            this->cap = new_cap;

            for (int i = 0; i < this->size; ++i) {
                this->array[i] = tmp_arr[i];
            }
            delete [] tmp_arr;
        }
    }

    void add_end(const T &val) {
        if (this->cap < this->size + 1) {
            recap(size * 2);
        }
        this->array[this->size] = val;
        this->size++;
    }

    int getSize() { return this->size; }
};


template <typename array>
void print_arr(array &arr) {
    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }

}

template< typename cont>
void print_vector(const cont &array) {
    typename cont::const_iterator i;
    typename cont::const_iterator end = array.end();

    std::cout << "Size array " << array.size() << "\n";
    //std::cout << "Capacity array " << array.capacity() << "\n";
    for (i = array.begin();
        i != end;
        i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}

int main() {

    // int pointer_array[5] {1,2,3,4,5};
    // std::vector<int> array(&(pointer_array[0]), &(pointer_array[5]));
    // print_vector(array);
    // array.push_back(6);
    // print_vector(array);

    // Array<int> my_array(&(pointer_array[0]), &(pointer_array[5]));
    // for (int i = 0; i < my_array.getSize(); ++i) {
    //     std::cout << my_array[i] << " ";
    // }
    // std::cout << "\n";
    // my_array.add_end(6);

    // print_arr(my_array);




    std::vector<int> int_vec;
    std::list<int> int_list;
    std::set<int> int_set;
    std::map<int, std::string> int_map;

    // int_map["Mike"] = 55;
    // int_map["Ivan"] = 5;
    // int_map["44"] = 15;
    // int_map["Alex"] = 733;
    // int_map["Egor"] = 25;

    int_map[1] = "Mike";
    int_map[0] = "Ivan";
    int_map[7] = "Alex";
    int_map[-1] = "Egor";
    int_map[0] += " Oleg";


    //auto str = "str";

    for (auto i = int_map.begin();
        i != int_map.end();
        ++i) {
            std::cout << i->first << " ";
            std::cout << i->second << "\n";
        }

    return 0;
}
