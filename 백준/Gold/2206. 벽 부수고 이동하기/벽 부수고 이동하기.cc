#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int INF = 10000000;

void BFS(vector<vector<int>>& _graph, vector<vector<int>>& _dist, pair<int,int> _start_num, int& _min_result)
{
	queue<pair<int, int>> bfs_queue;
	bfs_queue.push(_start_num);
	
	while (!bfs_queue.empty())
	{
		auto present_index = bfs_queue.front();
		bfs_queue.pop();

		int x = present_index.first;
		int y = present_index.second;

		//상 좌 우 하 순서대로
		if (y - 1 > 0) // 상
		{
			if (_graph[y - 1][x] == 0)
			{
				if (_dist[y - 1][x] > _dist[y][x] + 1) // (중복을 방지) 최소 거리가 아닐 경우라면
				{
					bfs_queue.emplace(x, y - 1);
					_dist[y - 1][x] = _dist[y][x] + 1;
				}
			}
			if (_graph[y - 1][x] == 1 && _graph[_start_num.second][_start_num.first] == 0) // 벽이라면
			{
				if (_dist[y - 1][x] > _dist[y][x] + 1)
				{
					_dist[y - 1][x] = _dist[y][x] + 1;
				}
			}
		}

		if (x - 1 > 0) // 좌
		{
			if (_graph[y][x - 1] == 0)
			{
				if (_dist[y][x - 1] > _dist[y][x] + 1) // (중복을 방지) 최소 거리가 아닐 경우라면
				{
					bfs_queue.emplace(x - 1, y);
					_dist[y][x - 1] = _dist[y][x] + 1;
				}
			}
			if (_graph[y][x - 1] == 1 && _graph[_start_num.second][_start_num.first] == 0) // 벽이라면
			{
				if (_dist[y][x - 1] > _dist[y][x] + 1)
				{
					_dist[y][x - 1] = _dist[y][x] + 1;
				}
			}
		}

		if (x + 1 < _graph[0].size()) // 우
		{
			if (_graph[y][x + 1] == 0)
			{
				if (_dist[y][x + 1] > _dist[y][x] + 1) // (중복을 방지) 최소 거리가 아닐 경우라면
				{
					bfs_queue.emplace(x + 1, y);
					_dist[y][x + 1] = _dist[y][x] + 1;
				}
			}
			if (_graph[y][x + 1] == 1 && _graph[_start_num.second][_start_num.first] == 0) // 벽이라면
			{
				if (_dist[y][x + 1] > _dist[y][x] + 1)
				{
					_dist[y][x + 1] = _dist[y][x] + 1;
				}
			}
		}

		if (y + 1 < _graph.size()) // 하
		{
			if (_graph[y + 1][x] == 0)
			{
				if (_dist[y + 1][x] > _dist[y][x] + 1) // (중복을 방지) 최소 거리가 아닐 경우라면
				{
					bfs_queue.emplace(x, y + 1);
					_dist[y + 1][x] = _dist[y][x] + 1;
				}
			}
			if (_graph[y + 1][x] == 1 && _graph[_start_num.second][_start_num.first] == 0) // 벽이라면
			{
				if (_dist[y + 1][x] > _dist[y][x] + 1)
				{
					_dist[y + 1][x] = _dist[y][x] + 1;
				}
			}
		}
	}
	if (_min_result > _dist[_graph.size() - 1][_graph[0].size() - 1])
	{
		_min_result = _dist[_graph.size() - 1][_graph[0].size() - 1];
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M; //세로길이, 가로길이
	cin >> N >> M;

	queue<pair<int, int>> wall_queue; // 벽을 담아두는 큐
	queue<pair<int, int>> bfs_queue; // 일반 bfs실행용 큐

	vector<vector<int>> graph(N+1, vector<int>(M + 1, -1));
	vector<vector<int>> dist(N+1, vector<int>(M + 1, INF));
	dist[1][1] = 1;

	for (int n = 1; n < N + 1; n++)
	{
		string map_tile;
		cin >> map_tile;

		for (int m = 1; m < M + 1; m++)
		{
			graph[n][m] = map_tile[m - 1] - '0';
			if (graph[n][m] == 1) // 벽이라면
			{
				wall_queue.emplace(m,n);
			}
		}
	}

	int min_result = INF;

	pair<int, int> start_index = { 1,1 };

	BFS(graph, dist, start_index, min_result); // 처음 거리 완성
	while (!wall_queue.empty())
	{
		BFS(graph, dist, wall_queue.front(), min_result);
		wall_queue.pop();
	}

	if (min_result == INF || min_result == INF +1)
	{
		cout << "-1";
		return 0;
	}
	cout << min_result;

	return 0;
}