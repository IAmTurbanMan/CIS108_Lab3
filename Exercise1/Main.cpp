#include <iostream>
#include "conio.h"
#include "Calculator.h"
#include <string>

using namespace std;

double num1;
double num2;
char oper;
char key;
string typed = "";
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
				typed += key;
			}
			else
			{
				secondTyped += key;
			}
			break;

		case '+': case '-': case '*': case '/': case '^':
			if (active == 1)
			{
				num1 = stod(typed);
				active = 2;
				typed = "";
				secondTyped = "";
			}
			cout << key;
			oper = key;
			break;

		case 'c': case 'C':
			cout << "Calculator has been cleared" << endl << "> ";
			typed = "";
			secondTyped = "";
			num1 = 0;
			num2 = 0;
			active = 1;
			break;

		case 'i': case 'I':
			num1 = invert(stod(typed));
			cout << num1 << endl << "> ";
			break;

		case 'm': case 'M':
			memClear();
			cout << "Memory has been cleared." << endl << "> ";
			break;

		case 'r': case 'R':
			num1 = memRecall();
			cout << num1 << " has been recalled." << endl << "> ";
			break;

		case 's': case 'S':
			memStore(num1);
			cout << num1 << " has been stored." << endl << "> ";
			break;

			case char(13) :
				cout << endl;
				if (secondTyped != "")
				{
					num2 = stod(secondTyped);
					switch (oper)
					{
					case '+':
						num1 = add(num1, num2);
						break;
					
					case '-':
						num1 = subtract(num1, num2);
						break;

					case '*':
						num1 = multiply(num1, num2);
						break;

					case '/':
						num1 = divide(num1, num2);
						break;

					case '^':
						num1 = exponent(num1, num2);
						break;

					default:
						break;
					}
				}
			cout << num1 << endl << "> ";
			typed = to_string(num1);
			secondTyped = "";
			active = 1;
			break;
		
		default:
			break;

		}
	} while (key != 'x' && key != 'X');

	return 0;
}