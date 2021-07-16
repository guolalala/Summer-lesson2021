//ODE
//Euler法

#include <iostream>
#include <sstream> 
#include <iomanip>
#include <cmath>
#define maxn 100
#define MAX 20

using namespace std;
#define Error 1e-6
void Euler2(double ta,double tb,double y0,int M);//向后Euler法

double f(double t,double y);
double y_t(double t);

int main()
{
    int i;
    printf("向后欧拉法求解常微分方程1\n");
    printf("步长h\t步数M\ty(3)近似值yM\ty(3)-yM\t\tO(h)\n");
    for(i=0;i<=6;i++)
    {
        Euler2(0,3,1,i);
        //cout<<endl;
    }
    
    return 0;
}

//向后Euler法
void Euler2(double ta,double tb,double y0,int m)
{
    double h=1/pow(2,m),t0=ta;
    int i, M=pow(2,m)*(tb-ta);
    for(i=1;i<=M;i++)
    {
        t0=t0+h;
        y0=(2*y0+h*t0)/(2+h);//隐式迭代
        
    }
    printf("%.3f\t%d\t%.8f\t%.8f\t%.3f\n",h,M,y0,fabs(y_t(t0)-y0),0.256*h);

}



double f(double t,double y)
{
    return (t-y)/2 ;
}
double y_t(double t)
{
    return 3*exp(-t/2)-2+t;
}