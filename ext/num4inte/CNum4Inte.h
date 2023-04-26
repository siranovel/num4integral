#ifndef _CNum4Inte_H_
#define _CNum4Inte_H_

/**************************************/
/* 構造体宣言                         */
/**************************************/
typedef struct _CNum4Inte CNum4Inte;
typedef double (*Func)(double x);

struct _CNum4Inte
{
    double (*FP_leftReimannSumMetod)(double a, double b, double h, Func func);
    double (*FP_rigtReimannSumMetod)(double a, double b, double h, Func func);
    double (*FP_newtonMethod)(double a, double b, double h, Func func);
};
/**************************************/
/* define宣言                         */
/**************************************/
/**************************************/
/* プロトタイプ宣言                   */
/**************************************/
double CNum4Inte_leftReimannSumMetod(double a, double b, double h, Func func);
double CNum4Inte_rigtReimannSumMetod(double a, double b, double h, Func func);
double CNum4Inte_newtonMethod(double a, double b, double h, Func func);
#endif
