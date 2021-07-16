#include <iostream>
#include <iomanip>
#include <armadillo>
#include "convert.hpp"
#include <cmath>
#include <string>
#include "myhpp.hpp"
using namespace std;
using namespace arma;
#define EPS (1e-3)

int cnt;
int main()
{
    puts("");
    puts("Jacobi");
    mat A = "8,-3,2;4,11,-1;6,3,12";
    mat M = getD(A);
    mat b = "20;33;36";
    mat N = M - A;

    A.print("A:");
    M.print("M:");
    N.print("N:");

    mat invM = inv(M);
    mat B = invM * N;
    mat F = invM * b;

    mat x = "0;0;0", prex = "1;1;1";
    //x.print("x:");
    //cout<<x(0);
    printf("\ncnt\t\tx[0]\t\tx[1]\t\tx[2]\t\terror\n");
    while (norm2(x, prex) > EPS)
    {
        printf(" %-5d\t    %-10.8f\t    %-10.8f\t    %-10.8f\t    %-10.8f\n", cnt, x(0), x(1), x(2), norm2(x, prex));
        cnt++;
        prex = x;
        x = B * x + F;
        if (cnt >= 150)
            break;
    }
    printf(" %-5d\t    %-10.8f\t    %-10.8f\t    %-10.8f\t    %-10.8f\n", cnt, x(0), x(1), x(2), norm2(x, prex));
    x.print("\nfinal-x:");
}