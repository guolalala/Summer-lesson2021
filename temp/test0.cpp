//割线法
#include <iostream>
#include <sstream> 
#include <iomanip>
#include <cmath>
#define M 100
#define Error1 1e-4
#define Error2 1e-5
#define Error3 1e-12
//#include <armadillo>

using namespace std;
//using namespace arma;

double f2(double x);
double f3(double x);
double f4(double x);
double f5(double x);

void Cut_find(double x0,double x1,int m);

const double pi = acos(-1.0);

int main()
{
    printf("\n割线法求非线性方程3\n");
    Cut_find(1,2,3);

    printf("\n割线法求非线性方程4\n");
    Cut_find(1,2,4);

    printf("\n割线法求非线性方程5\n");
    Cut_find(1,2,5);

    printf("\n割线法求非线性方程2\n");
    Cut_find(-0.51,0.49,2);
    return 0;
}

void Cut_find(double x0,double x1,int m)
{
    double x;
    int i;
    printf("迭代次数k\txk\t\t||x_{k+1}-x_k||\n");
    for(i=1;i<=M;i++)
    {
        if(m==2)
        {
            if(fabs(f2(x0)-f2(x1))<Error3)
            {
                x=x1;
                break;
            }
            else 
            {
                x=x1-f2(x1)*(x1-x0)/(f2(x1)-f2(x0));
                
                printf("%d\t\t%.8f\t%.8f\n",i,x,x-x1);

                if(fabs(f2(x))<Error1) {printf("test\t%.f\n",x);break;}
                else 
                {   
                    x0=x1;
                    x1=x;   
                }
            }
            
        }

        else if(m==3)
        {
            if(fabs(f3(x0)-f3(x1))<Error3)
            {
                x=x1;
                break;
            }
            else 
            {
                x=x1-f3(x1)*(x1-x0)/(f3(x1)-f3(x0));
                printf("%d\t\t%.8f\t%.8f\n",i,x,x-x1);
                if(fabs(f3(x))<Error1) break;
                else 
                {   
                    x0=x1;
                    x1=x;   
                }
            }
        }

        else if(m==4)
        {
            if(fabs(f4(x0)-f4(x1))<Error3)
            {
                x=x1;
                break;
            }
            else 
            {
                x=x1-f4(x1)*(x1-x0)/(f4(x1)-f4(x0));
                //printf("%d\t\t%.8f\t%.8f\n",i,x,x-x1);
                if(fabs(f4(x))<Error1) break;
                else 
                {   
                    x0=x1;
                    x1=x;   
                }
            }
        }
        else if(m==5)
        {
            if(fabs(f5(x1)-f5(x0))<Error3)
            {
                x=x1;
                break;
            }
            else 
            {
                x=x1-f5(x1)*(x1-x0)/(f5(x1)-f5(x0));
                //printf("%d\t\t%.8f\t%.8f\n",i,x,x-x1);
                if(fabs(f5(x))<Error1) break;
                else 
                {   
                    x0=x1;
                    x1=x;   
                }
            }
        }
    }
    if(i>M) cout<<"\n割线法不收敛"<<endl;
    else  printf("\n利用割线法求根,迭代次数:%d\t所求得数值解为:%.12f\n",i,x);
}


double f2(double x)
{
    return exp(-100*x)-1;
}

double f3(double x)
{
    return pow(x,3)+4*pow(x,2)-10;
}


double f4(double x)
{
    return x-1.6-0.99*cos(x);
}


double f5(double x)
{
    return pow(x,3)-x-1;
}

