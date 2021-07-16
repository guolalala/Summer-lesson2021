#include <iostream>
#include <iomanip>
#include "convert.hpp"
#include <cmath>
#include <string>
using namespace std;
int main()
{
    puts("");
    float pi20=7654321.0f;
    float pi21=0.2f;
    string s1="7654321.0f",s2="0.2f";
    cout<<s1<<" + "<<s2<<" + "<<s2<<" + "<<s2<<" + "<<s2<<" + "<<s2<<" = ";
    printf("%f\n",pi20+pi21+pi21+pi21+pi21+pi21);

    cout<<s2<<" + "<<s2<<" + "<<s2<<" + "<<s2<<" + "<<s2<<" + "<<s1<<" = ";
    printf("%f\n",pi21+pi21+pi21+pi21+pi21+pi20);
    puts("");

}