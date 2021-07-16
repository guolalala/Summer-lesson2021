//4级龙格库塔R-K法(经典法)
//ODE

#include <iostream>
#include <sstream> 
#include <iomanip>
#include <cmath>
#define maxn 100
#define MAX 20

using namespace std;
#define Error 1e-6
void RK4(double ta,double tb,double y0,int M);//4级龙格库塔R-K法

double f(double t,double y);
double y_t(double t);

int main()
{
    int i;
    printf("四级龙格库达塔法求解常微分方程1\n");
    printf("步长h\t步数M\ty(3)近似值yM\ty(3)-yM\t\tO(h)\n");
    for(i=0;i<=6;i++)
    {
        RK4(0,3,1,i);
        //cout<<endl;
    }
    
    return 0;
}

//4级R-K法(Kutta法)
void RK4(double ta,double tb,double y0,int m)
{
    double h=1/pow(2,m),t0=ta,k1,k2,k3,k4;
    int i, M=pow(2,m)*(tb-ta);
    for(i=1;i<=M;i++)
    {
        k1=f(t0,y0);
        k2=f(t0+h/2,y0+h*k1/2);
        k3=f(t0+h/2,y0+h*k2/2);
        k4=f(t0+h,y0+h*k3);
        y0=y0+h/6*(k1+2*k2+2*k3+k4);
        t0=t0+h;
    }
    printf("%.3f\t%d\t%.8f\t%.8e\t%.3f\n",h,M,y0,fabs(y_t(t0)-y0),0.256*h);

}

double f(double t,double y)
{
    return (t-y)/2 ;
}
double y_t(double t)
{
    return 3*exp(-t/2)-2+t;
}