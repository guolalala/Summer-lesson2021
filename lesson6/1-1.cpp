/*
 * @author: Bodan Chen
 * @Date: 2021-07-15 20:45:18
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-15 20:53:24
 * @Email: 18377475@buaa.edu.cn
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-5)
#define PI (acos(-1))
using namespace std;

double fx(double x)
{
    return 1+exp(-x)*sin(4*x);
}
//[0,1]
double h=1;
int main()
{
    printf("梯形公式：");
    printf("%.8f\n",h/2*(fx(0)+fx(1)));

    printf("辛普森公式：");
    printf("%.8f\n",h/6*(fx(0)+4*fx(0.5)+fx(1)));

    printf("辛普森3/8公式：");
    printf("%.8f\n",h/8*(fx(0)+3*fx(1.0/3)+3*fx(2.0/3)+fx(1)));

    printf("布尔公式：");
    printf("%.8f\n",h/90*(7*fx(0)+32*fx(0.25)+12*fx(0.5)+32*fx(0.75)+7*fx(1)));

}