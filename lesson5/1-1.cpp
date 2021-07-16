/*
 * @author: Bodan Chen
 * @Date: 2021-07-14 09:16:20
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-14 22:46:25
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
    return x*x-sin(x);
}
int main()
{
    double a=0,b=1,lambda,mu;
    double r0=(sqrt(5)-1)/2;
    double r1=1-r0;
    int cnt=0;
    lambda=a+r1*(b-a);
    mu=a+r0*(b-a);

    printf("\n黄金分割法求解\n\t\t\t\t\t  f(x)=x^2-sin(x)\nk\tak\t\tck\t\tdk\t\tbk\t\tf(ck)\t\tf(dk)\n");
    while(fabs(a-b)>EPS)
    {
        printf("%-3d  %-10.6f      %-10.6f      %-10.6f      %-10.6f      %-10.6f       %-10.6f\n",cnt,a,lambda,mu,b,fx(lambda),fx(mu));
        cnt++;
        if(fx(lambda)>fx(mu))
        {
            a=lambda;
            lambda=mu;
            mu=a+r0*(b-a);
        }
        else
        {
            b=mu;
            mu=lambda;
            lambda=a+r1*(b-a);
        }
    }
    printf("\nans=%-10.6f\n",a);
}