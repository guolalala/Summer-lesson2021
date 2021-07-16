#include<iostream>
#include<math.h>
#include"convert.hpp"

using namespace std;

int main()
{
    cout.precision(12);

    cout<<endl;
    double I[10] = {0};
    double II[10] = 
    {0.63212055882855767840447622983854, 0.36787944117144232159552377016146,
     0.26424111765711535680895245967708, 0.20727664702865392957314262096877, 
     0.17089341188538428170742951612494, 0.1455329405730785914628524193753, 
     0.12680235656152845122288548374818, 0.11238350406930084143980161376277, 
     0.10093196744559326848158708989782, 0.091612292989660583665716190919579};
    
    cout<< "method-1"<<endl;

    I[0] = con_d_4(exp(1-1) - exp(0-1));
    cout<< "I[0]: "<< I[0] << endl;
    for(int n=1;n<=9;n++)
    {
        I[n] = con_d_4(1-n*I[n-1]);
        cout<< "I["<< n <<"]: "<<I[n] <<endl; 
        double res = I[n] - II[n];
        cout << "absolute error = " << res << endl;
        cout << "relative error = " << res / II[n] << endl << endl;;
    }


    cout<<endl<< "method-2"<<endl;
    I[9] = con_d_4(0.091612);
    cout<< "I[9]: " << I[9] <<endl;
    for(int n=9;n>=1;n--)
    {
        I[n-1] = con_d_4((1-I[n])/n);
        cout<< "I["<< n-1 <<"]: "<<I[n-1] <<endl;
        double res = con_d_8(I[n-1]) - II[n-1];
        cout << "absolute error = " << res << endl;
        cout << "relative error = " << res / II[n-1] << endl << endl;; 
    }
    
}
