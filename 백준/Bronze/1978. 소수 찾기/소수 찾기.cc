#include <iostream>

using namespace std;

int main()
{
	int N; // 수의 갯수
	cin >> N;

	int count = 0; // 소수의 갯수

	for (int n = 0; n < N; n++)
	{
		int num;
		cin >> num;

		int divisor_num = 0; // 약수가 2개면 소수

		for (int i = 1; i <= num; i++)
		{
			if (num % i == 0)
			{
				divisor_num++;
				if (divisor_num > 2)
				{
					break;
				}
			}
		}

		if (divisor_num == 2)
		{
			count++;
		}
	}

	cout << count;

	return 0;
}