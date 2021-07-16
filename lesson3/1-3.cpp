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
    puts("");
    puts("Jacobi");
    mat A = "4,-2,-4;-2,17,10;-4,10,9";
    mat M = getD(A);
    mat b = "10;3;-7";
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
    int have=1;
    printf("\ncnt\t\tx[0]\t\tx[1]\t\tx[2]\t\terror\n");
    while (norm2(x, prex) > EPS)
    {
        if(cnt<10 || cnt>140)
        printf(" %-5d\t    %-10.8f\t    %-10.8f\t    %-10.8f\t    %-10.8f\n", cnt, x(0), x(1), x(2), norm2(x, prex));
        else
        {
            if(have)
            {
                puts(" ...");
                have=0;
            }
        }
        cnt++;
        prex = x;
        x = B * x + F;
        if (cnt >= 150)
            break;
    }
    printf(" %-5d\t    %-10.8f\t    %-10.8f\t    %-10.8f\t    %-10.8f\n", cnt, x(0), x(1), x(2), norm2(x, prex));
    
    if (cnt >= 150)
    {
        puts("迭代格式不收敛");
    }
    x.print("\nfinal-x:");
}