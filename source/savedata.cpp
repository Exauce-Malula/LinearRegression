#include <iostream>
#include <fstream>

void save2DArray(double** array, size_t rows, size_t columns, const std::string& filename) {	// Creates a .bin file which contains data on rows, columns and info within the 2D array. Time complexity O(N), space complexity O(1).
	std::ofstream saveData((filename + ".bin"), std::ios::binary);

	saveData.write(reinterpret_cast<char*>(&rows), sizeof(size_t));
	saveData.write(reinterpret_cast<char*>(&columns), sizeof(size_t));

	for (size_t i = 0; i < rows; ++i) {
		saveData.write(reinterpret_cast<char*>(array[i]), columns * sizeof(double));
	}
}

double** open2DArray(const std::string& filename, size_t& rows, size_t& columns) {		// Opens file and reads binary file to create a 2D array. O(N) time complexity, O(N*M) space complexity.
	double** array;
	std::ifstream input(filename + ".bin", std::ios::binary);
	if (!input.is_open()) {
		std::cerr << "Failed to open file.\n";
		return nullptr;
	}

	input.read(reinterpret_cast<char*>(&rows), sizeof(size_t));
	input.read(reinterpret_cast<char*>(&columns), sizeof(size_t));

	array = new(std::nothrow) double* [rows];
	for (size_t i = 0; i < rows; i++) {
		array[i] = new(std::nothrow) double[columns];
		input.read(reinterpret_cast<char*>(array[i]), columns * sizeof(double));
	}
	return array;
}