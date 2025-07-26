#pragma once

#include <new>
#include <string>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <limits>

double** two_dimensional_allocation(size_t rows, size_t columns);
void free_two_dimensional_array(double** array, size_t rows, size_t columns);
double** additional_allocation(double** array, size_t rows, size_t columns, size_t newRows, size_t newColumns);
void nullptr_check(void* allocatedMemory);

double xMean(double** array, size_t rows);
double yMean(double** array, size_t rows);

double summation_mean_beta_one(double** array, size_t rows, double x_mean, double y_mean);

double y_intercept_beta_zero(double y_mean, double x_mean, double gradient);

double linear_regression_prediction(double gradient, double y_intercept, double x_value);

void save2DArray(double** array, size_t rows, size_t columns, const std::string& filename);
double** open2DArray(const std::string& filename, size_t& rows, size_t& columns);

void menu();
