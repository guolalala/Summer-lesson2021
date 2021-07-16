/*
 * @author: Bodan Chen
 * @Date: 2021-07-15 20:54:28
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-15 21:07:50
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
    return 2+sin(2*sqrt(x));
}
double Fx(double x)
{
    return 2*x-sqrt(x)*cos(2*sqrt(x))+sin(2*sqrt(x))/2;
}
double a=1,b=6;
int main()
{
    printf("The exact value: %.15f\n\n",Fx(b)-Fx(a));

    for(int n=10;n<=160;n*=2)
    {
        printf("n=%d\n",n+1);
        double ans1=0,ans2=0;
        double h=(b-a)/n;
        ans1=ans2=fx(a)+fx(b);
        for(int i=1;i<n;i++)
        ans1+=2*fx(a+i*h);
        ans1*=(h/2);

        int m=n/2;
        for(int i=1;i<n;i++)
        {
            if(i%2)ans2+=4*fx(a+i*h);
            else ans2+=2*fx(a+i*h);
        }
        ans2*=(h/3);
        printf("复化梯形公式：%.15f\n复化辛普森公式：%.15f\n\n",ans1,ans2);
    }
}