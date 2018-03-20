/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testinterval.cpp
 * Author: Alexander Usov
 *
 * Created on January 20, 2017, 9:13 AM
 */
#include <iostream>
#include <math.h>
#include "interval_air.hpp"

using namespace std;
using namespace snowgoose::interval;

int main(int argc, char** argv) {

    Interval<double> a(2.0, 3.0), b(1, 2);
    auto c = sqr(a);
    std::cout << c;
    auto cc = a ^ 3;
    std::cout << cc;
    auto ccc = sin(a);
    std::cout << ccc;
    auto cccc = cos(a);
    std::cout << cccc;
    auto dd = exp(a);
    std::cout << dd;
    auto ddd = sqrt(a);
    std::cout << ddd;
    auto dddd = 1.0 / b;
    std::cout << dddd;
	std::cout << ln(dddd);
    std::cout << a + b;
    std::cout << a - b;
    std::cout << a * b;

    Interval<double> x(0.9, 1.1), y(-0.1, 0.1);
    Interval<double> z = -20.0 * exp(-0.2 * sqrt(0.5 * (sqr(x) + sqr(y)))) - 
                     exp(0.5*(cos(2.0 * M_PI * x) + 
                     cos(2.0 * M_PI * y))) + 20.0 + M_E;
    std::cout << z;

    Interval<double> z2 = sin(1.0/x);
    std::cout << z2;
    
    std::cout << abs(Interval<double>(-3.0, 1.0));
    std::cout << ln(Interval<double>(M_E, M_E * M_E));
    std::cout << log(Interval<double>(100.0, 1000.0), 10.0);
    IL<double> li = { { -1.0,1.0 }, { -7.0, 5.0 }, {-99.0, 0.0} };
    std::cout << min(li);

    std::cout << "sin " << sin(ln(Interval<double>(-3.0, 10.0)));
    std::cout << "sqrt " << sqrt(Interval<double>(-3.0, 100.0));
    return 0;
}

