#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int result = 0;

	for (int n = 1; n <= N; n++)
	{
		int new_N = 0;
		string sn = to_string(n);

		for (int i = 0; i < sn.length(); i++)
		{
			new_N += sn[i] - '0';
		}
		new_N += n;

		if (N == new_N)
		{
			result = n;
			break;
		}
	}

	cout << result;

	return 0;
}