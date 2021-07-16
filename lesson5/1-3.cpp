/*
 * @author: Bodan Chen
 * @Date: 2021-07-14 10:03:10
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-14 22:46:40
 * @Email: 18377475@buaa.edu.cn
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-5)
#define PI (acos(-1))
using namespace std;

double fx(double x)
{
    return 0.5-x*exp(-x*x);
}
double dfx(double x)
{
    return exp(-x*x)*(2*x*x-1);
}
double ddfx(double x)
{
    return exp(-x*x)*(-4*x*x*x+6*x);
}
int main()
{
    //printf("%.15f\n",dfx(0.5));
    double x=1,prex=0;
    int cnt=0;
    printf("\nNewton\n\t  f(x)=0.5-xe^(-x^2)\nk\txk\t\tf(xk)\n");
    while(fabs(dfx(x))>EPS)
    {
        printf("%-3d  %-10.6f       %-10.6f\n",cnt,x,fx(x));
        cnt++;
        prex=x;
        x=x-dfx(x)/ddfx(x);
    }
    printf("%-3d  %-10.6f       %-10.6f\n",cnt,x,fx(x));
    printf("ans=%f\n",x);
}