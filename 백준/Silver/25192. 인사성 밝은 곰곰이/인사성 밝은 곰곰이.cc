#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	unordered_map<string,pair<int, int>> map; // key : 닉네임, value : 입력 인덱스값, 채팅 횟수

	int Enter_index = 0;

	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;

		if (str == "ENTER")
		{
			Enter_index = n;
			continue;
		}

		if (Enter_index == 0)
		{
			map[str].first = Enter_index; // 영향을 받고 있는 인덱스의 값 받아옴
			map[str].second = 1; // 영향을 받고 있는 인덱스의 값 받아옴
		}
		
		if (map[str].first < Enter_index)
		{
			map[str].first = Enter_index;
			map[str].second++;
		}
	}
	
	int result = 0;

	for (auto p : map)
	{
		result += p.second.second;
	}

	cout << result;

	return 0;
}