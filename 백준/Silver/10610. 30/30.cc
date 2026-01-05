#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string N;
	cin >> N;

	if (N.find('0') == N.npos)
	{
		cout << -1;
		return 0;
	}
	else
	{
		swap(N[N.length()-1], N[N.find('0')]);
	}

	int sum = 0;

	for (int index = 0; index < N.length() - 1; index++)
	{
		sum += N[index] - '0';
	}

	if (sum % 3 == 0)
	{
		sort(N.begin(), N.end() - 1, [](const int& a, const int& b) {return a > b; });
		cout << N;
	}
	else
	{
		cout << -1;
	}
	return 0;
}