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
	vector<int> divisor; // 약수 / 소수-> prime number 

	if (N != 1)
	{
		for (int i = 2; i <= N; i++)
		{
			if (N % i == 0)
			{
				N /= i;
				divisor.push_back(i);
				i = 1;
			}
		}


		for (int j = 0; j < divisor.size(); j++)
		{
			cout << divisor[j] << '\n';
		}
	}
}