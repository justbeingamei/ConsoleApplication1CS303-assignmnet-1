#pragma once

#include <iostream>
#include <string> // For std::string
using namespace std;

//const int MAX_SIZE = 200; // Maximum size for the array

// Function to read data from a file into an array
// Returns the number of elements read
int readArrayFromFile(const std::string& filename, int arr[], int maxSize);

// Function to check if a number exists in the array and return its index
// Returns the index of the number or -1 if not found
int findNumberInArray(int arr[], int size, int number);

// Function to modify the value of an integer at a specific index
// Throws std::out_of_range if the index is invalid
void modifyValueInArray(int arr[], int size, int index, int newValue);

// Function to add a new integer to the end of the array
// Throws std::overflow_error if the array is full
void addValueToArray(int arr[], int& size, int newValue, int maxSize);

// Function to replace the value at an index with 0 or remove it
// Throws std::out_of_range if the index is invalid
void replaceOrRemoveValueInArray(int arr[], int& size, int index, bool remove, int maxSize);