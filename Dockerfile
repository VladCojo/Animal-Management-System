# Use an official GCC image as the base image
FROM gcc:latest

# Set the working directory within the container
WORKDIR /usr/src/app

# Copy your C++ source code and any necessary files into the container
COPY . .

# Compile your C++ program within the Docker container
RUN g++ -o main main.cpp

# Specify the command to run when the container starts
CMD ["./main"]
