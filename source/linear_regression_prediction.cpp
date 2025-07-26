#include "LinearRegression.h"

double linear_regression_prediction(double gradient, double y_intercept, double x_value) {	// y = mx + c (or y = mx + b, depends where you are from) to find a y - value prediction. Time and space complexity O(1).
	return (gradient * x_value) + y_intercept;
}

void menu() {
	char letter;
	bool loop = true;
	bool operation_loop = true;

	double** dataSet;
	size_t rows;
	size_t columns = 2;
	size_t newRows;
	double x_Mean;
	double y_Mean;
	double gradient;
	double y_intercept;
	double x_value;

	std::string filename;
	std::string file_new_name;
	
	while (loop) {
		printf("Welcome to Exauce's Linear Regression model.\nWould you like to enter new data or open previously saved data?\nType N for new data, S to open previously saved data, otherwise, type X to exit.\n");
		std::cin >> letter;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			printf("Wrong data type input error.\n");
			loop = false;
		}

		switch (letter) {
			case 'N':
			case 'n': {
				printf("\nHow many rows of data do you want to input?\n");
				std::cin >> rows;
				if (rows == 0) {
					printf("Cannot have zero rows. Try again.\n");
					break;
				}
				else {
					dataSet = two_dimensional_allocation(rows, columns);
					for (size_t i = 0; i < rows; i++) {
						printf("\nPlease input X value %zu: ", i + 1);
						std::cin >> dataSet[i][0];
						if (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							printf("\nWrong data type input error.\n");
							loop = false;
						}
					}

					for (size_t i = 0; i < rows; i++) {
						printf("\nPlease input Y value %zu: ", i + 1);
						std::cin >> dataSet[i][1];
						if (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							printf("\nWrong data type input error.\n");
							loop = false;
						}
					}

					break;
				}
			}
			
			case 'S':
			case 's': {
				printf("\nPlease enter the filename of the file you want to open (do not include file extension please).\n");
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, filename);
				dataSet = open2DArray(filename, rows, columns);
				break;
			}

			case 'X':
			case 'x': {
				free_two_dimensional_array(dataSet, rows, columns);
				exit(0);
				break;
			}

			default: {
				printf("Incorrect input. Please try again.\n");
				free_two_dimensional_array(dataSet, rows, columns);
				exit(0);
			}
		}

		while(operation_loop){
			x_Mean = xMean(dataSet, rows);
			y_Mean = yMean(dataSet, rows);
			gradient = summation_mean_beta_one(dataSet, rows, x_Mean, y_Mean);
			y_intercept = y_intercept_beta_zero(y_Mean, x_Mean, gradient);

			std::cout << "\nYour equation is y = " << gradient << "x + " << y_intercept << ".\nWould you like to input data or add new rows? Type I to input data, type N to add new rows, otherwise, type X to quit." << std::endl;
			std::cin >> letter;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				printf("Wrong data type input error.\n");
				operation_loop = false;
			}
			
			switch (letter) {
				case 'I':
				case 'i': {
					printf("Please input a value: ");
					std::cin >> x_value;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						printf("\nWrong data type input error.\n");
						operation_loop = false;
					}

					std::cout << "\nApproximate Y-Value: " << linear_regression_prediction(gradient, y_intercept, x_value) << "." << std::endl;
					operation_loop = false;
					break;
				}

				case 'N':
				case 'n': {
					printf("\nHow many new rows would you like to input? ");
					std::cin >> newRows;

					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						printf("\nWrong data type input error.\n");
						operation_loop = false;
					}

					if (newRows == 0 || newRows <= rows) {
						printf("Cannot have zero rows. Try again.\n");
						break;
					}

					dataSet = additional_allocation(dataSet, rows, columns, newRows, 2);
					for (size_t i = rows; i < newRows; i++) {
						printf("\nPlease input X value %zu: ", i + 1);
						std::cin >> dataSet[i][0];
						if (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							printf("\nWrong data type input error.\n");
							operation_loop = false;
						}
					}

					for (size_t i = rows; i < newRows; i++) {
						printf("\nPlease input Y value %zu: ", i + 1);
						std::cin >> dataSet[i][1];
						if (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							printf("\nWrong data type input error.\n");
							operation_loop = false;
						}
					}
					rows = newRows;
					break;
				}
				
				case 'X':
				case 'x': {
					free_two_dimensional_array(dataSet, rows, columns);
					exit(0);
					break;
				}

				default: {
					printf("Incorrect input. Please try again.\n");
					free_two_dimensional_array(dataSet, rows, columns);
					exit(0);
				}
			}

			printf("Would you like to try again?\nType Y for yes, N for no, S to save data and quit.\n");
			std::cin >> letter;
			switch (letter) {
				case 'Y':
				case 'y': {
					operation_loop = true;
					break;
				}
				case 'N': {
					free_two_dimensional_array(dataSet, rows, columns);
					exit(0);
					break;
				}
				case 'S':
				case 's': {
					printf("\nPlease name your file: ");
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::getline(std::cin, file_new_name);
					save2DArray(dataSet, rows, columns, file_new_name);
					free_two_dimensional_array(dataSet, rows, columns);
					exit(0);
					break;
				}
			}
		}
	}
	
}