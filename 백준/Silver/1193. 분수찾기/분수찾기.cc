#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int X;
	cin >> X;

	pair<int, int> N_location;

	//initialize N_location -> (1,1)
	N_location.first = 1;
	N_location.second = 1;
	int N_location_index = 1;

	int turn_num = 1; // 꺾이는 지점

	while(N_location_index != X)
	{
		if (turn_num % 2 == 1)
		{
			if (N_location.second == turn_num)
			{
				N_location.second += 1;
				N_location_index++;
				turn_num++;
				continue;
			}

			N_location.first -= 1;
			N_location.second += 1;
			N_location_index++;
			continue;
		}

		else if (turn_num % 2 == 0)
		{
			if (N_location.first == turn_num)
			{
				N_location.first += 1;
				N_location_index++;
				turn_num++;
				continue;
			}

			N_location.first += 1;
			N_location.second -= 1;
			N_location_index++;
			continue;
		}
	}

	string str = to_string(N_location.first) + '/' + to_string(N_location.second);
	cout << str;
}