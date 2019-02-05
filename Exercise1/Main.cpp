#include <iostream>
#include "conio.h"
#include "Calculator.h"
#include <string>

using namespace std;

double num1;
double num2;
char oper;
char key;
string firstTyped = "";
string secondTyped = "";
int active = 1;

int main()
{
	cout << "> ";
	do
	{
		key = char(_getch());

		switch (key)
		{
		case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': case '.':
			cout << key;
			if (active == 1)
			{
				firstTyped += key;
			}
			else
			{
				secondTyped += key;
			}
			break;

		case '+': case '-': case '*': case '/': case '^':
			if (active == 1)
			{
				num1 = stod(firstTyped);
				active = 2;
				firstTyped = "";
				secondTyped = "";
			}
			cout << key;
			oper = key;
			break;

		case 's': case 'S':
			calc::memStore(num1);
			cout << num1 << " stored." << endl << "> ";
			break;

		case 'r': case 'R':
			num1 = calc::memRecall();
			firstTyped = to_string(num1);
			cout << num1 << " recalled." << endl << "> ";
			break;

		case 'm': case 'M':
			calc::memClear();
			cout << "Memory cleared." << endl << "> ";
			break;

		case 'i': case 'I':
			num1 = calc::invert(stod(firstTyped));
			cout << num1 << endl << "> ";
			break;

		case 'c': case 'C':
			cout << "Cleared" << endl << "> ";
			firstTyped = "";
			secondTyped = "";
			num1 = 0;
			num2 = 0;
			active = 1;
			break;

		case char(13) :
			cout << endl;
			if (secondTyped != "")
			{
					num2 = stod(secondTyped);
					switch (oper)
					{
					case '+':
						num1 = calc::add(num1, num2);
						break;
					
					case '-':
						num1 = calc::subtract(num1, num2);
						break;

					case '*':
						num1 = calc::multiply(num1, num2);
						break;

					case '/':
						num1 = calc::divide(num1, num2);
						break;

					case '^':
						num1 = calc::exponent(num1, num2);
						break;

					default:
						break;
					}
				}
			cout << num1 << endl << "> ";
			firstTyped = to_string(num1);
			secondTyped = "";
			active = 1;
			break;
		
		default:
			break;

		}
	} while (key != 'x' && key != 'X');

	return 0;
}