#ifndef _CNum4Inte_H_
#define _CNum4Inte_H_

/**************************************/
/* 構造体宣言                         */
/**************************************/
typedef struct _CNum4Inte CNum4Inte;
typedef struct _CReimann  CReimann;
typedef struct _CNewton   CNewton;
typedef struct _CGauss    CGauss;
typedef double (*Func)(double x);
typedef struct _GaussTbl  GaussTbl;

struct _CReimann
{
    double (*FP_leftReimannSumMethod)(double a, double b, double h, Func func);
    double (*FP_rigtReimannSumMethod)(double a, double b, double h, Func func);
};
struct _CNewton
{
    double (*FP_trapezioidalRule)(double a, double b, double h, Func func);
    double (*FP_simpsonRule)(double a, double b, double h, Func func);
};
struct _CGauss
{
    double (*FP_gaussLegendreRule)(int n, double a, double b, double h, Func func);
};
struct _CNum4Inte
{
    CReimann reimann;
    CNewton  newton;
    CGauss   gauss;
};
struct _GaussTbl
{
    double xi[5];
    double wi[5];
};
/**************************************/
/* define宣言                         */
/**************************************/
/**************************************/
/* プロトタイプ宣言                    */
/**************************************/
double CNum4Inte_reimann_leftReimannSumMethod(double a, double b, double h, Func func);
double CNum4Inte_reimann_rigtReimannSumMethod(double a, double b, double h, Func func);
double CNum4Inte_rewton_trapezioidalRule(double a, double b, double h, Func func);
double CNum4Inte_rewton_simpsonRule(double a, double b, double h, Func func);
double CNum4Inte_gauss_gaussLegendreRule(int n, double a, double b, double h, Func func);
#endif
