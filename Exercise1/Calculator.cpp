#include <iostream>
#include "Calculator.h"

using namespace std;

double mem;

double add(double x, double y)
{
	return x + y;
}

double subtract(double x, double y)
{
	return x - y;
}

double multiply(double x, double y)
{
	return x * y;
}

double divide(double x, double y)
{
	return x / y;
}

double exponent(double x, double y)
{
	return pow(x, y);
}

double invert(double input)
{
	return 0.0 - input;
}

void memStore(double input)
{
	mem = input;
}

double memRecall()
{
	return mem;
}

void memClear()
{
	mem = 0;
}