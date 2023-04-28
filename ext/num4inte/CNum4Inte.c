#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "CNum4Inte.h"

static double CNum4Inte_doLeftReimannSumMethod(double a, double b, double h, Func func);
static double CNum4Inte_doRigtReimannSumMetod(double a, double b, double h, Func func);
static double CNum4Inte_doTrapezioidalRule(double a, double b, double h, Func func);
static double CNum4Inte_doSimpsonRule(double a, double b, double h, Func func);
static CNum4Inte _cNum4Inte = {
    .reimann = {
        .FP_leftReimannSumMethod = CNum4Inte_doLeftReimannSumMethod,
        .FP_rigtReimannSumMethod = CNum4Inte_doRigtReimannSumMetod,
    },
    .newton = {
        .FP_trapezioidalRule     = CNum4Inte_doTrapezioidalRule,
        .FP_simpsonRule          = CNum4Inte_doSimpsonRule,
    },
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



