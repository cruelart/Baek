#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> dp_table(N+1, vector<int>(10));
	dp_table[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		dp_table[1][i] = 1;
	}

	for (int n = 2; n <= N; n++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp_table[n][j] = dp_table[n - 1][j + 1] % 1000000000;
			}
			else if (j == 9)
			{
				dp_table[n][j] = dp_table[n - 1][j - 1] % 1000000000;
			}
			else
			{
				dp_table[n][j] = (dp_table[n - 1][j - 1] + dp_table[n - 1][j + 1]) % 1000000000;
			}
		}
	}
	int result = 0;

	for (int i = 0; i < 10; i++)
	{
		result =  (result + dp_table[N][i]) % 1000000000;
	}

	cout << result;
}

// N = 1 -> 0부터 9까지 10개 - (1)
// N = 2 -> 마지막이 9부터 1까지 arr[1] x 2 - (0에서 시작한거 2개빼고, 9에서 시작한거 1개뺌) (9다음 10은 안되니까)
// N = 3 -> arr[2]

