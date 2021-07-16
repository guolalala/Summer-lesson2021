#include <iostream>
#include <iomanip>
#include "convert.hpp"
using namespace std;
int main()
{
    //cout.precision(12);

    double f1 = 0.12346845;
    cout << f1 << " to 4 precision: " << con_d_4(f1) << endl;
    double f1_res = con_d_4(f1) - f1;
    cout << "absolute error = " << f1_res << endl;
    cout << "relative error = " << f1_res / f1 << endl;

    cout << endl;
    cout << endl;

    double f2 = 0.012346845;
    cout << f2 << " to 4 precision: " << con_d_4(f2) << endl;
    double f2_res = con_d_4(f2) - f2;
    cout << "absolute error = " << f2_res << endl;
    cout << "relative error = " << f2_res / f2 << endl;

    cout << endl;
    cout << endl;

    double f3 = 0.0012346845;
    cout << f3 << " to 4 precision: " << con_d_4(f3) << endl;
    double f3_res = con_d_4(f3) - f3;
    cout << "absolute error = " << f3_res << endl;
    cout << "relative error = " << f3_res / f3 << endl;

    cout << endl;
    cout << endl;

    double f4 = 0.0000012346845;
    cout << f4 << " to 4 precision: " << con_d_4(f4) << endl;
    double f4_res = con_d_4(f4) - f4;
    cout << "absolute error = " << f4_res << endl;
    cout << "relative error = " << f4_res / f4 << endl;

    cout << endl;
    cout << endl;
}