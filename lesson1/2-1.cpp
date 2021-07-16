#include <iostream>
#include <iomanip>
#include "convert.hpp"
#include <cmath>
using namespace std;
int main()
{
    cout << endl;
    double pi0 = 3.141592653589793;
    double pi1 = pi0 + 0.000123456789123;
    //cout<<pi0<<" to 8 precision: "<<con_d_8(pi0)<<endl;
    printf("pi0=%.15f", pi0);
    cout << "\nto 8 precision: ";
    printf("ppi0=%.15f\n", con_d_8(pi0));
    double pi0_res = con_d_8(pi0) - pi0;
    cout << "absolute error = " << pi0_res << endl;
    cout << "relative error = " << pi0_res / pi0 << endl;

    cout << endl;
    cout << "pi1= ";
    printf("%.15f\n", pi1);
    printf("to 8 precision: ppi1=%.15f\n", con_d_8(pi1));
    //<< pi1 << "\nto 8 precision: " << con_d_8(pi1) << endl;
    double pi1_res = con_d_8(pi1) - pi1;
    cout << "absolute error = " << pi1_res << endl;
    cout << "relative error = " << pi1_res / pi1 << endl;
    cout << endl;

    double ppi0 = con_d_8(pi0), ppi1 = con_d_8(pi1);
    printf("mpp = ppi1-ppi0 = %.15f\n", ppi1 - ppi0);
    double mpp_res = fabs((ppi1 - ppi0) - (pi1 - pi0));
    cout << "absolute error = " << mpp_res << endl;
    cout << "relative error = " << mpp_res / (pi1 - pi0) << endl;
    cout << endl;
}