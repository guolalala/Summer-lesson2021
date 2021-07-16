/*
 * @author: Bodan Chen
 * @Date: 2021-07-13 11:23:55
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-14 21:53:35
 * @Email: 18377475@buaa.edu.cn
 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define EPS (1e-5)
double fx(double x, int op)
{
    switch (op)
    {
    case 0:
        return x * sin(x) - 1;
        break;
    case 1:
        return exp(-10 * x) - 1;
        break;
    case 2:
        return x * x * x + 4 * x * x - 10;
        break;
    case 3:
        return 1.6 + 0.99 * cos(x) - x;
        break;
    case 4:
        return x * x * x - x - 1;
        break;
    default:
    return 0;
        break;
    }
}
double findc(double a,double b,int op)
{
    return b-(fx(b,op)*(b-a))/(fx(b,op)-fx(a,op));
}
double L[10]={0,-0.51,1,1,1};
double R[10]={2,0.49,2,2,2};
double mid;
int cnt;
int main()
{
    //printf("%f %f\n",cos(90),fx(2,3));
    for(int i=0;i<5;i++)
    {
        switch (i)
        {
        case 0:
            printf("\t\t\tf(x) = xsin(x) - 1");
            break;
        case 1:
            printf("\t\t\tf(x) = exp(-10x) - 1");
            break;
        case 2:
            printf("\t\t\tf(x) = x^3 + 4x^2 - 10");
            break;
        case 3:
            printf("\t\t\tf(x) = 1.6 + 0.99cos(x) - x");
            break;
        case 4:
            printf("\t\t\tf(x) = x^3 - x - 1");
            break;
        default:
            break;
        }
        putchar(10);
        double l=L[i],r=R[i];
        mid=(l+r)/2;cnt=0;
        puts("Dichotomy Method");
        printf("cnt\t\tl\t\tmid\t\tr\t\tf(x)\n");
        int have=1;
        while(fabs(fx(mid,i))>EPS)
        {
            printf("%-5d      %-10.8f       %-10.8f     %-10.8f       %-10.8f\n",cnt,l,mid,r,fx(mid,i));
            if(fx(l,i)*fx(mid,i)<0)
            r=mid;
            else
            l=mid;
            mid=(l+r)/2;cnt++;
            if(cnt>50){have=0;printf("Failed\n");break;}
        }
        if(have)
        printf("%-5d      %-10.8f       %-10.8f     %-10.8f       %-10.8f\n",cnt,l,mid,r,fx(mid,i));
        puts("");

        l=L[i],r=R[i];
        mid=findc(l,r,i);cnt=0;have=1;
        puts("Try Method");
        printf("cnt\t\tl\t\tmid\t\tr\t\tf(x)\n");
        while(fabs(fx(mid,i))>EPS)
        {
            printf("%-5d      %-10.8f       %-10.8f     %-10.8f       %-10.8f\n",cnt,l,mid,r,fx(mid,i));
            if(fx(l,i)*fx(mid,i)<0)
            r=mid;
            else
            l=mid;
            mid=findc(l,r,i);cnt++;
            if(cnt>50){have=0;printf("Failed\n");break;}
        }
        if(have)
        printf("%-5d      %-10.8f       %-10.8f     %-10.8f       %-10.8f\n",cnt,l,mid,r,fx(mid,i));
        puts("");
        puts("");
    }
    
}