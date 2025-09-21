#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	if (N != 1)
	{
		for(int i = 2; pow(i,2) <= N; i++)
		{
			while (N % i == 0)
			{
				N /= i;
				cout << i <<'\n';
			}
		}

		if (N > 1) // N값이 소수라면
		{
			cout << N;
		}
	}
}