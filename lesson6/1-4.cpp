/*
 * @author: Bodan Chen
 * @Date: 2021-07-15 21:12:14
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-15 21:30:29
 * @Email: 18377475@buaa.edu.cn
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (5e-9)
#define PI (acos(-1))
using namespace std;

double hTra=5,hSim=5;

double fx(double x)
{
    return 1.0/x;
}
double Tra(double l,double r)
{
    return (r-l)*(fx(l)+fx(r))/2;
}
double Sim(double l,double r)
{
    return (r-l)*(fx(l)+4*fx((l+r)/2)+fx(r))/6;
}
double Trapezoid(double l,double r)
{
    if((r-l)<hTra)hTra=(r-l);
    double mid=(l+r)/2;
    if(fabs(Tra(l,mid)-Tra(mid,r))<EPS)return Tra(l,r);
    return Trapezoid(l,mid)+Trapezoid(mid,r);
}
double Simpson(double l,double r)
{
    if((r-l)<hSim)hSim=(r-l);
    double mid=(l+r)/2;
    if(fabs(Sim(l,mid)-Sim(mid,r))<EPS)return Sim(l,r);
    return Simpson(l,mid)+Simpson(mid,r);
}
int main()
{
    double l=2,r=7;
    puts("");
    printf("The exact value:   %.15f\n",log(7)-log(2));
    printf("Complex trapezoid: %.15f\th for trapezoid: %.15f\n",Trapezoid(l,r),hTra);
    printf("Complex Simpson:   %.15f\th for simpson:   %.15f\n\n",Simpson(l,r),hSim);

    return 0;
}