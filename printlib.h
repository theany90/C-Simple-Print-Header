#include <iostream>
#include <vector>
#include <typeinfo>
#include <cstring>
template<class Type, size_t N>
Type print(Type (&data)[N], int opt = 0) {
    int typeSize = sizeof(Type);
    const size_t size = N;
    for(int i = 0; i < size; i++) {
        std::cout << *data + i; 
        if(opt == 1) {
            std::cout << std::endl;
        } 
    }
    std::cout.flush();
    return *data; 
}
template<class Type>
Type print(Type data, int opt = 0) {
    if(opt == 0) {
        std::cout << data << std::flush; 
        std::cout.flush();
        return data; 
    }
    std::cout << data << std::endl; 
    std::cout.flush();
}
template<class Type>
Type printLine(Type data) {
    print(data, 1); 
    std::cout.flush();
    return data; 
}
template<class Type, size_t N>
Type printLine(Type (&data)[N]) {
    char * buf; 
    sprintf(buf, "A%d_c", N);
    const char * str = typeid(data).name(); 
    if(strstr(str, buf)) {
        std::cout << data << std::endl;
        return 'c'; 
    }
    print(data, 1);
    std::cout.flush();
    return *data; 
}
template <class Type>
std::vector<Type> print(std::vector<Type> &data, int opt = 0) {
    auto it = data.begin();
    for(it; it != data.end(); it++) {
        std::cout << *it;  
        if(opt == 1) {
            std::cout << std::endl; 
        }
    }
    std::cout.flush();
    return data; 
}
template <class Type>
std::vector<Type> printLine(std::vector<Type> data) {
    print(data, 1);
    std::cout.flush(); 
    return data; 
}