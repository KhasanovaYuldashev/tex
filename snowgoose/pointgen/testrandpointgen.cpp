/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testrandpointgen.cpp
 * Author: mposypkin
 *
 * Created on February 22, 2017, 1:53 PM
 */

#include "randpointgen.hpp"
#include "common/vec.hpp"
/*
 * 
 */
int main(int argc, char** argv) {

    const int n = 3;
    double x[n];
    snowgoose::Box<double> box(n);
    for(int i =0; i < n; i ++) {
        box.mA[i] = 0;
        box.mB[i] = 1;
    }
    
    snowgoose::RandomPointGenerator<double> rgen(box);
    rgen.getPoint(x);
    for(int i = 0; i < n; i ++) {
        SG_ASSERT(x[i] >= box.mA[i]);
        SG_ASSERT(x[i] <= box.mB[i]);
    }
    std::cout << snowgoose::VecUtils::vecPrint(n, x) << "\n";
    return 0;
}

