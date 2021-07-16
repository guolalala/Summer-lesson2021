#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-5)
#define PI (acos(-1))
using namespace std;

double fx(double x)
{
    return x*x*x-1;
}
double y(double x)
{
    return fx(x);
}
double z(double x)
{
    return fx(y(x));
}
double fx1(double x)
{
    return x-pow(y(x)-x,2)/(z(x)-2*y(x)+x);
}
int main()
{
    printf("\n\t\t   x(k+1)=x^3-1\n");
    puts("简单迭代法");
    double x=1.5;
    int cnt=0,have=1;
    printf("cnt\t\tx(k)\t\tx(k+1)\t\t|x(k)-x(k+1)|\n");
    printf("%-5d       %-10.8f        %-10.8f         %-10.8f\n",cnt,x,fx(x),fabs(x-fx(x)));
    while(fabs(x-fx(x))>EPS)
    {
        cnt++;
        x=fx(x);
        printf("%-5d       %-10.8f        %-10.8f         %-10.8f\n",cnt,x,fx(x),fabs(x-fx(x)));

        if(cnt>1200)
        {
            puts("迭代不收敛");
            break;
        }
        if(fx(x)==NAN || fabs(fx(x))>1e18)
        {
            puts("NAN,迭代不收敛");
            break;
        }
    }
    puts("");
    puts("加速迭代法");
    x=1.5;
    cnt=0,have=1;
    printf("cnt\t\tx(k)\t\ty(k)\t\tz(k)\t\tx(k+1)\t\t|x(k)-x(k+1)|\n");
    printf("%-5d       %-10.8f      %-10.8f       %-10.8f       %-10.8f          %-10.8f\n",cnt,x,y(x),z(x),fx1(x),fabs(x-fx(x)));
    while(fabs(x-fx(x))>EPS)
    {
        cnt++;
        x=fx1(x);
        printf("%-5d       %-10.8f      %-10.8f       %-10.8f       %-10.8f          %-10.8f\n",cnt,x,y(x),z(x),fx1(x),fabs(x-fx(x)));

        if(cnt>1200)
        {
            puts("迭代不收敛");
            break;
        }
        if(fx(x)==NAN || fabs(fx(x))>1e18)
        {
            puts("NAN,迭代不收敛");
            break;
        }
    }
}