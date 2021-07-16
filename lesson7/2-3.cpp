//4级龙格库塔R-K法
//ODEs

#include <iostream>
#include <sstream> 
#include <iomanip>
#include <cmath>
#define maxn 100
#define MAX 20

using namespace std;
#define Error 1e-6
void RK4(double ta,double tb,double x0,double y0,double h);//4级龙格库塔R-K法

double fx(double x,double y);
double fy(double x,double y);
double x_t(double t);
double y_t(double t);

int main()
{
    int i;
    printf("四级龙格库达塔法求解常微分方程组2\n");
    printf("步长h\t步数M\ty(3)近似值yM\tt=3处误差二范数\tO(h)\n");
    RK4(0,0.2,6,4,0.02);
    
    return 0;
}

//4级R-K法(Kutta法)
void RK4(double ta,double tb,double x0,double y0,double h)
{
    double t0=ta,k1,k2,k3,k4,g1,g2,g3,g4;
    int i, M=(tb-ta)/h;
    for(i=1;i<=M;i++)
    {
        k1=fx(x0,y0);
        g1=fy(x0,y0);
        k2=fx(x0+h*k1/2,y0+h*g1/2);
        g2=fy(x0+h*k1/2,y0+h*g1/2);
        k3=fx(x0+h*k2/2,y0+h*g2/2);
        g3=fy(x0+h*k2/2,y0+h*g2/2);
        k4=fx(x0+h*k3,y0+h*g3);
        g4=fy(x0+h*k3,y0+h*g3);
        x0=x0+h/6*(k1+2*k2+2*k3+k4);
        y0=y0+h/6*(g1+2*g2+2*g3+g4);
        t0=t0+h;
    }
    printf("%.3f\t%d\t%.8f\t%.8e\t%.3f\n",h,M,y0,sqrt(pow(x_t(t0)-x0,2)+pow(y_t(t0)-y0,2)),0.256*h);

}

double fx(double x,double y)
{
    return x+2*y;
}

double fy(double x,double y)
{
    return 3*x+2*y;
}

double x_t(double t)
{
    return 4*exp(4*t)+2*exp(-t);
}

double y_t(double t)
{
    return 6*exp(4*t)-2*exp(-t);
}