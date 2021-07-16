/*
 * @author: Bodan Chen
 * @Date: 2021-07-14 12:22:29
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-15 18:00:52
 * @Email: 18377475@buaa.edu.cn
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#define MAXN 20
#define M 100
#define EPS1 (1e-4)
#define EPS2 (1e-5)

double f(double x0[]);
double grad_f(double x0[],int m);
double Hessian_f(double x0[], int m);
double norm2(double x[]);

void newton2(double x0[]);

int main()
{
    double xt[MAXN]={-0.3,0.2};

    newton2(xt);
    return 0;
}


void newton2(double x0[])
{
    double x[MAXN],xk[MAXN],fk[MAXN];
    int i;
    
    for(i=1;i<=M;i++)
    {
        //printf("%f %f %f\n",Hessian_f(x0,11),Hessian_f(x0,12),Hessian_f(x0,22));
        xk[0]=x0[0]-(Hessian_f(x0,11)*grad_f(x0,1)+Hessian_f(x0,12)*grad_f(x0,2));
        xk[1]=x0[1]-(Hessian_f(x0,21)*grad_f(x0,1)+Hessian_f(x0,22)*grad_f(x0,2));
        
        fk[0]=grad_f(x0,1);
        fk[1]=grad_f(x0,2);
        

        if(fabs(norm2(fk))<EPS1)
        {
            x[0]=xk[0];
            x[1]=xk[1];
            break;
        }
        else
        {
            x0[0]=xk[0];
            x0[1]=xk[1];
        }
        
    }
    if(i<=M) printf("利用牛顿法, 迭代次数为%d\n得极小值点P^*=(%.8f, %.8f)\n极小值f(P^*)=%.8f\n",i,x[0],x[1],f(x));
    else if(i>M) printf("牛顿法失效\n");
}


double f(double x0[])
{
    double x=x0[0],y=x0[1];
    return (x-y)/(pow(x,2)+pow(y,2)+2);
    
}

double grad_f(double x0[],int m)
{
    double x=x0[0],y=x0[1];
    switch (m)
    {
    case 1:
        return 1/(pow(x,2) + pow(y,2) + 2) - (2*x*(x - y))/pow((pow(x,2) + pow(y,2) + 2),2);
        break;
    case 2:
        return -1/(pow(x,2) + pow(y,2) + 2) - (2*y*(x - y))/pow((pow(x,2) + pow(y,2) + 2),2);
        break;
    default:
        return 0;
        break;
    }
}


double Hessian_f(double x0[], int m)
{
    double x=x0[0],y=x0[1];
    switch (m)
    {
    case 11:
        return (pow((pow(x,2) + pow(y,2) + 2),2)*(pow(x,3)- 3*pow(x,2)*y - 3*x*pow(y,2) + 2*x + pow(y,3)- 6*y))/(4*(pow(x,4) + 2*pow(x,2)*pow(y,2) - 2*pow(x,2) + 8*x*y +pow(y,4)- 2*pow(y,2)));
        break;
    case 12:
        return (pow((pow(x,2) + pow(y,2) + 2),2)*(pow(x,3) + 3*pow(x,2)*y - 3*x*pow(y,2) + 2*x - pow(y,3) - 2*y))/(4*(pow(x,4) + 2*pow(x,2)*pow(y,2) - 2*pow(x,2) + 8*x*y +pow(y,4) - 2*pow(y,2)));
        break;
    case 21:
        return (pow((pow(x,2) + pow(y,2) + 2),2)*(pow(x,3) + 3*pow(x,2)*y - 3*x*pow(y,2) + 2*x - pow(y,3) - 2*y))/(4*(pow(x,4)+ 2*pow(x,2)*pow(y,2) - 2*pow(x,2) + 8*x*y + pow(y,4) - 2*pow(y,2)));
        break;
    case 22:
        return (pow((pow(x,2) + pow(y,2) + 2),2)*(-pow(x,3) + 3*pow(x,2)*y +3*x*pow(y,2) + 6*x - pow(y,3) - 2*y))/(4*(pow(x,4)+ 2*pow(x,2)*pow(y,2) - 2*pow(x,2) + 8*x*y + pow(y,4) - 2*pow(y,2)));
        break;
    default:
        return 0;
        break;
    }
}


double norm2(double x[MAXN])
{
    double s;
    s=sqrt(pow(x[0],2)+pow(x[1],2));
    return s;
}