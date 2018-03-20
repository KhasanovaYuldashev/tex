/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   projecttosimplex.hpp
 * Author: mposypkin
 * 
 * Use the method proposed by Malozemov & Tamasyan
 * http://www.apmath.spbu.ru/ru/staff/tamasyan/publ/publ1.pdf
 *
 * Created on November 9, 2016, 3:37 PM
 */

#ifndef PROJECTTOSIMPLEX_HPP
#define PROJECTTOSIMPLEX_HPP

#include "vec.hpp"

namespace snowgoose {

    /**
     * Project a point to a simplex
     * The simplex is given as sum_i^n x_i = C, x_i >= 0
     */
    template <class FT> class ProjectToSimplex {
    public:

        /**
         * Constructor
         * @param c the value of RHS
         */
        ProjectToSimplex(FT c) : mC(c) {
        }

        /**
         * Projects vector x to simplex  sum_i^n x_i = mC, x_i >= 0
         * @param n dimension
         * @param x vector to project
         */
        void project(int n, FT* x) {
            FT lam = (1. / ((double) n)) * (mC - VecUtils::vecSum(n, x));
            VecUtils::vecAddScalar(n, lam, x, x);
            while (true) {
                FT s = 0;
                int np = 0;
                int nn = 0;
                for (int i = 0; i < n; i++) {
                    if (x[i] > 0) {
                        s += x[i];
                        np++;
                    } else if (x[i] < 0) {
                        nn++;
                    }
                }
                if (nn == 0)
                    break;
                else {
                    lam = (1. / ((double) np)) * (mC - s);
                    for (int i = 0; i < n; i++) {
                        if (x[i] < 0) {
                            x[i] = 0;
                        } else {
                            x[i] += lam;
                        }
                    }
                }
            }
        }



    private:

        FT mC;


    };

}

#endif /* PROJECTTOSIMPLEX_HPP */

