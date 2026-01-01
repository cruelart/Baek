#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>& _sequence, vector<int>& _output_arr, int _start_index, const int& _N, const int& _M, int _depth) // 수열배열, 출력배열, 실행중인 인덱스값, 크기, 뽑는 갯수
{
	if (_depth == _M)
	{
		for (int i = 1; i <= _M; i++)
		{
			cout << _output_arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int prev = -1; // 이전 값을 저장

	for (int i = _start_index; i < _N; i++)
	{
		if (prev == _sequence[i]) // 같은 깊이에서 또 같은 숫자를 반복했을 경우
		{
			continue;
		}

		prev = _sequence[i];
		_output_arr[_depth + 1] = _sequence[i];
		dfs(_sequence, _output_arr, i + 1, _N, _M, _depth + 1);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	// 9 7 9 1
	vector<int> sequence(N);
	vector<int> output_arr(M + 1, -1); // 0은 안씀
	 
	for (int n = 0; n < N; n++)
	{
		cin >> sequence[n];
	}

	// 1 7 9 9
	sort(sequence.begin(), sequence.end());

	dfs(sequence, output_arr, 0 , N, M, 0);

	return 0;
}