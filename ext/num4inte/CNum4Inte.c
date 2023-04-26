#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "CNum4Inte.h"

static double CNum4Inte_doLeftReimannSumMetod(double a, double b, double h, Func func);
static double CNum4Inte_doRigtReimannSumMetod(double a, double b, double h, Func func);
static double CNum4Inte_doNewtonMethod(double a, double b, double h, Func func);
static CNum4Inte _cNum4Inte = {
    .FP_leftReimannSumMetod = CNum4Inte_doLeftReimannSumMetod,
    .FP_rigtReimannSumMetod = CNum4Inte_doRigtReimannSumMetod,
    .FP_newtonMethod        = CNum4Inte_doNewtonMethod,
};
/**************************************/
/* InterFface部                       */
/**************************************/
/**************************************/
/* Class部                            */
/**************************************/
double CNum4Inte_leftReimannSumMetod(double a, double b, double h, Func func)
{
    assert(func != 0);

    return _cNum4Inte.FP_leftReimannSumMetod(a, b, h, func);
}
double CNum4Inte_rigtReimannSumMetod(double a, double b, double h, Func func)
{
    assert(func != 0);

    return _cNum4Inte.FP_rigtReimannSumMetod(a, b, h, func);
}
double CNum4Inte_newtonMethod(double a, double b, double h, Func func)
{
    assert(func != 0);

    return _cNum4Inte.FP_newtonMethod(a, b, h, func);
}
/**************************************/
/* 処理実行部                          */
/**************************************/
/*
 * 左リーマン和法
 */
static double CNum4Inte_doLeftReimannSumMetod(double a, double b, double h, Func func)
{
    double rimann = 0.0;
    double x = 0.0;

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
    double x = 0.0;

    for (x = a; x < b; x += h) {
        rimann += func(x + h);
    }
    return rimann * h;
}
/*
 * ニュートン・シンプソン法
 */
static double CNum4Inte_doNewtonMethod(double a, double b, double h, Func func)
{
    double newton = 0.0;
    double x = 0.0;
    double fx = func(a);
    double fxh = 0.0;

    for (x = a; x < b; x += h) {
        fxh = func(x + h);
        newton += (fx + fxh) /2;
        fx = fxh;
    }    
    return newton * h;
}



