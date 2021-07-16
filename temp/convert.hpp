
#include <iostream>
#include <sstream> //字符串流函数的调用准备
#include <iomanip> //格式化操作的调用准备

#pragma once

template <class T, int PRECISION>
T convert1(T input)
{
    std::stringstream is;
    T res;
    is.precision(PRECISION);
    is << input;
    is >> res;
    return res;
}

float con_f_3(float t)
{
    float tt;
    tt = convert1<float, 3>(t);
    return tt;
}

float con_f_4(float t)
{
    float tt;
    tt = convert1<float, 4>(t);
    return tt;
}

float con_f_5(float t)
{
    float tt;
    tt = convert1<float, 5>(t);
    return tt;
}

float con_f_6(float t)
{
    float tt;
    tt = convert1<float, 6>(t);
    return tt;
}

float con_f_7(float t)
{
    float tt;
    tt = convert1<float, 7>(t);
    return tt;
}

float con_f_8(float t)
{
    float tt;
    tt = convert1<float, 8>(t);
    return tt;
}

double con_d_3(double t)
{
    double tt;
    tt = convert1<double, 3>(t);
    return tt;
}

double con_d_4(double t)
{
    double tt;
    tt = convert1<double, 4>(t);
    return tt;
}

double con_d_5(double t)
{
    double tt;
    tt = convert1<double, 5>(t);
    return tt;
}

double con_d_6(double t)
{
    double tt;
    tt = convert1<double, 6>(t);
    return tt;
}

double con_d_7(double t)
{
    double tt;
    tt = convert1<double, 7>(t);
    return tt;
}

double con_d_8(double t)
{
    double tt;
    tt = convert1<double, 8>(t);
    return tt;
}