#include <iostream>
#include <iomanip>
#include <armadillo>
#include "convert.hpp"
#include <cmath>
#include <string>
#include "myhpp.hpp"
using namespace std;
using namespace arma;
#define EPS (1e-5)

int cnt;
int main()
{
    puts("Gauss-Seidel");
    mat A = "4,-2,-4;-2,17,10;-4,10,9";
    mat D = getD(A);
    mat L = getL(A);
    mat U = getU(A);
    mat b = "10;3;-7";

    A.print("A:");
    D.print("D:");
    L.print("L:");
    U.print("U:");

    mat invDL = inv(D + L);
    mat B = -invDL * U;
    mat F = invDL * b;

    mat x = "0;0;0", prex = "1;1;1";
    x.print("x0:");

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
    if (cnt >= 150)
    {
        puts("迭代格式不收敛");
    }
}