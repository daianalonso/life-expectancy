#include <iostream>
#include <algorithm>
#include "linear_regression.h"
#include <vector>
#include <string>

using namespace std;


LinearRegression::LinearRegression(): x() {}

void LinearRegression::fit(Matrix X, Vector y) { 
	// Se extiende la matriz, agregando columna de 1s para estimar intercept:
	Matrix X_ext(X.rows(), X.cols()+1); // Se declara X_ext con una columna más que X.
	X_ext.block(0, 0, X.rows(), X.cols()) = X; // Se copia X en X_ext.
	X_ext.col(X_ext.cols()-1).setOnes(); // Se llena la última columna de X_ext con 1s.
	//Planteamos la ecuacion normal y llamamos a la función de
	//Eigen colPivHouseholderQr para resolver el sistema
	//https://eigen.tuxfamily.org/dox/classEigen_1_1ColPivHouseholderQR.html
	Matrix X_ext_t = X_ext.transpose();
	this->x = (X_ext_t*X_ext).colPivHouseholderQr().solve(X_ext_t*y);
}

Vector LinearRegression::predict(Matrix X) {
	// Se extiende la matriz, agregando columna de 1s para estimar intercept:
	Matrix X_ext(X.rows(), X.cols()+1); // Se declara X_ext con una columna más que X.
	X_ext.block(0, 0, X.rows(), X.cols()) = X; // Se copia X en X_ext.
	X_ext.col(X_ext.cols()-1).setOnes(); // Se llena la última columna de X_ext con 1s.
	return X_ext*this->x;
}
