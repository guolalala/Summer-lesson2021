#include "convert.hpp"
#include <armadillo>
#include <cmath>
using namespace std;
using namespace arma;
void cll4(double *a)
{
    *a=con_d_4(*a);
}
double det2(double ma[][2])
{
    return ma[0][0]*ma[1][1]-ma[1][0]*ma[0][1];
}
double det3(double ma[][3])
{
    return ma[0][0]*(ma[1][1]*ma[2][2]-ma[1][2]*ma[2][1])\
    -ma[1][0]*(ma[0][1]*ma[2][2]-ma[0][2]*ma[2][1])\
    +ma[2][0]*(ma[0][1]*ma[1][2]-ma[0][2]*ma[1][1]);
}
void copy3(double newn[][3],double old[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        newn[i][j]=old[i][j];
    }
}
void copy31(double newn[3],double old[3])
{
    for(int i=0;i<3;i++)newn[i]=old[i];
}
double norm2(mat x1,mat x2)
{
    long long n=x1.n_rows;
    //printf("n=%llu\n",n);
    double error=0;
    for(int i=0;i<n;i++)error+=pow(x1(i)-x2(i),2);
    return sqrt(error);
}
mat getD(mat a)
{
    long long n=a.n_cols;
    mat res=a;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(i!=j)
    res(i,j)=0;
    return res;
}
mat getL(mat a)
{
    long long n=a.n_cols;
    mat res=a;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(i<=j)
    res(i,j)=0;
    return res;
}
mat getU(mat a)
{
    long long n=a.n_cols;
    mat res=a;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(i>=j)
    res(i,j)=0;
    return res;
}