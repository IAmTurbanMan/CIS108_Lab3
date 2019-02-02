#include <iostream>
#include "conio.h"
#include "Calculator.h"
#include <string>

using namespace std;

int main()
{
	double num1;
	double num2;
	char oper;
	char key;
	string typed = "";
	string secondTyped = "";
	double result;
	double mem;

	while (true)
	{
		cout << ">> ";
		cin >> num1 >> oper >> num2;

		switch (oper)
		{
		case'+':
			result = add(num1, num2);
			break;
		case'-':
			result = subtract(num1, num2);
			break;
		case'*':
			result = multiply(num1, num2);
			break;
		case'/':
			result = divide(num1, num2);
			break;
		case'^':
			result = exponent(num1, num2);
			break;
		default:
			break;
		}

		cout << result << endl;
		mem = result;
	}
}