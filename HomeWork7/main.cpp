#include <iostream>
#include "IntegerArray.h"

int main() {
    try {
        std::cout << "Create array:" << std::endl;
        IntegerArray array(10);
        for (int i = 0; i < array.get_length(); ++i) {
            array[i] = i + 1;
        }
        array.print();

        std::cout << "Copy array:" << std::endl;
        IntegerArray copy_array = array;
        copy_array.print();

        std::cout << "Get second element of array:" << std::endl;
        std::cout << array[1] << std::endl;

        std::cout << "Resize array:" << std::endl;
        array.resize(8);
        array.print();

        std::cout << "Set the first element of array:" << std::endl;
        array.insertAtBeginning(40);
        array.print();

        std::cout << "Set the last element of array:" << std::endl;
        array.insertAtEnd(20);
        array.print();

        std::cout << "Remove fourth element of array:" << std::endl;
        array.remove(3);
        array.print();

        std::cout << "Find value 6 in the array:" << std::endl;
        std::cout << array.findElement(6) << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}