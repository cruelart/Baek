#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b, c; // 각각의 주사위 수
	cin >> a >> b >> c;

	int reward = 0; //상금

	if (a == b && b == c && c == a) // 모두 같은 숫자가 나왔다면
	{
		reward = 10000 + a * 1000;
	}
	else if (a == b || b == c || c== a) // 셋중 둘만 같은 숫자라면
	{
		if (a == b)
		{
			reward = 1000 + a * 100;
		}
		else
		{
			reward = 1000 + c * 100;
		}
	}
	else
	{

		int max_num = 0;
		while (true)
		{
			if (max_num < a)
			{
				max_num = a;
				continue;
			}
			else if (max_num < b)
			{
				max_num = b;
				continue;
			}
			else if (max_num < c)
			{
				max_num = c;
				continue;
			}
			else{}

			break;
		}

		reward = max_num * 100;
	}

	cout << reward;

	return 0;
}