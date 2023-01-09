#include <iostream>
#include <vector>
#include <typeinfo>
#include <cstring>
template<class Type, size_t N>
void print(Type (&data)[N], int opt = 0) {
    int typeSize = sizeof(Type);
    const size_t size = N;
    for(int i = 0; i < size; i++) {
        std::cout << data[i]; 
        if(opt == 1) {
            std::cout << std::endl;
        } 
    }
}
template<class Type>
void print(Type data, int opt = 0) {
    if(opt == 0) {
        std::cout << data;
        return; 
    }
    std::cout << data << std::endl; 

}
template<class Type>
void printLine(Type data) {
    print(data, 1); 
}
template<class Type, size_t N>
void printLine(Type (&data)[N]) {
    char * buf; 
    sprintf(buf, "A%d_c", N);
    const char * str = typeid(data).name(); 
    if(strstr(str, buf)) {
        std::cout << data << std::endl;
        return; 
    }
    print(data, 1);
}
template<typename Container>
void print(const Container &data,  const std::string &delimiter = "") {
    if (data.size() == 0) return;
    for(auto it = data.begin(); it != data.end(); ++it) {
        std::cout << *it;
        if(it < data.end() - 1) {
            std::cout << delimiter;
        }
    }
    std::cout << std::endl; 
}
template <typename Container>
void printLine(const Container &data, const std::string &delimiter = "") {
    print(data,  delimiter + "\n");
}
template <typename T>
void print(std::initializer_list<T> data, const std::string &delimiter = "") {
    if (data.size() == 0) return;  // Return if the initializer list is empty
    for (auto it = data.begin(); it != data.end(); ++it) {
        std::cout << *it;
        if (it < data.end() - 1) {
            std::cout << delimiter;
        }
    }
}
template <typename T>
void printLine(std::initializer_list<T> data, const std::string &delimiter = "") {
    print(data, delimiter + "\n");
}