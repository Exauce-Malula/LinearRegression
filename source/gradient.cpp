double summation_mean_beta_one(double** array, size_t rows, double x_mean, double y_mean) {	// Poor naming choice, but finds the sum of x-values minus the x mean, multiplied by the y values minus the y mean all divided by sum of x-values minus the x mean squared. Time complexity O(N), space complexity O(1).
	double beta_one = 0.0;
	double sum_x_sub_mean_squared = 0.0;
	for (int i = 0; i < rows; i++) {
		beta_one = beta_one + (
			(array[i][0] - x_mean) *
			(array[i][1] - y_mean)
			);

		sum_x_sub_mean_squared = sum_x_sub_mean_squared + ((array[i][0] - x_mean) * (array[i][0] - x_mean));
	}
	return beta_one / sum_x_sub_mean_squared;
}