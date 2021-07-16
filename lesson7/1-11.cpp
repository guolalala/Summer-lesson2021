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
void Euler(double ta,double tb,double y0,int M);//向前Euler法

double f(double t,double y);
double y_t(double t);

int main()
{
    int i;
    printf("向前欧拉法求解常微分方程1\n");
    printf("步长h\t步数M\ty(3)近似值yM\ty(3)-yM\t\tO(h)\n");
    for(i=0;i<=6;i++)
    {
        Euler(0,3,1,i);
    }
    
    return 0;
}

//向前Euler法
void Euler(double ta,double tb,double y0,int m)
{
    double h=1/pow(2,m),t0=ta;
    int i, M=pow(2,m)*(tb-ta);
    //printf("tk\tyk\t\ty(tk)精确值\n");
    //printf("%.3f\t%.8f\t%.8f\n",t0,y0,y_t(t0));
    for(i=1;i<=M;i++)
    {
        y0=y0+h*f(t0,y0);
        t0=t0+h;
        //printf("%.3f\t%.8f\t%.8f\n",t0,y0,y_t(t0));
        
    }
    printf("%.3f\t%d\t%.8f\t%.8f\t%.3f\n",h,M,y0,y_t(t0)-y0,0.256*h);

}

double f(double t,double y)
{
    return (t-y)/2 ;
}
double y_t(double t)
{
    return 3*exp(-t/2)-2+t;
}