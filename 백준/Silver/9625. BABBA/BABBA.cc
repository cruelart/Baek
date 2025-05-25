#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int K;
	cin >> K;

	int* a_num = new int[K + 1]();
	int* b_num = new int[K + 1]();

	for (int i = 0; i < K+1;  i++)
	{
		if (i - 2 >= 0)
		{
			a_num[i] = a_num[i - 1] + a_num[i-2];
			b_num[i] = b_num[i - 1] + b_num[i-2];
		}
		else
		{
			if (i == 0)
			{
				a_num[i] += 1;
			} 
			else if (i == 1)
			{
				b_num[i] += 1;
			}
			else
			{

			}
		}
	}

	cout << a_num[K] << ' ' << b_num[K];

	return 0;
}