#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		int side_length[3];
		cin >> side_length[0] >> side_length[1] >> side_length[2];

		pair<int,int> max_length = pair<int,int>(0,side_length[0]); // 인덱스 번호, 인덱스값
		int withoutMax_sum = 0;

		for (int i = 0; i < 3; i++)
		{
			if (max_length.second < side_length[i])
			{
				max_length.first = i;
				max_length.second = side_length[i];
			}
		}
		for (int k = 0; k < 3; k++)
		{
			if (k != max_length.first)
			{
				withoutMax_sum += side_length[k];
			}
		}

		if (max_length.second == 0)
		{
			break;
		}

		if (max_length.second >= withoutMax_sum)
		{
			cout << "Invalid" << '\n';
		}
		else if (side_length[0] == side_length[1] || side_length[1] == side_length[2] || side_length[2] == side_length[0])
		{
			if (side_length[0] == side_length[1] && side_length[1] == side_length[2] && side_length[2] == side_length[0])
			{
				cout << "Equilateral" << '\n';
				continue;
			}
			cout << "Isosceles" << '\n';
		}
		else
		{
			cout << "Scalene" << '\n';
		}

	}
}