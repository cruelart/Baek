
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int _N, int _K, vector<int>& _dist)
{
	queue<pair<int,int>> bfs_queue; // 해당 좌표, 초
	bfs_queue.emplace(_N, 0);

	while (!bfs_queue.empty())
	{
		int present_location = bfs_queue.front().first; // 현재 좌표
		int present_time = bfs_queue.front().second;
		_dist[present_location] = present_time;

		bfs_queue.pop();

		if (present_location == _K)
		{
			return present_time; // 동생을 발견했다
		}

		if (present_location - 1 >= 0 && _dist[present_location - 1] == -1)
		{
			bfs_queue.emplace(present_location - 1, _dist[present_location] + 1);
		}
		if (present_location + 1 <= 100000 && _dist[present_location + 1] == -1)
		{
			bfs_queue.emplace(present_location + 1, _dist[present_location] + 1);
		}
		if (2 * present_location <= 100000 && _dist[2 * present_location] == -1)
		{
			bfs_queue.emplace(2 * present_location, _dist[present_location] + 1);
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K; // 수빈이의 위치, 동생의 위치
	cin >> N >> K;

	vector<int> dist(100001, -1);

	cout << BFS(N, K, dist);

	return 0;
}

