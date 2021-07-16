/*
 * @author: Bodan Chen
 * @Date: 2021-07-14 10:33:01
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-14 19:57:00
 * @Email: 18377475@buaa.edu.cn
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-5)
#define PI (acos(-1))
using namespace std;

double x[5]={-3,2};
double prex[5];
double g[5]={0,1};
double G[5][5];
double lambda=1;
double fx(double x,double y)
{
    return (x-y)/(x*x+y*y+2);
}
double gx(double x[5],int op)
{
    double down=pow(x[0]*x[0]+x[1]*x[1]+2,2);
    if(op==0)
    {
        return (x[1]*x[1]-x[0]*x[0]+2*x[0]*x[1]+2)/down;
    }
    else
    {
        return (x[1]*x[1]-x[0]*x[0]-2*x[0]*x[1]-2)/down;
    }
}
double Gx(double x[5],int op)
{
    double down=pow(x[0]*x[0]+x[1]*x[1]+2,3);
    if(op==0)
    {
        double up=(2*x[1]-2*x[0])*(x[0]*x[0]+x[1]*x[1]+2)-4*x[0]*(x[1]*x[1]-x[0]*x[0]+2*x[0]*x[1]+2);
        return up/down;
    }
    else if(op==1)
    {
        double up=2*(x[0]+x[1])*(x[0]*x[0]+x[1]*x[1]+2)-4*x[1]*(x[1]*x[1]-x[0]*x[0]+2*x[0]*x[1]+2);
        return up/down;
    }
    else
    {
        double up=(2*x[1]-2*x[0])*(x[0]*x[0]+x[1]*x[1]+2)-4*x[1]*(x[1]*x[1]-x[0]*x[0]-2*x[0]*x[1]-2);
        return up/down;
    }
}
double norm_2(void)
{
    return sqrt(g[0]*g[0]+g[1]*g[1]);
}
void update_g(void)
{
    g[0]=gx(x,0);
    g[1]=gx(x,1);
}
void update_G(void)
{
    G[0][0]=Gx(x,0);
    G[0][1]=G[1][0]=Gx(x,1);
    G[1][1]=Gx(x,2);
}
double normfx(double lam)
{
    double x1=x[0]-lam*g[0];
    double x2=x[1]-lam*g[1];
    return fx(x1,x2);
}
double find_min_la(void)
{
    double a=0,b=40,la,mu;
    double r0=(sqrt(5)-1)/2;
    double r1=1-r0;
    int cnt=0;
    la=a+r1*(b-a);
    mu=a+r0*(b-a);
    while(fabs(a-b)>EPS)
    {
        if(normfx(la)>normfx(mu))
        {
            a=la;
            la=mu;
            mu=a+r0*(b-a);
        }
        else
        {
            b=mu;
            mu=la;
            la=a+r1*(b-a);
        }
    }
    return a;
}
void update_lam(void)
{
    lambda=find_min_la();
    //lambda=(g[0]*g[0]+g[1]*g[1])/(G[0][0]*g[0]*g[0]+2*G[0][1]*g[0]*g[1]+G[1][1]*g[1]*g[1]);
}
void update_x(void)
{
    x[0]=x[0]-lambda*g[0];
    x[1]=x[1]-lambda*g[1];
}
int main()
{
    printf("\n最速下降法\n\t\t\t\t\t  f(x,y)=(x-y)/(x^2+y^2+2)\nk\tg[0]\t\tg[1]\t\tlambda\t\tx[0]\t\tx[1]\t\tnorm\n");
    int cnt=0;
    while(fabs(norm_2())>EPS)
    {
        printf("%-3d  %-10.6f      %-10.6f        %-10.6f    %-10.6f      %-10.6f       %-10.6f\n",cnt,g[0],g[1],lambda,x[0],x[1],norm_2());
        cnt++;
        //printf("lambda=%f x[0]=%f x[1]=%f\n",lambda,x[0],x[1]);
        //printf("g[0]=%f g[1]=%f\n",g[0],g[1]);
        //printf("G[0][0]=%f G[0][1]=%f G[1][1]=%f\n",G[0][0],G[0][1],G[1][1]);
        //prex[0]=x[0],prex[1]=x[1];
        update_g();
        //update_G();
        //printf("cnt=%d\ng[0]=%f g[1]=%f\n",cnt,g[0],g[1]);
        //printf("G[0][0]=%f G[0][1]=%f G[1][1]=%f\n",G[0][0],G[0][1],G[1][1]);
        update_lam();
        //lambda=1;
        update_x();
        //printf("lambda=%f x[0]=%f x[1]=%f\n\n",lambda,x[0],x[1]);
        if(cnt>50)break;
    }
    printf("%-3d  %-10.6f      %-10.6f        %-10.6f    %-10.6f      %-10.6f       %-10.6f\n",cnt,g[0],g[1],lambda,x[0],x[1],norm_2());
    printf("ans=[%-10.8f %-10.8f]\n",x[0],x[1]);
}