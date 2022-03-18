#pragma once
#include <vector>
#include "types.h"
#include <string>

using namespace std;

class LinearRegression {
public:
    LinearRegression();
    void fit(Matrix X, Vector y); 
    Vector predict(Matrix X);
private:
    Vector x; 
};
