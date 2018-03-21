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
#include <fstream>
#include "expr.hpp"
#include "algder.hpp"
#include "interval/interval_air.hpp"
#include <math.h>
#include <stdlib.h>
using namespace snowgoose::expression;
using namespace snowgoose::interval;

template <class T>
Expr<T> Ackley1(int N)
{
	Expr<T> x;
	Iterator i(0, N - 1);
	Expr<T> y = -20 * exp(-0.2 * sqrt((1.0 / N) * loopSum(sqr(x[i]), i))) - exp((1.0 / N) * loopSum(cos(2 * M_PI * x[i]), i)) + 20.0 + M_E;
	return y;
}


template <class T>
Expr<T> Brad()
{
	std::vector<double> vConst = { 0.14, 0.18, 0.22, 0.25, 0.29, 0.32, 0.35, 0.39, 0.37, 0.58, 0.73, 0.96, 1.34, 2.10, 4.39 };
	Expr<T> result = 0.0;
	Expr<T> y;
	for (int i = 0; i < 15; i++)
	{
		int I = i + 1;
		int J = 16 - I;
		Expr<T> a = vConst[i] - y[0] - I;
		Expr<T> b = J * y[1] + SGMIN(I, J) * y[2];
		result = result + sqr(a / b);
	}
	return result;
}


template <class T>
Expr<T> Alpine2()
{
int N = 3;
	Expr<T> x;
	Iterator i(0, N - 1);
	return loopMul(sqrt(x[i]) * sin(x[i]), i);
}

template <class T>
Expr<T> BiggsExpr2()
{
	Expr<T> x;
	Iterator i(1, 10);
	Expr<T> t = 0.1 * (Expr<T>)i;
	Expr<T> y = exp(-t) - 5 * exp(-10 * t);
	return loopSum(sqr(exp(-t * x[0]) - 5 * exp(-t * x[1]) - y), i);
}

template <class T>
Expr<T> Bird()
{
	Expr<T> x;
	return sin(x[0]) * exp(sqr(1 - cos(x[1]))) + cos(x[1]) * exp(sqr(1 - sin(x[0]))) + sqr(x[0] - x[1]);
}

template <class T>
Expr<T> BoxBettsQuadraticSum()
{
	Expr<T> x;
	Iterator i(1, 10);
	Expr<T> t = -0.1 * Expr<T>(i);
        Expr<T> a = exp(t*x[0]) - exp(t*x[1]);
        Expr<T> b = x[2] * (exp(t) - exp(10 * t));
	return loopSum(sqr(a-b), i);
}

template <class T>
Expr<T> Brown(int n)
{
	Expr<T> x;
	Iterator i(0, n - 2);
	Expr<T> t = (Expr<T>)i + 1;
	return loopSum(pow(sqr(x[i]), sqr(x[t]) + 1) + pow(sqr(x[t]), sqr(x[i]) + 1), i);
}

template <class T>
Expr<T> Hartman3()
{
	Expr<T> x;
	std::vector<std::vector<double>> a = { { 3, 10, 30 } , { 0.1, 10, 35 }, { 3, 10, 30 }, { 0.1, 10, 35 } };
	std::vector<std::vector<double>> p = { { 0.3689, 0.1170, 0.2673 } ,{ 0.4699, 0.4387, 0.7470 },{ 0.1091, 0.8732, 0.5547 }, { 0.03815, 0.5743, 0.8828 } };
	std::vector<double> c = {1.0, 1.2, 3.0, 3.2};
	
	Expr<T> y = 0.0;
	for (int i = 0; i < 4; i++)
	{
		Expr<T> e = 0.0;
		for (int j = 0; j < 3; j++)
			e += a[i][j] * sqr(x[j] - p[i][j]);
		y += c[i] * exp(-e);
	}
	return -y;
}

template <class T>
Expr<T> Hartman6()
{
	Expr<T> x;
	std::vector<std::vector<double>> a = { { 10, 3, 17, 3.5, 1.7, 8 } ,
	                                       { 0.05, 10, 17, 0.1, 8, 14 },
	                                       { 3, 3.5, 1.7, 10, 17, 8 }, 
										   { 17, 8, 0.05, 10, 0.1, 14 } };
	std::vector<std::vector<double>> p = { { 0.1312, 0.1696, 0.5569, 0.0124, 0.8283, 0.5886 },
	                                       { 0.2329, 0.4135, 0.8307, 0.3736, 0.1004, 0.9991 },
										   { 0.2348, 0.1451, 0.3522, 0.2883, 0.3047, 0.6650 },
										   { 0.4047, 0.8828, 0.8732, 0.5743, 0.1091, 0.0381 } };
	std::vector<double> c = { 1.0, 1.2, 3.0, 3.2 };

	Expr<T> y = 0.0;
	for (int i = 0; i < 4; i++)
	{
		Expr<T> e = 0.0;
		for (int j = 0; j < 6; j++)
			e += a[i][j] * sqr(x[j] - p[i][j]);
		y += c[i] * exp(-e);
	}
	return -y;
}

template <class T>
Expr<T> Ackley4()
{
	int n = 2;
	Expr<T> x;
	Iterator i(0, n - 2);
	Expr<T> t = (Expr<T>)i + 1;
	return loopSum(exp(1.0/pow(sqr(x[i]) + sqr(x[t]) ,5.0)) + 3*(cos(2*x[i]) + sin(2*x[t])), i);
}

template <class T>
Expr<T> Leon()
{
	Expr<T> x;
	return 100 * sqr(x[1] - sqr(x[0])) + sqr(1 - x[0]);
}

template <class T>
Expr<T> Factorial(int n)
{
	if (n == 0.0)
		return 1.0;
	Iterator i(1, n);
	Expr<T> result = loopMul((Expr<T>)i, i);
	return result;
}

template <class T>
Expr<T> Ball()
{
    Expr<T> x;
    Expr<T> rad = (M_PI/180) * x[0];
    Expr<T> t = sqr(x[1]*cos(rad));
    Expr<T> f=(t/32.0)*(tg(rad)+sqrt(sqr(tg(rad)) + 64.0*x[2]/t));
    return f;
}

template <class T>
Expr<T> TestIfThen()
{
    Expr<T> x;
    Expr<T> y = ifThen(x[0] > 2.0, sqr(x[0]), x[0] + x[0]);
    return y;
}



void calcFunc(const std::string& name, Expr<double> expr, const std::vector<double>& vars)
{
	auto result = expr.calc(FuncAlg<double>(vars));	
	std::cout << name << ": " << result << '\n';
}

void calcInterval(const std::string& name, Expr<Interval<double>> expr, const std::vector<Interval<double>>& vars)
{
	auto result = expr.calc(InterEvalAlg<double>(vars));
	std::cout << name << ": " << result;
}

void calcDerivative(const std::string& name, Expr<ValDer<double>> expr, const std::vector<double>& vars)
{
	ValDer<double> result = expr.calc(ValDerAlg<double>(vars));	
	std::cout << name << ": " << result << '\n';
}

void calcDerivativeInterval(const std::string& name, Expr<IntervalDer<double>> expr, const std::vector<Interval<double>>& vars)
{
	IntervalDer<double> result = expr.calc(IntervalDerAlg<double>(vars));
	std::cout << name << ": " << result;
}



void buildTex(std::ofstream& fout)
{
	fout << "test";
}

int main(int argc, char** argv) {
   
	/*std::ofstream fout("testtex.tex");
	buildTex(fout);*/
	//system("pdflatex tex/testtex.tex");

    //function value
	auto expr = Ball<double>();
    	expr.tex_prn(std::cout);
    
/*    
    //interval estimation of the function
    auto exprInterval = Ball<Interval<double>>();
    calcInterval("Ball interval", exprInterval, { {19, 21 }, {43.0, 45.0}, {8.0, 10.0} });
    
    //gradient of the function
    auto exprDer = Ball<ValDer<double>>();
    calcDerivative("Ball gradient", exprDer, { 20.0, 44.0, 9.0 });
    
    //interval estimation of the function
    auto exprDerInt = Ball<IntervalDer<double>>();
    calcDerivativeInterval("Ball interval gradient", exprDerInt, { {19, 21 }, {43.0, 45.0}, {8.0, 10.0} });
*/
     	
}


template <class T>
Expr<T> MyExpr()
{
	Expr<T> x;
	return (x[0] + (x[1] + sqr(x[1]))) * sqr(x[0] - sqr(x[1] - x[0]));
}

int main_(int argc, char** argv) {
	

	/*auto brad = Brad<double>();
	brad.tex_prn(std::cout);*/
	//auto leon = Leon<double>();
	//std::cout << "Leon: \n" << leon << std::endl;
	//leon.tex_prn(std::cout);



	/*
	auto my = MyExpr<double>();
	std::cout << "TEX PRN" << std::endl;	
	my.tex_prn(std::cout);
	*/
	/*auto expr = Ackley1<double>(2);	
	expr.tex_prn(std::cout);*/
	/*std::cout << "Ackley1: \n" << expr;
	calcFunc("Ackley1", expr, { 0.0, 0.0});
	calcFunc("Ackley1", expr, { 1.0, 1.0 });
	calcFunc("Ackley1", expr, { 2.0, 2.0 });
	
	auto exprInterval = Ackley1<Interval<double>>(2);
	calcInterval("Ackley1 estimation", exprInterval, { { 0.5, 1.5 }, { -0.5, 0.5 } });
	calcInterval("Ackley1 estimation", exprInterval, { { 0.9, 1.1 }, { -0.1, 0.1 } });

	auto brad = Brad<double>();
	calcFunc("Brad", brad, { 0.0824, 1.133, 2.3437 });

	calcFunc("Factorial 5", Factorial<double>(5), { });
	
	auto alpine = Alpine2<double>();
	calcFunc("Alpine", alpine, { 7.917, 7.9170526982459462172, 4.81584 });

	auto alpineInterval = Alpine2<Interval<double>>();
	calcInterval("Alpine estimation", alpineInterval, { { 7.5, 8.5 }, { 7.5, 8.5 }, { 7.5, 8.5 } });

	auto bigg = BiggsExpr2<double>();
	calcFunc("Biggs", bigg, { 1, 10});

	auto biggInterval = BiggsExpr2<Interval<double>>();
	calcInterval("Biggs estimation", biggInterval, { {0, 20}, { 0, 20 } });

	auto bird = Bird<double>();
	calcFunc("Bird", bird, { 4.70104, 3.15294 });
	calcFunc("Bird second minimum", bird, { -1.58214, -3.13024});

	auto birdInterval = Bird<Interval<double>>();
	calcInterval("Bird estimation", birdInterval, { { -2 * M_PI, 2 * M_PI },{ -2 * M_PI, 2 * M_PI } });

	auto boxBetts = BoxBettsQuadraticSum<double>();
	calcFunc("BoxBetts", boxBetts, { 1.0, 10.0, 1.0 });

	auto boxBettsOnterval = BoxBettsQuadraticSum<Interval<double>>();
	calcInterval("BoxBetts estimation", boxBettsOnterval, { { 0.9, 1.2 }, {9, 11.2}, { 0.9, 1.2 } });
	
	auto brown = Brown<double>(4);
	calcFunc("Brown", brown, { 0, 0, 0, 0 });
	
	auto hartman3 = Hartman3<double>();
	calcFunc("Hartman3", hartman3, { 0.114614, 0.555649, 0.852547 });
	auto hartman6 = Hartman6<double>();
	calcFunc("Hartman6", hartman6, {0.201690, 0.150011, 0.476874, 0.275332, 0.311652, 0.657301});


	//auto schewefel = Schewefel<Interval<double>>(2, 2);
	//calcInterval("Schewefel", schewefel, { { 2.0, 3.0 },{ 2.0, 3.0 } });

	IL<double> list = { { 1.0, 4.0 },{ 2.0, 3.0 } };
	auto minInterval = min(list);

	auto last = Ackley4<double>();
	calcFunc("Last", last, { 1.479252, -0.739807});
	//std::cout << last << '\n';

*/
    return 0;
}
