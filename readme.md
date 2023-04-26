# Arduino Utility Library

The Arduino Utility Library is an open-source library that provides a set of data structures and algorithms for Arduino development, similar to the C++ Standard Library. It includes a range of useful features that can help simplify your code and make your Arduino projects more efficient.

## Working Features

- **Containers**
    - [x] Array
    - [ ] Vector
    - [ ] Linked List
    - [ ] Stacks
    - [ ] Queues
    - [ ] Maps
    - [ ] Sets

- **Algorithms**
    - [ ] Sorting
    - [ ] Searching
    - [ ] Mathematics

## Future Features

The Arduino Utility Library includes the following features:

- **Containers**: The library includes several container types, including arrays, vectors, and linked lists. These containers can be used to store and manage collections of data.

- **Algorithms**: The library includes a range of algorithms for searching, sorting, and manipulating data in containers. These algorithms can help simplify complex operations and improve performance.

- **Math Functions**: The library includes a range of math functions, including trigonometric functions, exponential functions, and logarithmic functions. These functions can help simplify complex math operations in your Arduino projects.

- **Random Number Generation**: The library includes functions for generating random numbers, which can be useful for a range of applications, such as generating random values for testing or creating random animations.

- **String Functions**: The library includes functions for manipulating strings, such as concatenation, splitting, and formatting. These functions can help simplify working with text data in your Arduino projects.

## Installation

To use the Arduino Utility Library, simply download the library from our GitHub repository and add it to your Arduino project's libraries folder. You can then include the library in your code using the `#include` directive.

## Usage

To use the Arduino Utility Library, simply include the necessary headers in your code and use the provided functions and classes. Here's an example of how to use the library to create an array of integers and sort it:

```c++
#include <AUL/containers/array.h>
#include <AUL/algorithms/sort.h>

AUL::Array<int, 5> myArray = {5, 2, 8, 1, 3};

AUL::sort(myArray.begin(), myArray.end());

// myArray now contains {1, 2, 3, 5, 8}
```

For more information on how to use the library, please refer to the documentation in the `docs` folder.

## Contributions

The Arduino Utility Library is an open-source project, and we welcome contributions from the community. If you would like to contribute to the library, please fork the repository and submit a pull request. For more information on how to contribute, please refer to the `CONTRIBUTING.md` file.

## License

The Arduino Utility Library is licensed under the MIT License. See `LICENSE` for more information.