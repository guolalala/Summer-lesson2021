#include <iostream>
#include <iomanip>
#include <armadillo>
#include "convert.hpp"
#include <cmath>
#include <string>
#include "myhpp.hpp"
using namespace std;
using namespace arma;

int main()
{
    mat A="1,2,4;2,1,1;1,1,2;1,-1,-2;";
    mat b="-1;4;2;1";

    mat At=A.t()*A;
    mat Atb=A.t()*b;

    A.print("A:");
    b.print("b:");
    At.print("At:");
    Atb.print("Atb:");

    mat x=solve(At,Atb);
    x.print("x=solve(At,Atb):");

    return 0;
}