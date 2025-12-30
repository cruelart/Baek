#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>& _sequence, vector<int>& _output_arr, const int& _N, const int& _M, const int _depth, int _exe_num)
{
	if (_depth == _M) // 현재 뽑은게 M개에 도달했으면 빠져나가자
	{
		for (int i = 0; i < _M; i++)
		{
			cout << _output_arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	//2 4 5 라는 수열에서 M만큼 뽑아서 나열한걸 출력하겠다
	for (int i = _exe_num; i < _N; i++)
	{
		_output_arr[_depth] = _sequence[i];
		dfs(_sequence, _output_arr, _N, _M, _depth + 1,i + 1);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	//4 5 2
	vector<int> sequence(N);
	vector<int> ouput_arr(M);

	for (int n = 0; n < N; n++)
	{
		cin >> sequence[n];
	}

	//2 4 5
	sort(sequence.begin(), sequence.end(), [](int a, int b) { return a < b; });

	dfs(sequence, ouput_arr, N, M, 0, 0);

	return 0;
}