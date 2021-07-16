#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-5)
#define PI (acos(-1))
using namespace std;
double fx(double x, int op)
{
    switch (op)
    {
    case 3:
        return exp(-10 * x) - 1;
        break;
    case 0:
        return x * x * x + 4 * x * x - 10;
        break;
    case 1:
        return 1.6 + 0.99 * cos(x) - x;
        break;
    case 2:
        return x * x * x - x - 1;
        break;
    default:
        return 0;
        break;
    }
}
double dfx(double x,int op)
{
    switch (op)
    {
    case 0:
        return 3*x*x+8*x;
        break;
    case 1:
        return -0.99*sin(x)-1;
        break;
    case 2:
        return 3*x*x-1;
        break;
    case 3:
        return -10*exp(-10*x);
        break;
    default:
        return 1e18;
        break;
    }
}
double phix(double x,int op)
{
    return x-fx(x,op)/dfx(x,op);
}
double xk2(double x1,double x2,int op)
{
    return x2-fx(x2,op)*(x2-x1)/(fx(x2,op)-fx(x1,op));
}
double L[10]={1,1,1,-0.51};
double R[10]={2,2,2,0.49};
int main()
{
    for(int i=0;i<4;i++)
    {
        double x;
        switch (i)
        {
        case 0:
            printf("\t\t   f(x)=x^3+4x^2-10\n");
            x=1.5;
            break;
        case 1:
            printf("\t\t   f(x)=1.66+0.99cos(x)\n");
            x=PI/2;
            break;
        case 2:
            printf("\t\t   f(x)=x^3-x-1\n");
            x=1.5;
            break;
        case 3:
            printf("\t\t   f(x)=e^(-10x)-1\n");
            x=-0.51;
            break;
        default:
            break;
        }

        puts("Newton 迭代法");
        int cnt=0;
        printf("cnt\t\tx(k)\t\tx(k+1)\t\t|x(k)-x(k+1)|\n");
        printf("%-5d       %-10.7f        %-10.7f          %-10.7f\n",cnt,x,phix(x,i),fabs(x-phix(x,i)));
        while(fabs(x-phix(x,i))>EPS)
        {
            cnt++;
            x=phix(x,i);
            printf("%-5d       %-10.7f        %-10.7f          %-10.7f\n",cnt,x,phix(x,i),fabs(x-phix(x,i)));
            if(cnt>50)
            {
                puts("迭代不收敛");
                break;
            }
            if(phix(x,i)==NAN || fabs(phix(x,i))>1e18)
            {
                puts("NAN,迭代不收敛");
                break;
            }
        }
        puts("");

        puts("割线法");
        double x0=L[i],x1=R[i];cnt=0;
        printf("cnt\t\tx(k)\t\tx(k+1)\t\tx(k+2)\t\t|x(k)-x(k+2)|\n");
        printf("%-5d        %-10.7f       %-10.7f      %-10.7f          %-10.7f\n",cnt,x0,x1,xk2(x0,x1,i),fabs(x0-xk2(x0,x1,i)));
        while(fabs(x0-xk2(x0,x1,i))>EPS)
        {
            cnt++;
            double temp=xk2(x0,x1,i);
            x0=x1;
            x1=temp;
            printf("%-5d        %-10.7f       %-10.7f      %-10.7f          %-10.7f\n",cnt,x0,x1,xk2(x0,x1,i),fabs(x0-xk2(x0,x1,i)));
            if(cnt>50)
            {
                puts("迭代不收敛");
                break;
            }
            if(xk2(x0,x1,i)==NAN || fabs(xk2(x0,x1,i))>1e18)
            {
                puts("NAN,迭代不收敛");
                break;
            }
        }
        puts("");
    }
}