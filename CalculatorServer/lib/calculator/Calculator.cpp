#include <Calculator.h>

double Calculator::add(double a, double b)
{
    return a + b;
}

double Calculator::sub(double a, double b)
{
    return a - b;
}

double Calculator::mul(double a, double b)
{
    return a * b;
}

double Calculator::div(double a, double b)
{
    return b?(a / b):__INT32_MAX__;
}