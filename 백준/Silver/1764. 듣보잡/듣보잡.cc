#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M; // 듣도 못한 사람, 보도 못한 사람
	cin >> N >> M;

	int count = 0;

	unordered_map<string, bool> my_map;
	map<string,bool> save_map;

	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;

		my_map.insert({ str,true });
	}

	for (int m = 0; m < M; m++)
	{
		string str;
		cin >> str;

		if (my_map.find(str) != my_map.end())
		{
			save_map.insert({ str,true });
			count++;
		}
	}

	cout << count << '\n';

	for (pair<string, bool> p : save_map)
	{
		cout << p.first << '\n';
	}

	return 0;
}