#include <iostream>
#include <iomanip>
#include "convert.hpp"
#include <cmath>
#include <string>
using namespace std;
void cll4(double *a)
{
    *a=con_d_4(*a);
}
double temp[50]={0.63212055882855767840447622983854, 0.36787944117144232159552377016146,
     0.26424111765711535680895245967708, 0.20727664702865392957314262096877, 
     0.17089341188538428170742951612494, 0.1455329405730785914628524193753, 
     0.12680235656152845122288548374818, 0.11238350406930084143980161376277, 
     0.10093196744559326848158708989782, 0.091612292989660583665716190919579};
int main()
{
    double arr1[50]={0};
    arr1[0]=1-exp(-1);
    cll4(&arr1[0]);
    printf("from n=0 to n=9\ni=0 ans=%f error=%.15f\n",arr1[0],fabs(arr1[0]=temp[0]));
    for(int i=1;i<=9;i++)
    {
        arr1[i]=1-i*arr1[i-1];
        cll4(&arr1[i]);
        printf("i=%d ans=%f error=%.15f\n",i,arr1[i],fabs(arr1[i]-temp[i]));
    }

    puts("");
    double arr2[50]={0};
    arr2[9]=temp[9];
    cll4(&arr2[9]);
    puts("from n=9 to n=0");
    printf("i=9 ans=%f error=%.15f\n",arr2[9],fabs(arr2[9]-temp[9]));
    for(int i=8;i>=0;i--)
    {
        arr2[i]=(1-arr2[i+1])/(i+1);
        cll4(&arr2[i]);
        printf("i=%d ans=%f error=%.15f\n",i,arr2[i],fabs(arr2[i]-temp[i]));
    }
    puts("");

}