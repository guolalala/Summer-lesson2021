/*
 * @author: Bodan Chen
 * @Date: 2021-07-16 21:10:49
 * @LastEditors: Bodan Chen
 * @LastEditTime: 2021-07-16 21:10:50
 * @Email: 18377475@buaa.edu.cn
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-5)
#define PI (acos(-1))
using namespace std;

double ft(double t, double y)
{
    return (t - y) / 2;
}
double Ft(double t)
{
    return 3*exp(-0.5*t)-2+t;
}
//yn+1=yn+h*f
double a = 0, b = 3;
double f0 = 1;
int main()
{
    for (int m = 1; m <= 8; m *= 2)
    {
        printf("h=1/%d\n", m);
        double h = 1.0 / m;
        int n = (int)((b - a) / h + EPS);

        double ans = f0;
        for (int i = 0; i < n; i++)
        {
            double t = a + h * i;
            printf("tk=%-10.6f ans=%-10.6f exact value:%-10.6f\n", t, ans,Ft(t));
            ans = ans + h*ft(t, ans);
            //printf("tk=%f ans=%f\n", t, ans);
        }
        printf("tk=%-10.6f ans=%-10.6f exact value:%-10.6f\n", b, ans,Ft(b));
        //printf("ans=%f\n",ans);
        puts("");
    }
}