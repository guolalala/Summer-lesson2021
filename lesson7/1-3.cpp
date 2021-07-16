//ODE
//预报校正格式

#include <iostream>
#include <sstream> 
#include <iomanip>
#include <cmath>
#define maxn 100
#define MAX 50

using namespace std;
#define Error 1e-6
void report(double ta,double tb,double y0,int M);//预报校正格式

double f(double t,double y);
double y_t(double t);

int main()
{
    int i;
    printf("预报校正格式(不动点迭代法)求解常微分方程1\n");
    printf("步长h\t步数M\ty(3)近似值yM\ty(3)-yM\t\tO(h)\n");
    for(i=0;i<=6;i++)
    {
        report(0,3,1,i);
        //cout<<endl;
    }
    
    return 0;
}

//预报校正格式
void report(double ta,double tb,double y0,int m)
{
    double h=1/pow(2,m),t0=ta,tn;
    double yn[maxn],y_temp;
    int i,k, M=pow(2,m)*(tb-ta);
    yn[0]=y0;
    
    for(i=1;i<=M;i++)
    {
        k=0;
        
        yn[i]=yn[i-1]+h*f(t0+(i-1)*h,yn[i-1]);//显式预报

        y_temp=yn[i];
        yn[i]=yn[i-1]+h/2*(f(t0+(i-1)*h,yn[i-1])+f(tn,yn[i]));//隐式校正
        tn=t0+i*h;
        while(fabs(y_temp-yn[i])>Error)//不动点迭代
        {
            y_temp=yn[i];
            yn[i]=yn[i-1]+h/2*(f(t0+(i-1)*h,yn[i-1])+f(tn,yn[i]));//隐式校正
            k++;
            if(k>MAX) break;
        }
        if(k>MAX) break;
    }
    if(k>MAX) printf("步长为%.3f,算法发散\n",h);
    else
    {
        printf("%.3f\t%d\t%.8f\t%.8f\t%.3f\n",h,M,yn[M],fabs(y_t(tn)-yn[M]),0.256*h);
    }
}



double f(double t,double y)
{
    return (t-y)/2 ;
}
double y_t(double t)
{
    return 3*exp(-t/2)-2+t;
}