#include <iostream>
#include <iomanip>
#include "convert.hpp"
#include <cmath>
#include <string>
using namespace std;
int main()
{
    double pi30=3.141592653589793,pi31=pi31 = 0.000123456789123;
    double ppi30=con_d_8(pi30),ppi31=con_d_8(pi31);
    printf("pi30 = %.15f, ppi30 = %.15f\n",pi30,ppi30);
    double res1=fabs(pi30-ppi30);
    printf("absolute error = %.15f\n",res1);
    printf("relative error = %.15f\n\n",res1/pi30);

    printf("pi31 = %.15f, ppi31 = %.15f\n",pi31,ppi31);
    double res2=fabs(pi31-ppi31);
    printf("absolute error = %.15f\n",res2);
    printf("relative error = %.15f\n\n",res2/pi31);

    double mpp30=con_d_8(ppi30/ppi31);
    printf("mpp30 = %.15f\n",mpp30);
    double res3=fabs(mpp30-(pi30/pi31));
    printf("absolute error = %.15f\n",res3);
    printf("relative error = %.15f\n\n",res3/(pi30/pi31));
}