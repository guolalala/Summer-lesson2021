#include <iostream>
#include <iomanip>
#include <cmath>
#include "convert.hpp"
using namespace std;
int main()
{
    cout<<endl<<endl;
    double f5=4.015*100;
    cout<<f5<<" to 4 precision: "<<con_d_4(f5)<<endl;
    double f5_res=fabs(f5-con_d_4(f5));
    cout<<"absolute error = "<<f5_res<<endl;
    cout<<"relative error = "<<f5_res/f5<<endl;

    cout<<endl<<endl;
    float f6=7654321.0,f7=0.4;
    float sum67=f6+f7;
    printf("sum of %f and %f is %f\n",f6,f7,sum67);
    cout<<" to 7 precision: "<<con_d_7(sum67)<<endl;
    double sum67_res=fabs(sum67-con_d_7(sum67));
    cout<<"absolute error = "<<sum67_res<<endl;
    cout<<"relative error = "<<sum67_res/sum67<<endl;

    cout<<endl<<endl;

}