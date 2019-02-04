#include <iostream>
#include "Calculator.h"

using namespace std;

double mem;

double calc::add(double x, double y)
{
	return x + y;
}

double calc::subtract(double x, double y)
{
	return x - y;
}

double calc::multiply(double x, double y)
{
	return x * y;
}

double calc::divide(double x, double y)
{
	return x / y;
}

double calc::exponent(double x, double y)
{
	return pow(x, y);
}

double calc::invert(double input)
{
	return 0.0 - input;
}

void calc::memStore(double input)
{
	mem = input;
}

double calc::memRecall()
{
	return mem;
}

void calc::memClear()
{
	mem = 0;
}