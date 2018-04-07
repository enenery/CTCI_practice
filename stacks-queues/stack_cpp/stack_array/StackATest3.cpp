/*Erii Sugimoto
  CSC 330 : BMCC
  Programming Exercise 4
  May 26th, 2016

  Purpose: This program reads arithmetical expression from user, performs arithmetic operations
			and returns a result.
  */

#include "StackA.cpp"
#include <iostream>
using namespace std;
#include <string>

bool isParenthesizingCorrect(string item)
{
	stackA<int> today;

	bool open = false;

	for (int i = 0; i < item.length(); i++)
	{
		if (item.at(i) == '(')
		{
			today.push('(');
			open = true;
		}		
		else
		{
			if (item.at(i) == ')' && !open)
				return false;
			else
			{
				if (item.at(i) == ')' && open)
				{
					today.pop();

					if (today.isEmpty())
						open = false;
				}
			}
		}
	}

	if (!open)
		return true;
	else
		return false;

}

template <class x>
bool isEqual(stackA<x> one, stackA<x> two)
{
	if (one.getTop() == two.getTop())
	{
		while (!one.isEmpty())
		{
			if (one.getTopItem() != two.getTopItem())
				return false;

			one.pop();
			two.pop();
		}
		return true;
	}
	else return false;
}

int main()
{
	stackA<int> nums;
	stackA<char> opes;
	stackA<char> pares;
	string input;

	int right;
	int left;
	char middle;
	int result;

	cout << "\nEnter your choice of arithemetic expression (ex: 3*4+2): ";
	getline(cin, input);
	
	int i = 0;
	bool correct = true;

	while (i < input.length() && correct)
	{
		cout << "\ninput[i] = " << input[i];

		if (input[i] == '-' && isdigit(input[i + 1]))
		{
			if (!isdigit(input[i - 1]))
			{
				cout << "\nB";
				nums.push((input.at(i+1) - '0')*-1);
				i++;
			}
			else
			{
				opes.push('-');
			}
			
		}
		else
		{
			if (isdigit(input[i]))
			{
				nums.push(input.at(i) - '0');

				if (nums.getTop() == 1 && (opes.getTopItem() == '*' || opes.getTopItem() == '/'))
				{
					cout << "\nC";
					right = nums.getTopItem();
					nums.pop();
					left = nums.getTopItem();
					nums.pop();
					middle = opes.getTopItem();
					opes.pop();
					result = 0;

					if (middle == '*')
					{
						result = left * right;
					}
					else
					{
						result = left / right;
					}

					nums.push(result);
				}
			}
			else
			{
				if (input[i] == '(')
				{
					pares.push(input[i]);
				}
				else
				{
					if (input[i] == ')')
					{
						if (pares.getTopItem() == '(')
						{
							pares.pop();
							right = nums.getTopItem();
							nums.pop();
							left = nums.getTopItem();
							nums.pop();
							middle = opes.getTopItem();
							opes.pop();
							result = 0;

							if (middle == '+')
							{
								result = left + right;
							}
							else
							{
								if (middle == '-')
								{
									result = left - right;
								}
								else
								{
									if (middle == '*')
									{
										result = left * right;
									}
									else
									{
										result = left / right;
									}
								}
							}
							nums.push(result);
						}
						else
						{
							cout << "\nincorrect:";
							correct = false;
						}
					}
					else
					{
						if (input[i] == '*' || input[i] == '/')
						{
							opes.push(input[i]);
						}
						else
						{
							if (input[i] == '+' || input[i] == '-')
							{
								
								if (opes.getTopItem() == '*' || opes.getTopItem() == '/')
								{
									cout << "\nA: ";
									right = nums.getTopItem();
									nums.pop();
									left = nums.getTopItem();
									nums.pop();
									middle = opes.getTopItem();
									opes.pop();
									result = 0;

									if (middle == '*')
									{
										result = left * right;
									}
									else
									{
										result = left / right;
									}

									nums.push(result);
									opes.push(input[i]);
								}
								else
								{
									opes.push(input[i]);
								}

							}
						}
					}

				}
			}
		}

		i++;
	}

	if (!correct || !pares.isEmpty())
	{
		cout << "\nParenthesizing of your expression was incorrect.";
	}
	else
	{
		while (nums.getTop() != 0)
		{
			right = nums.getTopItem();
			nums.pop();
			left = nums.getTopItem();
			nums.pop();
			middle = opes.getTopItem();
			opes.pop();

			if (middle == '+')
			{
				nums.push(left + right);
			}
			else
			{
				if (middle == '-')
				{
					nums.push(left - right);
				}
				else
				{
					if (middle == '*')
					{
						nums.push(left * right);
					}
					else
					{
						nums.push(left / right);
					}
				}
			}

		}		
		cout << "\nThe result of your arithmetic expression: " << nums.getTopItem() << endl;
	}
}