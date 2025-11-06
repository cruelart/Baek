#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dijkstra(int _N, int _K)
{
	vector<vector<int>> isVisit(2,vector<int>(500001, -1));

	queue<pair<int, int>> dij_queue; // 걸린 시간, 인덱스번호
	dij_queue.push({ 0,_N });
	isVisit[0][_N] = 0;

	while (!dij_queue.empty())
	{
		int present_index = dij_queue.front().second;
		int present_value = dij_queue.front().first;

		dij_queue.pop();

		if (present_index - 1 >= 0 && isVisit[(present_value + 1) % 2][present_index - 1] == -1)
		{
			dij_queue.push({ present_value + 1, present_index - 1 });
			isVisit[(present_value + 1) % 2][present_index - 1] = present_value + 1; // 미리 방문했다고 알려줌
		}
		if (present_index + 1 <= 500000 && isVisit[(present_value + 1) % 2][present_index + 1] == -1)
		{
			dij_queue.push({ present_value + 1 , present_index + 1 });
			isVisit[(present_value + 1) % 2][present_index + 1] = present_value + 1;
		}
		if (present_index * 2 <= 500000 && isVisit[(present_value + 1) % 2][present_index * 2] == -1)
		{
			dij_queue.push({ present_value + 1 ,present_index * 2 });
			isVisit[(present_value + 1) % 2][present_index * 2] = present_value + 1;
		}
	}

	int time = 0;
	while (true)
	{
		_K += time;
		if (_K > 500000)
		{
			break;
		}

		if (isVisit[time % 2][_K] != -1 && isVisit[time%2][_K] <= time)
		{
			return time;
		}
		time++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	cout << dijkstra(N, K);

	return 0;
}