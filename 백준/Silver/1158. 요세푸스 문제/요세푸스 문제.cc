#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	deque<int> deq;
	int index = 1;

	for (int n = 1; n <= N; n++)
	{
		deq.push_back(n);
	}

	vector<int> result;

	while (!deq.empty())
	{
		for (int i = 1; i < K; i++) // K번째 인덱스전에는 뒤로 넘겨주기
		{
			deq.push_back(deq.front());
			deq.pop_front();
		}
		result.push_back(deq.front());
		deq.pop_front();
	}

	cout << '<';
	for (int i = 0; i < result.size(); i++)
	{
		if (i == result.size() - 1)
		{
			cout << result[i];
			break;
		}
		cout << result[i] << ',' << ' ';
	}
	cout << '>';

	return 0;
}

/*

원형큐 방식으로 풀 예정이고

1 2 3 4 5 6 7 이 존재한다고하면

(7.3)이라고 하자

1. 2 3 4 5 6 7 1
2. 3 4 5 6 7 1 2
3. 3제거 -> 4 5 6 7 1 2
4. 5 6 7 1 2 4
5. 6 7 1 2 4 5
6. 6제거 -> 7 1 2 4 5

*/