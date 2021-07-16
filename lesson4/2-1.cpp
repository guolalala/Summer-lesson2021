#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-5)
using namespace std;

double fx(double x,int op)
{
    switch (op)
    {
    case 0:
        return 0.5*sqrt(10-x*x*x);
        break;
    case 1:
        return sqrt(10/x-4*x);
        break;
    case 2:
        return x-x*x*x-4*x*x+10;
        break;
    default:
        return 0;
        break;
    }
}
int main()
{
    puts("简单迭代法");
    for(int i=0;i<3;i++)
    {
        switch (i)
        {
        case 0:
            printf("\t\t   x(k+1)=1/2*sqrt(10-x(k)^2)\n");
            break;
        case 1:
            printf("\t\t   x(k+1)=sqrt(10/x(k)-4x(k))\n");
            break;
        case 2:
            printf("\t\t   x(k+1)=x(k)-x(k)^3-4x(k)^2+10\n");
        default:
            break;
        }

        double x=1.5;
        int cnt=0;
        printf("cnt\t\tx(k)\t\tx(k+1)\t\t|x(k)-x(k+1)|\n");
        printf("%-5d       %-10.8f        %-10.8f         %-10.8f\n",cnt,x,fx(x,i),fabs(x-fx(x,i)));
        while(fabs(x-fx(x,i))>EPS)
        {
            cnt++;
            x=fx(x,i);
            printf("%-5d       %-10.8f        %-10.8f         %-10.8f\n",cnt,x,fx(x,i),fabs(x-fx(x,i)));
            if(cnt>50)
            {
                puts("迭代不收敛");
                break;
            }
            if(fx(x,i)==NAN || fabs(fx(x,i))>1e18)
            {
                puts("NAN,迭代不收敛");
                break;
            }
        }
        
        puts("");
    }
}