#include <stdio.h>
#include "LinearRegression.h"

double** two_dimensional_allocation(size_t rows, size_t columns) { // Function which dynamically allocates memory to a 2D double array. Time complexity O(N), space complexity O(N*M). 
	double** array = new(std::nothrow) double* [rows];	
	nullptr_check(array);

	for (int i = 0; i < rows; i++) {										   // For loop; goes through the rows, and allocates memory for a column/new array.
		array[i] = new(std::nothrow) double[columns];
		nullptr_check(array[i]);
	}
	return array;
}

void free_two_dimensional_array(double** array, size_t rows, size_t columns) { // Function which frees memory from a 2D double array. Time complexity O(N), space complexity O(1).
	for (int i = 0; i < rows; i++) {	
		delete[] array[i];
	}
	delete[] array;
	for (int i = 0; i < rows; i++) {
			array[i] = nullptr;
	}
	array = nullptr;
	printf("\n\n***MEMORY FREED***\n\n");
}

double** additional_allocation(double** array, size_t rows, size_t columns, size_t newRows, size_t newColumns) { // Allocates extra memory to accomdate for the new rows/columns the user wants to add. Time and space complexity O(N*M). 
	double** newArray = new(std::nothrow) double*[newRows];
	nullptr_check(newArray);

	for (size_t i = 0; i < newRows; ++i) {
		newArray[i] = new(std::nothrow) double[newColumns];
		if (!newArray[i]) {
			for (size_t j = 0; j < i; ++j)
				delete[] newArray[j];
			delete[] newArray;
			return nullptr;
		}
	}

	size_t copyRows = std::min(rows, newRows);
	size_t copyCols = std::min(columns, newColumns);

	for (size_t i = 0; i < copyRows; ++i) {
		for (size_t j = 0; j < copyCols; ++j) {
			newArray[i][j] = array[i][j];
		}
	}

	free_two_dimensional_array(array, rows, columns);

	return newArray;
}

void nullptr_check(void* allocatedMemory) {	// Checks if dynamic memory allocation has failed. Time and space complexity O(1).
	if (allocatedMemory == nullptr) {
		exit(1);
	}
}