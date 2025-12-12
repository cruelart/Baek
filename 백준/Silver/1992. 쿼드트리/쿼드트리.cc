#include <iostream>
#include <vector>

using namespace std;

string str;

void div(vector<vector<bool>>& _graph, pair<int,int> _start_index, int _N)
{
	int y = _start_index.first;
	int x = _start_index.second;

	bool color = _graph[y][x];

	for (int r = y; r < y + _N; r++)
	{
		for (int c = x; c < x + _N; c++)
		{
			if (_graph[r][c] != color) // 색이 하나라도 다르면
			{
				//그 즉시 4등분
				str += '(';
				div(_graph, { y,x }, _N / 2);
				div(_graph, { y,x + _N/2 }, _N / 2);
				div(_graph, { y + _N / 2,x }, _N / 2);
				div(_graph, { y + _N / 2,x + _N / 2 }, _N / 2);
				str += ')';
				
				return;
			}
		}
	}
	if (color)
	{
		str += '1';
	}
	else
	{
		str += '0';
	}
	return;
}

int main()
{
	int N;
	cin >> N;

	vector<vector<bool>> graph(N, vector<bool>(N)); // true : 1 false : 0

	//그래프 채우기
	for (int y = 0; y < N; y++)
	{
		string str1;
		cin >> str1;
		for (int x = 0; x < str1.length(); x++)
		{
			graph[y][x] = str1[x]-'0';
		}
	}
	
	div(graph, { 0,0 }, N);

	cout << str;

	return 0;
}