/*
 * @author: Bodan Chen
 * @Date: 2021-07-15 22:14:54
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-15 22:28:43
 * @Email: 18377475@buaa.edu.cn
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-4)
#define PI (acos(-1))
using namespace std;

//[1,5]  f(t)=1/t
//[-1,1] f(x)=2/(2x+3)
double fx(double x)
{
    return 2.0/(2*x+3);
}
double a=-1,b=1;
double xi[10]={-0.7745966692,0,0.7745966692};
double Ai[10]={0.5555555556,0.8888888889,0.5555555556};
int main()
{
    printf("The exact value: %.15f\n",log(5)-log(1));
    printf("Gauss-Legendre:  %.15f\n",Ai[0]*fx(xi[0])+Ai[1]*fx(xi[1])+Ai[2]*fx(xi[2]));
    printf("Cotes(布尔):     %.15f\n",(b-a)*(7*fx(-1)+32*fx(-0.5)+12*fx(0)+32*fx(0.5)+7*fx(1))/90);
    printf("Trapezoid:       %.15f\n",(b-a)*(fx(a)+fx(b))/2);
    printf("Simpson:         %.15f\n",(b-a)*(fx(a)+fx(b)+4*fx((b-a)/2))/6);

    return 0;
}