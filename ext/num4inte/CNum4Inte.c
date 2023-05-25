#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "CNum4Inte.h"

static double CNum4Inte_doLeftReimannSumMethod(double a, double b, double h, Func func);
static double CNum4Inte_doRigtReimannSumMetod(double a, double b, double h, Func func);
static double CNum4Inte_doTrapezioidalRule(double a, double b, double h, Func func);
static double CNum4Inte_doSimpsonRule(double a, double b, double h, Func func);
static double CNum4Inte_doGaussLegendreRule(int n, double a, double b, double h, Func func);
static CNum4Inte _cNum4Inte = {
    .reimann = {
        .FP_leftReimannSumMethod = CNum4Inte_doLeftReimannSumMethod,
        .FP_rigtReimannSumMethod = CNum4Inte_doRigtReimannSumMetod,
    },
    .newton = {
        .FP_trapezioidalRule     = CNum4Inte_doTrapezioidalRule,
        .FP_simpsonRule          = CNum4Inte_doSimpsonRule,
    },
    .gauss = {
        .FP_gaussLegendreRule    = CNum4Inte_doGaussLegendreRule,
    },
};
// ガウス・テーブル
// n = 1 
//   xi = 0                                  wi = 2
// n = 2 
//   xi = ±1/sqrt(3)=0.577350               wi = 1
// n = 3
//   xi = 0                                  wi = 8/9
//   xi = ±sqrt(3/5)=0.774597               wi = 5/9
// n = 4
//   xi = ±sqrt(3/7-2/7sqrt(6/5))=0.339981  wi = (18+sqrt(30))/36=0.652145
//   xi = ±sqrt(3/7+2/7sqrt(6/5))=0.861136  wi = (18-sqrt(30))/36=0.347855
// n = 5
//   xi = 0                                  wi = 128/225
//   xi = 1/3*sqrt(5-2sqrt(10/7))=0.538469   wi = (322+13sqrt(70))/900:0.478629
//   xi = 1/3*sqrt(5+2sqrt(10/7))=0.906180   wi = (322-13sqrt(70))/900:0.236927
static GaussTbl gaussTbl[] = {
    [0] = {.xi = {[0] = 0.0},
           .wi = {[0] = 2.0}},
    [1] = {.xi = {[0] = -0.577350, [1] = 0.577350},
           .wi = {[0] = 1.0, [1] = 1.0}},
    [2] = {.xi = {[0] = 0.0, [1] = -0.774597, [2] = 0.774597},
           .wi = {[0] = 0.888889, [1] = 0.555556, [2] = 0.555556}},
    [3] = {.xi = {[0] = -0.339981, [1] = 0.339981, [2] = -0.861136, [3] = 0.861136},
           .wi = {[0] = 0.652145, [1] = 0.652145, [2] = 0.347855, [3] = 0.347855}},
    [4] = {.xi = {[0] = 0.0, [1] = -0.538469, [2] = 0.538469, [3] = -0.906180, [4] = 0.906180},
           .wi = {[0] = 0.568889, [1] = 0.478629, [2] = 0.478629, [3] = 0.236927, [4] = 0.236927}},
};
/**************************************/
/* InterFface部                       */
/**************************************/
/**************************************/
/* Class部                            */
/**************************************/
double CNum4Inte_reimann_leftReimannSumMethod(double a, double b, double h, Func func)
{
    assert(func != 0);
    assert(a < b);

    return _cNum4Inte.reimann.FP_leftReimannSumMethod(a, b, h, func);
}
double CNum4Inte_reimann_rigtReimannSumMethod(double a, double b, double h, Func func)
{
    assert(func != 0);
    assert(a < b);

    return _cNum4Inte.reimann.FP_rigtReimannSumMethod(a, b, h, func);
}
double CNum4Inte_rewton_trapezioidalRule(double a, double b, double h, Func func)
{
    assert(func != 0);
    assert(a < b);

    return _cNum4Inte.newton.FP_trapezioidalRule(a, b, h, func);
}
double CNum4Inte_rewton_simpsonRule(double a, double b, double h, Func func)
{
    assert(func != 0);
    assert(a < b);

    return _cNum4Inte.newton.FP_simpsonRule(a, b, h, func);
}
double CNum4Inte_gauss_gaussLegendreRule(int n, double a, double b, double h, Func func)
{
    assert(func != 0);
    assert(a < b);
    assert((1 <= n) && (n <= 5));

    return _cNum4Inte.gauss.FP_gaussLegendreRule(n, a, b, h, func);
}
/**************************************/
/* 処理実行部                          */
/**************************************/
/*
 * 左リーマン和法
 */
static double CNum4Inte_doLeftReimannSumMethod(double a, double b, double h, Func func)
{
    double rimann = 0.0;
    double x;

    for (x = a; x < b; x += h) {
        rimann += func(x);
    }
    return rimann * h;
}
/*
 * 右リーマン和法
 */
static double CNum4Inte_doRigtReimannSumMetod(double a, double b, double h, Func func)
{
    double rimann = 0.0;
    double x;

    for (x = a; x < b; x += h) {
        rimann += func(x + h);
    }
    return rimann * h;
}
/*
 * 台形公式
 */
static double CNum4Inte_doTrapezioidalRule(double a, double b, double h, Func func)
{
    double trapezoidal = 0.0;
    double fx = func(a);
    double fxh = 0.0;
    double x;

    for (x = a; x < b; x += h) {
        fxh = func(x + h);
        trapezoidal += (fx + fxh);
        fx = fxh;
    }    
    return trapezoidal * h / 2.0;
}
/*
 * シンプソンの公式
 */
static double CNum4Inte_doSimpsonRule(double a, double b, double h, Func func)
{
    double simpson = 0.0;
    double fx = func(a);
    double fxh = 0.0;
    double h2 = h / 2.0;
    double x;

    for (x = a; x < b; x += h) {
        double fxh2 = func(x + h2);
        double fxh  = func(x + h);

        simpson += (fx + fxh + 4 * fxh2);
        fx = fxh2;
    }
    return simpson * h / 6.0;

}
/*
 * ガウス・ルジャンドルの公式
 */
static double CNum4Inte_doGaussLegendreRule(int n, double a, double b, double h, Func func)
{
    double x;
    double gauss = 0.0;
    GaussTbl *pt = &gaussTbl[n - 1];

    for (x = a; x < b; x += h) {
        int i;
        double xa = x;
        double xb = x + h;
        double bMa = (xb - xa) / 2.0;
        double aPb = (xa + xb) / 2.0;
        double wifi = 0.0;
             
        for (i = 0; i < n; i++) {
            wifi +=  pt->wi[i] * func(bMa * pt->xi[i] + aPb);
        }
        gauss += bMa * wifi;
    }
    return gauss;
}



