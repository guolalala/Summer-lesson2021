//Gram solve
#include <iostream>
#include <iomanip>
#include "convert.hpp"
#include <cmath>
#include <string>
#include "myhpp.hpp"
using namespace std;

int main()
{
    printf("\nGram solve\n\n");
    double A1[2][2]={0.00001,1,1,1};
    double b1[2]={1,2};
    double x1[2]={0};
    printf("A1:\n");
    printf("%-10.8f %-10.8f \n%-10.8f %-10.8f\n",A1[0][0],A1[0][1],A1[1][0],A1[1][1]);
    printf("b1:\n");
    printf("%-10.8f %-10.8f\n",b1[0],b1[1]);
    for(int i=0;i<2;i++)
    {
        double temp[2][2];
        temp[0][i]=b1[0];
        temp[1][i]=b1[1];
        temp[0][1-i]=A1[0][1-i];
        temp[1][1-i]=A1[1][1-i];

        double res1=det2(temp),res2=det2(A1);
        cll4(&res1),cll4(&res2);
        double res=res1/res2;
        cll4(&res);
        x1[i]=res;
    }
    printf("x[0]=%f\nx[1]=%f\n",x1[0],x1[1]);


    cout<<endl<<endl;
    double A2[3][3]={2,4,-2,1,-3,-3,4,2,2};
    double b2[3]={2,-1,3};
    double x2[3]={0};
    printf("A2:\n");
    printf("%-10.8f %-10.8f %-10.8f\n%-10.8f %-10.8f %-10.8f\n%-10.8f %-10.8f %-10.8f\n",
    A2[0][0],A2[0][1],A2[0][2],A2[1][0],A2[1][1],A2[1][2],A2[2][0],A2[2][1],A2[2][2]);
    printf("b2:\n");
    printf("%-10.8f %-10.8f %-10.8f\n",b2[0],b2[1],b2[2]);

    for(int i=0;i<3;i++)
    {
        double temp[3][3];
        copy3(temp,A2);
        temp[0][i]=b2[0];
        temp[1][i]=b2[1];
        temp[2][i]=b2[2];
        

        double res1=det3(temp),res2=det3(A2);
        cll4(&res1),cll4(&res2);
        double res=res1/res2;
        cll4(&res);
        x2[i]=res;
    }
    for(int i=0;i<3;i++)
    printf("x[%d] = %-10.8f\n",i,x2[i]);
    puts("");

    cout<<endl<<endl;
    double A3[3][3]={0.012,0.01,0.167,1,0.8334,5.91,3200,1200,4.2};
    double b3[3]={0.6781,12.1,981};
    double x3[3]={0};
    printf("A3:\n");
    printf("%-10.8f %-10.8f %-10.8f\n%-10.8f %-10.8f %-10.8f\n%-10.8f %-10.8f %-10.8f\n",
    A3[0][0],A3[0][1],A3[0][2],A3[1][0],A3[1][1],A3[1][2],A3[2][0],A3[2][1],A3[2][2]);
    printf("b3:\n");
    printf("%-10.8f %-10.8f %-10.8f\n",b3[0],b3[1],b3[2]);

    for(int i=0;i<3;i++)
    {
        double temp[3][3];
        copy3(temp,A3);
        temp[0][i]=b3[0];
        temp[1][i]=b3[1];
        temp[2][i]=b3[2];
        

        double res1=det3(temp),res2=det3(A3);
        cll4(&res1),cll4(&res2);
        double res=res1/res2;
        cll4(&res);
        x3[i]=res;
    }
    for(int i=0;i<3;i++)
    printf("x[%d] = %-10.8f\n",i,x3[i]);
    puts("");
}