/*
 * @author: Bodan Chen
 * @Date: 2021-07-15 16:42:44
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-15 17:08:26
 * @Email: 18377475@buaa.edu.cn
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-5)
#define PI (acos(-1))
using namespace std;

double x[5]={5,1};
double prex[5];
double g[5]={0,1};
double beta0=1;
double d[5];
double G[5][5];
double lambda=1;
double fx(double x,double y)
{
    return 0.5*x*x+2.5*y*y;;
}
double gx(double x[5],int op)
{
    if(op==0)
    return x[0];
    else
    return 5*x[1];
}
double Gx(double x[5],int op)
{
    if(op==0)
    return 1;
    else if(op==1)
    return 0;
    else
    return 5;
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
void update_beta0(void)
{
    beta0=(G[0][0]*g[0]*d[0]+G[0][1]*g[0]*d[1]+G[0][1]*d[0]*g[1]+G[1][1]*g[1]*d[1])/(G[0][0]*d[0]*d[0]+2*G[0][1]*d[0]*d[1]+G[1][1]*d[1]*d[1]);
}
void update_d(void)
{
    d[0]=-g[0]+beta0*d[0];
    d[1]=-g[1]+beta0*d[1];
}
void update_lam(void)
{
    lambda=-(g[0]*d[0]+g[1]*d[1])/(G[0][0]*d[0]*d[0]+2*G[0][1]*d[0]*d[1]+G[1][1]*d[1]*d[1]);
}
void update_x(void)
{
    x[0]=x[0]+lambda*d[0];
    x[1]=x[1]+lambda*d[1];
}
int main()
{
    printf("\n共轭梯度法\n\t\t\t\t\t  f(x,y)=0.5x^2+2.5y^2\nk\tg[0]\t\tg[1]\t\talpha\t\tx[0]\t\tx[1]\t\tnorm\n");
    int cnt=0;

    //x0
    update_g();
    d[0]=-g[0],d[1]=-g[1];

    while(fabs(norm_2())>EPS)
    {
        printf("%-3d  %-10.6f      %-10.6f        %-10.6f    %-10.6f      %-10.6f       %-10.6f\n",cnt,g[0],g[1],lambda,x[0],x[1],norm_2());
        cnt++;

        update_g();

        update_G();

        update_lam();

        update_x();

        update_g();

        update_beta0();

        update_d();
        
        if(cnt>50)break;
    }
    printf("%-3d  %-10.6f      %-10.6f        %-10.6f    %-10.6f      %-10.6f       %-10.6f\n",cnt,g[0],g[1],lambda,x[0],x[1],norm_2());
    printf("ans=[%-10.8f %-10.8f]\n",x[0],x[1]);

    return 0;
}