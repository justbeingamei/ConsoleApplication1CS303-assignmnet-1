// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <stdexcept> // For exception handling
#include "ConsoleApplication1.h"

const int MAX_SIZE = 200; // Maximum size for the array

// Part 1a of Q1 function to read data from a file into an array. 
int readArrayFromFile(const std::string& filename, int arr[], int maxSize) {
    std::ifstream infile(filename); // Open the file for reading
    if (!infile) { // Check if the file was opened successfully
        std::cout << "Error opening file!" << std::endl;
        return 0; // Return 0 if failed to open the file
    }

    int size = 0;
    while (infile >> arr[size] && size < maxSize) { // Read integers until the end of file or max size
        ++size;
    }

    infile.close(); // Close the file
    return size; // Return the number of elements read
}

// Part 1b of Q1: Function to check if a number exists in the array and return its index
int findNumberInArray(int arr[], int size, int number) {
    for (int i = 0; i < size; ++i) { // Loop through the array
        if (arr[i] == number) { // Check if the current element matches the number
           std::cout << " Number found at this index: " << i << std::endl; // Return the index if found
        }
    }
    return -1; // Return -1 if the number is not found
}

// 2 : Function to modify the value of an integer at a specific index
void modifyValueInArray(int arr[], int size, int index, int newValue) {
    if (index < 0 || index >= size) { // Check if index is within bounds
        throw std::out_of_range("Index out of range"); // Throw exception if out of bounds
    }

    int oldValue = arr[index]; // Store the old value
    arr[index] = newValue; // Update the value at the index
    std::cout << "Old Value: " << oldValue << ", New Value: " << newValue << std::endl; // Print results
}

// 3:  Function to add a new integer to the end of the array
void addValueToArray(int arr[], int& size, int newValue, int maxSize) {
    if (size >= maxSize) { // Check if the array is full
        throw std::overflow_error("Array is full"); // Throw exception if full
    }
    else {
        cout << newValue << " was added sucessfully to the end of this array! " << std::endl;
    }
    arr[size] = newValue; // Add new value to the end
    ++size; // Increment the size
}

// 4. Function to replace the value at an index with 0 or remove it
void replaceOrRemoveValueInArray(int arr[], int& size, int index, bool remove, int maxSize) {
    if (index < 0 || index >= size) { // Check if index is within bounds
        throw std::out_of_range("Index out of range"); // Throw exception if out of bounds
    }

    if (remove) { // If we want to remove the element
        for (int i = index; i < size - 1; ++i) { // Shift elements left
            arr[i] = arr[i + 1];
            std::cout << "Element has been succesfully removed!" << std::endl;
        }
        --size; // Decrement the size
    }
    else { // If we want to replace the element with 0
        arr[index] = 0; // Replace the element
        std::cout << "Element has been replaced succesfully with 0!" << std::endl;
    }
}

// Main function
int main() {
    int arr[MAX_SIZE];
    int size = readArrayFromFile("C:/Users/Melody/Downloads/A1input.txt", arr, MAX_SIZE); // Read data from file

    if (size == 0) { // Check if data was read
        std::cout << "No data read from file or file is empty!" << std::endl;
        return 1;
    }
    // find number in array
    
    try {

        int searchNumberInArray;
        std::cout << "Enter value you would like to find: ";
        std::cin >> searchNumberInArray;
        findNumberInArray(arr, MAX_SIZE, searchNumberInArray);

    }
    catch (const std::exception&e) {
        std::cout << "Error : " << e.what() << std::endl;
    }

    // Modify value in array with exception handling
    try {
        int indexToModify, newValue;
        std::cout << "Enter index to modify: ";
        std::cin >> indexToModify;
        std::cout << "Enter new value: ";
        std::cin >> newValue;
        modifyValueInArray(arr, size, indexToModify, newValue);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Add new value to array with exception handling
    try {
        int newValueToAdd;
        std::cout << "Enter a new value to add: ";
        std::cin >> newValueToAdd;
        addValueToArray(arr, size, newValueToAdd, MAX_SIZE);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Replace or remove value in array with exception handling
    try {
        int indexToReplaceOrRemove;
        char choice;
        std::cout << "Enter index to replace or remove: ";
        std::cin >> indexToReplaceOrRemove;
        std::cout << "Replace with 0 (r) or remove (d)? ";
        std::cin >> choice;
        bool remove = (choice == 'd');
        replaceOrRemoveValueInArray(arr, size, indexToReplaceOrRemove, remove, MAX_SIZE);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
