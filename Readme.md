# Animal Management System

This C++ program is an Animal Management System that allows users to add, display, delete, and save animals (Dogs and Cats) to a file. It utilizes object-oriented programming principles, including polymorphism and file handling.

## Files

1. **main.cpp**: Contains the source code for the Animal Management System. The program uses classes and inheritance to represent Dog and Cat entities as derived classes from the base class Animal. It provides a console-based interface for users to interact with the system.

2. **main**: The executable file generated after compiling the main.cpp code. This file is ready to run the Animal Management System.

3. **testFile.txt**: A sample file containing animal data for testing the program. The file includes information about dogs and cats in a specified format.

## Usage

1. **Compile**: Compile the `main.cpp` file using a C++ compiler to generate the executable file. (or simply use the provided "main" file which is already compiled)

   ```bash
   g++ main.cpp -o main

## Notes

   * The program utilizes file handling to save and load animal data, demonstrating basic I/O operations in C++.

   * Object-oriented concepts such as polymorphism and inheritance are employed for designing the animal classes.

   * Error handling is implemented to ensure the integrity of the entered data.