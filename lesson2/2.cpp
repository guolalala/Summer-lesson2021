//顺序Gauss
#include <iostream>
#include <iomanip>
#include "convert.hpp"
#include <cmath>
#include <string>
#include "myhpp.hpp"
using namespace std;

#define MAX 10
void ordergauss(double ma[][MAX],int n)
{
    for(int i=0;i<n;i++)
    {
        double temp=ma[i][i];
        for(int j=i+1;j<=n;j++)
        ma[i][j]/=temp,cll4(&ma[i][j]);
        ma[i][i]=1;
        for(int j=0;j<n;j++)
        {
            if(j!=i)
            {
                double temp=ma[j][i];
                for(int k=i;k<=n;k++)
                ma[j][k]-=ma[i][k]*temp,cll4(&ma[j][k]);
                ma[j][i]=0;
            }
        }
    }
}
int main()
{
    puts("顺序Gauss消去法");
    int n;

    puts("equation1");
    n=2;
    double A1[2][MAX]={{0.00001,1,1},{1,1,2}};
    ordergauss(A1,n);
    double x1[MAX]={0};
    for(int i=0;i<n;i++)
    x1[i]=A1[i][n],printf("x1[%d] = %-10.8f\n",i,x1[i]);
    puts("");

    puts("equation2");
    n=3;
    double A2[3][MAX]={{2,4,-2,2},{1,-3,-3,-1},{4,2,2,3}};
    double x2[MAX]={0};
    ordergauss(A2,n);
    for(int i=0;i<n;i++)
    x2[i]=A2[i][n],printf("x2[%d] = %-10.8f\n",i,x2[i]);
    puts("");

    puts("equation3");
    double A3[3][MAX]={{0.012,0.01,0.167,0.6781},{1,0.8334,5.91,12.1},{3200,1200,4.2,981}};
    double x3[MAX]={0};
    ordergauss(A3,n);
    for(int i=0;i<n;i++)
    x3[i]=A3[i][n],printf("x3[%d] = %-10.8f\n",i,x3[i]);
}