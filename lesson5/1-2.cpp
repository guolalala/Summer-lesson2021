/*
 * @author: Bodan Chen
 * @Date: 2021-07-14 09:36:56
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-14 22:46:36
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
double x1=0,x2=0.6,x3=1.2,x4;
int cnt=0;
double findx4(void)
{
    double res1=(x2*x2-x3*x3)*fx(x1)+(x3*x3-x1*x1)*fx(x2)+(x1*x1-x2*x2)*fx(x3);
    double res2=(x2-x3)*fx(x1)+(x3-x1)*fx(x2)+(x1-x2)*fx(x3);
    return res1/(2*res2);
}

int main()
{
    printf("\n逐次抛物插值\n\t\t\t  f(x)=0.5-xe^(-x^2)\nk\tx1\t\tx2\t\tx3\t\tf(x2)\n");
    while(fabs(x2-x4)>EPS)
    {
        printf("%-3d  %-10.6f      %-10.6f      %-10.6f      %-10.6f\n",cnt,x1,x2,x3,fx(x2));
        cnt++;
        x4=findx4();
        if(x4>x2)
        {
            x1=x2;
            x2=x4;
        }
        else
        {
            x3=x2;
            x2=x4;
        }
        x4=findx4();
    }
    printf("%-3d  %-10.6f      %-10.6f      %-10.6f      %-10.6f\n",cnt,x1,x2,x3,fx(x2));
    printf("ans=%f\n",x2);
}