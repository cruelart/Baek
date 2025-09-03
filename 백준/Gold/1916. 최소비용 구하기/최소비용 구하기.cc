#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

void dijkstra(vector<vector<pair<int, long long>>>& _graph, vector<long long>& _dist, int _start_index, long long _INF)
{
	_dist[_start_index] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<>> dijkstra_queue;
	dijkstra_queue.emplace(_dist[_start_index], _start_index);

	while (!dijkstra_queue.empty())
	{
		int present_index = dijkstra_queue.top().second;
		long long present_index_value = dijkstra_queue.top().first;
		dijkstra_queue.pop();

		if (present_index_value > _dist[present_index])
		{
			continue;
		}

		for (int i = 0; i < _graph[present_index].size(); i++)
		{
			int end_index = _graph[present_index][i].first;
			long long value = _graph[present_index][i].second;

			if (_dist[present_index] != _INF && _dist[end_index] > _dist[present_index] + value)
			{
				_dist[end_index] = _dist[present_index] + value;
				dijkstra_queue.emplace(_dist[end_index], end_index);
			}
		}
	}
}

int main()
{
	int N, M; // 도시의 갯수, 버스간선의 갯수

	cin >> N;
	cin >> M;

	long long INF = std::numeric_limits<long long>::max(); // 최대 가중치 100000 x 100000 이므로 int의 최댓값을 넘겨버림

	vector<vector<pair<int, long long>>> graph(N + 1); // 도착정점, 가중치
	vector<long long> dist(N + 1, INF);

	for (int i = 0; i < M; i++)
	{
		int start, end;
		long long value; // 시작, 끝, 가중치

		cin >> start >> end >> value;

		graph[start].emplace_back(end, value);
	}

	int start_num, end_num; // 시작도시, 도착도시
	cin >> start_num >> end_num;

	dijkstra(graph, dist, start_num, INF);

	cout << dist[end_num];

	return 0;
}