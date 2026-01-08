#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//   2  1

int main()
{
	int N;
	cin >> N;

	vector<int> result(N, -1);

	for (int i = 1; i <= N; i++)
	{
		int taller_num;
		cin >> taller_num;

		int tall_num = 0;
		int index = 0;

		for (int j = 0; j < N; j++)
		{
			if (tall_num == taller_num)
			{
				index = j;
				break;
			}

			if (result[j] == -1)
			{
				tall_num++;
			}
		}
		if (result[index] != -1)
		{
			while (result[index] != -1)
			{
				index++;
			}
		}
		result[index] = i;
	}

	for (int i = 0; i < N; i++)
	{
		cout << result[i] << ' ';
	}

	return 0;
}