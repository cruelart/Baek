#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	int N;
	cin >> N;

	unordered_map<long long, int> my_map;
	pair<long long, int> max = { 0,-1 };

	for (int n = 0; n < N; n++)
	{
		long long num;
		cin >> num;

		if (my_map.find(num) == my_map.end()) // 없던 거라면
		{
			my_map.insert({ num,1 });
		}
		else // 이미 존재한다면
		{
			my_map[num]++;
		}

		if (max.second < my_map[num])
		{
			max = { num, my_map[num] };
		}
		else if (max.second == my_map[num]) // 가장 많이 가지고 있는 정수가 여러가지면 ,작은 것을 출력
		{
			if (max.first > num)
			{
				max = { num, my_map[num] };
			}
		}

		else {}
	}

	cout << max.first;

	return 0;
}