/*
 * @author: Bodan Chen
 * @Date: 2021-07-15 21:44:01
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-15 23:13:01
 * @Email: 18377475@buaa.edu.cn
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-10)
#define PI (acos(-1))
using namespace std;

double fx(double x)
{
    return (x*x+x+1)*cos(x);
}
int min(int a,int b)
{
    return a<b?a:b;
}
double Tmj[100][5];
double a=0,b=PI/2;
int m;
int main()
{
    printf("\nm          R(j,0)             R(j,1)            R(j,2)             R(j,3)\n");
    Tmj[0][0]=(b-a)*(fx(a)+fx(b))/2;
    for(m=1;;m++)
    {
        double hm=(b-a)/(1LL<<m);
        double temp=0;
        for(int i=1;i<=(1LL<<(m-1));i++)
        temp+=fx(a+(2*i-1)*hm);
        Tmj[m][0]=0.5*Tmj[m-1][0]+hm*temp;
        printf("%-5d%.15f  ",m,Tmj[m][0]);
        for(int j=1;j<=min(3,m);j++)
        {
            Tmj[m-j][j]=(pow(4,j)*Tmj[m-j+1][j-1]-Tmj[m-j][j-1])/(pow(4,j)-1);
            printf("%.15f  ",Tmj[m-j][j]);
        }
        puts("");
        if(m>=4 && fabs(Tmj[m-3][3]-Tmj[m-3-1][3])<EPS)break;
        
    }
    printf("ans = %.15f\n",Tmj[m-3][3]);
}