#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<int> B_num; // B진법출력 큐

	int N , B;
	cin >> N >> B;

	while (N > 0)
	{
		B_num.push_front(N % B);
		N = N / B;
	}

	for (int i = 0; i < B_num.size(); i++)
	{
		if (B_num[i] < 10)
		{
			cout << B_num[i];
		}
		else
		{
			char str = B_num[i] + 55;

			cout << str;
		}
		
	}

	return 0;
}