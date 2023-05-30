#include <iostream>
#include "IntegerArray.h"

int main() {
    // Declare an array with 10 elements
    IntegerArray array(10);

    // Fill the array with numbers 1 through 10
    for (int i = 0; i < 10; ++i)
        array[i] = i + 1;

    // Resize the array to 8 elements
    array.resize(8);

    // A few more tests to ensure copy constructing / assigning arrays
    // doesn't break things
    {
        IntegerArray b(array);
        b = array;
        b = b;
        array = array;
    }

    // Print out all the numbers
    for (int i = 0; i < array.get_length(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    return 0;
}