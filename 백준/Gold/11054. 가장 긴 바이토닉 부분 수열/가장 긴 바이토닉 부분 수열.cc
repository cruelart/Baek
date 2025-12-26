#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> sequence(N);
	vector<int> dp_plustable(N, 1);
	vector<int> dp_minustable(N, 1);

	for (int n = 0; n < N; n++)
	{
		cin >> sequence[n];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (sequence[i] > sequence[j]) // 증가하고있다면
			{
				dp_plustable[i] = max(dp_plustable[i], dp_plustable[j] + 1);
			}
		}
	}

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (sequence[i] > sequence[j])
			{
				dp_minustable[i] = max(dp_minustable[i], dp_minustable[j] + 1);
			}
		}
	}

	vector<int> vitonic_sequence(N, 1);

	for (int i = 0; i < N; i++)
	{
		vitonic_sequence[i] = dp_plustable[i] + dp_minustable[i] - 1;
	}

	cout << *max_element(vitonic_sequence.begin(), vitonic_sequence.end());

	return 0;
}