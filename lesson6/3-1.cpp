/*
 * @author: Bodan Chen
 * @Date: 2021-07-15 22:05:36
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-15 22:25:19
 * @Email: 18377475@buaa.edu.cn
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-4)
#define PI (acos(-1))
using namespace std;

double fx(double x)
{
    return 1.0/(x+2);
}
double a=-1,b=1;
double xi[10]={-0.5773502692,0.5773502692};
int main()
{
    printf("The exact value: %.15f\n",log(3)-log(1));
    printf("Gauss-Legendre:  %.15f\n",fx(xi[0])+fx(xi[1]));
    printf("Trapezoid:       %.15f\n",(b-a)*(fx(a)+fx(b))/2);
    printf("Simpson:         %.15f\n",(b-a)*(fx(a)+fx(b)+4*fx((b-a)/2))/6);

    return 0;
}