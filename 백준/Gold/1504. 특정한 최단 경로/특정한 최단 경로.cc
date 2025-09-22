#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>

//풀이 방식 -> 다익스트라를 3번 호출한다. 꼭가야하는 정점 u의 최단거리를 일단 구하고 u에서 v의 최단거리를 또 한번, 마지막으로 v에서 최종 목적지까지의 최단 경로

using namespace std;

void dickstra(vector<vector<pair<int, int>>>& _graph, vector<int>& _dist, pair<int, int> start_index)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dic_queue;
	dic_queue.push(start_index);
	_dist[start_index.second] = start_index.first;

	while (!dic_queue.empty())
	{
		pair<int, int> present_index = dic_queue.top();
		dic_queue.pop();

		for (int i = 0; i < _graph[present_index.second].size(); i++)
		{
			int start = present_index.second;
			int end = _graph[present_index.second][i].second;
			int value = _graph[present_index.second][i].first;

			if (_dist[end] > _dist[start] + value)
			{
				_dist[end] = _dist[start] + value;
				dic_queue.push({ _dist[end],end });
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int INF = 2000000001;

	int N, E;// 정점의 개수, 간선의 개수
	cin >> N >> E;

	vector<vector<pair<int, int>>> graph(N + 1); // pair<int,int> 가중치, 도착지점

	vector<int> dist1(N + 1, INF);
	vector<int> dist2(N + 1, INF);
	vector<int> dist3(N + 1, INF);

	//그래프 작성
	for (int e = 0; e < E; e++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}

	int u, v;
	cin >> u >> v;

	dickstra(graph, dist1, { 0,1 }); // 1번정점부터 시작
	dickstra(graph, dist2, { 0,u }); // u번 정점부터 시작
	dickstra(graph, dist3, { 0,v }); // v번 정점부터 시작

	if (dist1[u] != INF && dist1[v] != INF)
	{
		if (dist2[v] != INF && dist2[N] != INF)
		{
			if(dist3[u] != INF && dist2[N] != INF)
			{
				int path1 = dist1[u] + dist2[v] + dist3[N];
				int path2 = dist1[v] + dist3[u] + dist2[N];

				int min_path = min(path1, path2);

				if (min_path >= INF)
				{
					cout << -1;
					return 0;
				}
				cout << min_path;
				return 0;
			}
		}
	}
	
	cout << -1;

}