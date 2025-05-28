#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string input_equation;
	cin >> input_equation;

	vector<pair<string, int>> equation_piece;

	int findOperator_pos = -1;

	//비연산자와 연산자를 나누기
	for (int i = 0; i < input_equation.size(); i++)
	{
		if (input_equation[i] == '-')
		{
			if (i - 1 >= 0)
			{
				string non_operator = input_equation.substr(findOperator_pos + 1, i - (findOperator_pos + 1));
				string minus_operator = "-";

				pair<string, int> p_nonOper;
				p_nonOper.first = non_operator;
				p_nonOper.second = 0;

				pair<string, int> p_minusOper;
				p_minusOper.first = minus_operator;
				p_minusOper.second = 2;

				equation_piece.push_back(p_nonOper);
				equation_piece.push_back(p_minusOper);

				findOperator_pos = i;
			}
		}
		else if (input_equation[i] == '+')
		{
			if (i - 1 >= 0)
			{
				string non_operator = input_equation.substr(findOperator_pos + 1, i - (findOperator_pos + 1));
				string plus_operator = "+";

				pair<string, int> p_nonOper;
				p_nonOper.first = non_operator;
				p_nonOper.second = 0;

				pair<string, int> p_plusOper;
				p_plusOper.first = plus_operator;
				p_plusOper.second = 2;

				equation_piece.push_back(p_nonOper);
				equation_piece.push_back(p_plusOper);

				findOperator_pos = i;
			}
		}
		else if (input_equation[i] == '*')
		{
			if (i - 1 >= 0)
			{
				string non_operator = input_equation.substr(findOperator_pos + 1, i - (findOperator_pos + 1));
				string multiplication_operator = "*";

				pair<string, int> p_nonOper;
				p_nonOper.first = non_operator;
				p_nonOper.second = 0;

				pair<string, int> p_multiOper;
				p_multiOper.first = multiplication_operator;
				p_multiOper.second = 3;

				equation_piece.push_back(p_nonOper);
				equation_piece.push_back(p_multiOper);

				findOperator_pos = i;
			}
		}
		else if (input_equation[i] == '/')
		{
			if (i - 1 >= 0)
			{
				string non_operator = input_equation.substr(findOperator_pos + 1, i - (findOperator_pos + 1));
				string division_operator = "/";

				pair<string, int> p_nonOper;
				p_nonOper.first = non_operator;
				p_nonOper.second = 0;

				pair<string, int> p_divisionOper;
				p_divisionOper.first = division_operator;
				p_divisionOper.second = 3;

				equation_piece.push_back(p_nonOper);
				equation_piece.push_back(p_divisionOper);

				findOperator_pos = i;
			}
		}
		else if (input_equation[i] == '(')
		{
			
			string smallOpen_operator = "(";

			pair<string, int> p_smallOpenOper;
			p_smallOpenOper.first = smallOpen_operator;
			p_smallOpenOper.second = 4;

			equation_piece.push_back(p_smallOpenOper);

			findOperator_pos = i;
			
		}
		else if (input_equation[i] == ')')
		{
			if (i - 1 >= 0)
			{
				string non_operator = input_equation.substr(findOperator_pos + 1, i - (findOperator_pos + 1));
				string smallClose_operator = ")";

				pair<string, int> p_nonOper;
				p_nonOper.first = non_operator;
				p_nonOper.second = 0;

				pair<string, int> p_smallCloseOper;
				p_smallCloseOper.first = smallClose_operator;
				p_smallCloseOper.second = 5;

				equation_piece.push_back(p_nonOper);
				equation_piece.push_back(p_smallCloseOper);

				findOperator_pos = i;
			}
		}

		else if (i == input_equation.size() - 1)
		{
			string rest_str = input_equation.substr(findOperator_pos + 1, i - (findOperator_pos - 1));

			pair<string, int> p_rest;

			p_rest.first = rest_str;
			p_rest.second = 0;
			equation_piece.push_back(p_rest);
		}

		else {}
	}

	/*for (int i = 0; i < equation_piece.size(); i++)
	{
		cout << equation_piece[i].first << '\n';
	}*/



	stack<pair<string, int>> info_stack;
	vector<string> result;

	for (int i = 0; i < equation_piece.size(); i++)
	{
		if (equation_piece[i].second == 0) // 비연산자일 경우
		{
			result.push_back(equation_piece[i].first);
		}
		else
		{

			if (info_stack.empty()) // 스택이 만약 비어있는 상태라면
			{
				info_stack.push(equation_piece[i]);
				continue;
			}

			int input_stackValue = equation_piece[i].second;
			//비연산자일 경우(예외 제외한)
			while (true)
			{
				if (info_stack.top().second >= input_stackValue && info_stack.top().second != 4)
				{
					result.push_back(info_stack.top().first);
					
					info_stack.pop();

					if (!info_stack.empty())
					{
						if (info_stack.top().second >= input_stackValue && info_stack.top().second != 4)
						{
							continue;
						}
					}
					info_stack.push(equation_piece[i]);

					input_stackValue = 1000;
				}

				if (input_stackValue == 5) // )를 만났다면
				{
					if (info_stack.top().second != 4)
					{
						result.push_back(info_stack.top().first);
						info_stack.pop();
						continue;
					}
					info_stack.pop();
				}
				
				if (input_stackValue < 5)
				{
					info_stack.push(equation_piece[i]);
				}
				break;
			}

		}

		if ((i == equation_piece.size() - 1) && !info_stack.empty())
		{
			while (!info_stack.empty())
			{
				result.push_back(info_stack.top().first);
				info_stack.pop();
			}
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}
}