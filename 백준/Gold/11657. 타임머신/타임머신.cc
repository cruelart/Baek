#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

bool BellmanFordAlgorithm(vector<tuple<int,int, long long>>& _graph, vector<long long>& _min_time, int _start_index, long long _max_longlong)
{
    _min_time[_start_index] = 0;
    int N = _min_time.size() - 1;

    // N-1번 반복
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < _graph.size(); j++)
        {
            int start = get<0>(_graph[j]);
            int end = get<1>(_graph[j]);
            long long value = get<2>(_graph[j]);

            if (_min_time[start] != _max_longlong && _min_time[end] > _min_time[start] + value)
            {
                _min_time[end] = _min_time[start] + value;
            }
        }
    }

    // 음수 사이클 확인
    for (int j = 0; j < _graph.size(); j++)
    {
        int start = get<0>(_graph[j]);
        int end = get<1>(_graph[j]);
        long long value = get<2>(_graph[j]);

        if (_min_time[start] != _max_longlong && _min_time[end] > _min_time[start] + value)
        {
            return false; // 음수 사이클 있음
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long max_longlong = std::numeric_limits<long long>::max();
    int start_index = 1;

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, long long>> graph(M);
    vector<long long> min_time(N + 1, max_longlong);

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[i] = {A, B, C};
    }

    if (!BellmanFordAlgorithm(graph, min_time, start_index, max_longlong))
    {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 2; i <= N; i++)
    {
        if (min_time[i] == max_longlong) cout << -1 << '\n';
        else cout << min_time[i] << '\n';
    }

    return 0;
}