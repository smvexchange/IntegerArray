#include <iostream>
#include "IntegerArray.h"

int main() {
    try {
        IntegerArray array(10);
        for (int i = 0; i < array.get_length(); ++i) {
            array[i] = i + 1;
        }
        array.reallocate(8);

        for (int i = 0; i < array.get_length(); ++i) {
            std::cout << array[i] << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}