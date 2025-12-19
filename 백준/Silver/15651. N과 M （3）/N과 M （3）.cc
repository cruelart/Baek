#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& _save_arr, int _N, int _M, int _depth)
{
	if (_depth == _M)
	{
		for (int i = 0; i < _save_arr.size(); i++)
		{
			cout << _save_arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int n = 1; n <= _N; n++)
	{
		_save_arr[_depth] = n;
		dfs(_save_arr, _N, _M, _depth + 1);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> save_arr(M);

	int depth = 0;
	dfs(save_arr, N, M, depth);

	return 0;
}