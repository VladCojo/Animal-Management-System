Steps to run the program using docker:
    1. Clone the repository
    2. Go to where you have cloned the repository
    3. Run in terminal:  docker build -t my_cpp_program .
    4. After the build is finished run: docker run -it my_cpp_program
The file created by choosing option 6 will bea created in the docker container so you won't be able to access it if you close the program

This is a simple C++ program that 
# Animal Database Program

This C++ program allows users to manage a database of animals, including dogs and cats. Users can perform operations such as adding animals, displaying the database, sorting animals by name, deleting animals by name, and saving the database to a file.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Building and Running](#building-and-running)
- [Contributing](#contributing)
- [License](#license)

## Features

1. **Add Animal:**
   - Users can add dogs or cats to the database.

2. **Display Animals:**
   - Display the current contents of the animal database.

3. **Sort Animals:**
   - Sort animals in ascending order based on their names.

4. **Delete Animal:**
   - Delete an animal from the database by providing its name.

5. **Save to File:**
   - Save the current contents of the database to a file.

## Usage

- Choose options from the menu to perform various operations.
- Follow on-screen instructions for data entry.

## Building and Running

1. **Build the Program:**
   ```bash
   g++ main.cpp -o main
