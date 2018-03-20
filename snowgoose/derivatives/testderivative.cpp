/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   valder.hpp
 * Author: alusov
 *
 * Created on June 22, 2017, 11:36 AM
 */

#include <iostream>
#include <math.h>
#include "valder.hpp"
#include "intervalder.hpp"
#include "grad.hpp"
#include "interval/interval_air.hpp"

using namespace std;
using namespace snowgoose::derivative;
using namespace snowgoose::interval;


void Test1()
{
    Grad<double> x({ 1.0, 0.0 });
    Grad<double> y({ 0.0, 1.0 });
    Grad<double> z = x + y;   
    std::cout << "Test1: " <<  z << '\n';
}

void Test2()
{
    ValDer<double> x(3.0, { 1.0, 0.0 });
    ValDer<double> y(5.0, { 0.0, 1.0 });
    std::cout << "Test2: x * y = " << x * y;
    ValDer<double> z = sin(x * y);   
    std::cout << "Test2: " <<  z;
}

void Test3()
{
    ValDer<double> a(20, { 1.0, 0.0, 0.0 });
    ValDer<double> v(44.0, { 0.0, 1.0, 0.0 });
    ValDer<double> h(9.0, { 0.0, 0.0, 1.0 });
    ValDer<double> rad = (M_PI/180) * a;
    ValDer<double> t = sqr(v*cos(rad));
    ValDer<double> f=(t/32.0)*(tg(rad)+sqrt(sqr(tg(rad)) + 64.0*h/t));
    std::cout << "Test3: " <<  f;
}

void Test4()
{
    IntervalDer<double> x({0.99, 1.01}, {1.0});
    IntervalDer<double> y = cos(x);
    std::cout << "Test4: " << y;
}

void Test5()
{
    IntervalDer<double> a({ 19, 21 }, { 1.0, 0.0, 0.0 });
    IntervalDer<double> v({ 43.0, 45 }, { 0.0, 1.0, 0.0 });
    IntervalDer<double> h({ 8.0, 10.0 }, { 0.0, 0.0, 1.0 });
    IntervalDer<double> rad = (M_PI/180) * a;
    IntervalDer<double> t = sqr(v*cos(rad));
    IntervalDer<double> f=(t/32.0)*(tg(rad)+sqrt(sqr(tg(rad)) + 64.0*h/t));
    std::cout << "Test6: " <<  f;
}

int main(int argc, char** argv) {

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
}
 




