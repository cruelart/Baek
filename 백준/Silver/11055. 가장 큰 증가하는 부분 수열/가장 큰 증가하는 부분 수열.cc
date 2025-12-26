#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> sequence(N);
	vector<int> dp_table(N , 0);

	for (int n = 0; n < N; n++)
	{
		cin >> sequence[n];
		dp_table[n] = sequence[n];
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (sequence[i] > sequence[j])
			{
				dp_table[i] = max(dp_table[i], dp_table[j] + sequence[i]);
			}
		}
	}

	cout << *max_element(dp_table.begin(), dp_table.end());

	return 0;
}