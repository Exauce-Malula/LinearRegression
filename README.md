# Linear Regression

Linear Regression is a statistical method attempting to find a linear line of best fit between bivariate data (dependent and independent variables), obversing if there is any correlation. It is calculated using the least squares regression. It then forms the equation: 

**y = mx+c / y = mx+b** 

as **ŷ = β1(x) + β0**. 

**https://www.ncl.ac.uk/webtemplate/ask-assets/external/maths-resources/statistics/regression-and-correlation/simple-linear-regression.html#:~:text=7%20See%20Also-,Definition,this%20is%20known%20as%20interpolation.**

Within machine learning, it is utilised within supervised learning algorithms, being fed data in order to create predictions. However, Linear Regression assumes that the data provided is linear, meaning it does not account for any polynomial relations.

# The Program:

The user is able to input a set of bivariate data, which is stored within a dynamically allocated 2-dimensional array which stores the double data type. The program calculates β1 (gradient), β0 (y - intercept). Then, the user has the choice of inputting sample data to test their prediction, add new rows of data, or save their data as a binary file (.bin); which can be accessed later.

# Updates:
**26th July 2025:** I have not fully tested all edge cases/error checking yet. When the binary file is saved, ensure that the file is in the same directory as the executable file. In the future, I may create a graphical user interface for the application. Additionally, apologies for writing the code in a C/C++ blend.

My next goal after fully completing the Linear Regression model is to move onto Polynomial Regression modelling. 


# Extras:

This project was inspired by Faisal-Alsayyari https://github.com/Faisal-Alsayyari / Faisal's Devlog's video, https://youtu.be/gqSbWMiOuFk?si=i09wBv9ikg5By4NT.
