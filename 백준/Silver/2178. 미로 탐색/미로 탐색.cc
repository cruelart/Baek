#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

void BFS(vector<vector<int>>& _graph, vector<vector<int>>& _dist, pair<int,int> start_index, int _INF)
{
	queue<pair<int, int>> bfs_queue;
	bfs_queue.push(start_index);

	while (!bfs_queue.empty())
	{
		pair<int,int> present_index = bfs_queue.front();
		bfs_queue.pop();

		int x = present_index.first;
		int y = present_index.second;

		if (_graph[y - 1][x] == 1 && _dist[y - 1][x] == _INF) // 이동할 수 있는 칸이면서 방문한 적 없는 미로칸이라면 (상 우 하 순서대로)
		{
			_dist[y - 1][x] = _dist[y][x] + 1;
			bfs_queue.emplace(x, y-1);
		}
		if (_graph[y][x + 1] == 1 && _dist[y][x + 1] == _INF) // 이동할 수 있는 칸이면서 방문한 적 없는 미로칸이라면 (상 우 하 순서대로)
		{
			_dist[y][x + 1] = _dist[y][x] + 1;
			bfs_queue.emplace(x+1, y);
		}
		if (_graph[y][x - 1] == 1 && _dist[y][x - 1] == _INF) // 이동할 수 있는 칸이면서 방문한 적 없는 미로칸이라면 (상 우 하 순서대로)
		{
			_dist[y][x - 1] = _dist[y][x] + 1;
			bfs_queue.emplace(x - 1, y);
		}

		if (_graph[y + 1][x] == 1 && _dist[y + 1][x] == _INF) // 이동할 수 있는 칸이면서 방문한 적 없는 미로칸이라면 (상 우 하 순서대로)
		{
			_dist[y + 1][x] = _dist[y][x] + 1;
			bfs_queue.emplace(x, y + 1);
		}
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M, N; // x좌표 갯수, y좌표 갯수
	cin >> N >> M;

	int INF = std::numeric_limits<int>::max();

	vector<vector<int>> graph(N + 2, vector<int>(M + 2, 0)); // 인접 행렬 그래프
	vector<vector<int>> dist(N + 2, vector<int>(M + 2, INF)); // 최단거리

	pair<int, int> start_num;
	start_num.first = 1;
	start_num.second = 1;

	dist[start_num.second][start_num.first] = 1; // 초기화

	//그래프 작성
	for (int i = 1; i < N +1; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j < M + 1; j++)
		{
			graph[i][j] = str[j - 1] - '0';
		}
	}

	BFS(graph, dist, start_num, INF);

	cout << dist[N][M];

	return 0;
}