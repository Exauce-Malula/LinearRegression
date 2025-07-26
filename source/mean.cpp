double xMean(double** array, size_t rows) { // Calculates the mean of the x values. Time complexity O(N), space complexity O(1).
	double xMean = 0.0;
	for (int i = 0; i < rows; i++) {
		xMean = xMean + array[i][0];
	}
	xMean = xMean / rows;
	return xMean;
}

double yMean(double** array, size_t rows) { // Calculates the mean of the y values. Time complexity O(N), space complexity O(1).
	double yMean = 0.0;
	for (int i = 0; i < rows; i++) {
		yMean = yMean + array[i][1];
	}
	yMean = yMean / rows;
	return yMean;
}