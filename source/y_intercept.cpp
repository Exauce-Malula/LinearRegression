double y_intercept_beta_zero(double y_mean, double x_mean, double gradient) { // Returns the Y-intercept, calculated by subtracting the y_mean by the x mean multiplied by gradient. Time and space complexity O(1)
	return (y_mean - (x_mean * gradient));
}