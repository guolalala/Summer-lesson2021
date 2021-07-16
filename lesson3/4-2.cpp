#include <iostream>
#include <iomanip>
#include <armadillo>
#include "convert.hpp"
#include <cmath>
#include <string>
#include "myhpp.hpp"
using namespace std;
using namespace arma;
/*
g++ -o 4-1 4-1.cpp -larmadillo && g++ -o 4-2 4-2.cpp -larmadillo
*/
int main()
{
    mat A="25,1;27,1;31,1;33,1;35,1;";
    mat b="110;115;155;160;180";

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