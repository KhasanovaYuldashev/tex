/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testprojecttosimplex.cpp
 * Author: mposypkin
 *
 * Created on November 9, 2016, 4:01 PM
 */

#include <iostream>
#include "projecttosimplex.hpp"
#include "sgerrcheck.hpp"

/*
 * 
 */
int main(int argc, char** argv) {

    const double C = 3.;
    const int N = 3;
    snowgoose::ProjectToSimplex<double> prj(C);
    auto check = [&N, &prj](double* x, const double* check) {
        prj.project(N, x);
        double d = snowgoose::VecUtils::vecDist(N, x, check);
        std::cout << "x = " << snowgoose::VecUtils::vecPrint(N, x) << ", distance from reference = " << d <<  "\n";
        SG_ASSERT(d < 0.001);
    };


    double x[N] = {4,4,0};
    double r[N] = {1.5, 1.5, 0};
    check(x, r);
    return 0;
}

